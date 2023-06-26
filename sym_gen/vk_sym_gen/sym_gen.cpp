#include "clang/AST/ASTConsumer.h"
#include "clang/AST/Decl.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/ASTMatchers/ASTMatchersInternal.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendAction.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using function_data_tuple = std::tuple<std::string, std::string, std::string, std::vector<std::string>>;
std::vector<function_data_tuple>      all_functions;        // This is horrible way of collecting the names but can't find another easy way
static const std::vector<std::string> function_types{"VkInstance", "VkPhysicalDevice", "VkDevice", "VkQueue", "VkCommandBuffer"};
static const std::vector<std::string> additional_shim_functions{"vkCreateDevice"};
static const std::vector<std::string> proc_addr_functions{"vkGetInstanceProcAddr", "vkGetDeviceProcAddr"};

// Better try this one https://stackoverflow.com/questions/49659274/getting-the-signature-of-a-functiondecl
static std::string getDeclaration(const clang::FunctionDecl *D)
{
	clang::ASTContext    &ctx = D->getASTContext();
	clang::SourceManager &mgr = ctx.getSourceManager();

	clang::SourceRange range = clang::SourceRange(D->getSourceRange().getBegin(), D->getSourceRange().getEnd());
	clang::StringRef   s     = clang::Lexer::getSourceText(clang::CharSourceRange::getTokenRange(range), mgr, ctx.getLangOpts());

	auto str = s.str();
	str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
	std::string res;
	std::unique_copy(str.begin(), str.end(), std::back_inserter(res),
	                 [](char c1, char c2) { return c1 == ' ' && c2 == ' '; });

	return res;
}

class FindFunctionVisitor : public clang::RecursiveASTVisitor<FindFunctionVisitor>
{
  public:
	explicit FindFunctionVisitor(clang::ASTContext *Context) :
	    Context(Context)
	{}

	bool VisitFunctionDecl(clang::FunctionDecl *a_function_declration)
	{
		auto params = a_function_declration->parameters();

		std::string              first_param{""};
		std::vector<std::string> arguments{};

		if ((a_function_declration->param_size() > 0 && !params.empty()))
		{
			arguments.reserve(params.size());
			first_param = (*params.begin())->getType().getAsString();

			for (auto &p : params)
			{
				arguments.push_back(p->getNameAsString());
			}
		}

		if (std::find(function_types.begin(), function_types.end(), first_param) == function_types.end())
			first_param = "";

		all_functions.push_back(std::make_tuple(a_function_declration->getNameInfo().getName().getAsString(),
		                                        first_param, getDeclaration(a_function_declration), arguments));
		return true;
	}

  private:
	clang::ASTContext *Context = nullptr;
};

class FindFunctionConsumer : public clang::ASTConsumer
{
  public:
	explicit FindFunctionConsumer(clang::ASTContext *Context) :
	    m_visitor(Context)
	{}
	void HandleTranslationUnit(clang::ASTContext &a_context)
	{
		// Traversing the translation unit decl via a RecursiveASTVisitor
		// will visit all nodes in the AST.
		this->m_visitor.TraverseDecl(a_context.getTranslationUnitDecl());
	}

  private:
	// A RecursiveASTVisitor implementation.
	FindFunctionVisitor m_visitor;
};

class FindFunctionFrontendAction : public clang::ASTFrontendAction
{
  public:
	std::unique_ptr<clang::ASTConsumer> CreateASTConsumer(clang::CompilerInstance &Compiler, llvm::StringRef)
	{
		return std::unique_ptr<clang::ASTConsumer>(new FindFunctionConsumer(&Compiler.getASTContext()));
	}
};

