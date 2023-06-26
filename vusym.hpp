#pragma once

#include <dlfcn.h>
#include <iostream>
#include <string>
#include <vector>

#define VUSYM_SUPPORT_MULTIPLE_VULKAN_DEVICES 1

#define VK_ENABLE_BETA_EXTENSIONS        // FIXME::

#if defined(__APPLE__)
#	if !defined(VK_USE_PLATFORM_METAL_EXT)
#		define VK_USE_PLATFORM_METAL_EXT        // TODO:: This should be in CMakeLists.txt somewhere
#	endif
#elif defined(__linux__)
#	if !defined(VK_USE_PLATFORM_XCB_KHR)
#		define VK_USE_PLATFORM_XCB_KHR        // Should this be XLIB instead?
#	endif
#elif defined(_WIN32)
#	if !defined(VK_USE_PLATFORM_WIN32_KHR)
#		define VK_USE_PLATFORM_WIN32_KHR
#	endif
#else
#	error "Platform not supported yet!"
#endif

// TODO: Just before including vulkan.h you need to define all the extensions you want to read for example VK_USE_PLATFORM_METAL_EXT etc
// This won't work if vulkan.h included by someone else
#ifndef VK_NO_PROTOTYPES
#	define VK_NO_PROTOTYPES
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

#define VUSYM_LOAD_VULKAN_INSTANCE_REAL_SYMBOL(a_pfn)                                            \
	{                                                                                            \
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

extern PFN_vkCreateInstance                                                  real_vkCreateInstance;
extern PFN_vkDestroyInstance                                                 vkDestroyInstance;
extern PFN_vkEnumeratePhysicalDevices                                        vkEnumeratePhysicalDevices;
extern PFN_vkGetPhysicalDeviceFeatures                                       vkGetPhysicalDeviceFeatures;
extern PFN_vkGetPhysicalDeviceFormatProperties                               vkGetPhysicalDeviceFormatProperties;
extern PFN_vkGetPhysicalDeviceImageFormatProperties                          vkGetPhysicalDeviceImageFormatProperties;
extern PFN_vkGetPhysicalDeviceProperties                                     vkGetPhysicalDeviceProperties;
extern PFN_vkGetPhysicalDeviceQueueFamilyProperties                          vkGetPhysicalDeviceQueueFamilyProperties;
extern PFN_vkGetPhysicalDeviceMemoryProperties                               vkGetPhysicalDeviceMemoryProperties;
extern PFN_vkGetInstanceProcAddr                                             vkGetInstanceProcAddr;
extern PFN_vkGetDeviceProcAddr                                               vkGetDeviceProcAddr;
extern PFN_vkCreateDevice                                                    real_vkCreateDevice;
extern PFN_vkEnumerateInstanceExtensionProperties                            real_vkEnumerateInstanceExtensionProperties;
extern PFN_vkEnumerateDeviceExtensionProperties                              vkEnumerateDeviceExtensionProperties;
extern PFN_vkEnumerateInstanceLayerProperties                                real_vkEnumerateInstanceLayerProperties;
extern PFN_vkEnumerateDeviceLayerProperties                                  vkEnumerateDeviceLayerProperties;
extern PFN_vkGetPhysicalDeviceSparseImageFormatProperties                    vkGetPhysicalDeviceSparseImageFormatProperties;
extern PFN_vkEnumerateInstanceVersion                                        real_vkEnumerateInstanceVersion;
extern PFN_vkEnumeratePhysicalDeviceGroups                                   vkEnumeratePhysicalDeviceGroups;
extern PFN_vkGetPhysicalDeviceFeatures2                                      vkGetPhysicalDeviceFeatures2;
extern PFN_vkGetPhysicalDeviceProperties2                                    vkGetPhysicalDeviceProperties2;
extern PFN_vkGetPhysicalDeviceFormatProperties2                              vkGetPhysicalDeviceFormatProperties2;
extern PFN_vkGetPhysicalDeviceImageFormatProperties2                         vkGetPhysicalDeviceImageFormatProperties2;
extern PFN_vkGetPhysicalDeviceQueueFamilyProperties2                         vkGetPhysicalDeviceQueueFamilyProperties2;
extern PFN_vkGetPhysicalDeviceMemoryProperties2                              vkGetPhysicalDeviceMemoryProperties2;
extern PFN_vkGetPhysicalDeviceSparseImageFormatProperties2                   vkGetPhysicalDeviceSparseImageFormatProperties2;
extern PFN_vkGetPhysicalDeviceExternalBufferProperties                       vkGetPhysicalDeviceExternalBufferProperties;
extern PFN_vkGetPhysicalDeviceExternalFenceProperties                        vkGetPhysicalDeviceExternalFenceProperties;
extern PFN_vkGetPhysicalDeviceExternalSemaphoreProperties                    vkGetPhysicalDeviceExternalSemaphoreProperties;
extern PFN_vkGetPhysicalDeviceToolProperties                                 vkGetPhysicalDeviceToolProperties;
extern PFN_vkDestroySurfaceKHR                                               vkDestroySurfaceKHR;
extern PFN_vkGetPhysicalDeviceSurfaceSupportKHR                              vkGetPhysicalDeviceSurfaceSupportKHR;
extern PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR                         vkGetPhysicalDeviceSurfaceCapabilitiesKHR;
extern PFN_vkGetPhysicalDeviceSurfaceFormatsKHR                              vkGetPhysicalDeviceSurfaceFormatsKHR;
extern PFN_vkGetPhysicalDeviceSurfacePresentModesKHR                         vkGetPhysicalDeviceSurfacePresentModesKHR;
extern PFN_vkGetPhysicalDevicePresentRectanglesKHR                           vkGetPhysicalDevicePresentRectanglesKHR;
extern PFN_vkGetPhysicalDeviceDisplayPropertiesKHR                           vkGetPhysicalDeviceDisplayPropertiesKHR;
extern PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR                      vkGetPhysicalDeviceDisplayPlanePropertiesKHR;
extern PFN_vkGetDisplayPlaneSupportedDisplaysKHR                             vkGetDisplayPlaneSupportedDisplaysKHR;
extern PFN_vkGetDisplayModePropertiesKHR                                     vkGetDisplayModePropertiesKHR;
extern PFN_vkCreateDisplayModeKHR                                            vkCreateDisplayModeKHR;
extern PFN_vkGetDisplayPlaneCapabilitiesKHR                                  vkGetDisplayPlaneCapabilitiesKHR;
extern PFN_vkCreateDisplayPlaneSurfaceKHR                                    vkCreateDisplayPlaneSurfaceKHR;
extern PFN_vkGetPhysicalDeviceVideoCapabilitiesKHR                           vkGetPhysicalDeviceVideoCapabilitiesKHR;
extern PFN_vkGetPhysicalDeviceVideoFormatPropertiesKHR                       vkGetPhysicalDeviceVideoFormatPropertiesKHR;
extern PFN_vkGetPhysicalDeviceFeatures2KHR                                   vkGetPhysicalDeviceFeatures2KHR;
extern PFN_vkGetPhysicalDeviceProperties2KHR                                 vkGetPhysicalDeviceProperties2KHR;
extern PFN_vkGetPhysicalDeviceFormatProperties2KHR                           vkGetPhysicalDeviceFormatProperties2KHR;
extern PFN_vkGetPhysicalDeviceImageFormatProperties2KHR                      vkGetPhysicalDeviceImageFormatProperties2KHR;
extern PFN_vkGetPhysicalDeviceQueueFamilyProperties2KHR                      vkGetPhysicalDeviceQueueFamilyProperties2KHR;
extern PFN_vkGetPhysicalDeviceMemoryProperties2KHR                           vkGetPhysicalDeviceMemoryProperties2KHR;
extern PFN_vkGetPhysicalDeviceSparseImageFormatProperties2KHR                vkGetPhysicalDeviceSparseImageFormatProperties2KHR;
extern PFN_vkEnumeratePhysicalDeviceGroupsKHR                                vkEnumeratePhysicalDeviceGroupsKHR;
extern PFN_vkGetPhysicalDeviceExternalBufferPropertiesKHR                    vkGetPhysicalDeviceExternalBufferPropertiesKHR;
extern PFN_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR                 vkGetPhysicalDeviceExternalSemaphorePropertiesKHR;
extern PFN_vkGetPhysicalDeviceExternalFencePropertiesKHR                     vkGetPhysicalDeviceExternalFencePropertiesKHR;
extern PFN_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR   vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR;
extern PFN_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR           vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR;
extern PFN_vkGetPhysicalDeviceSurfaceCapabilities2KHR                        vkGetPhysicalDeviceSurfaceCapabilities2KHR;
extern PFN_vkGetPhysicalDeviceSurfaceFormats2KHR                             vkGetPhysicalDeviceSurfaceFormats2KHR;
extern PFN_vkGetPhysicalDeviceDisplayProperties2KHR                          vkGetPhysicalDeviceDisplayProperties2KHR;
extern PFN_vkGetPhysicalDeviceDisplayPlaneProperties2KHR                     vkGetPhysicalDeviceDisplayPlaneProperties2KHR;
extern PFN_vkGetDisplayModeProperties2KHR                                    vkGetDisplayModeProperties2KHR;
extern PFN_vkGetDisplayPlaneCapabilities2KHR                                 vkGetDisplayPlaneCapabilities2KHR;
extern PFN_vkGetPhysicalDeviceFragmentShadingRatesKHR                        vkGetPhysicalDeviceFragmentShadingRatesKHR;
extern PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR                 vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR;
extern PFN_vkCreateDebugReportCallbackEXT                                    vkCreateDebugReportCallbackEXT;
extern PFN_vkDestroyDebugReportCallbackEXT                                   vkDestroyDebugReportCallbackEXT;
extern PFN_vkDebugReportMessageEXT                                           vkDebugReportMessageEXT;
extern PFN_vkGetPhysicalDeviceExternalImageFormatPropertiesNV                vkGetPhysicalDeviceExternalImageFormatPropertiesNV;
extern PFN_vkReleaseDisplayEXT                                               vkReleaseDisplayEXT;
extern PFN_vkGetPhysicalDeviceSurfaceCapabilities2EXT                        vkGetPhysicalDeviceSurfaceCapabilities2EXT;
extern PFN_vkCreateDebugUtilsMessengerEXT                                    vkCreateDebugUtilsMessengerEXT;
extern PFN_vkDestroyDebugUtilsMessengerEXT                                   vkDestroyDebugUtilsMessengerEXT;
extern PFN_vkSubmitDebugUtilsMessageEXT                                      vkSubmitDebugUtilsMessageEXT;
extern PFN_vkGetPhysicalDeviceMultisamplePropertiesEXT                       vkGetPhysicalDeviceMultisamplePropertiesEXT;
extern PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT                    vkGetPhysicalDeviceCalibrateableTimeDomainsEXT;
extern PFN_vkGetPhysicalDeviceToolPropertiesEXT                              vkGetPhysicalDeviceToolPropertiesEXT;
extern PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV                  vkGetPhysicalDeviceCooperativeMatrixPropertiesNV;
extern PFN_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV;
extern PFN_vkCreateHeadlessSurfaceEXT                                        vkCreateHeadlessSurfaceEXT;
extern PFN_vkAcquireDrmDisplayEXT                                            vkAcquireDrmDisplayEXT;
extern PFN_vkGetDrmDisplayEXT                                                vkGetDrmDisplayEXT;
extern PFN_vkGetPhysicalDeviceOpticalFlowImageFormatsNV                      vkGetPhysicalDeviceOpticalFlowImageFormatsNV;

#if defined(VUSYM_SUPPORT_MULTIPLE_VULKAN_DEVICES)
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

	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkDestroyDevice);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetDeviceQueue);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkQueueSubmit);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkQueueWaitIdle);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkDeviceWaitIdle);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkAllocateMemory);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkFreeMemory);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkMapMemory);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkUnmapMemory);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkFlushMappedMemoryRanges);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkInvalidateMappedMemoryRanges);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetDeviceMemoryCommitment);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkBindBufferMemory);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkBindImageMemory);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetBufferMemoryRequirements);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetImageMemoryRequirements);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetImageSparseMemoryRequirements);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkQueueBindSparse);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCreateFence);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkDestroyFence);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkResetFences);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetFenceStatus);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkWaitForFences);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCreateSemaphore);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkDestroySemaphore);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCreateEvent);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkDestroyEvent);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetEventStatus);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkSetEvent);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkResetEvent);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCreateQueryPool);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkDestroyQueryPool);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetQueryPoolResults);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCreateBuffer);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkDestroyBuffer);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCreateBufferView);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkDestroyBufferView);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCreateImage);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkDestroyImage);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetImageSubresourceLayout);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCreateImageView);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkDestroyImageView);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCreateShaderModule);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkDestroyShaderModule);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCreatePipelineCache);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkDestroyPipelineCache);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetPipelineCacheData);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkMergePipelineCaches);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCreateGraphicsPipelines);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCreateComputePipelines);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkDestroyPipeline);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCreatePipelineLayout);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkDestroyPipelineLayout);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCreateSampler);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkDestroySampler);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCreateDescriptorSetLayout);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkDestroyDescriptorSetLayout);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCreateDescriptorPool);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkDestroyDescriptorPool);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkResetDescriptorPool);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkAllocateDescriptorSets);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkFreeDescriptorSets);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkUpdateDescriptorSets);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCreateFramebuffer);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkDestroyFramebuffer);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCreateRenderPass);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkDestroyRenderPass);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetRenderAreaGranularity);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCreateCommandPool);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkDestroyCommandPool);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkResetCommandPool);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkAllocateCommandBuffers);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkFreeCommandBuffers);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkBeginCommandBuffer);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkEndCommandBuffer);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkResetCommandBuffer);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdBindPipeline);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetViewport);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetScissor);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetLineWidth);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetDepthBias);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetBlendConstants);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetDepthBounds);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetStencilCompareMask);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetStencilWriteMask);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetStencilReference);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdBindDescriptorSets);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdBindIndexBuffer);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdBindVertexBuffers);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdDraw);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdDrawIndexed);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdDrawIndirect);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdDrawIndexedIndirect);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdDispatch);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdDispatchIndirect);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdCopyBuffer);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdCopyImage);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdBlitImage);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdCopyBufferToImage);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdCopyImageToBuffer);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdUpdateBuffer);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdFillBuffer);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdClearColorImage);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdClearDepthStencilImage);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdClearAttachments);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdResolveImage);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetEvent);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdResetEvent);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdWaitEvents);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdPipelineBarrier);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdBeginQuery);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdEndQuery);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdResetQueryPool);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdWriteTimestamp);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdCopyQueryPoolResults);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdPushConstants);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdBeginRenderPass);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdNextSubpass);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdEndRenderPass);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdExecuteCommands);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkBindBufferMemory2);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkBindImageMemory2);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetDeviceGroupPeerMemoryFeatures);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetDeviceMask);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdDispatchBase);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetImageMemoryRequirements2);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetBufferMemoryRequirements2);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetImageSparseMemoryRequirements2);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkTrimCommandPool);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetDeviceQueue2);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCreateSamplerYcbcrConversion);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkDestroySamplerYcbcrConversion);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCreateDescriptorUpdateTemplate);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkDestroyDescriptorUpdateTemplate);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkUpdateDescriptorSetWithTemplate);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetDescriptorSetLayoutSupport);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdDrawIndirectCount);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdDrawIndexedIndirectCount);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCreateRenderPass2);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdBeginRenderPass2);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdNextSubpass2);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdEndRenderPass2);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkResetQueryPool);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetSemaphoreCounterValue);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkWaitSemaphores);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkSignalSemaphore);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetBufferDeviceAddress);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetBufferOpaqueCaptureAddress);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetDeviceMemoryOpaqueCaptureAddress);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCreatePrivateDataSlot);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkDestroyPrivateDataSlot);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkSetPrivateData);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetPrivateData);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetEvent2);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdResetEvent2);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdWaitEvents2);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdPipelineBarrier2);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdWriteTimestamp2);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkQueueSubmit2);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdCopyBuffer2);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdCopyImage2);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdCopyBufferToImage2);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdCopyImageToBuffer2);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdBlitImage2);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdResolveImage2);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdBeginRendering);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdEndRendering);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetCullMode);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetFrontFace);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetPrimitiveTopology);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetViewportWithCount);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetScissorWithCount);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdBindVertexBuffers2);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetDepthTestEnable);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetDepthWriteEnable);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetDepthCompareOp);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetDepthBoundsTestEnable);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetStencilTestEnable);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetStencilOp);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetRasterizerDiscardEnable);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetDepthBiasEnable);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetPrimitiveRestartEnable);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetDeviceBufferMemoryRequirements);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetDeviceImageMemoryRequirements);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetDeviceImageSparseMemoryRequirements);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCreateSwapchainKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkDestroySwapchainKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetSwapchainImagesKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkAcquireNextImageKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkQueuePresentKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetDeviceGroupPresentCapabilitiesKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetDeviceGroupSurfacePresentModesKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkAcquireNextImage2KHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCreateSharedSwapchainsKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCreateVideoSessionKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkDestroyVideoSessionKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetVideoSessionMemoryRequirementsKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkBindVideoSessionMemoryKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCreateVideoSessionParametersKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkUpdateVideoSessionParametersKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkDestroyVideoSessionParametersKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdBeginVideoCodingKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdEndVideoCodingKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdControlVideoCodingKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdDecodeVideoKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdBeginRenderingKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdEndRenderingKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetDeviceGroupPeerMemoryFeaturesKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetDeviceMaskKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdDispatchBaseKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkTrimCommandPoolKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetMemoryFdKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetMemoryFdPropertiesKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkImportSemaphoreFdKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetSemaphoreFdKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdPushDescriptorSetKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdPushDescriptorSetWithTemplateKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCreateDescriptorUpdateTemplateKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkDestroyDescriptorUpdateTemplateKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkUpdateDescriptorSetWithTemplateKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCreateRenderPass2KHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdBeginRenderPass2KHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdNextSubpass2KHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdEndRenderPass2KHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetSwapchainStatusKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkImportFenceFdKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetFenceFdKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkAcquireProfilingLockKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkReleaseProfilingLockKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetImageMemoryRequirements2KHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetBufferMemoryRequirements2KHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetImageSparseMemoryRequirements2KHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCreateSamplerYcbcrConversionKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkDestroySamplerYcbcrConversionKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkBindBufferMemory2KHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkBindImageMemory2KHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetDescriptorSetLayoutSupportKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdDrawIndirectCountKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdDrawIndexedIndirectCountKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetSemaphoreCounterValueKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkWaitSemaphoresKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkSignalSemaphoreKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetFragmentShadingRateKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkWaitForPresentKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetBufferDeviceAddressKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetBufferOpaqueCaptureAddressKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetDeviceMemoryOpaqueCaptureAddressKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCreateDeferredOperationKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkDestroyDeferredOperationKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetDeferredOperationMaxConcurrencyKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetDeferredOperationResultKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkDeferredOperationJoinKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetPipelineExecutablePropertiesKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetPipelineExecutableStatisticsKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetPipelineExecutableInternalRepresentationsKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkMapMemory2KHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkUnmapMemory2KHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetEvent2KHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdResetEvent2KHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdWaitEvents2KHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdPipelineBarrier2KHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdWriteTimestamp2KHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkQueueSubmit2KHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdWriteBufferMarker2AMD);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetQueueCheckpointData2NV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdCopyBuffer2KHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdCopyImage2KHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdCopyBufferToImage2KHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdCopyImageToBuffer2KHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdBlitImage2KHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdResolveImage2KHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdTraceRaysIndirect2KHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetDeviceBufferMemoryRequirementsKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetDeviceImageMemoryRequirementsKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetDeviceImageSparseMemoryRequirementsKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkDebugMarkerSetObjectTagEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkDebugMarkerSetObjectNameEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdDebugMarkerBeginEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdDebugMarkerEndEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdDebugMarkerInsertEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdBindTransformFeedbackBuffersEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdBeginTransformFeedbackEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdEndTransformFeedbackEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdBeginQueryIndexedEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdEndQueryIndexedEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdDrawIndirectByteCountEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCreateCuModuleNVX);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCreateCuFunctionNVX);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkDestroyCuModuleNVX);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkDestroyCuFunctionNVX);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdCuLaunchKernelNVX);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetImageViewHandleNVX);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetImageViewAddressNVX);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdDrawIndirectCountAMD);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdDrawIndexedIndirectCountAMD);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetShaderInfoAMD);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdBeginConditionalRenderingEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdEndConditionalRenderingEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetViewportWScalingNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkDisplayPowerControlEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkRegisterDeviceEventEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkRegisterDisplayEventEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetSwapchainCounterEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetRefreshCycleDurationGOOGLE);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetPastPresentationTimingGOOGLE);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetDiscardRectangleEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetDiscardRectangleEnableEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetDiscardRectangleModeEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkSetHdrMetadataEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkSetDebugUtilsObjectNameEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkSetDebugUtilsObjectTagEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkQueueBeginDebugUtilsLabelEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkQueueEndDebugUtilsLabelEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkQueueInsertDebugUtilsLabelEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdBeginDebugUtilsLabelEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdEndDebugUtilsLabelEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdInsertDebugUtilsLabelEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetSampleLocationsEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetImageDrmFormatModifierPropertiesEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCreateValidationCacheEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkDestroyValidationCacheEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkMergeValidationCachesEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetValidationCacheDataEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdBindShadingRateImageNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetViewportShadingRatePaletteNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetCoarseSampleOrderNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCreateAccelerationStructureNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkDestroyAccelerationStructureNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetAccelerationStructureMemoryRequirementsNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkBindAccelerationStructureMemoryNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdBuildAccelerationStructureNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdCopyAccelerationStructureNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdTraceRaysNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCreateRayTracingPipelinesNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetRayTracingShaderGroupHandlesKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetRayTracingShaderGroupHandlesNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetAccelerationStructureHandleNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdWriteAccelerationStructuresPropertiesNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCompileDeferredNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetMemoryHostPointerPropertiesEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdWriteBufferMarkerAMD);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetCalibratedTimestampsEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdDrawMeshTasksNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdDrawMeshTasksIndirectNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdDrawMeshTasksIndirectCountNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetExclusiveScissorEnableNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetExclusiveScissorNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetCheckpointNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetQueueCheckpointDataNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkInitializePerformanceApiINTEL);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkUninitializePerformanceApiINTEL);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetPerformanceMarkerINTEL);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetPerformanceStreamMarkerINTEL);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetPerformanceOverrideINTEL);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkAcquirePerformanceConfigurationINTEL);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkReleasePerformanceConfigurationINTEL);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkQueueSetPerformanceConfigurationINTEL);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetPerformanceParameterINTEL);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkSetLocalDimmingAMD);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetBufferDeviceAddressEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetLineStippleEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkResetQueryPoolEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetCullModeEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetFrontFaceEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetPrimitiveTopologyEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetViewportWithCountEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetScissorWithCountEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdBindVertexBuffers2EXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetDepthTestEnableEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetDepthWriteEnableEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetDepthCompareOpEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetDepthBoundsTestEnableEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetStencilTestEnableEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetStencilOpEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkReleaseSwapchainImagesEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetGeneratedCommandsMemoryRequirementsNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdPreprocessGeneratedCommandsNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdExecuteGeneratedCommandsNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdBindPipelineShaderGroupNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCreateIndirectCommandsLayoutNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkDestroyIndirectCommandsLayoutNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetDepthBias2EXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCreatePrivateDataSlotEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkDestroyPrivateDataSlotEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkSetPrivateDataEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetPrivateDataEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetDescriptorSetLayoutSizeEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetDescriptorSetLayoutBindingOffsetEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetDescriptorEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdBindDescriptorBuffersEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetDescriptorBufferOffsetsEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdBindDescriptorBufferEmbeddedSamplersEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetBufferOpaqueCaptureDescriptorDataEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetImageOpaqueCaptureDescriptorDataEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetImageViewOpaqueCaptureDescriptorDataEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetSamplerOpaqueCaptureDescriptorDataEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetFragmentShadingRateEnumNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetImageSubresourceLayout2EXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetDeviceFaultInfoEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetVertexInputEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSubpassShadingHUAWEI);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdBindInvocationMaskHUAWEI);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetMemoryRemoteAddressNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetPipelinePropertiesEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetPatchControlPointsEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetRasterizerDiscardEnableEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetDepthBiasEnableEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetLogicOpEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetPrimitiveRestartEnableEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetColorWriteEnableEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdDrawMultiEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdDrawMultiIndexedEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCreateMicromapEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkDestroyMicromapEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdBuildMicromapsEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkBuildMicromapsEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCopyMicromapEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCopyMicromapToMemoryEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCopyMemoryToMicromapEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkWriteMicromapsPropertiesEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdCopyMicromapEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdCopyMicromapToMemoryEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdCopyMemoryToMicromapEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdWriteMicromapsPropertiesEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetDeviceMicromapCompatibilityEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetMicromapBuildSizesEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdDrawClusterHUAWEI);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdDrawClusterIndirectHUAWEI);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkSetDeviceMemoryPriorityEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetDescriptorSetLayoutHostMappingInfoVALVE);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetDescriptorSetHostMappingVALVE);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdCopyMemoryIndirectNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdCopyMemoryToImageIndirectNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdDecompressMemoryNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdDecompressMemoryIndirectCountNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetTessellationDomainOriginEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetDepthClampEnableEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetPolygonModeEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetRasterizationSamplesEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetSampleMaskEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetAlphaToCoverageEnableEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetAlphaToOneEnableEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetLogicOpEnableEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetColorBlendEnableEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetColorBlendEquationEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetColorWriteMaskEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetRasterizationStreamEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetConservativeRasterizationModeEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetExtraPrimitiveOverestimationSizeEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetDepthClipEnableEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetSampleLocationsEnableEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetColorBlendAdvancedEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetProvokingVertexModeEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetLineRasterizationModeEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetLineStippleEnableEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetDepthClipNegativeOneToOneEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetViewportWScalingEnableNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetViewportSwizzleNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetCoverageToColorEnableNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetCoverageToColorLocationNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetCoverageModulationModeNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetCoverageModulationTableEnableNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetCoverageModulationTableNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetShadingRateImageEnableNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetRepresentativeFragmentTestEnableNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetCoverageReductionModeNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetShaderModuleIdentifierEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetShaderModuleCreateInfoIdentifierEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCreateOpticalFlowSessionNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkDestroyOpticalFlowSessionNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkBindOpticalFlowSessionImageNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdOpticalFlowExecuteNV);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCreateShadersEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkDestroyShaderEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetShaderBinaryDataEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdBindShadersEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetFramebufferTilePropertiesQCOM);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetDynamicRenderingTilePropertiesQCOM);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetAttachmentFeedbackLoopEnableEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCreateAccelerationStructureKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkDestroyAccelerationStructureKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdBuildAccelerationStructuresKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdBuildAccelerationStructuresIndirectKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkBuildAccelerationStructuresKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCopyAccelerationStructureKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCopyAccelerationStructureToMemoryKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCopyMemoryToAccelerationStructureKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkWriteAccelerationStructuresPropertiesKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdCopyAccelerationStructureKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdCopyAccelerationStructureToMemoryKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdCopyMemoryToAccelerationStructureKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetAccelerationStructureDeviceAddressKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdWriteAccelerationStructuresPropertiesKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetDeviceAccelerationStructureCompatibilityKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetAccelerationStructureBuildSizesKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdTraceRaysKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCreateRayTracingPipelinesKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetRayTracingCaptureReplayShaderGroupHandlesKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdTraceRaysIndirectKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkGetRayTracingShaderGroupStackSizeKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdSetRayTracingPipelineStackSizeKHR);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdDrawMeshTasksEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdDrawMeshTasksIndirectEXT);
	VUSYM_DECLARE_VULKAN_SYMBOL_EXTERN_OR_NOT(vkCmdDrawMeshTasksIndirectCountEXT);