static const std::string main_header{R"header(#pragma once
#include <dlfcn.h>
#include <iostream>
#include <string>
#include <vector>

// #define VUSYM_SUPPORT_MULTIPLE_VULKAN_DEVICES 1

#define VK_ENABLE_BETA_EXTENSIONS        // FIXME::

#if defined (__APPLE__)
#    if !defined (VK_USE_PLATFORM_METAL_EXT)
#        define VK_USE_PLATFORM_METAL_EXT        // TODO:: This should be in CMakeLists.txt somewhere
#    endif
#elif defined (__linux__)
#    if !defined (VK_USE_PLATFORM_XCB_KHR)
#        define VK_USE_PLATFORM_XCB_KHR        // Should this be XLIB instead?
#    endif
#elif defined (_WIN32)
#    if !defined (VK_USE_PLATFORM_WIN32_KHR)
#        define VK_USE_PLATFORM_WIN32_KHR
#    endif
#else
#     error "Platform not supported yet!"
#endif

// TODO: Just before including vulkan.h you need to define all the extensions you want to read for example VK_USE_PLATFORM_METAL_EXT etc
// This won't work if vulkan.h included by someone else
#ifndef VK_NO_PROTOTYPES
#    define VK_NO_PROTOTYPES
#endif
#include <vulkan/vulkan.h>

// Utility Macros
#define VUSYM_LOAD_VULKAN_GLOBAL_SYMBOL(a_pfn)                                                \
	{                                                                                         \
		real_##a_pfn = reinterpret_cast<PFN_##a_pfn>(vkGetInstanceProcAddr(nullptr, #a_pfn)); \
		if (nullptr == real_##a_pfn)                                                          \
			return VK_FALSE;                                                                  \
	}

#define VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(a_pfn)                                          \
	{                                                                                     \
		a_pfn = reinterpret_cast<PFN_##a_pfn>(vkGetInstanceProcAddr(a_instance, #a_pfn)); \
		if (nullptr == a_pfn && a_print_errors)                                           \
			std::cout << "Instance function " << #a_pfn << " is nullptr" << std::endl;    \
	}

#if defined(VUSYM_SUPPORT_MULTIPLE_VULKAN_DEVICES)
#	define VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(a_pfn)                                                 \
		{                                                                                          \
			a_table->a_pfn = reinterpret_cast<PFN_##a_pfn>(vkGetDeviceProcAddr(a_device, #a_pfn)); \
			if (nullptr == a_table->a_pfn && a_print_errors)                                       \
				std::cout << "Device function " << #a_pfn << " is nullptr" << std::endl;           \
		}
#else
#	define VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(a_pfn)                                        \
		{                                                                                 \
			a_pfn = reinterpret_cast<PFN_##a_pfn>(vkGetDeviceProcAddr(a_device, #a_pfn)); \
			if (nullptr == a_pfn && a_print_errors)                                       \
				std::cout << "Device function " << #a_pfn << " is nullptr" << std::endl;  \
		}
#endif

#define VUSYM_LOAD_VULKAN_INSTANCE_REAL_SYMBOL(a_pfn)                                             \
	{																\
		real_##a_pfn = reinterpret_cast<PFN_##a_pfn>(vkGetInstanceProcAddr(a_instance, #a_pfn)); \
		if (nullptr == real_##a_pfn && a_print_errors)                                           \
			std::cout << "Instance function " << #a_pfn << " is nullptr" << std::endl;           \
	}

#if defined(VUSYM_SUPPORT_MULTIPLE_VULKAN_DEVICES)
#	define VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(a_pfn) \
		PFN_##a_pfn a_pfn
#else
#	define VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(a_pfn) \
		extern PFN_##a_pfn a_pfn
#endif

// Utility functions
/**
  Init and load vkGetInstanceProcAddr and vkGetDeviceProcAddr function pointers
  so we can load other vulkan functions with
*/

VkBool32 vusym_load_proc_addr_symbols();

/**
  Init and load function pointers for functions that
  does not take an instance as first argument
*/

VkBool32 vusym_init_vulkan_global_symbols();

/**
  Init and load function pointers for functions that
  need an instance as first argument
*/

VkBool32 vusym_init_vulkan_instance_symbols(VkInstance a_instance, bool a_print_errors = true);

/**
  Init and load function pointers for functions that
  need a device, these are optimized functions and
  are only required if you want to access device
  functions directly.
*/

struct PFNTable;

VkBool32 vusym_init_vulkan_device_symbols(VkDevice a_device,
#ifdef VUSYM_SUPPORT_MULTIPLE_VULKAN_DEVICES
										  PFNTable *a_table,
#endif
										  bool a_print_errors = true);

// Function declarations

)header"};

static const std::string platform_function{R"platfunc(
VkBool32 vusym_load_proc_addr_symbols()
{
	std::string loader_lib{"libvulkan"};
#if defined(__APPLE__)
	std::vector<std::string> versions{".dylib", ".1.dylib"};
#elif defined(__linux__) || defined(__ANDROID__)
	std::vector<std::string> versions{".so", "so.1"};
#else
#	error "Platform not supported at the moment."
#endif

	void *vulkan_loader{nullptr};

	for (auto &version : versions)
	{
		vulkan_loader = dlopen((loader_lib + version).c_str(), RTLD_NOW | RTLD_LOCAL);

		if (vulkan_loader != nullptr)
		{
			break;
		}
	}

	if (vulkan_loader == nullptr)
	{
		std::cout << "Can't find libvulkan.* in known library paths exiting now" << std::endl;
		exit(1);
	}

	vkGetInstanceProcAddr = reinterpret_cast<PFN_vkGetInstanceProcAddr>(dlsym(vulkan_loader, "vkGetInstanceProcAddr"));
	vkGetDeviceProcAddr   = reinterpret_cast<PFN_vkGetDeviceProcAddr>(dlsym(vulkan_loader, "vkGetDeviceProcAddr"));

    // TODO: Find out where can I dlclose the loader
	// dlclose(vulkan_loader);

	return VK_TRUE;
}

)platfunc"};

static const std::string global_header{R"gheader(
// Assumes vkGetInstanceProcAddr and vkGetDeviceProcAddr are now loaded
VkBool32 vusym_init_vulkan_global_symbols()
{
	assert(vkGetInstanceProcAddr != nullptr && "vusym error vkGetInstanceProcAddr is nullptr.");

)gheader"};

static const std::string instance_header{R"gheader(
VkBool32 vusym_init_vulkan_instance_symbols(VkInstance a_instance, bool a_print_errors)
{
	assert(vkGetInstanceProcAddr != nullptr && "vusym error vkGetInstanceProcAddr is nullptr.");

)gheader"};

static const std::string device_header{R"gheader(
VkBool32 vusym_init_vulkan_device_symbols(VkDevice a_device,
#ifdef VUSYM_SUPPORT_MULTIPLE_VULKAN_DEVICES
										  PFNTable *a_table,
#endif
										  bool a_print_errors)
{
	assert(vkGetInstanceProcAddr != nullptr && "vusym error vkGetInstanceProcAddr is nullptr.");
	assert(vkGetDeviceProcAddr != nullptr && "vusym error vkGetDeviceProcAddr is nullptr.");
#ifdef VUSYM_SUPPORT_MULTIPLE_VULKAN_DEVICES
	assert(a_table != nullptr && "vusym error PFNTable is nullptr.");
#endif

)gheader"};

static const std::string multi_device_struct{R"multi(
#if defined (VUSYM_SUPPORT_MULTIPLE_VULKAN_DEVICES)
struct PFNTable
{
	PFNTable()
	{}
	PFNTable(VkDevice a_device) :
		real_device(a_device)
	{
		// load_device_function();
		vusym_init_vulkan_device_symbols(a_device, this);
	}

	VkDevice real_device{nullptr};
#endif

)multi"};

static const std::string multi_device_struct_end{R"multiend(
#ifdef VUSYM_SUPPORT_MULTIPLE_VULKAN_DEVICES
};
#endif

)multiend"};

static const std::string init_func{R"init(
// Initialise vusym if not already initialized, do nothing otherwise
void initialise()
{
	static bool initialized = false;        // Valid per application lifetime, good enough

	if (!initialized)
	{
		vusym_load_proc_addr_symbols();
		vusym_init_vulkan_global_symbols();
		initialized = true;
	}
}

)init"};

auto get_function_name(const function_data_tuple &a_entry)
{
	return std::get<0>(a_entry);
}

auto get_function_first_argument(const function_data_tuple &a_entry)
{
	return std::get<1>(a_entry);
}

auto get_function_declaration(const function_data_tuple &a_entry)
{
	return std::get<2>(a_entry);
}

auto get_function_arguments(const function_data_tuple &a_entry)
{
	return std::get<3>(a_entry);
}

auto is_global_function(const function_data_tuple &a_entry)
{
	auto first_arg = get_function_first_argument(a_entry);
	auto func_name = get_function_name(a_entry);

	if (first_arg == "" ||
	    std::find(additional_shim_functions.begin(),
	              additional_shim_functions.end(), func_name) !=
	        additional_shim_functions.end())
	{
		return true;
	}

	return false;
}

auto is_proc_addr_function(const function_data_tuple &a_entry)
{
	auto func_name = get_function_name(a_entry);

	if (std::find(proc_addr_functions.begin(),
	              proc_addr_functions.end(), func_name) !=
	    proc_addr_functions.end())
	{
		return true;
	}

	return false;
}

auto is_instance_function(const function_data_tuple &a_entry)
{
	auto first_arg = get_function_first_argument(a_entry);

	// This needs a bit more thinking
	if ((first_arg == "VkInstance" || first_arg == "VkPhysicalDevice"))        // && !is_proc_addr_function(a_entry))
	{
		return true;
	}

	return false;
}

auto is_device_function(const function_data_tuple &a_entry)
{
	auto first_arg = get_function_first_argument(a_entry);
	auto func_name = get_function_name(a_entry);

	// Everything else other than the below is a device function is this true
	if (first_arg == "VkInstance" || first_arg == "VkPhysicalDevice" || first_arg == "")
	{
		return false;
	}

	return true;
}

auto is_additional_shim_function(const function_data_tuple &a_entry)
{
	auto func_name = get_function_name(a_entry);

	if (std::find(additional_shim_functions.begin(),
	              additional_shim_functions.end(), func_name) !=
	    additional_shim_functions.end())
	{
		return true;
	}

	return false;
}

// Modified version of libTooling tutorial https://clang.llvm.org/docs/LibASTMatchersTutorial.html
int main(int argc, const char **argv)
{
	all_functions.reserve(500);        // Enough for all functions in vulkan 1.2 with extensions

	llvm::cl::OptionCategory vusym_options_category("vusym options:");
	auto expected_parser = clang::tooling::CommonOptionsParser::create(argc, argv, vusym_options_category);

	if (!expected_parser)
	{
		// Fail gracefully for unsupported options.
		llvm::errs() << expected_parser.takeError();
		return 1;
	}

	clang::tooling::CommonOptionsParser &options_parser = expected_parser.get();

	clang::tooling::ClangTool function_finder_tool(options_parser.getCompilations(), options_parser.getSourcePathList());
	function_finder_tool.run(clang::tooling::newFrontendActionFactory<FindFunctionFrontendAction>().get());

	{
		std::fstream header{"vusym.hpp", std::ios::out};
		header << main_header;

		// Write all functions extern declaration
		for (auto &f : all_functions)
		{
			auto func_name = get_function_name(f);

			if (!is_device_function(f) || is_proc_addr_function(f))
			{
				header << "extern PFN_" << func_name << " ";

				if (is_global_function(f))
					header << "real_" << func_name << ";\n";
				else
					header << func_name << ";\n";
			}
		}

		// open multi struct
		header << multi_device_struct << "\n";

		for (auto &f : all_functions)
		{
			auto func_name = get_function_name(f);

			if (is_device_function(f) && !is_proc_addr_function(f))
			{
				header << "VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(" << func_name << ");\n";
			}
		}

		// close multi struct
		header << multi_device_struct_end << "\n";

		header << "\n";

		// Write shim functions for global functions
		for (auto &f : all_functions)
		{
			auto func_name = get_function_name(f);

			if (is_global_function(f))
				header << get_function_declaration(f) << ";\n";
		}

		header << "#if defined (VUSYM_SUPPORT_MULTIPLE_VULKAN_DEVICES)"
		       << "\n";

		// All device functions
		for (auto &f : all_functions)
		{
			// All declarations
			if (is_device_function(f) && get_function_first_argument(f) == "VkDevice" && !is_proc_addr_function(f))
				header << get_function_declaration(f) << ";\n";
		}

		// close multi struct
		header << "#endif"
		       << "\n";

		header.close();
	}
	{
		std::fstream header{"vusym.cpp", std::ios::out};
		header << "#include \"vusym.hpp\"\n\n";

		// Need to split this between real_funcs, global funcs, instance funcs and device funcs
		// After instance funcs start multi struct
		// All global functions
		for (auto &f : all_functions)
		{
			// All declarations
			if (is_global_function(f))
				header << "PFN_" << get_function_name(f) << " real_" << get_function_name(f) << " = nullptr;\n";
		}

		// All instance functions
		for (auto &f : all_functions)
		{
			// All declarations
			if ((is_instance_function(f) && !is_global_function(f)) || (is_proc_addr_function(f)))        // Need to test this one
				header << "PFN_" << get_function_name(f) << " " << get_function_name(f) << " = nullptr;\n";
		}

		header << "#if !defined (VUSYM_SUPPORT_MULTIPLE_VULKAN_DEVICES)"
		       << "\n";

		// All device functions
		for (auto &f : all_functions)
		{
			// All declarations
			if (is_device_function(f) && !is_proc_addr_function(f))
				header << "PFN_" << get_function_name(f) << " " << get_function_name(f) << " = nullptr;\n";
		}

		// close multi struct
		header << "#endif"
		       << "\n";

		// Add init_func
		header << init_func << "\n";

		// Init platform symbols
		header << platform_function << std::endl;

		// Init global symbols
		header << global_header << std::endl;

		for (auto &f : all_functions)
			if (get_function_first_argument(f) == "")
				header << "VUSYM_LOAD_VULKAN_GLOBAL_SYMBOL(" << get_function_name(f) << ");\n";

		header << "\nreturn VK_TRUE;\n}\n";

		// Init instance symbols
		header << instance_header << std::endl;

		for (auto &f : all_functions)
		{
			if (is_instance_function(f) && !is_proc_addr_function(f))
			{
				if (is_additional_shim_function(f))
				{
					header << "VUSYM_LOAD_VULKAN_INSTANCE_REAL_SYMBOL(" << get_function_name(f) << ");\n\n";
				}
				else
				{
					header << "VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(" << get_function_name(f) << ");\n";
				}
			}
		}

		header << "\nreturn VK_TRUE;\n}\n";

		// Init device symbols
		header << device_header << std::endl;

		for (auto &f : all_functions)
		{
			if (is_device_function(f) && !is_proc_addr_function(f))
				header << "VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(" << get_function_name(f) << ");\n";
		}

		header << "\nreturn VK_TRUE;\n}";

		// Define shim functions for global functions
		for (auto &f : all_functions)
		{
			auto func_name = get_function_name(f);

			if (is_global_function(f))
			{
				header << "\n\n"
				       << get_function_declaration(f) << "\n{\n";
				if (func_name == "vkCreateInstance")
				{
					header << "initialise();\n\nauto res = real_";
					header << func_name << "(";
					auto arguments = get_function_arguments(f);
					for (size_t i = 0; i < arguments.size(); ++i)
					{
						header << arguments[i];
						if (i + 1 < arguments.size())
							header << ", ";
					}
					header << ");\nvusym_init_vulkan_instance_symbols(*";
					for (auto a : arguments)
					{
						if (a == "pInstance")        // TODO: Fix this, this should be type based not name based
							header << a;
					}
					header << ");\nreturn res;\n}";
				}
				else if (func_name == "vkCreateDevice")
				{
					header << "// Assumed to be initialised by now\n auto res = real_";
					header << func_name << "(";
					auto arguments = get_function_arguments(f);
					for (size_t i = 0; i < arguments.size(); ++i)
					{
						header << arguments[i];
						if (i + 1 < arguments.size())
							header << ", ";
					}

					header << ");\n\n#if defined(VUSYM_SUPPORT_MULTIPLE_VULKAN_DEVICES)";
					header << "\nauto device_table = new PFNTable(*";
					for (auto a : arguments)
					{
						if (a == "pDevice")        // TODO: Fix this, this should be type based not name based
							header << a << ");\n *" << a << " = reinterpret_cast<VkDevice>(device_table);\n#else\nvusym_init_vulkan_device_symbols(*" << a << ");\n #endif \nreturn res;\n}";
					}
				}
				else
				{
					header << "initialise();\n\n return real_";
					header << func_name << "(";
					auto arguments = get_function_arguments(f);
					for (size_t i = 0; i < arguments.size(); ++i)
					{
						header << arguments[i];
						if (i + 1 < arguments.size())
							header << ", ";
					}

					header << ");\n}";
				}
			}
		}

		// Add the following
		header << "\n\n#if defined (VUSYM_SUPPORT_MULTIPLE_VULKAN_DEVICES)\n";
		for (auto &f : all_functions)
		{
			if (is_device_function(f) && !is_proc_addr_function(f) && get_function_first_argument(f) == "VkDevice")
			{
				auto arguments = get_function_arguments(f);

				header << "\n"
				       << get_function_declaration(f) << "\n{\nauto d = reinterpret_cast<PFNTable *>(device);\n";        // TODO: Fix the device name

				if (get_function_name(f) == "vkDestroyDevice")
					header << "d->";
				else
					header << "return d->";

				header << get_function_name(f) << "(d->real_device";

				if (arguments.size() > 1)
					header << ",";

				for (size_t i = 1; i < arguments.size(); ++i)
				{
					header << arguments[i];
					if (i + 1 < arguments.size())
						header << ", ";
				}
				header << ");\n";

				if (get_function_name(f) == "vkDestroyDevice")
					header << "delete d;";

				header << "\n}\n";
			}
		}

		// Add the following
		header << "\n#endif\n";
		header.close();
	}
}