#ifdef VUSYM_SUPPORT_MULTIPLE_VULKAN_DEVICES
};
#endif

VkResult VKAPI_CALL vkCreateInstance(const VkInstanceCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkInstance *pInstance);
VkResult VKAPI_CALL vkCreateDevice(VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkDevice *pDevice);
VkResult VKAPI_CALL vkEnumerateInstanceExtensionProperties(const char *pLayerName, uint32_t *pPropertyCount, VkExtensionProperties *pProperties);
VkResult VKAPI_CALL vkEnumerateInstanceLayerProperties(uint32_t *pPropertyCount, VkLayerProperties *pProperties);
VkResult VKAPI_CALL vkEnumerateInstanceVersion(uint32_t *pApiVersion);
#if defined(VUSYM_SUPPORT_MULTIPLE_VULKAN_DEVICES)
void VKAPI_CALL            vkDestroyDevice(VkDevice device, const VkAllocationCallbacks *pAllocator);
void VKAPI_CALL            vkGetDeviceQueue(VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue *pQueue);
VkResult VKAPI_CALL        vkDeviceWaitIdle(VkDevice device);
VkResult VKAPI_CALL        vkAllocateMemory(VkDevice device, const VkMemoryAllocateInfo *pAllocateInfo, const VkAllocationCallbacks *pAllocator, VkDeviceMemory *pMemory);
void VKAPI_CALL            vkFreeMemory(VkDevice device, VkDeviceMemory memory, const VkAllocationCallbacks *pAllocator);
VkResult VKAPI_CALL        vkMapMemory(VkDevice device, VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void **ppData);
void VKAPI_CALL            vkUnmapMemory(VkDevice device, VkDeviceMemory memory);
VkResult VKAPI_CALL        vkFlushMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange *pMemoryRanges);
VkResult VKAPI_CALL        vkInvalidateMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange *pMemoryRanges);
void VKAPI_CALL            vkGetDeviceMemoryCommitment(VkDevice device, VkDeviceMemory memory, VkDeviceSize *pCommittedMemoryInBytes);
VkResult VKAPI_CALL        vkBindBufferMemory(VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset);
VkResult VKAPI_CALL        vkBindImageMemory(VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset);
void VKAPI_CALL            vkGetBufferMemoryRequirements(VkDevice device, VkBuffer buffer, VkMemoryRequirements *pMemoryRequirements);
void VKAPI_CALL            vkGetImageMemoryRequirements(VkDevice device, VkImage image, VkMemoryRequirements *pMemoryRequirements);
void VKAPI_CALL            vkGetImageSparseMemoryRequirements(VkDevice device, VkImage image, uint32_t *pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements *pSparseMemoryRequirements);
VkResult VKAPI_CALL        vkCreateFence(VkDevice device, const VkFenceCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkFence *pFence);
void VKAPI_CALL            vkDestroyFence(VkDevice device, VkFence fence, const VkAllocationCallbacks *pAllocator);
VkResult VKAPI_CALL        vkResetFences(VkDevice device, uint32_t fenceCount, const VkFence *pFences);
VkResult VKAPI_CALL        vkGetFenceStatus(VkDevice device, VkFence fence);
VkResult VKAPI_CALL        vkWaitForFences(VkDevice device, uint32_t fenceCount, const VkFence *pFences, VkBool32 waitAll, uint64_t timeout);
VkResult VKAPI_CALL        vkCreateSemaphore(VkDevice device, const VkSemaphoreCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkSemaphore *pSemaphore);
void VKAPI_CALL            vkDestroySemaphore(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks *pAllocator);
VkResult VKAPI_CALL        vkCreateEvent(VkDevice device, const VkEventCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkEvent *pEvent);
void VKAPI_CALL            vkDestroyEvent(VkDevice device, VkEvent event, const VkAllocationCallbacks *pAllocator);
VkResult VKAPI_CALL        vkGetEventStatus(VkDevice device, VkEvent event);
VkResult VKAPI_CALL        vkSetEvent(VkDevice device, VkEvent event);
VkResult VKAPI_CALL        vkResetEvent(VkDevice device, VkEvent event);
VkResult VKAPI_CALL        vkCreateQueryPool(VkDevice device, const VkQueryPoolCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkQueryPool *pQueryPool);
void VKAPI_CALL            vkDestroyQueryPool(VkDevice device, VkQueryPool queryPool, const VkAllocationCallbacks *pAllocator);
VkResult VKAPI_CALL        vkGetQueryPoolResults(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, size_t dataSize, void *pData, VkDeviceSize stride, VkQueryResultFlags flags);
VkResult VKAPI_CALL        vkCreateBuffer(VkDevice device, const VkBufferCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkBuffer *pBuffer);
void VKAPI_CALL            vkDestroyBuffer(VkDevice device, VkBuffer buffer, const VkAllocationCallbacks *pAllocator);
VkResult VKAPI_CALL        vkCreateBufferView(VkDevice device, const VkBufferViewCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkBufferView *pView);
void VKAPI_CALL            vkDestroyBufferView(VkDevice device, VkBufferView bufferView, const VkAllocationCallbacks *pAllocator);
VkResult VKAPI_CALL        vkCreateImage(VkDevice device, const VkImageCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkImage *pImage);
void VKAPI_CALL            vkDestroyImage(VkDevice device, VkImage image, const VkAllocationCallbacks *pAllocator);
void VKAPI_CALL            vkGetImageSubresourceLayout(VkDevice device, VkImage image, const VkImageSubresource *pSubresource, VkSubresourceLayout *pLayout);
VkResult VKAPI_CALL        vkCreateImageView(VkDevice device, const VkImageViewCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkImageView *pView);
void VKAPI_CALL            vkDestroyImageView(VkDevice device, VkImageView imageView, const VkAllocationCallbacks *pAllocator);
VkResult VKAPI_CALL        vkCreateShaderModule(VkDevice device, const VkShaderModuleCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkShaderModule *pShaderModule);
void VKAPI_CALL            vkDestroyShaderModule(VkDevice device, VkShaderModule shaderModule, const VkAllocationCallbacks *pAllocator);
VkResult VKAPI_CALL        vkCreatePipelineCache(VkDevice device, const VkPipelineCacheCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkPipelineCache *pPipelineCache);
void VKAPI_CALL            vkDestroyPipelineCache(VkDevice device, VkPipelineCache pipelineCache, const VkAllocationCallbacks *pAllocator);
VkResult VKAPI_CALL        vkGetPipelineCacheData(VkDevice device, VkPipelineCache pipelineCache, size_t *pDataSize, void *pData);
VkResult VKAPI_CALL        vkMergePipelineCaches(VkDevice device, VkPipelineCache dstCache, uint32_t srcCacheCount, const VkPipelineCache *pSrcCaches);
VkResult VKAPI_CALL        vkCreateGraphicsPipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkGraphicsPipelineCreateInfo *pCreateInfos, const VkAllocationCallbacks *pAllocator, VkPipeline *pPipelines);
VkResult VKAPI_CALL        vkCreateComputePipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkComputePipelineCreateInfo *pCreateInfos, const VkAllocationCallbacks *pAllocator, VkPipeline *pPipelines);
void VKAPI_CALL            vkDestroyPipeline(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks *pAllocator);
VkResult VKAPI_CALL        vkCreatePipelineLayout(VkDevice device, const VkPipelineLayoutCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkPipelineLayout *pPipelineLayout);
void VKAPI_CALL            vkDestroyPipelineLayout(VkDevice device, VkPipelineLayout pipelineLayout, const VkAllocationCallbacks *pAllocator);
VkResult VKAPI_CALL        vkCreateSampler(VkDevice device, const VkSamplerCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkSampler *pSampler);
void VKAPI_CALL            vkDestroySampler(VkDevice device, VkSampler sampler, const VkAllocationCallbacks *pAllocator);
VkResult VKAPI_CALL        vkCreateDescriptorSetLayout(VkDevice device, const VkDescriptorSetLayoutCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkDescriptorSetLayout *pSetLayout);
void VKAPI_CALL            vkDestroyDescriptorSetLayout(VkDevice device, VkDescriptorSetLayout descriptorSetLayout, const VkAllocationCallbacks *pAllocator);
VkResult VKAPI_CALL        vkCreateDescriptorPool(VkDevice device, const VkDescriptorPoolCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkDescriptorPool *pDescriptorPool);
void VKAPI_CALL            vkDestroyDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool, const VkAllocationCallbacks *pAllocator);
VkResult VKAPI_CALL        vkResetDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool, VkDescriptorPoolResetFlags flags);
VkResult VKAPI_CALL        vkAllocateDescriptorSets(VkDevice device, const VkDescriptorSetAllocateInfo *pAllocateInfo, VkDescriptorSet *pDescriptorSets);
VkResult VKAPI_CALL        vkFreeDescriptorSets(VkDevice device, VkDescriptorPool descriptorPool, uint32_t descriptorSetCount, const VkDescriptorSet *pDescriptorSets);
void VKAPI_CALL            vkUpdateDescriptorSets(VkDevice device, uint32_t descriptorWriteCount, const VkWriteDescriptorSet *pDescriptorWrites, uint32_t descriptorCopyCount, const VkCopyDescriptorSet *pDescriptorCopies);
VkResult VKAPI_CALL        vkCreateFramebuffer(VkDevice device, const VkFramebufferCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkFramebuffer *pFramebuffer);
void VKAPI_CALL            vkDestroyFramebuffer(VkDevice device, VkFramebuffer framebuffer, const VkAllocationCallbacks *pAllocator);
VkResult VKAPI_CALL        vkCreateRenderPass(VkDevice device, const VkRenderPassCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkRenderPass *pRenderPass);
void VKAPI_CALL            vkDestroyRenderPass(VkDevice device, VkRenderPass renderPass, const VkAllocationCallbacks *pAllocator);
void VKAPI_CALL            vkGetRenderAreaGranularity(VkDevice device, VkRenderPass renderPass, VkExtent2D *pGranularity);
VkResult VKAPI_CALL        vkCreateCommandPool(VkDevice device, const VkCommandPoolCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkCommandPool *pCommandPool);
void VKAPI_CALL            vkDestroyCommandPool(VkDevice device, VkCommandPool commandPool, const VkAllocationCallbacks *pAllocator);
VkResult VKAPI_CALL        vkResetCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags);
VkResult VKAPI_CALL        vkAllocateCommandBuffers(VkDevice device, const VkCommandBufferAllocateInfo *pAllocateInfo, VkCommandBuffer *pCommandBuffers);
void VKAPI_CALL            vkFreeCommandBuffers(VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount, const VkCommandBuffer *pCommandBuffers);
VkResult VKAPI_CALL        vkBindBufferMemory2(VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo *pBindInfos);
VkResult VKAPI_CALL        vkBindImageMemory2(VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo *pBindInfos);
void VKAPI_CALL            vkGetDeviceGroupPeerMemoryFeatures(VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags *pPeerMemoryFeatures);
void VKAPI_CALL            vkGetImageMemoryRequirements2(VkDevice device, const VkImageMemoryRequirementsInfo2 *pInfo, VkMemoryRequirements2 *pMemoryRequirements);
void VKAPI_CALL            vkGetBufferMemoryRequirements2(VkDevice device, const VkBufferMemoryRequirementsInfo2 *pInfo, VkMemoryRequirements2 *pMemoryRequirements);
void VKAPI_CALL            vkGetImageSparseMemoryRequirements2(VkDevice device, const VkImageSparseMemoryRequirementsInfo2 *pInfo, uint32_t *pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2 *pSparseMemoryRequirements);
void VKAPI_CALL            vkTrimCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags);
void VKAPI_CALL            vkGetDeviceQueue2(VkDevice device, const VkDeviceQueueInfo2 *pQueueInfo, VkQueue *pQueue);
VkResult VKAPI_CALL        vkCreateSamplerYcbcrConversion(VkDevice device, const VkSamplerYcbcrConversionCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkSamplerYcbcrConversion *pYcbcrConversion);
void VKAPI_CALL            vkDestroySamplerYcbcrConversion(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks *pAllocator);
VkResult VKAPI_CALL        vkCreateDescriptorUpdateTemplate(VkDevice device, const VkDescriptorUpdateTemplateCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkDescriptorUpdateTemplate *pDescriptorUpdateTemplate);
void VKAPI_CALL            vkDestroyDescriptorUpdateTemplate(VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks *pAllocator);
void VKAPI_CALL            vkUpdateDescriptorSetWithTemplate(VkDevice device, VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void *pData);
void VKAPI_CALL            vkGetDescriptorSetLayoutSupport(VkDevice device, const VkDescriptorSetLayoutCreateInfo *pCreateInfo, VkDescriptorSetLayoutSupport *pSupport);
VkResult VKAPI_CALL        vkCreateRenderPass2(VkDevice device, const VkRenderPassCreateInfo2 *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkRenderPass *pRenderPass);
void VKAPI_CALL            vkResetQueryPool(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount);
VkResult VKAPI_CALL        vkGetSemaphoreCounterValue(VkDevice device, VkSemaphore semaphore, uint64_t *pValue);
VkResult VKAPI_CALL        vkWaitSemaphores(VkDevice device, const VkSemaphoreWaitInfo *pWaitInfo, uint64_t timeout);
VkResult VKAPI_CALL        vkSignalSemaphore(VkDevice device, const VkSemaphoreSignalInfo *pSignalInfo);
VkDeviceAddress VKAPI_CALL vkGetBufferDeviceAddress(VkDevice device, const VkBufferDeviceAddressInfo *pInfo);
uint64_t VKAPI_CALL        vkGetBufferOpaqueCaptureAddress(VkDevice device, const VkBufferDeviceAddressInfo *pInfo);
uint64_t VKAPI_CALL        vkGetDeviceMemoryOpaqueCaptureAddress(VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo *pInfo);
VkResult VKAPI_CALL        vkCreatePrivateDataSlot(VkDevice device, const VkPrivateDataSlotCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkPrivateDataSlot *pPrivateDataSlot);
void VKAPI_CALL            vkDestroyPrivateDataSlot(VkDevice device, VkPrivateDataSlot privateDataSlot, const VkAllocationCallbacks *pAllocator);
VkResult VKAPI_CALL        vkSetPrivateData(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t data);
void VKAPI_CALL            vkGetPrivateData(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t *pData);
void VKAPI_CALL            vkGetDeviceBufferMemoryRequirements(VkDevice device, const VkDeviceBufferMemoryRequirements *pInfo, VkMemoryRequirements2 *pMemoryRequirements);
void VKAPI_CALL            vkGetDeviceImageMemoryRequirements(VkDevice device, const VkDeviceImageMemoryRequirements *pInfo, VkMemoryRequirements2 *pMemoryRequirements);
void VKAPI_CALL            vkGetDeviceImageSparseMemoryRequirements(VkDevice device, const VkDeviceImageMemoryRequirements *pInfo, uint32_t *pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2 *pSparseMemoryRequirements);
VkResult VKAPI_CALL        vkCreateSwapchainKHR(VkDevice device, const VkSwapchainCreateInfoKHR *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkSwapchainKHR *pSwapchain);
void VKAPI_CALL            vkDestroySwapchainKHR(VkDevice device, VkSwapchainKHR swapchain, const VkAllocationCallbacks *pAllocator);
VkResult VKAPI_CALL        vkGetSwapchainImagesKHR(VkDevice device, VkSwapchainKHR swapchain, uint32_t *pSwapchainImageCount, VkImage *pSwapchainImages);
VkResult VKAPI_CALL        vkAcquireNextImageKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore, VkFence fence, uint32_t *pImageIndex);
VkResult VKAPI_CALL        vkGetDeviceGroupPresentCapabilitiesKHR(VkDevice device, VkDeviceGroupPresentCapabilitiesKHR *pDeviceGroupPresentCapabilities);
VkResult VKAPI_CALL        vkGetDeviceGroupSurfacePresentModesKHR(VkDevice device, VkSurfaceKHR surface, VkDeviceGroupPresentModeFlagsKHR *pModes);
VkResult VKAPI_CALL        vkAcquireNextImage2KHR(VkDevice device, const VkAcquireNextImageInfoKHR *pAcquireInfo, uint32_t *pImageIndex);
VkResult VKAPI_CALL        vkCreateSharedSwapchainsKHR(VkDevice device, uint32_t swapchainCount, const VkSwapchainCreateInfoKHR *pCreateInfos, const VkAllocationCallbacks *pAllocator, VkSwapchainKHR *pSwapchains);
VkResult VKAPI_CALL        vkCreateVideoSessionKHR(VkDevice device, const VkVideoSessionCreateInfoKHR *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkVideoSessionKHR *pVideoSession);
void VKAPI_CALL            vkDestroyVideoSessionKHR(VkDevice device, VkVideoSessionKHR videoSession, const VkAllocationCallbacks *pAllocator);
VkResult VKAPI_CALL        vkGetVideoSessionMemoryRequirementsKHR(VkDevice device, VkVideoSessionKHR videoSession, uint32_t *pMemoryRequirementsCount, VkVideoSessionMemoryRequirementsKHR *pMemoryRequirements);
VkResult VKAPI_CALL        vkBindVideoSessionMemoryKHR(VkDevice device, VkVideoSessionKHR videoSession, uint32_t bindSessionMemoryInfoCount, const VkBindVideoSessionMemoryInfoKHR *pBindSessionMemoryInfos);
VkResult VKAPI_CALL        vkCreateVideoSessionParametersKHR(VkDevice device, const VkVideoSessionParametersCreateInfoKHR *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkVideoSessionParametersKHR *pVideoSessionParameters);
VkResult VKAPI_CALL        vkUpdateVideoSessionParametersKHR(VkDevice device, VkVideoSessionParametersKHR videoSessionParameters, const VkVideoSessionParametersUpdateInfoKHR *pUpdateInfo);
void VKAPI_CALL            vkDestroyVideoSessionParametersKHR(VkDevice device, VkVideoSessionParametersKHR videoSessionParameters, const VkAllocationCallbacks *pAllocator);
void VKAPI_CALL            vkGetDeviceGroupPeerMemoryFeaturesKHR(VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags *pPeerMemoryFeatures);
void VKAPI_CALL            vkTrimCommandPoolKHR(VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags);
VkResult VKAPI_CALL        vkGetMemoryFdKHR(VkDevice device, const VkMemoryGetFdInfoKHR *pGetFdInfo, int *pFd);
VkResult VKAPI_CALL        vkGetMemoryFdPropertiesKHR(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, int fd, VkMemoryFdPropertiesKHR *pMemoryFdProperties);
VkResult VKAPI_CALL        vkImportSemaphoreFdKHR(VkDevice device, const VkImportSemaphoreFdInfoKHR *pImportSemaphoreFdInfo);
VkResult VKAPI_CALL        vkGetSemaphoreFdKHR(VkDevice device, const VkSemaphoreGetFdInfoKHR *pGetFdInfo, int *pFd);
VkResult VKAPI_CALL        vkCreateDescriptorUpdateTemplateKHR(VkDevice device, const VkDescriptorUpdateTemplateCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkDescriptorUpdateTemplate *pDescriptorUpdateTemplate);
void VKAPI_CALL            vkDestroyDescriptorUpdateTemplateKHR(VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks *pAllocator);
void VKAPI_CALL            vkUpdateDescriptorSetWithTemplateKHR(VkDevice device, VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void *pData);
VkResult VKAPI_CALL        vkCreateRenderPass2KHR(VkDevice device, const VkRenderPassCreateInfo2 *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkRenderPass *pRenderPass);
VkResult VKAPI_CALL        vkGetSwapchainStatusKHR(VkDevice device, VkSwapchainKHR swapchain);
VkResult VKAPI_CALL        vkImportFenceFdKHR(VkDevice device, const VkImportFenceFdInfoKHR *pImportFenceFdInfo);
VkResult VKAPI_CALL        vkGetFenceFdKHR(VkDevice device, const VkFenceGetFdInfoKHR *pGetFdInfo, int *pFd);
VkResult VKAPI_CALL        vkAcquireProfilingLockKHR(VkDevice device, const VkAcquireProfilingLockInfoKHR *pInfo);
void VKAPI_CALL            vkReleaseProfilingLockKHR(VkDevice device);
void VKAPI_CALL            vkGetImageMemoryRequirements2KHR(VkDevice device, const VkImageMemoryRequirementsInfo2 *pInfo, VkMemoryRequirements2 *pMemoryRequirements);
void VKAPI_CALL            vkGetBufferMemoryRequirements2KHR(VkDevice device, const VkBufferMemoryRequirementsInfo2 *pInfo, VkMemoryRequirements2 *pMemoryRequirements);
void VKAPI_CALL            vkGetImageSparseMemoryRequirements2KHR(VkDevice device, const VkImageSparseMemoryRequirementsInfo2 *pInfo, uint32_t *pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2 *pSparseMemoryRequirements);
VkResult VKAPI_CALL        vkCreateSamplerYcbcrConversionKHR(VkDevice device, const VkSamplerYcbcrConversionCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkSamplerYcbcrConversion *pYcbcrConversion);
void VKAPI_CALL            vkDestroySamplerYcbcrConversionKHR(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks *pAllocator);
VkResult VKAPI_CALL        vkBindBufferMemory2KHR(VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo *pBindInfos);
VkResult VKAPI_CALL        vkBindImageMemory2KHR(VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo *pBindInfos);
void VKAPI_CALL            vkGetDescriptorSetLayoutSupportKHR(VkDevice device, const VkDescriptorSetLayoutCreateInfo *pCreateInfo, VkDescriptorSetLayoutSupport *pSupport);
VkResult VKAPI_CALL        vkGetSemaphoreCounterValueKHR(VkDevice device, VkSemaphore semaphore, uint64_t *pValue);
VkResult VKAPI_CALL        vkWaitSemaphoresKHR(VkDevice device, const VkSemaphoreWaitInfo *pWaitInfo, uint64_t timeout);
VkResult VKAPI_CALL        vkSignalSemaphoreKHR(VkDevice device, const VkSemaphoreSignalInfo *pSignalInfo);
VkResult VKAPI_CALL        vkWaitForPresentKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t presentId, uint64_t timeout);
VkDeviceAddress VKAPI_CALL vkGetBufferDeviceAddressKHR(VkDevice device, const VkBufferDeviceAddressInfo *pInfo);
uint64_t VKAPI_CALL        vkGetBufferOpaqueCaptureAddressKHR(VkDevice device, const VkBufferDeviceAddressInfo *pInfo);
uint64_t VKAPI_CALL        vkGetDeviceMemoryOpaqueCaptureAddressKHR(VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo *pInfo);
VkResult VKAPI_CALL        vkCreateDeferredOperationKHR(VkDevice device, const VkAllocationCallbacks *pAllocator, VkDeferredOperationKHR *pDeferredOperation);
void VKAPI_CALL            vkDestroyDeferredOperationKHR(VkDevice device, VkDeferredOperationKHR operation, const VkAllocationCallbacks *pAllocator);
uint32_t VKAPI_CALL        vkGetDeferredOperationMaxConcurrencyKHR(VkDevice device, VkDeferredOperationKHR operation);
VkResult VKAPI_CALL        vkGetDeferredOperationResultKHR(VkDevice device, VkDeferredOperationKHR operation);
VkResult VKAPI_CALL        vkDeferredOperationJoinKHR(VkDevice device, VkDeferredOperationKHR operation);
VkResult VKAPI_CALL        vkGetPipelineExecutablePropertiesKHR(VkDevice device, const VkPipelineInfoKHR *pPipelineInfo, uint32_t *pExecutableCount, VkPipelineExecutablePropertiesKHR *pProperties);
VkResult VKAPI_CALL        vkGetPipelineExecutableStatisticsKHR(VkDevice device, const VkPipelineExecutableInfoKHR *pExecutableInfo, uint32_t *pStatisticCount, VkPipelineExecutableStatisticKHR *pStatistics);
VkResult VKAPI_CALL        vkGetPipelineExecutableInternalRepresentationsKHR(VkDevice device, const VkPipelineExecutableInfoKHR *pExecutableInfo, uint32_t *pInternalRepresentationCount, VkPipelineExecutableInternalRepresentationKHR *pInternalRepresentations);
VkResult VKAPI_CALL        vkMapMemory2KHR(VkDevice device, const VkMemoryMapInfoKHR *pMemoryMapInfo, void **ppData);
VkResult VKAPI_CALL        vkUnmapMemory2KHR(VkDevice device, const VkMemoryUnmapInfoKHR *pMemoryUnmapInfo);
void VKAPI_CALL            vkGetDeviceBufferMemoryRequirementsKHR(VkDevice device, const VkDeviceBufferMemoryRequirements *pInfo, VkMemoryRequirements2 *pMemoryRequirements);
void VKAPI_CALL            vkGetDeviceImageMemoryRequirementsKHR(VkDevice device, const VkDeviceImageMemoryRequirements *pInfo, VkMemoryRequirements2 *pMemoryRequirements);
void VKAPI_CALL            vkGetDeviceImageSparseMemoryRequirementsKHR(VkDevice device, const VkDeviceImageMemoryRequirements *pInfo, uint32_t *pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2 *pSparseMemoryRequirements);
VkResult VKAPI_CALL        vkDebugMarkerSetObjectTagEXT(VkDevice device, const VkDebugMarkerObjectTagInfoEXT *pTagInfo);
VkResult VKAPI_CALL        vkDebugMarkerSetObjectNameEXT(VkDevice device, const VkDebugMarkerObjectNameInfoEXT *pNameInfo);
VkResult VKAPI_CALL        vkCreateCuModuleNVX(VkDevice device, const VkCuModuleCreateInfoNVX *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkCuModuleNVX *pModule);
VkResult VKAPI_CALL        vkCreateCuFunctionNVX(VkDevice device, const VkCuFunctionCreateInfoNVX *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkCuFunctionNVX *pFunction);
void VKAPI_CALL            vkDestroyCuModuleNVX(VkDevice device, VkCuModuleNVX module, const VkAllocationCallbacks *pAllocator);
void VKAPI_CALL            vkDestroyCuFunctionNVX(VkDevice device, VkCuFunctionNVX function, const VkAllocationCallbacks *pAllocator);
uint32_t VKAPI_CALL        vkGetImageViewHandleNVX(VkDevice device, const VkImageViewHandleInfoNVX *pInfo);
VkResult VKAPI_CALL        vkGetImageViewAddressNVX(VkDevice device, VkImageView imageView, VkImageViewAddressPropertiesNVX *pProperties);
VkResult VKAPI_CALL        vkGetShaderInfoAMD(VkDevice device, VkPipeline pipeline, VkShaderStageFlagBits shaderStage, VkShaderInfoTypeAMD infoType, size_t *pInfoSize, void *pInfo);
VkResult VKAPI_CALL        vkDisplayPowerControlEXT(VkDevice device, VkDisplayKHR display, const VkDisplayPowerInfoEXT *pDisplayPowerInfo);
VkResult VKAPI_CALL        vkRegisterDeviceEventEXT(VkDevice device, const VkDeviceEventInfoEXT *pDeviceEventInfo, const VkAllocationCallbacks *pAllocator, VkFence *pFence);
VkResult VKAPI_CALL        vkRegisterDisplayEventEXT(VkDevice device, VkDisplayKHR display, const VkDisplayEventInfoEXT *pDisplayEventInfo, const VkAllocationCallbacks *pAllocator, VkFence *pFence);
VkResult VKAPI_CALL        vkGetSwapchainCounterEXT(VkDevice device, VkSwapchainKHR swapchain, VkSurfaceCounterFlagBitsEXT counter, uint64_t *pCounterValue);
VkResult VKAPI_CALL        vkGetRefreshCycleDurationGOOGLE(VkDevice device, VkSwapchainKHR swapchain, VkRefreshCycleDurationGOOGLE *pDisplayTimingProperties);
VkResult VKAPI_CALL        vkGetPastPresentationTimingGOOGLE(VkDevice device, VkSwapchainKHR swapchain, uint32_t *pPresentationTimingCount, VkPastPresentationTimingGOOGLE *pPresentationTimings);
void VKAPI_CALL            vkSetHdrMetadataEXT(VkDevice device, uint32_t swapchainCount, const VkSwapchainKHR *pSwapchains, const VkHdrMetadataEXT *pMetadata);
VkResult VKAPI_CALL        vkSetDebugUtilsObjectNameEXT(VkDevice device, const VkDebugUtilsObjectNameInfoEXT *pNameInfo);
VkResult VKAPI_CALL        vkSetDebugUtilsObjectTagEXT(VkDevice device, const VkDebugUtilsObjectTagInfoEXT *pTagInfo);
VkResult VKAPI_CALL        vkGetImageDrmFormatModifierPropertiesEXT(VkDevice device, VkImage image, VkImageDrmFormatModifierPropertiesEXT *pProperties);
VkResult VKAPI_CALL        vkCreateValidationCacheEXT(VkDevice device, const VkValidationCacheCreateInfoEXT *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkValidationCacheEXT *pValidationCache);
void VKAPI_CALL            vkDestroyValidationCacheEXT(VkDevice device, VkValidationCacheEXT validationCache, const VkAllocationCallbacks *pAllocator);
VkResult VKAPI_CALL        vkMergeValidationCachesEXT(VkDevice device, VkValidationCacheEXT dstCache, uint32_t srcCacheCount, const VkValidationCacheEXT *pSrcCaches);
VkResult VKAPI_CALL        vkGetValidationCacheDataEXT(VkDevice device, VkValidationCacheEXT validationCache, size_t *pDataSize, void *pData);
VkResult VKAPI_CALL        vkCreateAccelerationStructureNV(VkDevice device, const VkAccelerationStructureCreateInfoNV *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkAccelerationStructureNV *pAccelerationStructure);
void VKAPI_CALL            vkDestroyAccelerationStructureNV(VkDevice device, VkAccelerationStructureNV accelerationStructure, const VkAllocationCallbacks *pAllocator);
void VKAPI_CALL            vkGetAccelerationStructureMemoryRequirementsNV(VkDevice device, const VkAccelerationStructureMemoryRequirementsInfoNV *pInfo, VkMemoryRequirements2KHR *pMemoryRequirements);
VkResult VKAPI_CALL        vkBindAccelerationStructureMemoryNV(VkDevice device, uint32_t bindInfoCount, const VkBindAccelerationStructureMemoryInfoNV *pBindInfos);
VkResult VKAPI_CALL        vkCreateRayTracingPipelinesNV(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoNV *pCreateInfos, const VkAllocationCallbacks *pAllocator, VkPipeline *pPipelines);
VkResult VKAPI_CALL        vkGetRayTracingShaderGroupHandlesKHR(VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void *pData);
VkResult VKAPI_CALL        vkGetRayTracingShaderGroupHandlesNV(VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void *pData);
VkResult VKAPI_CALL        vkGetAccelerationStructureHandleNV(VkDevice device, VkAccelerationStructureNV accelerationStructure, size_t dataSize, void *pData);
VkResult VKAPI_CALL        vkCompileDeferredNV(VkDevice device, VkPipeline pipeline, uint32_t shader);
VkResult VKAPI_CALL        vkGetMemoryHostPointerPropertiesEXT(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, const void *pHostPointer, VkMemoryHostPointerPropertiesEXT *pMemoryHostPointerProperties);
VkResult VKAPI_CALL        vkGetCalibratedTimestampsEXT(VkDevice device, uint32_t timestampCount, const VkCalibratedTimestampInfoEXT *pTimestampInfos, uint64_t *pTimestamps, uint64_t *pMaxDeviation);
VkResult VKAPI_CALL        vkInitializePerformanceApiINTEL(VkDevice device, const VkInitializePerformanceApiInfoINTEL *pInitializeInfo);
void VKAPI_CALL            vkUninitializePerformanceApiINTEL(VkDevice device);
VkResult VKAPI_CALL        vkAcquirePerformanceConfigurationINTEL(VkDevice device, const VkPerformanceConfigurationAcquireInfoINTEL *pAcquireInfo, VkPerformanceConfigurationINTEL *pConfiguration);
VkResult VKAPI_CALL        vkReleasePerformanceConfigurationINTEL(VkDevice device, VkPerformanceConfigurationINTEL configuration);
VkResult VKAPI_CALL        vkGetPerformanceParameterINTEL(VkDevice device, VkPerformanceParameterTypeINTEL parameter, VkPerformanceValueINTEL *pValue);
void VKAPI_CALL            vkSetLocalDimmingAMD(VkDevice device, VkSwapchainKHR swapChain, VkBool32 localDimmingEnable);
VkDeviceAddress VKAPI_CALL vkGetBufferDeviceAddressEXT(VkDevice device, const VkBufferDeviceAddressInfo *pInfo);
void VKAPI_CALL            vkResetQueryPoolEXT(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount);
VkResult VKAPI_CALL        vkReleaseSwapchainImagesEXT(VkDevice device, const VkReleaseSwapchainImagesInfoEXT *pReleaseInfo);
void VKAPI_CALL            vkGetGeneratedCommandsMemoryRequirementsNV(VkDevice device, const VkGeneratedCommandsMemoryRequirementsInfoNV *pInfo, VkMemoryRequirements2 *pMemoryRequirements);
VkResult VKAPI_CALL        vkCreateIndirectCommandsLayoutNV(VkDevice device, const VkIndirectCommandsLayoutCreateInfoNV *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkIndirectCommandsLayoutNV *pIndirectCommandsLayout);
void VKAPI_CALL            vkDestroyIndirectCommandsLayoutNV(VkDevice device, VkIndirectCommandsLayoutNV indirectCommandsLayout, const VkAllocationCallbacks *pAllocator);
VkResult VKAPI_CALL        vkCreatePrivateDataSlotEXT(VkDevice device, const VkPrivateDataSlotCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkPrivateDataSlot *pPrivateDataSlot);
void VKAPI_CALL            vkDestroyPrivateDataSlotEXT(VkDevice device, VkPrivateDataSlot privateDataSlot, const VkAllocationCallbacks *pAllocator);
VkResult VKAPI_CALL        vkSetPrivateDataEXT(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t data);
void VKAPI_CALL            vkGetPrivateDataEXT(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t *pData);
void VKAPI_CALL            vkGetDescriptorSetLayoutSizeEXT(VkDevice device, VkDescriptorSetLayout layout, VkDeviceSize *pLayoutSizeInBytes);
void VKAPI_CALL            vkGetDescriptorSetLayoutBindingOffsetEXT(VkDevice device, VkDescriptorSetLayout layout, uint32_t binding, VkDeviceSize *pOffset);
void VKAPI_CALL            vkGetDescriptorEXT(VkDevice device, const VkDescriptorGetInfoEXT *pDescriptorInfo, size_t dataSize, void *pDescriptor);
VkResult VKAPI_CALL        vkGetBufferOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkBufferCaptureDescriptorDataInfoEXT *pInfo, void *pData);
VkResult VKAPI_CALL        vkGetImageOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkImageCaptureDescriptorDataInfoEXT *pInfo, void *pData);
VkResult VKAPI_CALL        vkGetImageViewOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkImageViewCaptureDescriptorDataInfoEXT *pInfo, void *pData);
VkResult VKAPI_CALL        vkGetSamplerOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkSamplerCaptureDescriptorDataInfoEXT *pInfo, void *pData);
VkResult VKAPI_CALL        vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkAccelerationStructureCaptureDescriptorDataInfoEXT *pInfo, void *pData);
void VKAPI_CALL            vkGetImageSubresourceLayout2EXT(VkDevice device, VkImage image, const VkImageSubresource2EXT *pSubresource, VkSubresourceLayout2EXT *pLayout);
VkResult VKAPI_CALL        vkGetDeviceFaultInfoEXT(VkDevice device, VkDeviceFaultCountsEXT *pFaultCounts, VkDeviceFaultInfoEXT *pFaultInfo);
VkResult VKAPI_CALL        vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI(VkDevice device, VkRenderPass renderpass, VkExtent2D *pMaxWorkgroupSize);
VkResult VKAPI_CALL        vkGetMemoryRemoteAddressNV(VkDevice device, const VkMemoryGetRemoteAddressInfoNV *pMemoryGetRemoteAddressInfo, VkRemoteAddressNV *pAddress);
VkResult VKAPI_CALL        vkGetPipelinePropertiesEXT(VkDevice device, const VkPipelineInfoEXT *pPipelineInfo, VkBaseOutStructure *pPipelineProperties);
VkResult VKAPI_CALL        vkCreateMicromapEXT(VkDevice device, const VkMicromapCreateInfoEXT *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkMicromapEXT *pMicromap);
void VKAPI_CALL            vkDestroyMicromapEXT(VkDevice device, VkMicromapEXT micromap, const VkAllocationCallbacks *pAllocator);
VkResult VKAPI_CALL        vkBuildMicromapsEXT(VkDevice device, VkDeferredOperationKHR deferredOperation, uint32_t infoCount, const VkMicromapBuildInfoEXT *pInfos);
VkResult VKAPI_CALL        vkCopyMicromapEXT(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMicromapInfoEXT *pInfo);
VkResult VKAPI_CALL        vkCopyMicromapToMemoryEXT(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMicromapToMemoryInfoEXT *pInfo);
VkResult VKAPI_CALL        vkCopyMemoryToMicromapEXT(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMemoryToMicromapInfoEXT *pInfo);
VkResult VKAPI_CALL        vkWriteMicromapsPropertiesEXT(VkDevice device, uint32_t micromapCount, const VkMicromapEXT *pMicromaps, VkQueryType queryType, size_t dataSize, void *pData, size_t stride);
void VKAPI_CALL            vkGetDeviceMicromapCompatibilityEXT(VkDevice device, const VkMicromapVersionInfoEXT *pVersionInfo, VkAccelerationStructureCompatibilityKHR *pCompatibility);
void VKAPI_CALL            vkGetMicromapBuildSizesEXT(VkDevice device, VkAccelerationStructureBuildTypeKHR buildType, const VkMicromapBuildInfoEXT *pBuildInfo, VkMicromapBuildSizesInfoEXT *pSizeInfo);
void VKAPI_CALL            vkSetDeviceMemoryPriorityEXT(VkDevice device, VkDeviceMemory memory, float priority);
void VKAPI_CALL            vkGetDescriptorSetLayoutHostMappingInfoVALVE(VkDevice device, const VkDescriptorSetBindingReferenceVALVE *pBindingReference, VkDescriptorSetLayoutHostMappingInfoVALVE *pHostMapping);
void VKAPI_CALL            vkGetDescriptorSetHostMappingVALVE(VkDevice device, VkDescriptorSet descriptorSet, void **ppData);
void VKAPI_CALL            vkGetShaderModuleIdentifierEXT(VkDevice device, VkShaderModule shaderModule, VkShaderModuleIdentifierEXT *pIdentifier);
void VKAPI_CALL            vkGetShaderModuleCreateInfoIdentifierEXT(VkDevice device, const VkShaderModuleCreateInfo *pCreateInfo, VkShaderModuleIdentifierEXT *pIdentifier);
VkResult VKAPI_CALL        vkCreateOpticalFlowSessionNV(VkDevice device, const VkOpticalFlowSessionCreateInfoNV *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkOpticalFlowSessionNV *pSession);
void VKAPI_CALL            vkDestroyOpticalFlowSessionNV(VkDevice device, VkOpticalFlowSessionNV session, const VkAllocationCallbacks *pAllocator);
VkResult VKAPI_CALL        vkBindOpticalFlowSessionImageNV(VkDevice device, VkOpticalFlowSessionNV session, VkOpticalFlowSessionBindingPointNV bindingPoint, VkImageView view, VkImageLayout layout);
VkResult VKAPI_CALL        vkCreateShadersEXT(VkDevice device, uint32_t createInfoCount, const VkShaderCreateInfoEXT *pCreateInfos, const VkAllocationCallbacks *pAllocator, VkShaderEXT *pShaders);
void VKAPI_CALL            vkDestroyShaderEXT(VkDevice device, VkShaderEXT shader, const VkAllocationCallbacks *pAllocator);
VkResult VKAPI_CALL        vkGetShaderBinaryDataEXT(VkDevice device, VkShaderEXT shader, size_t *pDataSize, void *pData);
VkResult VKAPI_CALL        vkGetFramebufferTilePropertiesQCOM(VkDevice device, VkFramebuffer framebuffer, uint32_t *pPropertiesCount, VkTilePropertiesQCOM *pProperties);
VkResult VKAPI_CALL        vkGetDynamicRenderingTilePropertiesQCOM(VkDevice device, const VkRenderingInfo *pRenderingInfo, VkTilePropertiesQCOM *pProperties);
VkResult VKAPI_CALL        vkCreateAccelerationStructureKHR(VkDevice device, const VkAccelerationStructureCreateInfoKHR *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkAccelerationStructureKHR *pAccelerationStructure);
void VKAPI_CALL            vkDestroyAccelerationStructureKHR(VkDevice device, VkAccelerationStructureKHR accelerationStructure, const VkAllocationCallbacks *pAllocator);
VkResult VKAPI_CALL        vkBuildAccelerationStructuresKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR *pInfos, const VkAccelerationStructureBuildRangeInfoKHR *const *ppBuildRangeInfos);
VkResult VKAPI_CALL        vkCopyAccelerationStructureKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyAccelerationStructureInfoKHR *pInfo);
VkResult VKAPI_CALL        vkCopyAccelerationStructureToMemoryKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyAccelerationStructureToMemoryInfoKHR *pInfo);
VkResult VKAPI_CALL        vkCopyMemoryToAccelerationStructureKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMemoryToAccelerationStructureInfoKHR *pInfo);
VkResult VKAPI_CALL        vkWriteAccelerationStructuresPropertiesKHR(VkDevice device, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR *pAccelerationStructures, VkQueryType queryType, size_t dataSize, void *pData, size_t stride);
VkDeviceAddress VKAPI_CALL vkGetAccelerationStructureDeviceAddressKHR(VkDevice device, const VkAccelerationStructureDeviceAddressInfoKHR *pInfo);
void VKAPI_CALL            vkGetDeviceAccelerationStructureCompatibilityKHR(VkDevice device, const VkAccelerationStructureVersionInfoKHR *pVersionInfo, VkAccelerationStructureCompatibilityKHR *pCompatibility);
void VKAPI_CALL            vkGetAccelerationStructureBuildSizesKHR(VkDevice device, VkAccelerationStructureBuildTypeKHR buildType, const VkAccelerationStructureBuildGeometryInfoKHR *pBuildInfo, const uint32_t *pMaxPrimitiveCounts, VkAccelerationStructureBuildSizesInfoKHR *pSizeInfo);
VkResult VKAPI_CALL        vkCreateRayTracingPipelinesKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoKHR *pCreateInfos, const VkAllocationCallbacks *pAllocator, VkPipeline *pPipelines);
VkResult VKAPI_CALL        vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void *pData);
VkDeviceSize VKAPI_CALL    vkGetRayTracingShaderGroupStackSizeKHR(VkDevice device, VkPipeline pipeline, uint32_t group, VkShaderGroupShaderKHR groupShader);
#endif
