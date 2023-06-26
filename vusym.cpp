#include "vusym.hpp"

PFN_vkCreateInstance                                                  real_vkCreateInstance                                             = nullptr;
PFN_vkCreateDevice                                                    real_vkCreateDevice                                               = nullptr;
PFN_vkEnumerateInstanceExtensionProperties                            real_vkEnumerateInstanceExtensionProperties                       = nullptr;
PFN_vkEnumerateInstanceLayerProperties                                real_vkEnumerateInstanceLayerProperties                           = nullptr;
PFN_vkEnumerateInstanceVersion                                        real_vkEnumerateInstanceVersion                                   = nullptr;
PFN_vkDestroyInstance                                                 vkDestroyInstance                                                 = nullptr;
PFN_vkEnumeratePhysicalDevices                                        vkEnumeratePhysicalDevices                                        = nullptr;
PFN_vkGetPhysicalDeviceFeatures                                       vkGetPhysicalDeviceFeatures                                       = nullptr;
PFN_vkGetPhysicalDeviceFormatProperties                               vkGetPhysicalDeviceFormatProperties                               = nullptr;
PFN_vkGetPhysicalDeviceImageFormatProperties                          vkGetPhysicalDeviceImageFormatProperties                          = nullptr;
PFN_vkGetPhysicalDeviceProperties                                     vkGetPhysicalDeviceProperties                                     = nullptr;
PFN_vkGetPhysicalDeviceQueueFamilyProperties                          vkGetPhysicalDeviceQueueFamilyProperties                          = nullptr;
PFN_vkGetPhysicalDeviceMemoryProperties                               vkGetPhysicalDeviceMemoryProperties                               = nullptr;
PFN_vkGetInstanceProcAddr                                             vkGetInstanceProcAddr                                             = nullptr;
PFN_vkGetDeviceProcAddr                                               vkGetDeviceProcAddr                                               = nullptr;
PFN_vkEnumerateDeviceExtensionProperties                              vkEnumerateDeviceExtensionProperties                              = nullptr;
PFN_vkEnumerateDeviceLayerProperties                                  vkEnumerateDeviceLayerProperties                                  = nullptr;
PFN_vkGetPhysicalDeviceSparseImageFormatProperties                    vkGetPhysicalDeviceSparseImageFormatProperties                    = nullptr;
PFN_vkEnumeratePhysicalDeviceGroups                                   vkEnumeratePhysicalDeviceGroups                                   = nullptr;
PFN_vkGetPhysicalDeviceFeatures2                                      vkGetPhysicalDeviceFeatures2                                      = nullptr;
PFN_vkGetPhysicalDeviceProperties2                                    vkGetPhysicalDeviceProperties2                                    = nullptr;
PFN_vkGetPhysicalDeviceFormatProperties2                              vkGetPhysicalDeviceFormatProperties2                              = nullptr;
PFN_vkGetPhysicalDeviceImageFormatProperties2                         vkGetPhysicalDeviceImageFormatProperties2                         = nullptr;
PFN_vkGetPhysicalDeviceQueueFamilyProperties2                         vkGetPhysicalDeviceQueueFamilyProperties2                         = nullptr;
PFN_vkGetPhysicalDeviceMemoryProperties2                              vkGetPhysicalDeviceMemoryProperties2                              = nullptr;
PFN_vkGetPhysicalDeviceSparseImageFormatProperties2                   vkGetPhysicalDeviceSparseImageFormatProperties2                   = nullptr;
PFN_vkGetPhysicalDeviceExternalBufferProperties                       vkGetPhysicalDeviceExternalBufferProperties                       = nullptr;
PFN_vkGetPhysicalDeviceExternalFenceProperties                        vkGetPhysicalDeviceExternalFenceProperties                        = nullptr;
PFN_vkGetPhysicalDeviceExternalSemaphoreProperties                    vkGetPhysicalDeviceExternalSemaphoreProperties                    = nullptr;
PFN_vkGetPhysicalDeviceToolProperties                                 vkGetPhysicalDeviceToolProperties                                 = nullptr;
PFN_vkDestroySurfaceKHR                                               vkDestroySurfaceKHR                                               = nullptr;
PFN_vkGetPhysicalDeviceSurfaceSupportKHR                              vkGetPhysicalDeviceSurfaceSupportKHR                              = nullptr;
PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR                         vkGetPhysicalDeviceSurfaceCapabilitiesKHR                         = nullptr;
PFN_vkGetPhysicalDeviceSurfaceFormatsKHR                              vkGetPhysicalDeviceSurfaceFormatsKHR                              = nullptr;
PFN_vkGetPhysicalDeviceSurfacePresentModesKHR                         vkGetPhysicalDeviceSurfacePresentModesKHR                         = nullptr;
PFN_vkGetPhysicalDevicePresentRectanglesKHR                           vkGetPhysicalDevicePresentRectanglesKHR                           = nullptr;
PFN_vkGetPhysicalDeviceDisplayPropertiesKHR                           vkGetPhysicalDeviceDisplayPropertiesKHR                           = nullptr;
PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR                      vkGetPhysicalDeviceDisplayPlanePropertiesKHR                      = nullptr;
PFN_vkGetDisplayPlaneSupportedDisplaysKHR                             vkGetDisplayPlaneSupportedDisplaysKHR                             = nullptr;
PFN_vkGetDisplayModePropertiesKHR                                     vkGetDisplayModePropertiesKHR                                     = nullptr;
PFN_vkCreateDisplayModeKHR                                            vkCreateDisplayModeKHR                                            = nullptr;
PFN_vkGetDisplayPlaneCapabilitiesKHR                                  vkGetDisplayPlaneCapabilitiesKHR                                  = nullptr;
PFN_vkCreateDisplayPlaneSurfaceKHR                                    vkCreateDisplayPlaneSurfaceKHR                                    = nullptr;
PFN_vkGetPhysicalDeviceVideoCapabilitiesKHR                           vkGetPhysicalDeviceVideoCapabilitiesKHR                           = nullptr;
PFN_vkGetPhysicalDeviceVideoFormatPropertiesKHR                       vkGetPhysicalDeviceVideoFormatPropertiesKHR                       = nullptr;
PFN_vkGetPhysicalDeviceFeatures2KHR                                   vkGetPhysicalDeviceFeatures2KHR                                   = nullptr;
PFN_vkGetPhysicalDeviceProperties2KHR                                 vkGetPhysicalDeviceProperties2KHR                                 = nullptr;
PFN_vkGetPhysicalDeviceFormatProperties2KHR                           vkGetPhysicalDeviceFormatProperties2KHR                           = nullptr;
PFN_vkGetPhysicalDeviceImageFormatProperties2KHR                      vkGetPhysicalDeviceImageFormatProperties2KHR                      = nullptr;
PFN_vkGetPhysicalDeviceQueueFamilyProperties2KHR                      vkGetPhysicalDeviceQueueFamilyProperties2KHR                      = nullptr;
PFN_vkGetPhysicalDeviceMemoryProperties2KHR                           vkGetPhysicalDeviceMemoryProperties2KHR                           = nullptr;
PFN_vkGetPhysicalDeviceSparseImageFormatProperties2KHR                vkGetPhysicalDeviceSparseImageFormatProperties2KHR                = nullptr;
PFN_vkEnumeratePhysicalDeviceGroupsKHR                                vkEnumeratePhysicalDeviceGroupsKHR                                = nullptr;
PFN_vkGetPhysicalDeviceExternalBufferPropertiesKHR                    vkGetPhysicalDeviceExternalBufferPropertiesKHR                    = nullptr;
PFN_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR                 vkGetPhysicalDeviceExternalSemaphorePropertiesKHR                 = nullptr;
PFN_vkGetPhysicalDeviceExternalFencePropertiesKHR                     vkGetPhysicalDeviceExternalFencePropertiesKHR                     = nullptr;
PFN_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR   vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR   = nullptr;
PFN_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR           vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR           = nullptr;
PFN_vkGetPhysicalDeviceSurfaceCapabilities2KHR                        vkGetPhysicalDeviceSurfaceCapabilities2KHR                        = nullptr;
PFN_vkGetPhysicalDeviceSurfaceFormats2KHR                             vkGetPhysicalDeviceSurfaceFormats2KHR                             = nullptr;
PFN_vkGetPhysicalDeviceDisplayProperties2KHR                          vkGetPhysicalDeviceDisplayProperties2KHR                          = nullptr;
PFN_vkGetPhysicalDeviceDisplayPlaneProperties2KHR                     vkGetPhysicalDeviceDisplayPlaneProperties2KHR                     = nullptr;
PFN_vkGetDisplayModeProperties2KHR                                    vkGetDisplayModeProperties2KHR                                    = nullptr;
PFN_vkGetDisplayPlaneCapabilities2KHR                                 vkGetDisplayPlaneCapabilities2KHR                                 = nullptr;
PFN_vkGetPhysicalDeviceFragmentShadingRatesKHR                        vkGetPhysicalDeviceFragmentShadingRatesKHR                        = nullptr;
PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR                 vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR                 = nullptr;
PFN_vkCreateDebugReportCallbackEXT                                    vkCreateDebugReportCallbackEXT                                    = nullptr;
PFN_vkDestroyDebugReportCallbackEXT                                   vkDestroyDebugReportCallbackEXT                                   = nullptr;
PFN_vkDebugReportMessageEXT                                           vkDebugReportMessageEXT                                           = nullptr;
PFN_vkGetPhysicalDeviceExternalImageFormatPropertiesNV                vkGetPhysicalDeviceExternalImageFormatPropertiesNV                = nullptr;
PFN_vkReleaseDisplayEXT                                               vkReleaseDisplayEXT                                               = nullptr;
PFN_vkGetPhysicalDeviceSurfaceCapabilities2EXT                        vkGetPhysicalDeviceSurfaceCapabilities2EXT                        = nullptr;
PFN_vkCreateDebugUtilsMessengerEXT                                    vkCreateDebugUtilsMessengerEXT                                    = nullptr;
PFN_vkDestroyDebugUtilsMessengerEXT                                   vkDestroyDebugUtilsMessengerEXT                                   = nullptr;
PFN_vkSubmitDebugUtilsMessageEXT                                      vkSubmitDebugUtilsMessageEXT                                      = nullptr;
PFN_vkGetPhysicalDeviceMultisamplePropertiesEXT                       vkGetPhysicalDeviceMultisamplePropertiesEXT                       = nullptr;
PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT                    vkGetPhysicalDeviceCalibrateableTimeDomainsEXT                    = nullptr;
PFN_vkGetPhysicalDeviceToolPropertiesEXT                              vkGetPhysicalDeviceToolPropertiesEXT                              = nullptr;
PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV                  vkGetPhysicalDeviceCooperativeMatrixPropertiesNV                  = nullptr;
PFN_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV = nullptr;
PFN_vkCreateHeadlessSurfaceEXT                                        vkCreateHeadlessSurfaceEXT                                        = nullptr;
PFN_vkAcquireDrmDisplayEXT                                            vkAcquireDrmDisplayEXT                                            = nullptr;
PFN_vkGetDrmDisplayEXT                                                vkGetDrmDisplayEXT                                                = nullptr;
PFN_vkGetPhysicalDeviceOpticalFlowImageFormatsNV                      vkGetPhysicalDeviceOpticalFlowImageFormatsNV                      = nullptr;
#if !defined(VUSYM_SUPPORT_MULTIPLE_VULKAN_DEVICES)
PFN_vkDestroyDevice                                          vkDestroyDevice                                          = nullptr;
PFN_vkGetDeviceQueue                                         vkGetDeviceQueue                                         = nullptr;
PFN_vkQueueSubmit                                            vkQueueSubmit                                            = nullptr;
PFN_vkQueueWaitIdle                                          vkQueueWaitIdle                                          = nullptr;
PFN_vkDeviceWaitIdle                                         vkDeviceWaitIdle                                         = nullptr;
PFN_vkAllocateMemory                                         vkAllocateMemory                                         = nullptr;
PFN_vkFreeMemory                                             vkFreeMemory                                             = nullptr;
PFN_vkMapMemory                                              vkMapMemory                                              = nullptr;
PFN_vkUnmapMemory                                            vkUnmapMemory                                            = nullptr;
PFN_vkFlushMappedMemoryRanges                                vkFlushMappedMemoryRanges                                = nullptr;
PFN_vkInvalidateMappedMemoryRanges                           vkInvalidateMappedMemoryRanges                           = nullptr;
PFN_vkGetDeviceMemoryCommitment                              vkGetDeviceMemoryCommitment                              = nullptr;
PFN_vkBindBufferMemory                                       vkBindBufferMemory                                       = nullptr;
PFN_vkBindImageMemory                                        vkBindImageMemory                                        = nullptr;
PFN_vkGetBufferMemoryRequirements                            vkGetBufferMemoryRequirements                            = nullptr;
PFN_vkGetImageMemoryRequirements                             vkGetImageMemoryRequirements                             = nullptr;
PFN_vkGetImageSparseMemoryRequirements                       vkGetImageSparseMemoryRequirements                       = nullptr;
PFN_vkQueueBindSparse                                        vkQueueBindSparse                                        = nullptr;
PFN_vkCreateFence                                            vkCreateFence                                            = nullptr;
PFN_vkDestroyFence                                           vkDestroyFence                                           = nullptr;
PFN_vkResetFences                                            vkResetFences                                            = nullptr;
PFN_vkGetFenceStatus                                         vkGetFenceStatus                                         = nullptr;
PFN_vkWaitForFences                                          vkWaitForFences                                          = nullptr;
PFN_vkCreateSemaphore                                        vkCreateSemaphore                                        = nullptr;
PFN_vkDestroySemaphore                                       vkDestroySemaphore                                       = nullptr;
PFN_vkCreateEvent                                            vkCreateEvent                                            = nullptr;
PFN_vkDestroyEvent                                           vkDestroyEvent                                           = nullptr;
PFN_vkGetEventStatus                                         vkGetEventStatus                                         = nullptr;
PFN_vkSetEvent                                               vkSetEvent                                               = nullptr;
PFN_vkResetEvent                                             vkResetEvent                                             = nullptr;
PFN_vkCreateQueryPool                                        vkCreateQueryPool                                        = nullptr;
PFN_vkDestroyQueryPool                                       vkDestroyQueryPool                                       = nullptr;
PFN_vkGetQueryPoolResults                                    vkGetQueryPoolResults                                    = nullptr;
PFN_vkCreateBuffer                                           vkCreateBuffer                                           = nullptr;
PFN_vkDestroyBuffer                                          vkDestroyBuffer                                          = nullptr;
PFN_vkCreateBufferView                                       vkCreateBufferView                                       = nullptr;
PFN_vkDestroyBufferView                                      vkDestroyBufferView                                      = nullptr;
PFN_vkCreateImage                                            vkCreateImage                                            = nullptr;
PFN_vkDestroyImage                                           vkDestroyImage                                           = nullptr;
PFN_vkGetImageSubresourceLayout                              vkGetImageSubresourceLayout                              = nullptr;
PFN_vkCreateImageView                                        vkCreateImageView                                        = nullptr;
PFN_vkDestroyImageView                                       vkDestroyImageView                                       = nullptr;
PFN_vkCreateShaderModule                                     vkCreateShaderModule                                     = nullptr;
PFN_vkDestroyShaderModule                                    vkDestroyShaderModule                                    = nullptr;
PFN_vkCreatePipelineCache                                    vkCreatePipelineCache                                    = nullptr;
PFN_vkDestroyPipelineCache                                   vkDestroyPipelineCache                                   = nullptr;
PFN_vkGetPipelineCacheData                                   vkGetPipelineCacheData                                   = nullptr;
PFN_vkMergePipelineCaches                                    vkMergePipelineCaches                                    = nullptr;
PFN_vkCreateGraphicsPipelines                                vkCreateGraphicsPipelines                                = nullptr;
PFN_vkCreateComputePipelines                                 vkCreateComputePipelines                                 = nullptr;
PFN_vkDestroyPipeline                                        vkDestroyPipeline                                        = nullptr;
PFN_vkCreatePipelineLayout                                   vkCreatePipelineLayout                                   = nullptr;
PFN_vkDestroyPipelineLayout                                  vkDestroyPipelineLayout                                  = nullptr;
PFN_vkCreateSampler                                          vkCreateSampler                                          = nullptr;
PFN_vkDestroySampler                                         vkDestroySampler                                         = nullptr;
PFN_vkCreateDescriptorSetLayout                              vkCreateDescriptorSetLayout                              = nullptr;
PFN_vkDestroyDescriptorSetLayout                             vkDestroyDescriptorSetLayout                             = nullptr;
PFN_vkCreateDescriptorPool                                   vkCreateDescriptorPool                                   = nullptr;
PFN_vkDestroyDescriptorPool                                  vkDestroyDescriptorPool                                  = nullptr;
PFN_vkResetDescriptorPool                                    vkResetDescriptorPool                                    = nullptr;
PFN_vkAllocateDescriptorSets                                 vkAllocateDescriptorSets                                 = nullptr;
PFN_vkFreeDescriptorSets                                     vkFreeDescriptorSets                                     = nullptr;
PFN_vkUpdateDescriptorSets                                   vkUpdateDescriptorSets                                   = nullptr;
PFN_vkCreateFramebuffer                                      vkCreateFramebuffer                                      = nullptr;
PFN_vkDestroyFramebuffer                                     vkDestroyFramebuffer                                     = nullptr;
PFN_vkCreateRenderPass                                       vkCreateRenderPass                                       = nullptr;
PFN_vkDestroyRenderPass                                      vkDestroyRenderPass                                      = nullptr;
PFN_vkGetRenderAreaGranularity                               vkGetRenderAreaGranularity                               = nullptr;
PFN_vkCreateCommandPool                                      vkCreateCommandPool                                      = nullptr;
PFN_vkDestroyCommandPool                                     vkDestroyCommandPool                                     = nullptr;
PFN_vkResetCommandPool                                       vkResetCommandPool                                       = nullptr;
PFN_vkAllocateCommandBuffers                                 vkAllocateCommandBuffers                                 = nullptr;
PFN_vkFreeCommandBuffers                                     vkFreeCommandBuffers                                     = nullptr;
PFN_vkBeginCommandBuffer                                     vkBeginCommandBuffer                                     = nullptr;
PFN_vkEndCommandBuffer                                       vkEndCommandBuffer                                       = nullptr;
PFN_vkResetCommandBuffer                                     vkResetCommandBuffer                                     = nullptr;
PFN_vkCmdBindPipeline                                        vkCmdBindPipeline                                        = nullptr;
PFN_vkCmdSetViewport                                         vkCmdSetViewport                                         = nullptr;
PFN_vkCmdSetScissor                                          vkCmdSetScissor                                          = nullptr;
PFN_vkCmdSetLineWidth                                        vkCmdSetLineWidth                                        = nullptr;
PFN_vkCmdSetDepthBias                                        vkCmdSetDepthBias                                        = nullptr;
PFN_vkCmdSetBlendConstants                                   vkCmdSetBlendConstants                                   = nullptr;
PFN_vkCmdSetDepthBounds                                      vkCmdSetDepthBounds                                      = nullptr;
PFN_vkCmdSetStencilCompareMask                               vkCmdSetStencilCompareMask                               = nullptr;
PFN_vkCmdSetStencilWriteMask                                 vkCmdSetStencilWriteMask                                 = nullptr;
PFN_vkCmdSetStencilReference                                 vkCmdSetStencilReference                                 = nullptr;
PFN_vkCmdBindDescriptorSets                                  vkCmdBindDescriptorSets                                  = nullptr;
PFN_vkCmdBindIndexBuffer                                     vkCmdBindIndexBuffer                                     = nullptr;
PFN_vkCmdBindVertexBuffers                                   vkCmdBindVertexBuffers                                   = nullptr;
PFN_vkCmdDraw                                                vkCmdDraw                                                = nullptr;
PFN_vkCmdDrawIndexed                                         vkCmdDrawIndexed                                         = nullptr;
PFN_vkCmdDrawIndirect                                        vkCmdDrawIndirect                                        = nullptr;
PFN_vkCmdDrawIndexedIndirect                                 vkCmdDrawIndexedIndirect                                 = nullptr;
PFN_vkCmdDispatch                                            vkCmdDispatch                                            = nullptr;
PFN_vkCmdDispatchIndirect                                    vkCmdDispatchIndirect                                    = nullptr;
PFN_vkCmdCopyBuffer                                          vkCmdCopyBuffer                                          = nullptr;
PFN_vkCmdCopyImage                                           vkCmdCopyImage                                           = nullptr;
PFN_vkCmdBlitImage                                           vkCmdBlitImage                                           = nullptr;
PFN_vkCmdCopyBufferToImage                                   vkCmdCopyBufferToImage                                   = nullptr;
PFN_vkCmdCopyImageToBuffer                                   vkCmdCopyImageToBuffer                                   = nullptr;
PFN_vkCmdUpdateBuffer                                        vkCmdUpdateBuffer                                        = nullptr;
PFN_vkCmdFillBuffer                                          vkCmdFillBuffer                                          = nullptr;
PFN_vkCmdClearColorImage                                     vkCmdClearColorImage                                     = nullptr;
PFN_vkCmdClearDepthStencilImage                              vkCmdClearDepthStencilImage                              = nullptr;
PFN_vkCmdClearAttachments                                    vkCmdClearAttachments                                    = nullptr;
PFN_vkCmdResolveImage                                        vkCmdResolveImage                                        = nullptr;
PFN_vkCmdSetEvent                                            vkCmdSetEvent                                            = nullptr;
PFN_vkCmdResetEvent                                          vkCmdResetEvent                                          = nullptr;
PFN_vkCmdWaitEvents                                          vkCmdWaitEvents                                          = nullptr;
PFN_vkCmdPipelineBarrier                                     vkCmdPipelineBarrier                                     = nullptr;
PFN_vkCmdBeginQuery                                          vkCmdBeginQuery                                          = nullptr;
PFN_vkCmdEndQuery                                            vkCmdEndQuery                                            = nullptr;
PFN_vkCmdResetQueryPool                                      vkCmdResetQueryPool                                      = nullptr;
PFN_vkCmdWriteTimestamp                                      vkCmdWriteTimestamp                                      = nullptr;
PFN_vkCmdCopyQueryPoolResults                                vkCmdCopyQueryPoolResults                                = nullptr;
PFN_vkCmdPushConstants                                       vkCmdPushConstants                                       = nullptr;
PFN_vkCmdBeginRenderPass                                     vkCmdBeginRenderPass                                     = nullptr;
PFN_vkCmdNextSubpass                                         vkCmdNextSubpass                                         = nullptr;
PFN_vkCmdEndRenderPass                                       vkCmdEndRenderPass                                       = nullptr;
PFN_vkCmdExecuteCommands                                     vkCmdExecuteCommands                                     = nullptr;
PFN_vkBindBufferMemory2                                      vkBindBufferMemory2                                      = nullptr;
PFN_vkBindImageMemory2                                       vkBindImageMemory2                                       = nullptr;
PFN_vkGetDeviceGroupPeerMemoryFeatures                       vkGetDeviceGroupPeerMemoryFeatures                       = nullptr;
PFN_vkCmdSetDeviceMask                                       vkCmdSetDeviceMask                                       = nullptr;
PFN_vkCmdDispatchBase                                        vkCmdDispatchBase                                        = nullptr;
PFN_vkGetImageMemoryRequirements2                            vkGetImageMemoryRequirements2                            = nullptr;
PFN_vkGetBufferMemoryRequirements2                           vkGetBufferMemoryRequirements2                           = nullptr;
PFN_vkGetImageSparseMemoryRequirements2                      vkGetImageSparseMemoryRequirements2                      = nullptr;
PFN_vkTrimCommandPool                                        vkTrimCommandPool                                        = nullptr;
PFN_vkGetDeviceQueue2                                        vkGetDeviceQueue2                                        = nullptr;
PFN_vkCreateSamplerYcbcrConversion                           vkCreateSamplerYcbcrConversion                           = nullptr;
PFN_vkDestroySamplerYcbcrConversion                          vkDestroySamplerYcbcrConversion                          = nullptr;
PFN_vkCreateDescriptorUpdateTemplate                         vkCreateDescriptorUpdateTemplate                         = nullptr;
PFN_vkDestroyDescriptorUpdateTemplate                        vkDestroyDescriptorUpdateTemplate                        = nullptr;
PFN_vkUpdateDescriptorSetWithTemplate                        vkUpdateDescriptorSetWithTemplate                        = nullptr;
PFN_vkGetDescriptorSetLayoutSupport                          vkGetDescriptorSetLayoutSupport                          = nullptr;
PFN_vkCmdDrawIndirectCount                                   vkCmdDrawIndirectCount                                   = nullptr;
PFN_vkCmdDrawIndexedIndirectCount                            vkCmdDrawIndexedIndirectCount                            = nullptr;
PFN_vkCreateRenderPass2                                      vkCreateRenderPass2                                      = nullptr;
PFN_vkCmdBeginRenderPass2                                    vkCmdBeginRenderPass2                                    = nullptr;
PFN_vkCmdNextSubpass2                                        vkCmdNextSubpass2                                        = nullptr;
PFN_vkCmdEndRenderPass2                                      vkCmdEndRenderPass2                                      = nullptr;
PFN_vkResetQueryPool                                         vkResetQueryPool                                         = nullptr;
PFN_vkGetSemaphoreCounterValue                               vkGetSemaphoreCounterValue                               = nullptr;
PFN_vkWaitSemaphores                                         vkWaitSemaphores                                         = nullptr;
PFN_vkSignalSemaphore                                        vkSignalSemaphore                                        = nullptr;
PFN_vkGetBufferDeviceAddress                                 vkGetBufferDeviceAddress                                 = nullptr;
PFN_vkGetBufferOpaqueCaptureAddress                          vkGetBufferOpaqueCaptureAddress                          = nullptr;
PFN_vkGetDeviceMemoryOpaqueCaptureAddress                    vkGetDeviceMemoryOpaqueCaptureAddress                    = nullptr;
PFN_vkCreatePrivateDataSlot                                  vkCreatePrivateDataSlot                                  = nullptr;
PFN_vkDestroyPrivateDataSlot                                 vkDestroyPrivateDataSlot                                 = nullptr;
PFN_vkSetPrivateData                                         vkSetPrivateData                                         = nullptr;
PFN_vkGetPrivateData                                         vkGetPrivateData                                         = nullptr;
PFN_vkCmdSetEvent2                                           vkCmdSetEvent2                                           = nullptr;
PFN_vkCmdResetEvent2                                         vkCmdResetEvent2                                         = nullptr;
PFN_vkCmdWaitEvents2                                         vkCmdWaitEvents2                                         = nullptr;
PFN_vkCmdPipelineBarrier2                                    vkCmdPipelineBarrier2                                    = nullptr;
PFN_vkCmdWriteTimestamp2                                     vkCmdWriteTimestamp2                                     = nullptr;
PFN_vkQueueSubmit2                                           vkQueueSubmit2                                           = nullptr;
PFN_vkCmdCopyBuffer2                                         vkCmdCopyBuffer2                                         = nullptr;
PFN_vkCmdCopyImage2                                          vkCmdCopyImage2                                          = nullptr;
PFN_vkCmdCopyBufferToImage2                                  vkCmdCopyBufferToImage2                                  = nullptr;
PFN_vkCmdCopyImageToBuffer2                                  vkCmdCopyImageToBuffer2                                  = nullptr;
PFN_vkCmdBlitImage2                                          vkCmdBlitImage2                                          = nullptr;
PFN_vkCmdResolveImage2                                       vkCmdResolveImage2                                       = nullptr;
PFN_vkCmdBeginRendering                                      vkCmdBeginRendering                                      = nullptr;
PFN_vkCmdEndRendering                                        vkCmdEndRendering                                        = nullptr;
PFN_vkCmdSetCullMode                                         vkCmdSetCullMode                                         = nullptr;
PFN_vkCmdSetFrontFace                                        vkCmdSetFrontFace                                        = nullptr;
PFN_vkCmdSetPrimitiveTopology                                vkCmdSetPrimitiveTopology                                = nullptr;
PFN_vkCmdSetViewportWithCount                                vkCmdSetViewportWithCount                                = nullptr;
PFN_vkCmdSetScissorWithCount                                 vkCmdSetScissorWithCount                                 = nullptr;
PFN_vkCmdBindVertexBuffers2                                  vkCmdBindVertexBuffers2                                  = nullptr;
PFN_vkCmdSetDepthTestEnable                                  vkCmdSetDepthTestEnable                                  = nullptr;
PFN_vkCmdSetDepthWriteEnable                                 vkCmdSetDepthWriteEnable                                 = nullptr;
PFN_vkCmdSetDepthCompareOp                                   vkCmdSetDepthCompareOp                                   = nullptr;
PFN_vkCmdSetDepthBoundsTestEnable                            vkCmdSetDepthBoundsTestEnable                            = nullptr;
PFN_vkCmdSetStencilTestEnable                                vkCmdSetStencilTestEnable                                = nullptr;
PFN_vkCmdSetStencilOp                                        vkCmdSetStencilOp                                        = nullptr;
PFN_vkCmdSetRasterizerDiscardEnable                          vkCmdSetRasterizerDiscardEnable                          = nullptr;
PFN_vkCmdSetDepthBiasEnable                                  vkCmdSetDepthBiasEnable                                  = nullptr;
PFN_vkCmdSetPrimitiveRestartEnable                           vkCmdSetPrimitiveRestartEnable                           = nullptr;
PFN_vkGetDeviceBufferMemoryRequirements                      vkGetDeviceBufferMemoryRequirements                      = nullptr;
PFN_vkGetDeviceImageMemoryRequirements                       vkGetDeviceImageMemoryRequirements                       = nullptr;
PFN_vkGetDeviceImageSparseMemoryRequirements                 vkGetDeviceImageSparseMemoryRequirements                 = nullptr;
PFN_vkCreateSwapchainKHR                                     vkCreateSwapchainKHR                                     = nullptr;
PFN_vkDestroySwapchainKHR                                    vkDestroySwapchainKHR                                    = nullptr;
PFN_vkGetSwapchainImagesKHR                                  vkGetSwapchainImagesKHR                                  = nullptr;
PFN_vkAcquireNextImageKHR                                    vkAcquireNextImageKHR                                    = nullptr;
PFN_vkQueuePresentKHR                                        vkQueuePresentKHR                                        = nullptr;
PFN_vkGetDeviceGroupPresentCapabilitiesKHR                   vkGetDeviceGroupPresentCapabilitiesKHR                   = nullptr;
PFN_vkGetDeviceGroupSurfacePresentModesKHR                   vkGetDeviceGroupSurfacePresentModesKHR                   = nullptr;
PFN_vkAcquireNextImage2KHR                                   vkAcquireNextImage2KHR                                   = nullptr;
PFN_vkCreateSharedSwapchainsKHR                              vkCreateSharedSwapchainsKHR                              = nullptr;
PFN_vkCreateVideoSessionKHR                                  vkCreateVideoSessionKHR                                  = nullptr;
PFN_vkDestroyVideoSessionKHR                                 vkDestroyVideoSessionKHR                                 = nullptr;
PFN_vkGetVideoSessionMemoryRequirementsKHR                   vkGetVideoSessionMemoryRequirementsKHR                   = nullptr;
PFN_vkBindVideoSessionMemoryKHR                              vkBindVideoSessionMemoryKHR                              = nullptr;
PFN_vkCreateVideoSessionParametersKHR                        vkCreateVideoSessionParametersKHR                        = nullptr;
PFN_vkUpdateVideoSessionParametersKHR                        vkUpdateVideoSessionParametersKHR                        = nullptr;
PFN_vkDestroyVideoSessionParametersKHR                       vkDestroyVideoSessionParametersKHR                       = nullptr;
PFN_vkCmdBeginVideoCodingKHR                                 vkCmdBeginVideoCodingKHR                                 = nullptr;
PFN_vkCmdEndVideoCodingKHR                                   vkCmdEndVideoCodingKHR                                   = nullptr;
PFN_vkCmdControlVideoCodingKHR                               vkCmdControlVideoCodingKHR                               = nullptr;
PFN_vkCmdDecodeVideoKHR                                      vkCmdDecodeVideoKHR                                      = nullptr;
PFN_vkCmdBeginRenderingKHR                                   vkCmdBeginRenderingKHR                                   = nullptr;
PFN_vkCmdEndRenderingKHR                                     vkCmdEndRenderingKHR                                     = nullptr;
PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR                    vkGetDeviceGroupPeerMemoryFeaturesKHR                    = nullptr;
PFN_vkCmdSetDeviceMaskKHR                                    vkCmdSetDeviceMaskKHR                                    = nullptr;
PFN_vkCmdDispatchBaseKHR                                     vkCmdDispatchBaseKHR                                     = nullptr;
PFN_vkTrimCommandPoolKHR                                     vkTrimCommandPoolKHR                                     = nullptr;
PFN_vkGetMemoryFdKHR                                         vkGetMemoryFdKHR                                         = nullptr;
PFN_vkGetMemoryFdPropertiesKHR                               vkGetMemoryFdPropertiesKHR                               = nullptr;
PFN_vkImportSemaphoreFdKHR                                   vkImportSemaphoreFdKHR                                   = nullptr;
PFN_vkGetSemaphoreFdKHR                                      vkGetSemaphoreFdKHR                                      = nullptr;
PFN_vkCmdPushDescriptorSetKHR                                vkCmdPushDescriptorSetKHR                                = nullptr;
PFN_vkCmdPushDescriptorSetWithTemplateKHR                    vkCmdPushDescriptorSetWithTemplateKHR                    = nullptr;
PFN_vkCreateDescriptorUpdateTemplateKHR                      vkCreateDescriptorUpdateTemplateKHR                      = nullptr;
PFN_vkDestroyDescriptorUpdateTemplateKHR                     vkDestroyDescriptorUpdateTemplateKHR                     = nullptr;
PFN_vkUpdateDescriptorSetWithTemplateKHR                     vkUpdateDescriptorSetWithTemplateKHR                     = nullptr;
PFN_vkCreateRenderPass2KHR                                   vkCreateRenderPass2KHR                                   = nullptr;
PFN_vkCmdBeginRenderPass2KHR                                 vkCmdBeginRenderPass2KHR                                 = nullptr;
PFN_vkCmdNextSubpass2KHR                                     vkCmdNextSubpass2KHR                                     = nullptr;
PFN_vkCmdEndRenderPass2KHR                                   vkCmdEndRenderPass2KHR                                   = nullptr;
PFN_vkGetSwapchainStatusKHR                                  vkGetSwapchainStatusKHR                                  = nullptr;
PFN_vkImportFenceFdKHR                                       vkImportFenceFdKHR                                       = nullptr;
PFN_vkGetFenceFdKHR                                          vkGetFenceFdKHR                                          = nullptr;
PFN_vkAcquireProfilingLockKHR                                vkAcquireProfilingLockKHR                                = nullptr;
PFN_vkReleaseProfilingLockKHR                                vkReleaseProfilingLockKHR                                = nullptr;
PFN_vkGetImageMemoryRequirements2KHR                         vkGetImageMemoryRequirements2KHR                         = nullptr;
PFN_vkGetBufferMemoryRequirements2KHR                        vkGetBufferMemoryRequirements2KHR                        = nullptr;
PFN_vkGetImageSparseMemoryRequirements2KHR                   vkGetImageSparseMemoryRequirements2KHR                   = nullptr;
PFN_vkCreateSamplerYcbcrConversionKHR                        vkCreateSamplerYcbcrConversionKHR                        = nullptr;
PFN_vkDestroySamplerYcbcrConversionKHR                       vkDestroySamplerYcbcrConversionKHR                       = nullptr;
PFN_vkBindBufferMemory2KHR                                   vkBindBufferMemory2KHR                                   = nullptr;
PFN_vkBindImageMemory2KHR                                    vkBindImageMemory2KHR                                    = nullptr;
PFN_vkGetDescriptorSetLayoutSupportKHR                       vkGetDescriptorSetLayoutSupportKHR                       = nullptr;
PFN_vkCmdDrawIndirectCountKHR                                vkCmdDrawIndirectCountKHR                                = nullptr;
PFN_vkCmdDrawIndexedIndirectCountKHR                         vkCmdDrawIndexedIndirectCountKHR                         = nullptr;
PFN_vkGetSemaphoreCounterValueKHR                            vkGetSemaphoreCounterValueKHR                            = nullptr;
PFN_vkWaitSemaphoresKHR                                      vkWaitSemaphoresKHR                                      = nullptr;
PFN_vkSignalSemaphoreKHR                                     vkSignalSemaphoreKHR                                     = nullptr;
PFN_vkCmdSetFragmentShadingRateKHR                           vkCmdSetFragmentShadingRateKHR                           = nullptr;
PFN_vkWaitForPresentKHR                                      vkWaitForPresentKHR                                      = nullptr;
PFN_vkGetBufferDeviceAddressKHR                              vkGetBufferDeviceAddressKHR                              = nullptr;
PFN_vkGetBufferOpaqueCaptureAddressKHR                       vkGetBufferOpaqueCaptureAddressKHR                       = nullptr;
PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR                 vkGetDeviceMemoryOpaqueCaptureAddressKHR                 = nullptr;
PFN_vkCreateDeferredOperationKHR                             vkCreateDeferredOperationKHR                             = nullptr;
PFN_vkDestroyDeferredOperationKHR                            vkDestroyDeferredOperationKHR                            = nullptr;
PFN_vkGetDeferredOperationMaxConcurrencyKHR                  vkGetDeferredOperationMaxConcurrencyKHR                  = nullptr;
PFN_vkGetDeferredOperationResultKHR                          vkGetDeferredOperationResultKHR                          = nullptr;
PFN_vkDeferredOperationJoinKHR                               vkDeferredOperationJoinKHR                               = nullptr;
PFN_vkGetPipelineExecutablePropertiesKHR                     vkGetPipelineExecutablePropertiesKHR                     = nullptr;
PFN_vkGetPipelineExecutableStatisticsKHR                     vkGetPipelineExecutableStatisticsKHR                     = nullptr;
PFN_vkGetPipelineExecutableInternalRepresentationsKHR        vkGetPipelineExecutableInternalRepresentationsKHR        = nullptr;
PFN_vkMapMemory2KHR                                          vkMapMemory2KHR                                          = nullptr;
PFN_vkUnmapMemory2KHR                                        vkUnmapMemory2KHR                                        = nullptr;
PFN_vkCmdSetEvent2KHR                                        vkCmdSetEvent2KHR                                        = nullptr;
PFN_vkCmdResetEvent2KHR                                      vkCmdResetEvent2KHR                                      = nullptr;
PFN_vkCmdWaitEvents2KHR                                      vkCmdWaitEvents2KHR                                      = nullptr;
PFN_vkCmdPipelineBarrier2KHR                                 vkCmdPipelineBarrier2KHR                                 = nullptr;
PFN_vkCmdWriteTimestamp2KHR                                  vkCmdWriteTimestamp2KHR                                  = nullptr;
PFN_vkQueueSubmit2KHR                                        vkQueueSubmit2KHR                                        = nullptr;
PFN_vkCmdWriteBufferMarker2AMD                               vkCmdWriteBufferMarker2AMD                               = nullptr;
PFN_vkGetQueueCheckpointData2NV                              vkGetQueueCheckpointData2NV                              = nullptr;
PFN_vkCmdCopyBuffer2KHR                                      vkCmdCopyBuffer2KHR                                      = nullptr;
PFN_vkCmdCopyImage2KHR                                       vkCmdCopyImage2KHR                                       = nullptr;
PFN_vkCmdCopyBufferToImage2KHR                               vkCmdCopyBufferToImage2KHR                               = nullptr;
PFN_vkCmdCopyImageToBuffer2KHR                               vkCmdCopyImageToBuffer2KHR                               = nullptr;
PFN_vkCmdBlitImage2KHR                                       vkCmdBlitImage2KHR                                       = nullptr;
PFN_vkCmdResolveImage2KHR                                    vkCmdResolveImage2KHR                                    = nullptr;
PFN_vkCmdTraceRaysIndirect2KHR                               vkCmdTraceRaysIndirect2KHR                               = nullptr;
PFN_vkGetDeviceBufferMemoryRequirementsKHR                   vkGetDeviceBufferMemoryRequirementsKHR                   = nullptr;
PFN_vkGetDeviceImageMemoryRequirementsKHR                    vkGetDeviceImageMemoryRequirementsKHR                    = nullptr;
PFN_vkGetDeviceImageSparseMemoryRequirementsKHR              vkGetDeviceImageSparseMemoryRequirementsKHR              = nullptr;
PFN_vkDebugMarkerSetObjectTagEXT                             vkDebugMarkerSetObjectTagEXT                             = nullptr;
PFN_vkDebugMarkerSetObjectNameEXT                            vkDebugMarkerSetObjectNameEXT                            = nullptr;
PFN_vkCmdDebugMarkerBeginEXT                                 vkCmdDebugMarkerBeginEXT                                 = nullptr;
PFN_vkCmdDebugMarkerEndEXT                                   vkCmdDebugMarkerEndEXT                                   = nullptr;
PFN_vkCmdDebugMarkerInsertEXT                                vkCmdDebugMarkerInsertEXT                                = nullptr;
PFN_vkCmdBindTransformFeedbackBuffersEXT                     vkCmdBindTransformFeedbackBuffersEXT                     = nullptr;
PFN_vkCmdBeginTransformFeedbackEXT                           vkCmdBeginTransformFeedbackEXT                           = nullptr;
PFN_vkCmdEndTransformFeedbackEXT                             vkCmdEndTransformFeedbackEXT                             = nullptr;
PFN_vkCmdBeginQueryIndexedEXT                                vkCmdBeginQueryIndexedEXT                                = nullptr;
PFN_vkCmdEndQueryIndexedEXT                                  vkCmdEndQueryIndexedEXT                                  = nullptr;
PFN_vkCmdDrawIndirectByteCountEXT                            vkCmdDrawIndirectByteCountEXT                            = nullptr;
PFN_vkCreateCuModuleNVX                                      vkCreateCuModuleNVX                                      = nullptr;
PFN_vkCreateCuFunctionNVX                                    vkCreateCuFunctionNVX                                    = nullptr;
PFN_vkDestroyCuModuleNVX                                     vkDestroyCuModuleNVX                                     = nullptr;
PFN_vkDestroyCuFunctionNVX                                   vkDestroyCuFunctionNVX                                   = nullptr;
PFN_vkCmdCuLaunchKernelNVX                                   vkCmdCuLaunchKernelNVX                                   = nullptr;
PFN_vkGetImageViewHandleNVX                                  vkGetImageViewHandleNVX                                  = nullptr;
PFN_vkGetImageViewAddressNVX                                 vkGetImageViewAddressNVX                                 = nullptr;
PFN_vkCmdDrawIndirectCountAMD                                vkCmdDrawIndirectCountAMD                                = nullptr;
PFN_vkCmdDrawIndexedIndirectCountAMD                         vkCmdDrawIndexedIndirectCountAMD                         = nullptr;
PFN_vkGetShaderInfoAMD                                       vkGetShaderInfoAMD                                       = nullptr;
PFN_vkCmdBeginConditionalRenderingEXT                        vkCmdBeginConditionalRenderingEXT                        = nullptr;
PFN_vkCmdEndConditionalRenderingEXT                          vkCmdEndConditionalRenderingEXT                          = nullptr;
PFN_vkCmdSetViewportWScalingNV                               vkCmdSetViewportWScalingNV                               = nullptr;
PFN_vkDisplayPowerControlEXT                                 vkDisplayPowerControlEXT                                 = nullptr;
PFN_vkRegisterDeviceEventEXT                                 vkRegisterDeviceEventEXT                                 = nullptr;
PFN_vkRegisterDisplayEventEXT                                vkRegisterDisplayEventEXT                                = nullptr;
PFN_vkGetSwapchainCounterEXT                                 vkGetSwapchainCounterEXT                                 = nullptr;
PFN_vkGetRefreshCycleDurationGOOGLE                          vkGetRefreshCycleDurationGOOGLE                          = nullptr;
PFN_vkGetPastPresentationTimingGOOGLE                        vkGetPastPresentationTimingGOOGLE                        = nullptr;
PFN_vkCmdSetDiscardRectangleEXT                              vkCmdSetDiscardRectangleEXT                              = nullptr;
PFN_vkCmdSetDiscardRectangleEnableEXT                        vkCmdSetDiscardRectangleEnableEXT                        = nullptr;
PFN_vkCmdSetDiscardRectangleModeEXT                          vkCmdSetDiscardRectangleModeEXT                          = nullptr;
PFN_vkSetHdrMetadataEXT                                      vkSetHdrMetadataEXT                                      = nullptr;
PFN_vkSetDebugUtilsObjectNameEXT                             vkSetDebugUtilsObjectNameEXT                             = nullptr;
PFN_vkSetDebugUtilsObjectTagEXT                              vkSetDebugUtilsObjectTagEXT                              = nullptr;
PFN_vkQueueBeginDebugUtilsLabelEXT                           vkQueueBeginDebugUtilsLabelEXT                           = nullptr;
PFN_vkQueueEndDebugUtilsLabelEXT                             vkQueueEndDebugUtilsLabelEXT                             = nullptr;
PFN_vkQueueInsertDebugUtilsLabelEXT                          vkQueueInsertDebugUtilsLabelEXT                          = nullptr;
PFN_vkCmdBeginDebugUtilsLabelEXT                             vkCmdBeginDebugUtilsLabelEXT                             = nullptr;
PFN_vkCmdEndDebugUtilsLabelEXT                               vkCmdEndDebugUtilsLabelEXT                               = nullptr;
PFN_vkCmdInsertDebugUtilsLabelEXT                            vkCmdInsertDebugUtilsLabelEXT                            = nullptr;
PFN_vkCmdSetSampleLocationsEXT                               vkCmdSetSampleLocationsEXT                               = nullptr;
PFN_vkGetImageDrmFormatModifierPropertiesEXT                 vkGetImageDrmFormatModifierPropertiesEXT                 = nullptr;
PFN_vkCreateValidationCacheEXT                               vkCreateValidationCacheEXT                               = nullptr;
PFN_vkDestroyValidationCacheEXT                              vkDestroyValidationCacheEXT                              = nullptr;
PFN_vkMergeValidationCachesEXT                               vkMergeValidationCachesEXT                               = nullptr;
PFN_vkGetValidationCacheDataEXT                              vkGetValidationCacheDataEXT                              = nullptr;
PFN_vkCmdBindShadingRateImageNV                              vkCmdBindShadingRateImageNV                              = nullptr;
PFN_vkCmdSetViewportShadingRatePaletteNV                     vkCmdSetViewportShadingRatePaletteNV                     = nullptr;
PFN_vkCmdSetCoarseSampleOrderNV                              vkCmdSetCoarseSampleOrderNV                              = nullptr;
PFN_vkCreateAccelerationStructureNV                          vkCreateAccelerationStructureNV                          = nullptr;
PFN_vkDestroyAccelerationStructureNV                         vkDestroyAccelerationStructureNV                         = nullptr;
PFN_vkGetAccelerationStructureMemoryRequirementsNV           vkGetAccelerationStructureMemoryRequirementsNV           = nullptr;
PFN_vkBindAccelerationStructureMemoryNV                      vkBindAccelerationStructureMemoryNV                      = nullptr;
PFN_vkCmdBuildAccelerationStructureNV                        vkCmdBuildAccelerationStructureNV                        = nullptr;
PFN_vkCmdCopyAccelerationStructureNV                         vkCmdCopyAccelerationStructureNV                         = nullptr;
PFN_vkCmdTraceRaysNV                                         vkCmdTraceRaysNV                                         = nullptr;
PFN_vkCreateRayTracingPipelinesNV                            vkCreateRayTracingPipelinesNV                            = nullptr;
PFN_vkGetRayTracingShaderGroupHandlesKHR                     vkGetRayTracingShaderGroupHandlesKHR                     = nullptr;
PFN_vkGetRayTracingShaderGroupHandlesNV                      vkGetRayTracingShaderGroupHandlesNV                      = nullptr;
PFN_vkGetAccelerationStructureHandleNV                       vkGetAccelerationStructureHandleNV                       = nullptr;
PFN_vkCmdWriteAccelerationStructuresPropertiesNV             vkCmdWriteAccelerationStructuresPropertiesNV             = nullptr;
PFN_vkCompileDeferredNV                                      vkCompileDeferredNV                                      = nullptr;
PFN_vkGetMemoryHostPointerPropertiesEXT                      vkGetMemoryHostPointerPropertiesEXT                      = nullptr;
PFN_vkCmdWriteBufferMarkerAMD                                vkCmdWriteBufferMarkerAMD                                = nullptr;
PFN_vkGetCalibratedTimestampsEXT                             vkGetCalibratedTimestampsEXT                             = nullptr;
PFN_vkCmdDrawMeshTasksNV                                     vkCmdDrawMeshTasksNV                                     = nullptr;
PFN_vkCmdDrawMeshTasksIndirectNV                             vkCmdDrawMeshTasksIndirectNV                             = nullptr;
PFN_vkCmdDrawMeshTasksIndirectCountNV                        vkCmdDrawMeshTasksIndirectCountNV                        = nullptr;
PFN_vkCmdSetExclusiveScissorEnableNV                         vkCmdSetExclusiveScissorEnableNV                         = nullptr;
PFN_vkCmdSetExclusiveScissorNV                               vkCmdSetExclusiveScissorNV                               = nullptr;
PFN_vkCmdSetCheckpointNV                                     vkCmdSetCheckpointNV                                     = nullptr;
PFN_vkGetQueueCheckpointDataNV                               vkGetQueueCheckpointDataNV                               = nullptr;
PFN_vkInitializePerformanceApiINTEL                          vkInitializePerformanceApiINTEL                          = nullptr;
PFN_vkUninitializePerformanceApiINTEL                        vkUninitializePerformanceApiINTEL                        = nullptr;
PFN_vkCmdSetPerformanceMarkerINTEL                           vkCmdSetPerformanceMarkerINTEL                           = nullptr;
PFN_vkCmdSetPerformanceStreamMarkerINTEL                     vkCmdSetPerformanceStreamMarkerINTEL                     = nullptr;
PFN_vkCmdSetPerformanceOverrideINTEL                         vkCmdSetPerformanceOverrideINTEL                         = nullptr;
PFN_vkAcquirePerformanceConfigurationINTEL                   vkAcquirePerformanceConfigurationINTEL                   = nullptr;
PFN_vkReleasePerformanceConfigurationINTEL                   vkReleasePerformanceConfigurationINTEL                   = nullptr;
PFN_vkQueueSetPerformanceConfigurationINTEL                  vkQueueSetPerformanceConfigurationINTEL                  = nullptr;
PFN_vkGetPerformanceParameterINTEL                           vkGetPerformanceParameterINTEL                           = nullptr;
PFN_vkSetLocalDimmingAMD                                     vkSetLocalDimmingAMD                                     = nullptr;
PFN_vkGetBufferDeviceAddressEXT                              vkGetBufferDeviceAddressEXT                              = nullptr;
PFN_vkCmdSetLineStippleEXT                                   vkCmdSetLineStippleEXT                                   = nullptr;
PFN_vkResetQueryPoolEXT                                      vkResetQueryPoolEXT                                      = nullptr;
PFN_vkCmdSetCullModeEXT                                      vkCmdSetCullModeEXT                                      = nullptr;
PFN_vkCmdSetFrontFaceEXT                                     vkCmdSetFrontFaceEXT                                     = nullptr;
PFN_vkCmdSetPrimitiveTopologyEXT                             vkCmdSetPrimitiveTopologyEXT                             = nullptr;
PFN_vkCmdSetViewportWithCountEXT                             vkCmdSetViewportWithCountEXT                             = nullptr;
PFN_vkCmdSetScissorWithCountEXT                              vkCmdSetScissorWithCountEXT                              = nullptr;
PFN_vkCmdBindVertexBuffers2EXT                               vkCmdBindVertexBuffers2EXT                               = nullptr;
PFN_vkCmdSetDepthTestEnableEXT                               vkCmdSetDepthTestEnableEXT                               = nullptr;
PFN_vkCmdSetDepthWriteEnableEXT                              vkCmdSetDepthWriteEnableEXT                              = nullptr;
PFN_vkCmdSetDepthCompareOpEXT                                vkCmdSetDepthCompareOpEXT                                = nullptr;
PFN_vkCmdSetDepthBoundsTestEnableEXT                         vkCmdSetDepthBoundsTestEnableEXT                         = nullptr;
PFN_vkCmdSetStencilTestEnableEXT                             vkCmdSetStencilTestEnableEXT                             = nullptr;
PFN_vkCmdSetStencilOpEXT                                     vkCmdSetStencilOpEXT                                     = nullptr;
PFN_vkReleaseSwapchainImagesEXT                              vkReleaseSwapchainImagesEXT                              = nullptr;
PFN_vkGetGeneratedCommandsMemoryRequirementsNV               vkGetGeneratedCommandsMemoryRequirementsNV               = nullptr;
PFN_vkCmdPreprocessGeneratedCommandsNV                       vkCmdPreprocessGeneratedCommandsNV                       = nullptr;
PFN_vkCmdExecuteGeneratedCommandsNV                          vkCmdExecuteGeneratedCommandsNV                          = nullptr;
PFN_vkCmdBindPipelineShaderGroupNV                           vkCmdBindPipelineShaderGroupNV                           = nullptr;
PFN_vkCreateIndirectCommandsLayoutNV                         vkCreateIndirectCommandsLayoutNV                         = nullptr;
PFN_vkDestroyIndirectCommandsLayoutNV                        vkDestroyIndirectCommandsLayoutNV                        = nullptr;
PFN_vkCmdSetDepthBias2EXT                                    vkCmdSetDepthBias2EXT                                    = nullptr;
PFN_vkCreatePrivateDataSlotEXT                               vkCreatePrivateDataSlotEXT                               = nullptr;
PFN_vkDestroyPrivateDataSlotEXT                              vkDestroyPrivateDataSlotEXT                              = nullptr;
PFN_vkSetPrivateDataEXT                                      vkSetPrivateDataEXT                                      = nullptr;
PFN_vkGetPrivateDataEXT                                      vkGetPrivateDataEXT                                      = nullptr;
PFN_vkGetDescriptorSetLayoutSizeEXT                          vkGetDescriptorSetLayoutSizeEXT                          = nullptr;
PFN_vkGetDescriptorSetLayoutBindingOffsetEXT                 vkGetDescriptorSetLayoutBindingOffsetEXT                 = nullptr;
PFN_vkGetDescriptorEXT                                       vkGetDescriptorEXT                                       = nullptr;
PFN_vkCmdBindDescriptorBuffersEXT                            vkCmdBindDescriptorBuffersEXT                            = nullptr;
PFN_vkCmdSetDescriptorBufferOffsetsEXT                       vkCmdSetDescriptorBufferOffsetsEXT                       = nullptr;
PFN_vkCmdBindDescriptorBufferEmbeddedSamplersEXT             vkCmdBindDescriptorBufferEmbeddedSamplersEXT             = nullptr;
PFN_vkGetBufferOpaqueCaptureDescriptorDataEXT                vkGetBufferOpaqueCaptureDescriptorDataEXT                = nullptr;
PFN_vkGetImageOpaqueCaptureDescriptorDataEXT                 vkGetImageOpaqueCaptureDescriptorDataEXT                 = nullptr;
PFN_vkGetImageViewOpaqueCaptureDescriptorDataEXT             vkGetImageViewOpaqueCaptureDescriptorDataEXT             = nullptr;
PFN_vkGetSamplerOpaqueCaptureDescriptorDataEXT               vkGetSamplerOpaqueCaptureDescriptorDataEXT               = nullptr;
PFN_vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT = nullptr;
PFN_vkCmdSetFragmentShadingRateEnumNV                        vkCmdSetFragmentShadingRateEnumNV                        = nullptr;
PFN_vkGetImageSubresourceLayout2EXT                          vkGetImageSubresourceLayout2EXT                          = nullptr;
PFN_vkGetDeviceFaultInfoEXT                                  vkGetDeviceFaultInfoEXT                                  = nullptr;
PFN_vkCmdSetVertexInputEXT                                   vkCmdSetVertexInputEXT                                   = nullptr;
PFN_vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI          vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI          = nullptr;
PFN_vkCmdSubpassShadingHUAWEI                                vkCmdSubpassShadingHUAWEI                                = nullptr;
PFN_vkCmdBindInvocationMaskHUAWEI                            vkCmdBindInvocationMaskHUAWEI                            = nullptr;
PFN_vkGetMemoryRemoteAddressNV                               vkGetMemoryRemoteAddressNV                               = nullptr;
PFN_vkGetPipelinePropertiesEXT                               vkGetPipelinePropertiesEXT                               = nullptr;
PFN_vkCmdSetPatchControlPointsEXT                            vkCmdSetPatchControlPointsEXT                            = nullptr;
PFN_vkCmdSetRasterizerDiscardEnableEXT                       vkCmdSetRasterizerDiscardEnableEXT                       = nullptr;
PFN_vkCmdSetDepthBiasEnableEXT                               vkCmdSetDepthBiasEnableEXT                               = nullptr;
PFN_vkCmdSetLogicOpEXT                                       vkCmdSetLogicOpEXT                                       = nullptr;
PFN_vkCmdSetPrimitiveRestartEnableEXT                        vkCmdSetPrimitiveRestartEnableEXT                        = nullptr;
PFN_vkCmdSetColorWriteEnableEXT                              vkCmdSetColorWriteEnableEXT                              = nullptr;
PFN_vkCmdDrawMultiEXT                                        vkCmdDrawMultiEXT                                        = nullptr;
PFN_vkCmdDrawMultiIndexedEXT                                 vkCmdDrawMultiIndexedEXT                                 = nullptr;
PFN_vkCreateMicromapEXT                                      vkCreateMicromapEXT                                      = nullptr;
PFN_vkDestroyMicromapEXT                                     vkDestroyMicromapEXT                                     = nullptr;
PFN_vkCmdBuildMicromapsEXT                                   vkCmdBuildMicromapsEXT                                   = nullptr;
PFN_vkBuildMicromapsEXT                                      vkBuildMicromapsEXT                                      = nullptr;
PFN_vkCopyMicromapEXT                                        vkCopyMicromapEXT                                        = nullptr;
PFN_vkCopyMicromapToMemoryEXT                                vkCopyMicromapToMemoryEXT                                = nullptr;
PFN_vkCopyMemoryToMicromapEXT                                vkCopyMemoryToMicromapEXT                                = nullptr;
PFN_vkWriteMicromapsPropertiesEXT                            vkWriteMicromapsPropertiesEXT                            = nullptr;
PFN_vkCmdCopyMicromapEXT                                     vkCmdCopyMicromapEXT                                     = nullptr;
PFN_vkCmdCopyMicromapToMemoryEXT                             vkCmdCopyMicromapToMemoryEXT                             = nullptr;
PFN_vkCmdCopyMemoryToMicromapEXT                             vkCmdCopyMemoryToMicromapEXT                             = nullptr;
PFN_vkCmdWriteMicromapsPropertiesEXT                         vkCmdWriteMicromapsPropertiesEXT                         = nullptr;
PFN_vkGetDeviceMicromapCompatibilityEXT                      vkGetDeviceMicromapCompatibilityEXT                      = nullptr;
PFN_vkGetMicromapBuildSizesEXT                               vkGetMicromapBuildSizesEXT                               = nullptr;
PFN_vkCmdDrawClusterHUAWEI                                   vkCmdDrawClusterHUAWEI                                   = nullptr;
PFN_vkCmdDrawClusterIndirectHUAWEI                           vkCmdDrawClusterIndirectHUAWEI                           = nullptr;
PFN_vkSetDeviceMemoryPriorityEXT                             vkSetDeviceMemoryPriorityEXT                             = nullptr;
PFN_vkGetDescriptorSetLayoutHostMappingInfoVALVE             vkGetDescriptorSetLayoutHostMappingInfoVALVE             = nullptr;
PFN_vkGetDescriptorSetHostMappingVALVE                       vkGetDescriptorSetHostMappingVALVE                       = nullptr;
PFN_vkCmdCopyMemoryIndirectNV                                vkCmdCopyMemoryIndirectNV                                = nullptr;
PFN_vkCmdCopyMemoryToImageIndirectNV                         vkCmdCopyMemoryToImageIndirectNV                         = nullptr;
PFN_vkCmdDecompressMemoryNV                                  vkCmdDecompressMemoryNV                                  = nullptr;
PFN_vkCmdDecompressMemoryIndirectCountNV                     vkCmdDecompressMemoryIndirectCountNV                     = nullptr;
PFN_vkCmdSetTessellationDomainOriginEXT                      vkCmdSetTessellationDomainOriginEXT                      = nullptr;
PFN_vkCmdSetDepthClampEnableEXT                              vkCmdSetDepthClampEnableEXT                              = nullptr;
PFN_vkCmdSetPolygonModeEXT                                   vkCmdSetPolygonModeEXT                                   = nullptr;
PFN_vkCmdSetRasterizationSamplesEXT                          vkCmdSetRasterizationSamplesEXT                          = nullptr;
PFN_vkCmdSetSampleMaskEXT                                    vkCmdSetSampleMaskEXT                                    = nullptr;
PFN_vkCmdSetAlphaToCoverageEnableEXT                         vkCmdSetAlphaToCoverageEnableEXT                         = nullptr;
PFN_vkCmdSetAlphaToOneEnableEXT                              vkCmdSetAlphaToOneEnableEXT                              = nullptr;
PFN_vkCmdSetLogicOpEnableEXT                                 vkCmdSetLogicOpEnableEXT                                 = nullptr;
PFN_vkCmdSetColorBlendEnableEXT                              vkCmdSetColorBlendEnableEXT                              = nullptr;
PFN_vkCmdSetColorBlendEquationEXT                            vkCmdSetColorBlendEquationEXT                            = nullptr;
PFN_vkCmdSetColorWriteMaskEXT                                vkCmdSetColorWriteMaskEXT                                = nullptr;
PFN_vkCmdSetRasterizationStreamEXT                           vkCmdSetRasterizationStreamEXT                           = nullptr;
PFN_vkCmdSetConservativeRasterizationModeEXT                 vkCmdSetConservativeRasterizationModeEXT                 = nullptr;
PFN_vkCmdSetExtraPrimitiveOverestimationSizeEXT              vkCmdSetExtraPrimitiveOverestimationSizeEXT              = nullptr;
PFN_vkCmdSetDepthClipEnableEXT                               vkCmdSetDepthClipEnableEXT                               = nullptr;
PFN_vkCmdSetSampleLocationsEnableEXT                         vkCmdSetSampleLocationsEnableEXT                         = nullptr;
PFN_vkCmdSetColorBlendAdvancedEXT                            vkCmdSetColorBlendAdvancedEXT                            = nullptr;
PFN_vkCmdSetProvokingVertexModeEXT                           vkCmdSetProvokingVertexModeEXT                           = nullptr;
PFN_vkCmdSetLineRasterizationModeEXT                         vkCmdSetLineRasterizationModeEXT                         = nullptr;
PFN_vkCmdSetLineStippleEnableEXT                             vkCmdSetLineStippleEnableEXT                             = nullptr;
PFN_vkCmdSetDepthClipNegativeOneToOneEXT                     vkCmdSetDepthClipNegativeOneToOneEXT                     = nullptr;
PFN_vkCmdSetViewportWScalingEnableNV                         vkCmdSetViewportWScalingEnableNV                         = nullptr;
PFN_vkCmdSetViewportSwizzleNV                                vkCmdSetViewportSwizzleNV                                = nullptr;
PFN_vkCmdSetCoverageToColorEnableNV                          vkCmdSetCoverageToColorEnableNV                          = nullptr;
PFN_vkCmdSetCoverageToColorLocationNV                        vkCmdSetCoverageToColorLocationNV                        = nullptr;
PFN_vkCmdSetCoverageModulationModeNV                         vkCmdSetCoverageModulationModeNV                         = nullptr;
PFN_vkCmdSetCoverageModulationTableEnableNV                  vkCmdSetCoverageModulationTableEnableNV                  = nullptr;
PFN_vkCmdSetCoverageModulationTableNV                        vkCmdSetCoverageModulationTableNV                        = nullptr;
PFN_vkCmdSetShadingRateImageEnableNV                         vkCmdSetShadingRateImageEnableNV                         = nullptr;
PFN_vkCmdSetRepresentativeFragmentTestEnableNV               vkCmdSetRepresentativeFragmentTestEnableNV               = nullptr;
PFN_vkCmdSetCoverageReductionModeNV                          vkCmdSetCoverageReductionModeNV                          = nullptr;
PFN_vkGetShaderModuleIdentifierEXT                           vkGetShaderModuleIdentifierEXT                           = nullptr;
PFN_vkGetShaderModuleCreateInfoIdentifierEXT                 vkGetShaderModuleCreateInfoIdentifierEXT                 = nullptr;
PFN_vkCreateOpticalFlowSessionNV                             vkCreateOpticalFlowSessionNV                             = nullptr;
PFN_vkDestroyOpticalFlowSessionNV                            vkDestroyOpticalFlowSessionNV                            = nullptr;
PFN_vkBindOpticalFlowSessionImageNV                          vkBindOpticalFlowSessionImageNV                          = nullptr;
PFN_vkCmdOpticalFlowExecuteNV                                vkCmdOpticalFlowExecuteNV                                = nullptr;
PFN_vkCreateShadersEXT                                       vkCreateShadersEXT                                       = nullptr;
PFN_vkDestroyShaderEXT                                       vkDestroyShaderEXT                                       = nullptr;
PFN_vkGetShaderBinaryDataEXT                                 vkGetShaderBinaryDataEXT                                 = nullptr;
PFN_vkCmdBindShadersEXT                                      vkCmdBindShadersEXT                                      = nullptr;
PFN_vkGetFramebufferTilePropertiesQCOM                       vkGetFramebufferTilePropertiesQCOM                       = nullptr;
PFN_vkGetDynamicRenderingTilePropertiesQCOM                  vkGetDynamicRenderingTilePropertiesQCOM                  = nullptr;
PFN_vkCmdSetAttachmentFeedbackLoopEnableEXT                  vkCmdSetAttachmentFeedbackLoopEnableEXT                  = nullptr;
PFN_vkCreateAccelerationStructureKHR                         vkCreateAccelerationStructureKHR                         = nullptr;
PFN_vkDestroyAccelerationStructureKHR                        vkDestroyAccelerationStructureKHR                        = nullptr;
PFN_vkCmdBuildAccelerationStructuresKHR                      vkCmdBuildAccelerationStructuresKHR                      = nullptr;
PFN_vkCmdBuildAccelerationStructuresIndirectKHR              vkCmdBuildAccelerationStructuresIndirectKHR              = nullptr;
PFN_vkBuildAccelerationStructuresKHR                         vkBuildAccelerationStructuresKHR                         = nullptr;
PFN_vkCopyAccelerationStructureKHR                           vkCopyAccelerationStructureKHR                           = nullptr;
PFN_vkCopyAccelerationStructureToMemoryKHR                   vkCopyAccelerationStructureToMemoryKHR                   = nullptr;
PFN_vkCopyMemoryToAccelerationStructureKHR                   vkCopyMemoryToAccelerationStructureKHR                   = nullptr;
PFN_vkWriteAccelerationStructuresPropertiesKHR               vkWriteAccelerationStructuresPropertiesKHR               = nullptr;
PFN_vkCmdCopyAccelerationStructureKHR                        vkCmdCopyAccelerationStructureKHR                        = nullptr;
PFN_vkCmdCopyAccelerationStructureToMemoryKHR                vkCmdCopyAccelerationStructureToMemoryKHR                = nullptr;
PFN_vkCmdCopyMemoryToAccelerationStructureKHR                vkCmdCopyMemoryToAccelerationStructureKHR                = nullptr;
PFN_vkGetAccelerationStructureDeviceAddressKHR               vkGetAccelerationStructureDeviceAddressKHR               = nullptr;
PFN_vkCmdWriteAccelerationStructuresPropertiesKHR            vkCmdWriteAccelerationStructuresPropertiesKHR            = nullptr;
PFN_vkGetDeviceAccelerationStructureCompatibilityKHR         vkGetDeviceAccelerationStructureCompatibilityKHR         = nullptr;
PFN_vkGetAccelerationStructureBuildSizesKHR                  vkGetAccelerationStructureBuildSizesKHR                  = nullptr;
PFN_vkCmdTraceRaysKHR                                        vkCmdTraceRaysKHR                                        = nullptr;
PFN_vkCreateRayTracingPipelinesKHR                           vkCreateRayTracingPipelinesKHR                           = nullptr;
PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR        vkGetRayTracingCaptureReplayShaderGroupHandlesKHR        = nullptr;
PFN_vkCmdTraceRaysIndirectKHR                                vkCmdTraceRaysIndirectKHR                                = nullptr;
PFN_vkGetRayTracingShaderGroupStackSizeKHR                   vkGetRayTracingShaderGroupStackSizeKHR                   = nullptr;
PFN_vkCmdSetRayTracingPipelineStackSizeKHR                   vkCmdSetRayTracingPipelineStackSizeKHR                   = nullptr;
PFN_vkCmdDrawMeshTasksEXT                                    vkCmdDrawMeshTasksEXT                                    = nullptr;
PFN_vkCmdDrawMeshTasksIndirectEXT                            vkCmdDrawMeshTasksIndirectEXT                            = nullptr;
PFN_vkCmdDrawMeshTasksIndirectCountEXT                       vkCmdDrawMeshTasksIndirectCountEXT                       = nullptr;
#endif

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

	dlclose(vulkan_loader);

	return VK_TRUE;
}

// Assumes vkGetInstanceProcAddr and vkGetDeviceProcAddr are now loaded
VkBool32 vusym_init_vulkan_global_symbols()
{
	assert(vkGetInstanceProcAddr != nullptr && "vusym error vkGetInstanceProcAddr is nullptr.");

	VUSYM_LOAD_VULKAN_GLOBAL_SYMBOL(vkCreateInstance);
	VUSYM_LOAD_VULKAN_GLOBAL_SYMBOL(vkEnumerateInstanceExtensionProperties);
	VUSYM_LOAD_VULKAN_GLOBAL_SYMBOL(vkEnumerateInstanceLayerProperties);
	VUSYM_LOAD_VULKAN_GLOBAL_SYMBOL(vkEnumerateInstanceVersion);

	return VK_TRUE;
}

VkBool32 vusym_init_vulkan_instance_symbols(VkInstance a_instance, bool a_print_errors)
{
	assert(vkGetInstanceProcAddr != nullptr && "vusym error vkGetInstanceProcAddr is nullptr.");

	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkDestroyInstance);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkEnumeratePhysicalDevices);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceFeatures);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceFormatProperties);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceImageFormatProperties);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceProperties);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceQueueFamilyProperties);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceMemoryProperties);
	VUSYM_LOAD_VULKAN_INSTANCE_REAL_SYMBOL(vkCreateDevice);

	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkEnumerateDeviceExtensionProperties);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkEnumerateDeviceLayerProperties);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceSparseImageFormatProperties);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkEnumeratePhysicalDeviceGroups);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceFeatures2);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceProperties2);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceFormatProperties2);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceImageFormatProperties2);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceQueueFamilyProperties2);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceMemoryProperties2);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceSparseImageFormatProperties2);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceExternalBufferProperties);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceExternalFenceProperties);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceExternalSemaphoreProperties);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceToolProperties);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkDestroySurfaceKHR);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceSurfaceSupportKHR);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceSurfaceCapabilitiesKHR);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceSurfaceFormatsKHR);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceSurfacePresentModesKHR);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDevicePresentRectanglesKHR);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceDisplayPropertiesKHR);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceDisplayPlanePropertiesKHR);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetDisplayPlaneSupportedDisplaysKHR);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetDisplayModePropertiesKHR);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkCreateDisplayModeKHR);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetDisplayPlaneCapabilitiesKHR);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkCreateDisplayPlaneSurfaceKHR);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceVideoCapabilitiesKHR);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceVideoFormatPropertiesKHR);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceFeatures2KHR);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceProperties2KHR);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceFormatProperties2KHR);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceImageFormatProperties2KHR);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceQueueFamilyProperties2KHR);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceMemoryProperties2KHR);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceSparseImageFormatProperties2KHR);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkEnumeratePhysicalDeviceGroupsKHR);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceExternalBufferPropertiesKHR);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceExternalSemaphorePropertiesKHR);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceExternalFencePropertiesKHR);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceSurfaceCapabilities2KHR);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceSurfaceFormats2KHR);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceDisplayProperties2KHR);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceDisplayPlaneProperties2KHR);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetDisplayModeProperties2KHR);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetDisplayPlaneCapabilities2KHR);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceFragmentShadingRatesKHR);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkCreateDebugReportCallbackEXT);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkDestroyDebugReportCallbackEXT);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkDebugReportMessageEXT);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceExternalImageFormatPropertiesNV);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkReleaseDisplayEXT);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceSurfaceCapabilities2EXT);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkCreateDebugUtilsMessengerEXT);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkDestroyDebugUtilsMessengerEXT);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkSubmitDebugUtilsMessageEXT);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceMultisamplePropertiesEXT);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceCalibrateableTimeDomainsEXT);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceToolPropertiesEXT);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceCooperativeMatrixPropertiesNV);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkCreateHeadlessSurfaceEXT);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkAcquireDrmDisplayEXT);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetDrmDisplayEXT);
	VUSYM_LOAD_VULKAN_INSTANCE_SYMBOL(vkGetPhysicalDeviceOpticalFlowImageFormatsNV);

	return VK_TRUE;
}

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

	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkDestroyDevice);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetDeviceQueue);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkQueueSubmit);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkQueueWaitIdle);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkDeviceWaitIdle);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkAllocateMemory);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkFreeMemory);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkMapMemory);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkUnmapMemory);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkFlushMappedMemoryRanges);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkInvalidateMappedMemoryRanges);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetDeviceMemoryCommitment);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkBindBufferMemory);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkBindImageMemory);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetBufferMemoryRequirements);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetImageMemoryRequirements);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetImageSparseMemoryRequirements);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkQueueBindSparse);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCreateFence);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkDestroyFence);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkResetFences);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetFenceStatus);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkWaitForFences);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCreateSemaphore);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkDestroySemaphore);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCreateEvent);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkDestroyEvent);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetEventStatus);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkSetEvent);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkResetEvent);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCreateQueryPool);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkDestroyQueryPool);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetQueryPoolResults);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCreateBuffer);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkDestroyBuffer);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCreateBufferView);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkDestroyBufferView);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCreateImage);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkDestroyImage);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetImageSubresourceLayout);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCreateImageView);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkDestroyImageView);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCreateShaderModule);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkDestroyShaderModule);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCreatePipelineCache);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkDestroyPipelineCache);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetPipelineCacheData);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkMergePipelineCaches);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCreateGraphicsPipelines);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCreateComputePipelines);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkDestroyPipeline);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCreatePipelineLayout);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkDestroyPipelineLayout);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCreateSampler);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkDestroySampler);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCreateDescriptorSetLayout);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkDestroyDescriptorSetLayout);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCreateDescriptorPool);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkDestroyDescriptorPool);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkResetDescriptorPool);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkAllocateDescriptorSets);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkFreeDescriptorSets);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkUpdateDescriptorSets);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCreateFramebuffer);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkDestroyFramebuffer);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCreateRenderPass);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkDestroyRenderPass);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetRenderAreaGranularity);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCreateCommandPool);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkDestroyCommandPool);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkResetCommandPool);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkAllocateCommandBuffers);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkFreeCommandBuffers);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkBeginCommandBuffer);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkEndCommandBuffer);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkResetCommandBuffer);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdBindPipeline);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetViewport);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetScissor);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetLineWidth);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetDepthBias);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetBlendConstants);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetDepthBounds);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetStencilCompareMask);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetStencilWriteMask);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetStencilReference);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdBindDescriptorSets);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdBindIndexBuffer);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdBindVertexBuffers);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdDraw);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdDrawIndexed);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdDrawIndirect);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdDrawIndexedIndirect);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdDispatch);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdDispatchIndirect);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdCopyBuffer);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdCopyImage);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdBlitImage);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdCopyBufferToImage);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdCopyImageToBuffer);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdUpdateBuffer);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdFillBuffer);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdClearColorImage);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdClearDepthStencilImage);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdClearAttachments);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdResolveImage);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetEvent);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdResetEvent);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdWaitEvents);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdPipelineBarrier);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdBeginQuery);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdEndQuery);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdResetQueryPool);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdWriteTimestamp);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdCopyQueryPoolResults);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdPushConstants);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdBeginRenderPass);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdNextSubpass);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdEndRenderPass);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdExecuteCommands);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkBindBufferMemory2);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkBindImageMemory2);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetDeviceGroupPeerMemoryFeatures);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetDeviceMask);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdDispatchBase);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetImageMemoryRequirements2);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetBufferMemoryRequirements2);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetImageSparseMemoryRequirements2);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkTrimCommandPool);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetDeviceQueue2);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCreateSamplerYcbcrConversion);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkDestroySamplerYcbcrConversion);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCreateDescriptorUpdateTemplate);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkDestroyDescriptorUpdateTemplate);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkUpdateDescriptorSetWithTemplate);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetDescriptorSetLayoutSupport);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdDrawIndirectCount);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdDrawIndexedIndirectCount);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCreateRenderPass2);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdBeginRenderPass2);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdNextSubpass2);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdEndRenderPass2);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkResetQueryPool);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetSemaphoreCounterValue);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkWaitSemaphores);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkSignalSemaphore);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetBufferDeviceAddress);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetBufferOpaqueCaptureAddress);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetDeviceMemoryOpaqueCaptureAddress);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCreatePrivateDataSlot);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkDestroyPrivateDataSlot);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkSetPrivateData);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetPrivateData);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetEvent2);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdResetEvent2);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdWaitEvents2);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdPipelineBarrier2);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdWriteTimestamp2);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkQueueSubmit2);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdCopyBuffer2);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdCopyImage2);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdCopyBufferToImage2);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdCopyImageToBuffer2);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdBlitImage2);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdResolveImage2);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdBeginRendering);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdEndRendering);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetCullMode);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetFrontFace);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetPrimitiveTopology);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetViewportWithCount);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetScissorWithCount);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdBindVertexBuffers2);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetDepthTestEnable);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetDepthWriteEnable);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetDepthCompareOp);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetDepthBoundsTestEnable);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetStencilTestEnable);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetStencilOp);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetRasterizerDiscardEnable);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetDepthBiasEnable);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetPrimitiveRestartEnable);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetDeviceBufferMemoryRequirements);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetDeviceImageMemoryRequirements);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetDeviceImageSparseMemoryRequirements);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCreateSwapchainKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkDestroySwapchainKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetSwapchainImagesKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkAcquireNextImageKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkQueuePresentKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetDeviceGroupPresentCapabilitiesKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetDeviceGroupSurfacePresentModesKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkAcquireNextImage2KHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCreateSharedSwapchainsKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCreateVideoSessionKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkDestroyVideoSessionKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetVideoSessionMemoryRequirementsKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkBindVideoSessionMemoryKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCreateVideoSessionParametersKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkUpdateVideoSessionParametersKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkDestroyVideoSessionParametersKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdBeginVideoCodingKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdEndVideoCodingKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdControlVideoCodingKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdDecodeVideoKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdBeginRenderingKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdEndRenderingKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetDeviceGroupPeerMemoryFeaturesKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetDeviceMaskKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdDispatchBaseKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkTrimCommandPoolKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetMemoryFdKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetMemoryFdPropertiesKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkImportSemaphoreFdKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetSemaphoreFdKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdPushDescriptorSetKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdPushDescriptorSetWithTemplateKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCreateDescriptorUpdateTemplateKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkDestroyDescriptorUpdateTemplateKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkUpdateDescriptorSetWithTemplateKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCreateRenderPass2KHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdBeginRenderPass2KHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdNextSubpass2KHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdEndRenderPass2KHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetSwapchainStatusKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkImportFenceFdKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetFenceFdKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkAcquireProfilingLockKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkReleaseProfilingLockKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetImageMemoryRequirements2KHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetBufferMemoryRequirements2KHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetImageSparseMemoryRequirements2KHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCreateSamplerYcbcrConversionKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkDestroySamplerYcbcrConversionKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkBindBufferMemory2KHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkBindImageMemory2KHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetDescriptorSetLayoutSupportKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdDrawIndirectCountKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdDrawIndexedIndirectCountKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetSemaphoreCounterValueKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkWaitSemaphoresKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkSignalSemaphoreKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetFragmentShadingRateKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkWaitForPresentKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetBufferDeviceAddressKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetBufferOpaqueCaptureAddressKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetDeviceMemoryOpaqueCaptureAddressKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCreateDeferredOperationKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkDestroyDeferredOperationKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetDeferredOperationMaxConcurrencyKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetDeferredOperationResultKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkDeferredOperationJoinKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetPipelineExecutablePropertiesKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetPipelineExecutableStatisticsKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetPipelineExecutableInternalRepresentationsKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkMapMemory2KHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkUnmapMemory2KHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetEvent2KHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdResetEvent2KHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdWaitEvents2KHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdPipelineBarrier2KHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdWriteTimestamp2KHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkQueueSubmit2KHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdWriteBufferMarker2AMD);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetQueueCheckpointData2NV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdCopyBuffer2KHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdCopyImage2KHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdCopyBufferToImage2KHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdCopyImageToBuffer2KHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdBlitImage2KHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdResolveImage2KHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdTraceRaysIndirect2KHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetDeviceBufferMemoryRequirementsKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetDeviceImageMemoryRequirementsKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetDeviceImageSparseMemoryRequirementsKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkDebugMarkerSetObjectTagEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkDebugMarkerSetObjectNameEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdDebugMarkerBeginEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdDebugMarkerEndEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdDebugMarkerInsertEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdBindTransformFeedbackBuffersEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdBeginTransformFeedbackEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdEndTransformFeedbackEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdBeginQueryIndexedEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdEndQueryIndexedEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdDrawIndirectByteCountEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCreateCuModuleNVX);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCreateCuFunctionNVX);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkDestroyCuModuleNVX);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkDestroyCuFunctionNVX);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdCuLaunchKernelNVX);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetImageViewHandleNVX);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetImageViewAddressNVX);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdDrawIndirectCountAMD);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdDrawIndexedIndirectCountAMD);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetShaderInfoAMD);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdBeginConditionalRenderingEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdEndConditionalRenderingEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetViewportWScalingNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkDisplayPowerControlEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkRegisterDeviceEventEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkRegisterDisplayEventEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetSwapchainCounterEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetRefreshCycleDurationGOOGLE);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetPastPresentationTimingGOOGLE);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetDiscardRectangleEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetDiscardRectangleEnableEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetDiscardRectangleModeEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkSetHdrMetadataEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkSetDebugUtilsObjectNameEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkSetDebugUtilsObjectTagEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkQueueBeginDebugUtilsLabelEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkQueueEndDebugUtilsLabelEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkQueueInsertDebugUtilsLabelEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdBeginDebugUtilsLabelEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdEndDebugUtilsLabelEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdInsertDebugUtilsLabelEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetSampleLocationsEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetImageDrmFormatModifierPropertiesEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCreateValidationCacheEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkDestroyValidationCacheEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkMergeValidationCachesEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetValidationCacheDataEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdBindShadingRateImageNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetViewportShadingRatePaletteNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetCoarseSampleOrderNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCreateAccelerationStructureNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkDestroyAccelerationStructureNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetAccelerationStructureMemoryRequirementsNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkBindAccelerationStructureMemoryNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdBuildAccelerationStructureNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdCopyAccelerationStructureNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdTraceRaysNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCreateRayTracingPipelinesNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetRayTracingShaderGroupHandlesKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetRayTracingShaderGroupHandlesNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetAccelerationStructureHandleNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdWriteAccelerationStructuresPropertiesNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCompileDeferredNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetMemoryHostPointerPropertiesEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdWriteBufferMarkerAMD);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetCalibratedTimestampsEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdDrawMeshTasksNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdDrawMeshTasksIndirectNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdDrawMeshTasksIndirectCountNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetExclusiveScissorEnableNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetExclusiveScissorNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetCheckpointNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetQueueCheckpointDataNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkInitializePerformanceApiINTEL);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkUninitializePerformanceApiINTEL);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetPerformanceMarkerINTEL);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetPerformanceStreamMarkerINTEL);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetPerformanceOverrideINTEL);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkAcquirePerformanceConfigurationINTEL);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkReleasePerformanceConfigurationINTEL);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkQueueSetPerformanceConfigurationINTEL);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetPerformanceParameterINTEL);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkSetLocalDimmingAMD);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetBufferDeviceAddressEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetLineStippleEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkResetQueryPoolEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetCullModeEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetFrontFaceEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetPrimitiveTopologyEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetViewportWithCountEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetScissorWithCountEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdBindVertexBuffers2EXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetDepthTestEnableEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetDepthWriteEnableEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetDepthCompareOpEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetDepthBoundsTestEnableEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetStencilTestEnableEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetStencilOpEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkReleaseSwapchainImagesEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetGeneratedCommandsMemoryRequirementsNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdPreprocessGeneratedCommandsNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdExecuteGeneratedCommandsNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdBindPipelineShaderGroupNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCreateIndirectCommandsLayoutNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkDestroyIndirectCommandsLayoutNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetDepthBias2EXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCreatePrivateDataSlotEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkDestroyPrivateDataSlotEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkSetPrivateDataEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetPrivateDataEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetDescriptorSetLayoutSizeEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetDescriptorSetLayoutBindingOffsetEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetDescriptorEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdBindDescriptorBuffersEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetDescriptorBufferOffsetsEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdBindDescriptorBufferEmbeddedSamplersEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetBufferOpaqueCaptureDescriptorDataEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetImageOpaqueCaptureDescriptorDataEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetImageViewOpaqueCaptureDescriptorDataEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetSamplerOpaqueCaptureDescriptorDataEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetFragmentShadingRateEnumNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetImageSubresourceLayout2EXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetDeviceFaultInfoEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetVertexInputEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSubpassShadingHUAWEI);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdBindInvocationMaskHUAWEI);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetMemoryRemoteAddressNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetPipelinePropertiesEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetPatchControlPointsEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetRasterizerDiscardEnableEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetDepthBiasEnableEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetLogicOpEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetPrimitiveRestartEnableEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetColorWriteEnableEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdDrawMultiEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdDrawMultiIndexedEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCreateMicromapEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkDestroyMicromapEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdBuildMicromapsEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkBuildMicromapsEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCopyMicromapEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCopyMicromapToMemoryEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCopyMemoryToMicromapEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkWriteMicromapsPropertiesEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdCopyMicromapEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdCopyMicromapToMemoryEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdCopyMemoryToMicromapEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdWriteMicromapsPropertiesEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetDeviceMicromapCompatibilityEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetMicromapBuildSizesEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdDrawClusterHUAWEI);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdDrawClusterIndirectHUAWEI);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkSetDeviceMemoryPriorityEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetDescriptorSetLayoutHostMappingInfoVALVE);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetDescriptorSetHostMappingVALVE);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdCopyMemoryIndirectNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdCopyMemoryToImageIndirectNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdDecompressMemoryNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdDecompressMemoryIndirectCountNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetTessellationDomainOriginEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetDepthClampEnableEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetPolygonModeEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetRasterizationSamplesEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetSampleMaskEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetAlphaToCoverageEnableEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetAlphaToOneEnableEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetLogicOpEnableEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetColorBlendEnableEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetColorBlendEquationEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetColorWriteMaskEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetRasterizationStreamEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetConservativeRasterizationModeEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetExtraPrimitiveOverestimationSizeEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetDepthClipEnableEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetSampleLocationsEnableEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetColorBlendAdvancedEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetProvokingVertexModeEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetLineRasterizationModeEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetLineStippleEnableEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetDepthClipNegativeOneToOneEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetViewportWScalingEnableNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetViewportSwizzleNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetCoverageToColorEnableNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetCoverageToColorLocationNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetCoverageModulationModeNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetCoverageModulationTableEnableNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetCoverageModulationTableNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetShadingRateImageEnableNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetRepresentativeFragmentTestEnableNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetCoverageReductionModeNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetShaderModuleIdentifierEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetShaderModuleCreateInfoIdentifierEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCreateOpticalFlowSessionNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkDestroyOpticalFlowSessionNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkBindOpticalFlowSessionImageNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdOpticalFlowExecuteNV);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCreateShadersEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkDestroyShaderEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetShaderBinaryDataEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdBindShadersEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetFramebufferTilePropertiesQCOM);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetDynamicRenderingTilePropertiesQCOM);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetAttachmentFeedbackLoopEnableEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCreateAccelerationStructureKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkDestroyAccelerationStructureKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdBuildAccelerationStructuresKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdBuildAccelerationStructuresIndirectKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkBuildAccelerationStructuresKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCopyAccelerationStructureKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCopyAccelerationStructureToMemoryKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCopyMemoryToAccelerationStructureKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkWriteAccelerationStructuresPropertiesKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdCopyAccelerationStructureKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdCopyAccelerationStructureToMemoryKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdCopyMemoryToAccelerationStructureKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetAccelerationStructureDeviceAddressKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdWriteAccelerationStructuresPropertiesKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetDeviceAccelerationStructureCompatibilityKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetAccelerationStructureBuildSizesKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdTraceRaysKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCreateRayTracingPipelinesKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetRayTracingCaptureReplayShaderGroupHandlesKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdTraceRaysIndirectKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkGetRayTracingShaderGroupStackSizeKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdSetRayTracingPipelineStackSizeKHR);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdDrawMeshTasksEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdDrawMeshTasksIndirectEXT);
	VUSYM_LOAD_VULKAN_DEVICE_SYMBOL(vkCmdDrawMeshTasksIndirectCountEXT);

	return VK_TRUE;
}

VkResult VKAPI_CALL vkCreateInstance(const VkInstanceCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkInstance *pInstance)
{
	initialise();

	auto res = real_vkCreateInstance(pCreateInfo, pAllocator, pInstance);
	vusym_init_vulkan_instance_symbols(*pInstance);
	return res;
}

VkResult VKAPI_CALL vkCreateDevice(VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkDevice *pDevice)
{
	// Assumed to be initialised by now
	auto res = real_vkCreateDevice(physicalDevice, pCreateInfo, pAllocator, pDevice);

#if defined(VUSYM_SUPPORT_MULTIPLE_VULKAN_DEVICES)
	auto device_table = new PFNTable(*pDevice);
	*pDevice          = reinterpret_cast<VkDevice>(device_table);
#else
	vusym_init_vulkan_device_symbols(*pDevice);
#endif
	return res;
}

VkResult VKAPI_CALL vkEnumerateInstanceExtensionProperties(const char *pLayerName, uint32_t *pPropertyCount, VkExtensionProperties *pProperties)
{
	initialise();

	return real_vkEnumerateInstanceExtensionProperties(pLayerName, pPropertyCount, pProperties);
}

VkResult VKAPI_CALL vkEnumerateInstanceLayerProperties(uint32_t *pPropertyCount, VkLayerProperties *pProperties)
{
	initialise();

	return real_vkEnumerateInstanceLayerProperties(pPropertyCount, pProperties);
}

VkResult VKAPI_CALL vkEnumerateInstanceVersion(uint32_t *pApiVersion)
{
	initialise();

	return real_vkEnumerateInstanceVersion(pApiVersion);
}

#if defined(VUSYM_SUPPORT_MULTIPLE_VULKAN_DEVICES)

void VKAPI_CALL vkDestroyDevice(VkDevice device, const VkAllocationCallbacks *pAllocator)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	d->vkDestroyDevice(d->real_device, pAllocator);
	delete d;
}

void VKAPI_CALL vkGetDeviceQueue(VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue *pQueue)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetDeviceQueue(d->real_device, queueFamilyIndex, queueIndex, pQueue);
}

VkResult VKAPI_CALL vkDeviceWaitIdle(VkDevice device)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkDeviceWaitIdle(d->real_device);
}

VkResult VKAPI_CALL vkAllocateMemory(VkDevice device, const VkMemoryAllocateInfo *pAllocateInfo, const VkAllocationCallbacks *pAllocator, VkDeviceMemory *pMemory)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkAllocateMemory(d->real_device, pAllocateInfo, pAllocator, pMemory);
}

void VKAPI_CALL vkFreeMemory(VkDevice device, VkDeviceMemory memory, const VkAllocationCallbacks *pAllocator)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkFreeMemory(d->real_device, memory, pAllocator);
}

VkResult VKAPI_CALL vkMapMemory(VkDevice device, VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void **ppData)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkMapMemory(d->real_device, memory, offset, size, flags, ppData);
}

void VKAPI_CALL vkUnmapMemory(VkDevice device, VkDeviceMemory memory)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkUnmapMemory(d->real_device, memory);
}

VkResult VKAPI_CALL vkFlushMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange *pMemoryRanges)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkFlushMappedMemoryRanges(d->real_device, memoryRangeCount, pMemoryRanges);
}

VkResult VKAPI_CALL vkInvalidateMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange *pMemoryRanges)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkInvalidateMappedMemoryRanges(d->real_device, memoryRangeCount, pMemoryRanges);
}

void VKAPI_CALL vkGetDeviceMemoryCommitment(VkDevice device, VkDeviceMemory memory, VkDeviceSize *pCommittedMemoryInBytes)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetDeviceMemoryCommitment(d->real_device, memory, pCommittedMemoryInBytes);
}

VkResult VKAPI_CALL vkBindBufferMemory(VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkBindBufferMemory(d->real_device, buffer, memory, memoryOffset);
}

VkResult VKAPI_CALL vkBindImageMemory(VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkBindImageMemory(d->real_device, image, memory, memoryOffset);
}

void VKAPI_CALL vkGetBufferMemoryRequirements(VkDevice device, VkBuffer buffer, VkMemoryRequirements *pMemoryRequirements)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetBufferMemoryRequirements(d->real_device, buffer, pMemoryRequirements);
}

void VKAPI_CALL vkGetImageMemoryRequirements(VkDevice device, VkImage image, VkMemoryRequirements *pMemoryRequirements)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetImageMemoryRequirements(d->real_device, image, pMemoryRequirements);
}

void VKAPI_CALL vkGetImageSparseMemoryRequirements(VkDevice device, VkImage image, uint32_t *pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements *pSparseMemoryRequirements)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetImageSparseMemoryRequirements(d->real_device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}

VkResult VKAPI_CALL vkCreateFence(VkDevice device, const VkFenceCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkFence *pFence)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCreateFence(d->real_device, pCreateInfo, pAllocator, pFence);
}

void VKAPI_CALL vkDestroyFence(VkDevice device, VkFence fence, const VkAllocationCallbacks *pAllocator)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkDestroyFence(d->real_device, fence, pAllocator);
}

VkResult VKAPI_CALL vkResetFences(VkDevice device, uint32_t fenceCount, const VkFence *pFences)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkResetFences(d->real_device, fenceCount, pFences);
}

VkResult VKAPI_CALL vkGetFenceStatus(VkDevice device, VkFence fence)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetFenceStatus(d->real_device, fence);
}

VkResult VKAPI_CALL vkWaitForFences(VkDevice device, uint32_t fenceCount, const VkFence *pFences, VkBool32 waitAll, uint64_t timeout)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkWaitForFences(d->real_device, fenceCount, pFences, waitAll, timeout);
}

VkResult VKAPI_CALL vkCreateSemaphore(VkDevice device, const VkSemaphoreCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkSemaphore *pSemaphore)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCreateSemaphore(d->real_device, pCreateInfo, pAllocator, pSemaphore);
}

void VKAPI_CALL vkDestroySemaphore(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks *pAllocator)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkDestroySemaphore(d->real_device, semaphore, pAllocator);
}

VkResult VKAPI_CALL vkCreateEvent(VkDevice device, const VkEventCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkEvent *pEvent)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCreateEvent(d->real_device, pCreateInfo, pAllocator, pEvent);
}

void VKAPI_CALL vkDestroyEvent(VkDevice device, VkEvent event, const VkAllocationCallbacks *pAllocator)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkDestroyEvent(d->real_device, event, pAllocator);
}

VkResult VKAPI_CALL vkGetEventStatus(VkDevice device, VkEvent event)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetEventStatus(d->real_device, event);
}

VkResult VKAPI_CALL vkSetEvent(VkDevice device, VkEvent event)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkSetEvent(d->real_device, event);
}

VkResult VKAPI_CALL vkResetEvent(VkDevice device, VkEvent event)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkResetEvent(d->real_device, event);
}

VkResult VKAPI_CALL vkCreateQueryPool(VkDevice device, const VkQueryPoolCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkQueryPool *pQueryPool)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCreateQueryPool(d->real_device, pCreateInfo, pAllocator, pQueryPool);
}

void VKAPI_CALL vkDestroyQueryPool(VkDevice device, VkQueryPool queryPool, const VkAllocationCallbacks *pAllocator)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkDestroyQueryPool(d->real_device, queryPool, pAllocator);
}

VkResult VKAPI_CALL vkGetQueryPoolResults(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, size_t dataSize, void *pData, VkDeviceSize stride, VkQueryResultFlags flags)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetQueryPoolResults(d->real_device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);
}

VkResult VKAPI_CALL vkCreateBuffer(VkDevice device, const VkBufferCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkBuffer *pBuffer)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCreateBuffer(d->real_device, pCreateInfo, pAllocator, pBuffer);
}

void VKAPI_CALL vkDestroyBuffer(VkDevice device, VkBuffer buffer, const VkAllocationCallbacks *pAllocator)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkDestroyBuffer(d->real_device, buffer, pAllocator);
}

VkResult VKAPI_CALL vkCreateBufferView(VkDevice device, const VkBufferViewCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkBufferView *pView)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCreateBufferView(d->real_device, pCreateInfo, pAllocator, pView);
}

void VKAPI_CALL vkDestroyBufferView(VkDevice device, VkBufferView bufferView, const VkAllocationCallbacks *pAllocator)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkDestroyBufferView(d->real_device, bufferView, pAllocator);
}

VkResult VKAPI_CALL vkCreateImage(VkDevice device, const VkImageCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkImage *pImage)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCreateImage(d->real_device, pCreateInfo, pAllocator, pImage);
}

void VKAPI_CALL vkDestroyImage(VkDevice device, VkImage image, const VkAllocationCallbacks *pAllocator)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkDestroyImage(d->real_device, image, pAllocator);
}

void VKAPI_CALL vkGetImageSubresourceLayout(VkDevice device, VkImage image, const VkImageSubresource *pSubresource, VkSubresourceLayout *pLayout)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetImageSubresourceLayout(d->real_device, image, pSubresource, pLayout);
}

VkResult VKAPI_CALL vkCreateImageView(VkDevice device, const VkImageViewCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkImageView *pView)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCreateImageView(d->real_device, pCreateInfo, pAllocator, pView);
}

void VKAPI_CALL vkDestroyImageView(VkDevice device, VkImageView imageView, const VkAllocationCallbacks *pAllocator)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkDestroyImageView(d->real_device, imageView, pAllocator);
}

VkResult VKAPI_CALL vkCreateShaderModule(VkDevice device, const VkShaderModuleCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkShaderModule *pShaderModule)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCreateShaderModule(d->real_device, pCreateInfo, pAllocator, pShaderModule);
}

void VKAPI_CALL vkDestroyShaderModule(VkDevice device, VkShaderModule shaderModule, const VkAllocationCallbacks *pAllocator)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkDestroyShaderModule(d->real_device, shaderModule, pAllocator);
}

VkResult VKAPI_CALL vkCreatePipelineCache(VkDevice device, const VkPipelineCacheCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkPipelineCache *pPipelineCache)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCreatePipelineCache(d->real_device, pCreateInfo, pAllocator, pPipelineCache);
}

void VKAPI_CALL vkDestroyPipelineCache(VkDevice device, VkPipelineCache pipelineCache, const VkAllocationCallbacks *pAllocator)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkDestroyPipelineCache(d->real_device, pipelineCache, pAllocator);
}

VkResult VKAPI_CALL vkGetPipelineCacheData(VkDevice device, VkPipelineCache pipelineCache, size_t *pDataSize, void *pData)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetPipelineCacheData(d->real_device, pipelineCache, pDataSize, pData);
}

VkResult VKAPI_CALL vkMergePipelineCaches(VkDevice device, VkPipelineCache dstCache, uint32_t srcCacheCount, const VkPipelineCache *pSrcCaches)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkMergePipelineCaches(d->real_device, dstCache, srcCacheCount, pSrcCaches);
}

VkResult VKAPI_CALL vkCreateGraphicsPipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkGraphicsPipelineCreateInfo *pCreateInfos, const VkAllocationCallbacks *pAllocator, VkPipeline *pPipelines)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCreateGraphicsPipelines(d->real_device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
}

VkResult VKAPI_CALL vkCreateComputePipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkComputePipelineCreateInfo *pCreateInfos, const VkAllocationCallbacks *pAllocator, VkPipeline *pPipelines)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCreateComputePipelines(d->real_device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
}

void VKAPI_CALL vkDestroyPipeline(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks *pAllocator)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkDestroyPipeline(d->real_device, pipeline, pAllocator);
}

VkResult VKAPI_CALL vkCreatePipelineLayout(VkDevice device, const VkPipelineLayoutCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkPipelineLayout *pPipelineLayout)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCreatePipelineLayout(d->real_device, pCreateInfo, pAllocator, pPipelineLayout);
}

void VKAPI_CALL vkDestroyPipelineLayout(VkDevice device, VkPipelineLayout pipelineLayout, const VkAllocationCallbacks *pAllocator)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkDestroyPipelineLayout(d->real_device, pipelineLayout, pAllocator);
}

VkResult VKAPI_CALL vkCreateSampler(VkDevice device, const VkSamplerCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkSampler *pSampler)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCreateSampler(d->real_device, pCreateInfo, pAllocator, pSampler);
}

void VKAPI_CALL vkDestroySampler(VkDevice device, VkSampler sampler, const VkAllocationCallbacks *pAllocator)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkDestroySampler(d->real_device, sampler, pAllocator);
}

VkResult VKAPI_CALL vkCreateDescriptorSetLayout(VkDevice device, const VkDescriptorSetLayoutCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkDescriptorSetLayout *pSetLayout)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCreateDescriptorSetLayout(d->real_device, pCreateInfo, pAllocator, pSetLayout);
}

void VKAPI_CALL vkDestroyDescriptorSetLayout(VkDevice device, VkDescriptorSetLayout descriptorSetLayout, const VkAllocationCallbacks *pAllocator)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkDestroyDescriptorSetLayout(d->real_device, descriptorSetLayout, pAllocator);
}

VkResult VKAPI_CALL vkCreateDescriptorPool(VkDevice device, const VkDescriptorPoolCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkDescriptorPool *pDescriptorPool)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCreateDescriptorPool(d->real_device, pCreateInfo, pAllocator, pDescriptorPool);
}

void VKAPI_CALL vkDestroyDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool, const VkAllocationCallbacks *pAllocator)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkDestroyDescriptorPool(d->real_device, descriptorPool, pAllocator);
}

VkResult VKAPI_CALL vkResetDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool, VkDescriptorPoolResetFlags flags)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkResetDescriptorPool(d->real_device, descriptorPool, flags);
}

VkResult VKAPI_CALL vkAllocateDescriptorSets(VkDevice device, const VkDescriptorSetAllocateInfo *pAllocateInfo, VkDescriptorSet *pDescriptorSets)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkAllocateDescriptorSets(d->real_device, pAllocateInfo, pDescriptorSets);
}

VkResult VKAPI_CALL vkFreeDescriptorSets(VkDevice device, VkDescriptorPool descriptorPool, uint32_t descriptorSetCount, const VkDescriptorSet *pDescriptorSets)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkFreeDescriptorSets(d->real_device, descriptorPool, descriptorSetCount, pDescriptorSets);
}

void VKAPI_CALL vkUpdateDescriptorSets(VkDevice device, uint32_t descriptorWriteCount, const VkWriteDescriptorSet *pDescriptorWrites, uint32_t descriptorCopyCount, const VkCopyDescriptorSet *pDescriptorCopies)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkUpdateDescriptorSets(d->real_device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
}

VkResult VKAPI_CALL vkCreateFramebuffer(VkDevice device, const VkFramebufferCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkFramebuffer *pFramebuffer)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCreateFramebuffer(d->real_device, pCreateInfo, pAllocator, pFramebuffer);
}

void VKAPI_CALL vkDestroyFramebuffer(VkDevice device, VkFramebuffer framebuffer, const VkAllocationCallbacks *pAllocator)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkDestroyFramebuffer(d->real_device, framebuffer, pAllocator);
}

VkResult VKAPI_CALL vkCreateRenderPass(VkDevice device, const VkRenderPassCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkRenderPass *pRenderPass)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCreateRenderPass(d->real_device, pCreateInfo, pAllocator, pRenderPass);
}

void VKAPI_CALL vkDestroyRenderPass(VkDevice device, VkRenderPass renderPass, const VkAllocationCallbacks *pAllocator)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkDestroyRenderPass(d->real_device, renderPass, pAllocator);
}

void VKAPI_CALL vkGetRenderAreaGranularity(VkDevice device, VkRenderPass renderPass, VkExtent2D *pGranularity)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetRenderAreaGranularity(d->real_device, renderPass, pGranularity);
}

VkResult VKAPI_CALL vkCreateCommandPool(VkDevice device, const VkCommandPoolCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkCommandPool *pCommandPool)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCreateCommandPool(d->real_device, pCreateInfo, pAllocator, pCommandPool);
}

void VKAPI_CALL vkDestroyCommandPool(VkDevice device, VkCommandPool commandPool, const VkAllocationCallbacks *pAllocator)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkDestroyCommandPool(d->real_device, commandPool, pAllocator);
}

VkResult VKAPI_CALL vkResetCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkResetCommandPool(d->real_device, commandPool, flags);
}

VkResult VKAPI_CALL vkAllocateCommandBuffers(VkDevice device, const VkCommandBufferAllocateInfo *pAllocateInfo, VkCommandBuffer *pCommandBuffers)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkAllocateCommandBuffers(d->real_device, pAllocateInfo, pCommandBuffers);
}

void VKAPI_CALL vkFreeCommandBuffers(VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount, const VkCommandBuffer *pCommandBuffers)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkFreeCommandBuffers(d->real_device, commandPool, commandBufferCount, pCommandBuffers);
}

VkResult VKAPI_CALL vkBindBufferMemory2(VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo *pBindInfos)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkBindBufferMemory2(d->real_device, bindInfoCount, pBindInfos);
}

VkResult VKAPI_CALL vkBindImageMemory2(VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo *pBindInfos)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkBindImageMemory2(d->real_device, bindInfoCount, pBindInfos);
}

void VKAPI_CALL vkGetDeviceGroupPeerMemoryFeatures(VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags *pPeerMemoryFeatures)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetDeviceGroupPeerMemoryFeatures(d->real_device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
}

void VKAPI_CALL vkGetImageMemoryRequirements2(VkDevice device, const VkImageMemoryRequirementsInfo2 *pInfo, VkMemoryRequirements2 *pMemoryRequirements)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetImageMemoryRequirements2(d->real_device, pInfo, pMemoryRequirements);
}

void VKAPI_CALL vkGetBufferMemoryRequirements2(VkDevice device, const VkBufferMemoryRequirementsInfo2 *pInfo, VkMemoryRequirements2 *pMemoryRequirements)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetBufferMemoryRequirements2(d->real_device, pInfo, pMemoryRequirements);
}

void VKAPI_CALL vkGetImageSparseMemoryRequirements2(VkDevice device, const VkImageSparseMemoryRequirementsInfo2 *pInfo, uint32_t *pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2 *pSparseMemoryRequirements)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetImageSparseMemoryRequirements2(d->real_device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}

void VKAPI_CALL vkTrimCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkTrimCommandPool(d->real_device, commandPool, flags);
}

void VKAPI_CALL vkGetDeviceQueue2(VkDevice device, const VkDeviceQueueInfo2 *pQueueInfo, VkQueue *pQueue)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetDeviceQueue2(d->real_device, pQueueInfo, pQueue);
}

VkResult VKAPI_CALL vkCreateSamplerYcbcrConversion(VkDevice device, const VkSamplerYcbcrConversionCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkSamplerYcbcrConversion *pYcbcrConversion)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCreateSamplerYcbcrConversion(d->real_device, pCreateInfo, pAllocator, pYcbcrConversion);
}

void VKAPI_CALL vkDestroySamplerYcbcrConversion(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks *pAllocator)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkDestroySamplerYcbcrConversion(d->real_device, ycbcrConversion, pAllocator);
}

VkResult VKAPI_CALL vkCreateDescriptorUpdateTemplate(VkDevice device, const VkDescriptorUpdateTemplateCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkDescriptorUpdateTemplate *pDescriptorUpdateTemplate)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCreateDescriptorUpdateTemplate(d->real_device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
}

void VKAPI_CALL vkDestroyDescriptorUpdateTemplate(VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks *pAllocator)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkDestroyDescriptorUpdateTemplate(d->real_device, descriptorUpdateTemplate, pAllocator);
}

void VKAPI_CALL vkUpdateDescriptorSetWithTemplate(VkDevice device, VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void *pData)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkUpdateDescriptorSetWithTemplate(d->real_device, descriptorSet, descriptorUpdateTemplate, pData);
}

void VKAPI_CALL vkGetDescriptorSetLayoutSupport(VkDevice device, const VkDescriptorSetLayoutCreateInfo *pCreateInfo, VkDescriptorSetLayoutSupport *pSupport)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetDescriptorSetLayoutSupport(d->real_device, pCreateInfo, pSupport);
}

VkResult VKAPI_CALL vkCreateRenderPass2(VkDevice device, const VkRenderPassCreateInfo2 *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkRenderPass *pRenderPass)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCreateRenderPass2(d->real_device, pCreateInfo, pAllocator, pRenderPass);
}

void VKAPI_CALL vkResetQueryPool(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkResetQueryPool(d->real_device, queryPool, firstQuery, queryCount);
}

VkResult VKAPI_CALL vkGetSemaphoreCounterValue(VkDevice device, VkSemaphore semaphore, uint64_t *pValue)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetSemaphoreCounterValue(d->real_device, semaphore, pValue);
}

VkResult VKAPI_CALL vkWaitSemaphores(VkDevice device, const VkSemaphoreWaitInfo *pWaitInfo, uint64_t timeout)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkWaitSemaphores(d->real_device, pWaitInfo, timeout);
}

VkResult VKAPI_CALL vkSignalSemaphore(VkDevice device, const VkSemaphoreSignalInfo *pSignalInfo)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkSignalSemaphore(d->real_device, pSignalInfo);
}

VkDeviceAddress VKAPI_CALL vkGetBufferDeviceAddress(VkDevice device, const VkBufferDeviceAddressInfo *pInfo)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetBufferDeviceAddress(d->real_device, pInfo);
}

uint64_t VKAPI_CALL vkGetBufferOpaqueCaptureAddress(VkDevice device, const VkBufferDeviceAddressInfo *pInfo)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetBufferOpaqueCaptureAddress(d->real_device, pInfo);
}

uint64_t VKAPI_CALL vkGetDeviceMemoryOpaqueCaptureAddress(VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo *pInfo)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetDeviceMemoryOpaqueCaptureAddress(d->real_device, pInfo);
}

VkResult VKAPI_CALL vkCreatePrivateDataSlot(VkDevice device, const VkPrivateDataSlotCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkPrivateDataSlot *pPrivateDataSlot)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCreatePrivateDataSlot(d->real_device, pCreateInfo, pAllocator, pPrivateDataSlot);
}

void VKAPI_CALL vkDestroyPrivateDataSlot(VkDevice device, VkPrivateDataSlot privateDataSlot, const VkAllocationCallbacks *pAllocator)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkDestroyPrivateDataSlot(d->real_device, privateDataSlot, pAllocator);
}

VkResult VKAPI_CALL vkSetPrivateData(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t data)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkSetPrivateData(d->real_device, objectType, objectHandle, privateDataSlot, data);
}

void VKAPI_CALL vkGetPrivateData(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t *pData)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetPrivateData(d->real_device, objectType, objectHandle, privateDataSlot, pData);
}

void VKAPI_CALL vkGetDeviceBufferMemoryRequirements(VkDevice device, const VkDeviceBufferMemoryRequirements *pInfo, VkMemoryRequirements2 *pMemoryRequirements)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetDeviceBufferMemoryRequirements(d->real_device, pInfo, pMemoryRequirements);
}

void VKAPI_CALL vkGetDeviceImageMemoryRequirements(VkDevice device, const VkDeviceImageMemoryRequirements *pInfo, VkMemoryRequirements2 *pMemoryRequirements)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetDeviceImageMemoryRequirements(d->real_device, pInfo, pMemoryRequirements);
}

void VKAPI_CALL vkGetDeviceImageSparseMemoryRequirements(VkDevice device, const VkDeviceImageMemoryRequirements *pInfo, uint32_t *pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2 *pSparseMemoryRequirements)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetDeviceImageSparseMemoryRequirements(d->real_device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}

VkResult VKAPI_CALL vkCreateSwapchainKHR(VkDevice device, const VkSwapchainCreateInfoKHR *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkSwapchainKHR *pSwapchain)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCreateSwapchainKHR(d->real_device, pCreateInfo, pAllocator, pSwapchain);
}

void VKAPI_CALL vkDestroySwapchainKHR(VkDevice device, VkSwapchainKHR swapchain, const VkAllocationCallbacks *pAllocator)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkDestroySwapchainKHR(d->real_device, swapchain, pAllocator);
}

VkResult VKAPI_CALL vkGetSwapchainImagesKHR(VkDevice device, VkSwapchainKHR swapchain, uint32_t *pSwapchainImageCount, VkImage *pSwapchainImages)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetSwapchainImagesKHR(d->real_device, swapchain, pSwapchainImageCount, pSwapchainImages);
}

VkResult VKAPI_CALL vkAcquireNextImageKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore, VkFence fence, uint32_t *pImageIndex)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkAcquireNextImageKHR(d->real_device, swapchain, timeout, semaphore, fence, pImageIndex);
}

VkResult VKAPI_CALL vkGetDeviceGroupPresentCapabilitiesKHR(VkDevice device, VkDeviceGroupPresentCapabilitiesKHR *pDeviceGroupPresentCapabilities)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetDeviceGroupPresentCapabilitiesKHR(d->real_device, pDeviceGroupPresentCapabilities);
}

VkResult VKAPI_CALL vkGetDeviceGroupSurfacePresentModesKHR(VkDevice device, VkSurfaceKHR surface, VkDeviceGroupPresentModeFlagsKHR *pModes)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetDeviceGroupSurfacePresentModesKHR(d->real_device, surface, pModes);
}

VkResult VKAPI_CALL vkAcquireNextImage2KHR(VkDevice device, const VkAcquireNextImageInfoKHR *pAcquireInfo, uint32_t *pImageIndex)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkAcquireNextImage2KHR(d->real_device, pAcquireInfo, pImageIndex);
}

VkResult VKAPI_CALL vkCreateSharedSwapchainsKHR(VkDevice device, uint32_t swapchainCount, const VkSwapchainCreateInfoKHR *pCreateInfos, const VkAllocationCallbacks *pAllocator, VkSwapchainKHR *pSwapchains)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCreateSharedSwapchainsKHR(d->real_device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);
}

VkResult VKAPI_CALL vkCreateVideoSessionKHR(VkDevice device, const VkVideoSessionCreateInfoKHR *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkVideoSessionKHR *pVideoSession)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCreateVideoSessionKHR(d->real_device, pCreateInfo, pAllocator, pVideoSession);
}

void VKAPI_CALL vkDestroyVideoSessionKHR(VkDevice device, VkVideoSessionKHR videoSession, const VkAllocationCallbacks *pAllocator)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkDestroyVideoSessionKHR(d->real_device, videoSession, pAllocator);
}

VkResult VKAPI_CALL vkGetVideoSessionMemoryRequirementsKHR(VkDevice device, VkVideoSessionKHR videoSession, uint32_t *pMemoryRequirementsCount, VkVideoSessionMemoryRequirementsKHR *pMemoryRequirements)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetVideoSessionMemoryRequirementsKHR(d->real_device, videoSession, pMemoryRequirementsCount, pMemoryRequirements);
}

VkResult VKAPI_CALL vkBindVideoSessionMemoryKHR(VkDevice device, VkVideoSessionKHR videoSession, uint32_t bindSessionMemoryInfoCount, const VkBindVideoSessionMemoryInfoKHR *pBindSessionMemoryInfos)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkBindVideoSessionMemoryKHR(d->real_device, videoSession, bindSessionMemoryInfoCount, pBindSessionMemoryInfos);
}

VkResult VKAPI_CALL vkCreateVideoSessionParametersKHR(VkDevice device, const VkVideoSessionParametersCreateInfoKHR *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkVideoSessionParametersKHR *pVideoSessionParameters)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCreateVideoSessionParametersKHR(d->real_device, pCreateInfo, pAllocator, pVideoSessionParameters);
}

VkResult VKAPI_CALL vkUpdateVideoSessionParametersKHR(VkDevice device, VkVideoSessionParametersKHR videoSessionParameters, const VkVideoSessionParametersUpdateInfoKHR *pUpdateInfo)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkUpdateVideoSessionParametersKHR(d->real_device, videoSessionParameters, pUpdateInfo);
}

void VKAPI_CALL vkDestroyVideoSessionParametersKHR(VkDevice device, VkVideoSessionParametersKHR videoSessionParameters, const VkAllocationCallbacks *pAllocator)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkDestroyVideoSessionParametersKHR(d->real_device, videoSessionParameters, pAllocator);
}

void VKAPI_CALL vkGetDeviceGroupPeerMemoryFeaturesKHR(VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags *pPeerMemoryFeatures)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetDeviceGroupPeerMemoryFeaturesKHR(d->real_device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
}

void VKAPI_CALL vkTrimCommandPoolKHR(VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkTrimCommandPoolKHR(d->real_device, commandPool, flags);
}

VkResult VKAPI_CALL vkGetMemoryFdKHR(VkDevice device, const VkMemoryGetFdInfoKHR *pGetFdInfo, int *pFd)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetMemoryFdKHR(d->real_device, pGetFdInfo, pFd);
}

VkResult VKAPI_CALL vkGetMemoryFdPropertiesKHR(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, int fd, VkMemoryFdPropertiesKHR *pMemoryFdProperties)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetMemoryFdPropertiesKHR(d->real_device, handleType, fd, pMemoryFdProperties);
}

VkResult VKAPI_CALL vkImportSemaphoreFdKHR(VkDevice device, const VkImportSemaphoreFdInfoKHR *pImportSemaphoreFdInfo)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkImportSemaphoreFdKHR(d->real_device, pImportSemaphoreFdInfo);
}

VkResult VKAPI_CALL vkGetSemaphoreFdKHR(VkDevice device, const VkSemaphoreGetFdInfoKHR *pGetFdInfo, int *pFd)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetSemaphoreFdKHR(d->real_device, pGetFdInfo, pFd);
}

VkResult VKAPI_CALL vkCreateDescriptorUpdateTemplateKHR(VkDevice device, const VkDescriptorUpdateTemplateCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkDescriptorUpdateTemplate *pDescriptorUpdateTemplate)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCreateDescriptorUpdateTemplateKHR(d->real_device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
}

void VKAPI_CALL vkDestroyDescriptorUpdateTemplateKHR(VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks *pAllocator)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkDestroyDescriptorUpdateTemplateKHR(d->real_device, descriptorUpdateTemplate, pAllocator);
}

void VKAPI_CALL vkUpdateDescriptorSetWithTemplateKHR(VkDevice device, VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void *pData)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkUpdateDescriptorSetWithTemplateKHR(d->real_device, descriptorSet, descriptorUpdateTemplate, pData);
}

VkResult VKAPI_CALL vkCreateRenderPass2KHR(VkDevice device, const VkRenderPassCreateInfo2 *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkRenderPass *pRenderPass)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCreateRenderPass2KHR(d->real_device, pCreateInfo, pAllocator, pRenderPass);
}

VkResult VKAPI_CALL vkGetSwapchainStatusKHR(VkDevice device, VkSwapchainKHR swapchain)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetSwapchainStatusKHR(d->real_device, swapchain);
}

VkResult VKAPI_CALL vkImportFenceFdKHR(VkDevice device, const VkImportFenceFdInfoKHR *pImportFenceFdInfo)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkImportFenceFdKHR(d->real_device, pImportFenceFdInfo);
}

VkResult VKAPI_CALL vkGetFenceFdKHR(VkDevice device, const VkFenceGetFdInfoKHR *pGetFdInfo, int *pFd)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetFenceFdKHR(d->real_device, pGetFdInfo, pFd);
}

VkResult VKAPI_CALL vkAcquireProfilingLockKHR(VkDevice device, const VkAcquireProfilingLockInfoKHR *pInfo)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkAcquireProfilingLockKHR(d->real_device, pInfo);
}

void VKAPI_CALL vkReleaseProfilingLockKHR(VkDevice device)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkReleaseProfilingLockKHR(d->real_device);
}

void VKAPI_CALL vkGetImageMemoryRequirements2KHR(VkDevice device, const VkImageMemoryRequirementsInfo2 *pInfo, VkMemoryRequirements2 *pMemoryRequirements)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetImageMemoryRequirements2KHR(d->real_device, pInfo, pMemoryRequirements);
}

void VKAPI_CALL vkGetBufferMemoryRequirements2KHR(VkDevice device, const VkBufferMemoryRequirementsInfo2 *pInfo, VkMemoryRequirements2 *pMemoryRequirements)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetBufferMemoryRequirements2KHR(d->real_device, pInfo, pMemoryRequirements);
}

void VKAPI_CALL vkGetImageSparseMemoryRequirements2KHR(VkDevice device, const VkImageSparseMemoryRequirementsInfo2 *pInfo, uint32_t *pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2 *pSparseMemoryRequirements)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetImageSparseMemoryRequirements2KHR(d->real_device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}

VkResult VKAPI_CALL vkCreateSamplerYcbcrConversionKHR(VkDevice device, const VkSamplerYcbcrConversionCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkSamplerYcbcrConversion *pYcbcrConversion)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCreateSamplerYcbcrConversionKHR(d->real_device, pCreateInfo, pAllocator, pYcbcrConversion);
}

void VKAPI_CALL vkDestroySamplerYcbcrConversionKHR(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks *pAllocator)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkDestroySamplerYcbcrConversionKHR(d->real_device, ycbcrConversion, pAllocator);
}

VkResult VKAPI_CALL vkBindBufferMemory2KHR(VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo *pBindInfos)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkBindBufferMemory2KHR(d->real_device, bindInfoCount, pBindInfos);
}

VkResult VKAPI_CALL vkBindImageMemory2KHR(VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo *pBindInfos)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkBindImageMemory2KHR(d->real_device, bindInfoCount, pBindInfos);
}

void VKAPI_CALL vkGetDescriptorSetLayoutSupportKHR(VkDevice device, const VkDescriptorSetLayoutCreateInfo *pCreateInfo, VkDescriptorSetLayoutSupport *pSupport)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetDescriptorSetLayoutSupportKHR(d->real_device, pCreateInfo, pSupport);
}

VkResult VKAPI_CALL vkGetSemaphoreCounterValueKHR(VkDevice device, VkSemaphore semaphore, uint64_t *pValue)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetSemaphoreCounterValueKHR(d->real_device, semaphore, pValue);
}

VkResult VKAPI_CALL vkWaitSemaphoresKHR(VkDevice device, const VkSemaphoreWaitInfo *pWaitInfo, uint64_t timeout)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkWaitSemaphoresKHR(d->real_device, pWaitInfo, timeout);
}

VkResult VKAPI_CALL vkSignalSemaphoreKHR(VkDevice device, const VkSemaphoreSignalInfo *pSignalInfo)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkSignalSemaphoreKHR(d->real_device, pSignalInfo);
}

VkResult VKAPI_CALL vkWaitForPresentKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t presentId, uint64_t timeout)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkWaitForPresentKHR(d->real_device, swapchain, presentId, timeout);
}

VkDeviceAddress VKAPI_CALL vkGetBufferDeviceAddressKHR(VkDevice device, const VkBufferDeviceAddressInfo *pInfo)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetBufferDeviceAddressKHR(d->real_device, pInfo);
}

uint64_t VKAPI_CALL vkGetBufferOpaqueCaptureAddressKHR(VkDevice device, const VkBufferDeviceAddressInfo *pInfo)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetBufferOpaqueCaptureAddressKHR(d->real_device, pInfo);
}

uint64_t VKAPI_CALL vkGetDeviceMemoryOpaqueCaptureAddressKHR(VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo *pInfo)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetDeviceMemoryOpaqueCaptureAddressKHR(d->real_device, pInfo);
}

VkResult VKAPI_CALL vkCreateDeferredOperationKHR(VkDevice device, const VkAllocationCallbacks *pAllocator, VkDeferredOperationKHR *pDeferredOperation)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCreateDeferredOperationKHR(d->real_device, pAllocator, pDeferredOperation);
}

void VKAPI_CALL vkDestroyDeferredOperationKHR(VkDevice device, VkDeferredOperationKHR operation, const VkAllocationCallbacks *pAllocator)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkDestroyDeferredOperationKHR(d->real_device, operation, pAllocator);
}

uint32_t VKAPI_CALL vkGetDeferredOperationMaxConcurrencyKHR(VkDevice device, VkDeferredOperationKHR operation)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetDeferredOperationMaxConcurrencyKHR(d->real_device, operation);
}

VkResult VKAPI_CALL vkGetDeferredOperationResultKHR(VkDevice device, VkDeferredOperationKHR operation)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetDeferredOperationResultKHR(d->real_device, operation);
}

VkResult VKAPI_CALL vkDeferredOperationJoinKHR(VkDevice device, VkDeferredOperationKHR operation)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkDeferredOperationJoinKHR(d->real_device, operation);
}

VkResult VKAPI_CALL vkGetPipelineExecutablePropertiesKHR(VkDevice device, const VkPipelineInfoKHR *pPipelineInfo, uint32_t *pExecutableCount, VkPipelineExecutablePropertiesKHR *pProperties)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetPipelineExecutablePropertiesKHR(d->real_device, pPipelineInfo, pExecutableCount, pProperties);
}

VkResult VKAPI_CALL vkGetPipelineExecutableStatisticsKHR(VkDevice device, const VkPipelineExecutableInfoKHR *pExecutableInfo, uint32_t *pStatisticCount, VkPipelineExecutableStatisticKHR *pStatistics)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetPipelineExecutableStatisticsKHR(d->real_device, pExecutableInfo, pStatisticCount, pStatistics);
}

VkResult VKAPI_CALL vkGetPipelineExecutableInternalRepresentationsKHR(VkDevice device, const VkPipelineExecutableInfoKHR *pExecutableInfo, uint32_t *pInternalRepresentationCount, VkPipelineExecutableInternalRepresentationKHR *pInternalRepresentations)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetPipelineExecutableInternalRepresentationsKHR(d->real_device, pExecutableInfo, pInternalRepresentationCount, pInternalRepresentations);
}

VkResult VKAPI_CALL vkMapMemory2KHR(VkDevice device, const VkMemoryMapInfoKHR *pMemoryMapInfo, void **ppData)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkMapMemory2KHR(d->real_device, pMemoryMapInfo, ppData);
}

VkResult VKAPI_CALL vkUnmapMemory2KHR(VkDevice device, const VkMemoryUnmapInfoKHR *pMemoryUnmapInfo)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkUnmapMemory2KHR(d->real_device, pMemoryUnmapInfo);
}

void VKAPI_CALL vkGetDeviceBufferMemoryRequirementsKHR(VkDevice device, const VkDeviceBufferMemoryRequirements *pInfo, VkMemoryRequirements2 *pMemoryRequirements)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetDeviceBufferMemoryRequirementsKHR(d->real_device, pInfo, pMemoryRequirements);
}

void VKAPI_CALL vkGetDeviceImageMemoryRequirementsKHR(VkDevice device, const VkDeviceImageMemoryRequirements *pInfo, VkMemoryRequirements2 *pMemoryRequirements)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetDeviceImageMemoryRequirementsKHR(d->real_device, pInfo, pMemoryRequirements);
}

void VKAPI_CALL vkGetDeviceImageSparseMemoryRequirementsKHR(VkDevice device, const VkDeviceImageMemoryRequirements *pInfo, uint32_t *pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2 *pSparseMemoryRequirements)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetDeviceImageSparseMemoryRequirementsKHR(d->real_device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}

VkResult VKAPI_CALL vkDebugMarkerSetObjectTagEXT(VkDevice device, const VkDebugMarkerObjectTagInfoEXT *pTagInfo)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkDebugMarkerSetObjectTagEXT(d->real_device, pTagInfo);
}

VkResult VKAPI_CALL vkDebugMarkerSetObjectNameEXT(VkDevice device, const VkDebugMarkerObjectNameInfoEXT *pNameInfo)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkDebugMarkerSetObjectNameEXT(d->real_device, pNameInfo);
}

VkResult VKAPI_CALL vkCreateCuModuleNVX(VkDevice device, const VkCuModuleCreateInfoNVX *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkCuModuleNVX *pModule)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCreateCuModuleNVX(d->real_device, pCreateInfo, pAllocator, pModule);
}

VkResult VKAPI_CALL vkCreateCuFunctionNVX(VkDevice device, const VkCuFunctionCreateInfoNVX *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkCuFunctionNVX *pFunction)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCreateCuFunctionNVX(d->real_device, pCreateInfo, pAllocator, pFunction);
}

void VKAPI_CALL vkDestroyCuModuleNVX(VkDevice device, VkCuModuleNVX module, const VkAllocationCallbacks *pAllocator)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkDestroyCuModuleNVX(d->real_device, module, pAllocator);
}

void VKAPI_CALL vkDestroyCuFunctionNVX(VkDevice device, VkCuFunctionNVX function, const VkAllocationCallbacks *pAllocator)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkDestroyCuFunctionNVX(d->real_device, function, pAllocator);
}

uint32_t VKAPI_CALL vkGetImageViewHandleNVX(VkDevice device, const VkImageViewHandleInfoNVX *pInfo)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetImageViewHandleNVX(d->real_device, pInfo);
}

VkResult VKAPI_CALL vkGetImageViewAddressNVX(VkDevice device, VkImageView imageView, VkImageViewAddressPropertiesNVX *pProperties)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetImageViewAddressNVX(d->real_device, imageView, pProperties);
}

VkResult VKAPI_CALL vkGetShaderInfoAMD(VkDevice device, VkPipeline pipeline, VkShaderStageFlagBits shaderStage, VkShaderInfoTypeAMD infoType, size_t *pInfoSize, void *pInfo)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetShaderInfoAMD(d->real_device, pipeline, shaderStage, infoType, pInfoSize, pInfo);
}

VkResult VKAPI_CALL vkDisplayPowerControlEXT(VkDevice device, VkDisplayKHR display, const VkDisplayPowerInfoEXT *pDisplayPowerInfo)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkDisplayPowerControlEXT(d->real_device, display, pDisplayPowerInfo);
}

VkResult VKAPI_CALL vkRegisterDeviceEventEXT(VkDevice device, const VkDeviceEventInfoEXT *pDeviceEventInfo, const VkAllocationCallbacks *pAllocator, VkFence *pFence)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkRegisterDeviceEventEXT(d->real_device, pDeviceEventInfo, pAllocator, pFence);
}

VkResult VKAPI_CALL vkRegisterDisplayEventEXT(VkDevice device, VkDisplayKHR display, const VkDisplayEventInfoEXT *pDisplayEventInfo, const VkAllocationCallbacks *pAllocator, VkFence *pFence)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkRegisterDisplayEventEXT(d->real_device, display, pDisplayEventInfo, pAllocator, pFence);
}

VkResult VKAPI_CALL vkGetSwapchainCounterEXT(VkDevice device, VkSwapchainKHR swapchain, VkSurfaceCounterFlagBitsEXT counter, uint64_t *pCounterValue)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetSwapchainCounterEXT(d->real_device, swapchain, counter, pCounterValue);
}

VkResult VKAPI_CALL vkGetRefreshCycleDurationGOOGLE(VkDevice device, VkSwapchainKHR swapchain, VkRefreshCycleDurationGOOGLE *pDisplayTimingProperties)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetRefreshCycleDurationGOOGLE(d->real_device, swapchain, pDisplayTimingProperties);
}

VkResult VKAPI_CALL vkGetPastPresentationTimingGOOGLE(VkDevice device, VkSwapchainKHR swapchain, uint32_t *pPresentationTimingCount, VkPastPresentationTimingGOOGLE *pPresentationTimings)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetPastPresentationTimingGOOGLE(d->real_device, swapchain, pPresentationTimingCount, pPresentationTimings);
}

void VKAPI_CALL vkSetHdrMetadataEXT(VkDevice device, uint32_t swapchainCount, const VkSwapchainKHR *pSwapchains, const VkHdrMetadataEXT *pMetadata)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkSetHdrMetadataEXT(d->real_device, swapchainCount, pSwapchains, pMetadata);
}

VkResult VKAPI_CALL vkSetDebugUtilsObjectNameEXT(VkDevice device, const VkDebugUtilsObjectNameInfoEXT *pNameInfo)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkSetDebugUtilsObjectNameEXT(d->real_device, pNameInfo);
}

VkResult VKAPI_CALL vkSetDebugUtilsObjectTagEXT(VkDevice device, const VkDebugUtilsObjectTagInfoEXT *pTagInfo)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkSetDebugUtilsObjectTagEXT(d->real_device, pTagInfo);
}

VkResult VKAPI_CALL vkGetImageDrmFormatModifierPropertiesEXT(VkDevice device, VkImage image, VkImageDrmFormatModifierPropertiesEXT *pProperties)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetImageDrmFormatModifierPropertiesEXT(d->real_device, image, pProperties);
}

VkResult VKAPI_CALL vkCreateValidationCacheEXT(VkDevice device, const VkValidationCacheCreateInfoEXT *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkValidationCacheEXT *pValidationCache)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCreateValidationCacheEXT(d->real_device, pCreateInfo, pAllocator, pValidationCache);
}

void VKAPI_CALL vkDestroyValidationCacheEXT(VkDevice device, VkValidationCacheEXT validationCache, const VkAllocationCallbacks *pAllocator)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkDestroyValidationCacheEXT(d->real_device, validationCache, pAllocator);
}

VkResult VKAPI_CALL vkMergeValidationCachesEXT(VkDevice device, VkValidationCacheEXT dstCache, uint32_t srcCacheCount, const VkValidationCacheEXT *pSrcCaches)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkMergeValidationCachesEXT(d->real_device, dstCache, srcCacheCount, pSrcCaches);
}

VkResult VKAPI_CALL vkGetValidationCacheDataEXT(VkDevice device, VkValidationCacheEXT validationCache, size_t *pDataSize, void *pData)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetValidationCacheDataEXT(d->real_device, validationCache, pDataSize, pData);
}

VkResult VKAPI_CALL vkCreateAccelerationStructureNV(VkDevice device, const VkAccelerationStructureCreateInfoNV *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkAccelerationStructureNV *pAccelerationStructure)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCreateAccelerationStructureNV(d->real_device, pCreateInfo, pAllocator, pAccelerationStructure);
}

void VKAPI_CALL vkDestroyAccelerationStructureNV(VkDevice device, VkAccelerationStructureNV accelerationStructure, const VkAllocationCallbacks *pAllocator)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkDestroyAccelerationStructureNV(d->real_device, accelerationStructure, pAllocator);
}

void VKAPI_CALL vkGetAccelerationStructureMemoryRequirementsNV(VkDevice device, const VkAccelerationStructureMemoryRequirementsInfoNV *pInfo, VkMemoryRequirements2KHR *pMemoryRequirements)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetAccelerationStructureMemoryRequirementsNV(d->real_device, pInfo, pMemoryRequirements);
}

VkResult VKAPI_CALL vkBindAccelerationStructureMemoryNV(VkDevice device, uint32_t bindInfoCount, const VkBindAccelerationStructureMemoryInfoNV *pBindInfos)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkBindAccelerationStructureMemoryNV(d->real_device, bindInfoCount, pBindInfos);
}

VkResult VKAPI_CALL vkCreateRayTracingPipelinesNV(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoNV *pCreateInfos, const VkAllocationCallbacks *pAllocator, VkPipeline *pPipelines)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCreateRayTracingPipelinesNV(d->real_device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
}

VkResult VKAPI_CALL vkGetRayTracingShaderGroupHandlesKHR(VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void *pData)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetRayTracingShaderGroupHandlesKHR(d->real_device, pipeline, firstGroup, groupCount, dataSize, pData);
}

VkResult VKAPI_CALL vkGetRayTracingShaderGroupHandlesNV(VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void *pData)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetRayTracingShaderGroupHandlesNV(d->real_device, pipeline, firstGroup, groupCount, dataSize, pData);
}

VkResult VKAPI_CALL vkGetAccelerationStructureHandleNV(VkDevice device, VkAccelerationStructureNV accelerationStructure, size_t dataSize, void *pData)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetAccelerationStructureHandleNV(d->real_device, accelerationStructure, dataSize, pData);
}

VkResult VKAPI_CALL vkCompileDeferredNV(VkDevice device, VkPipeline pipeline, uint32_t shader)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCompileDeferredNV(d->real_device, pipeline, shader);
}

VkResult VKAPI_CALL vkGetMemoryHostPointerPropertiesEXT(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, const void *pHostPointer, VkMemoryHostPointerPropertiesEXT *pMemoryHostPointerProperties)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetMemoryHostPointerPropertiesEXT(d->real_device, handleType, pHostPointer, pMemoryHostPointerProperties);
}

VkResult VKAPI_CALL vkGetCalibratedTimestampsEXT(VkDevice device, uint32_t timestampCount, const VkCalibratedTimestampInfoEXT *pTimestampInfos, uint64_t *pTimestamps, uint64_t *pMaxDeviation)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetCalibratedTimestampsEXT(d->real_device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);
}

VkResult VKAPI_CALL vkInitializePerformanceApiINTEL(VkDevice device, const VkInitializePerformanceApiInfoINTEL *pInitializeInfo)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkInitializePerformanceApiINTEL(d->real_device, pInitializeInfo);
}

void VKAPI_CALL vkUninitializePerformanceApiINTEL(VkDevice device)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkUninitializePerformanceApiINTEL(d->real_device);
}

VkResult VKAPI_CALL vkAcquirePerformanceConfigurationINTEL(VkDevice device, const VkPerformanceConfigurationAcquireInfoINTEL *pAcquireInfo, VkPerformanceConfigurationINTEL *pConfiguration)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkAcquirePerformanceConfigurationINTEL(d->real_device, pAcquireInfo, pConfiguration);
}

VkResult VKAPI_CALL vkReleasePerformanceConfigurationINTEL(VkDevice device, VkPerformanceConfigurationINTEL configuration)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkReleasePerformanceConfigurationINTEL(d->real_device, configuration);
}

VkResult VKAPI_CALL vkGetPerformanceParameterINTEL(VkDevice device, VkPerformanceParameterTypeINTEL parameter, VkPerformanceValueINTEL *pValue)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetPerformanceParameterINTEL(d->real_device, parameter, pValue);
}

void VKAPI_CALL vkSetLocalDimmingAMD(VkDevice device, VkSwapchainKHR swapChain, VkBool32 localDimmingEnable)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkSetLocalDimmingAMD(d->real_device, swapChain, localDimmingEnable);
}

VkDeviceAddress VKAPI_CALL vkGetBufferDeviceAddressEXT(VkDevice device, const VkBufferDeviceAddressInfo *pInfo)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetBufferDeviceAddressEXT(d->real_device, pInfo);
}

void VKAPI_CALL vkResetQueryPoolEXT(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkResetQueryPoolEXT(d->real_device, queryPool, firstQuery, queryCount);
}

VkResult VKAPI_CALL vkReleaseSwapchainImagesEXT(VkDevice device, const VkReleaseSwapchainImagesInfoEXT *pReleaseInfo)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkReleaseSwapchainImagesEXT(d->real_device, pReleaseInfo);
}

void VKAPI_CALL vkGetGeneratedCommandsMemoryRequirementsNV(VkDevice device, const VkGeneratedCommandsMemoryRequirementsInfoNV *pInfo, VkMemoryRequirements2 *pMemoryRequirements)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetGeneratedCommandsMemoryRequirementsNV(d->real_device, pInfo, pMemoryRequirements);
}

VkResult VKAPI_CALL vkCreateIndirectCommandsLayoutNV(VkDevice device, const VkIndirectCommandsLayoutCreateInfoNV *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkIndirectCommandsLayoutNV *pIndirectCommandsLayout)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCreateIndirectCommandsLayoutNV(d->real_device, pCreateInfo, pAllocator, pIndirectCommandsLayout);
}

void VKAPI_CALL vkDestroyIndirectCommandsLayoutNV(VkDevice device, VkIndirectCommandsLayoutNV indirectCommandsLayout, const VkAllocationCallbacks *pAllocator)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkDestroyIndirectCommandsLayoutNV(d->real_device, indirectCommandsLayout, pAllocator);
}

VkResult VKAPI_CALL vkCreatePrivateDataSlotEXT(VkDevice device, const VkPrivateDataSlotCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkPrivateDataSlot *pPrivateDataSlot)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCreatePrivateDataSlotEXT(d->real_device, pCreateInfo, pAllocator, pPrivateDataSlot);
}

void VKAPI_CALL vkDestroyPrivateDataSlotEXT(VkDevice device, VkPrivateDataSlot privateDataSlot, const VkAllocationCallbacks *pAllocator)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkDestroyPrivateDataSlotEXT(d->real_device, privateDataSlot, pAllocator);
}

VkResult VKAPI_CALL vkSetPrivateDataEXT(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t data)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkSetPrivateDataEXT(d->real_device, objectType, objectHandle, privateDataSlot, data);
}

void VKAPI_CALL vkGetPrivateDataEXT(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t *pData)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetPrivateDataEXT(d->real_device, objectType, objectHandle, privateDataSlot, pData);
}

void VKAPI_CALL vkGetDescriptorSetLayoutSizeEXT(VkDevice device, VkDescriptorSetLayout layout, VkDeviceSize *pLayoutSizeInBytes)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetDescriptorSetLayoutSizeEXT(d->real_device, layout, pLayoutSizeInBytes);
}

void VKAPI_CALL vkGetDescriptorSetLayoutBindingOffsetEXT(VkDevice device, VkDescriptorSetLayout layout, uint32_t binding, VkDeviceSize *pOffset)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetDescriptorSetLayoutBindingOffsetEXT(d->real_device, layout, binding, pOffset);
}

void VKAPI_CALL vkGetDescriptorEXT(VkDevice device, const VkDescriptorGetInfoEXT *pDescriptorInfo, size_t dataSize, void *pDescriptor)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetDescriptorEXT(d->real_device, pDescriptorInfo, dataSize, pDescriptor);
}

VkResult VKAPI_CALL vkGetBufferOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkBufferCaptureDescriptorDataInfoEXT *pInfo, void *pData)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetBufferOpaqueCaptureDescriptorDataEXT(d->real_device, pInfo, pData);
}

VkResult VKAPI_CALL vkGetImageOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkImageCaptureDescriptorDataInfoEXT *pInfo, void *pData)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetImageOpaqueCaptureDescriptorDataEXT(d->real_device, pInfo, pData);
}

VkResult VKAPI_CALL vkGetImageViewOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkImageViewCaptureDescriptorDataInfoEXT *pInfo, void *pData)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetImageViewOpaqueCaptureDescriptorDataEXT(d->real_device, pInfo, pData);
}

VkResult VKAPI_CALL vkGetSamplerOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkSamplerCaptureDescriptorDataInfoEXT *pInfo, void *pData)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetSamplerOpaqueCaptureDescriptorDataEXT(d->real_device, pInfo, pData);
}

VkResult VKAPI_CALL vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkAccelerationStructureCaptureDescriptorDataInfoEXT *pInfo, void *pData)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT(d->real_device, pInfo, pData);
}

void VKAPI_CALL vkGetImageSubresourceLayout2EXT(VkDevice device, VkImage image, const VkImageSubresource2EXT *pSubresource, VkSubresourceLayout2EXT *pLayout)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetImageSubresourceLayout2EXT(d->real_device, image, pSubresource, pLayout);
}

VkResult VKAPI_CALL vkGetDeviceFaultInfoEXT(VkDevice device, VkDeviceFaultCountsEXT *pFaultCounts, VkDeviceFaultInfoEXT *pFaultInfo)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetDeviceFaultInfoEXT(d->real_device, pFaultCounts, pFaultInfo);
}

VkResult VKAPI_CALL vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI(VkDevice device, VkRenderPass renderpass, VkExtent2D *pMaxWorkgroupSize)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI(d->real_device, renderpass, pMaxWorkgroupSize);
}

VkResult VKAPI_CALL vkGetMemoryRemoteAddressNV(VkDevice device, const VkMemoryGetRemoteAddressInfoNV *pMemoryGetRemoteAddressInfo, VkRemoteAddressNV *pAddress)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetMemoryRemoteAddressNV(d->real_device, pMemoryGetRemoteAddressInfo, pAddress);
}

VkResult VKAPI_CALL vkGetPipelinePropertiesEXT(VkDevice device, const VkPipelineInfoEXT *pPipelineInfo, VkBaseOutStructure *pPipelineProperties)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetPipelinePropertiesEXT(d->real_device, pPipelineInfo, pPipelineProperties);
}

VkResult VKAPI_CALL vkCreateMicromapEXT(VkDevice device, const VkMicromapCreateInfoEXT *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkMicromapEXT *pMicromap)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCreateMicromapEXT(d->real_device, pCreateInfo, pAllocator, pMicromap);
}

void VKAPI_CALL vkDestroyMicromapEXT(VkDevice device, VkMicromapEXT micromap, const VkAllocationCallbacks *pAllocator)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkDestroyMicromapEXT(d->real_device, micromap, pAllocator);
}

VkResult VKAPI_CALL vkBuildMicromapsEXT(VkDevice device, VkDeferredOperationKHR deferredOperation, uint32_t infoCount, const VkMicromapBuildInfoEXT *pInfos)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkBuildMicromapsEXT(d->real_device, deferredOperation, infoCount, pInfos);
}

VkResult VKAPI_CALL vkCopyMicromapEXT(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMicromapInfoEXT *pInfo)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCopyMicromapEXT(d->real_device, deferredOperation, pInfo);
}

VkResult VKAPI_CALL vkCopyMicromapToMemoryEXT(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMicromapToMemoryInfoEXT *pInfo)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCopyMicromapToMemoryEXT(d->real_device, deferredOperation, pInfo);
}

VkResult VKAPI_CALL vkCopyMemoryToMicromapEXT(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMemoryToMicromapInfoEXT *pInfo)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCopyMemoryToMicromapEXT(d->real_device, deferredOperation, pInfo);
}

VkResult VKAPI_CALL vkWriteMicromapsPropertiesEXT(VkDevice device, uint32_t micromapCount, const VkMicromapEXT *pMicromaps, VkQueryType queryType, size_t dataSize, void *pData, size_t stride)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkWriteMicromapsPropertiesEXT(d->real_device, micromapCount, pMicromaps, queryType, dataSize, pData, stride);
}

void VKAPI_CALL vkGetDeviceMicromapCompatibilityEXT(VkDevice device, const VkMicromapVersionInfoEXT *pVersionInfo, VkAccelerationStructureCompatibilityKHR *pCompatibility)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetDeviceMicromapCompatibilityEXT(d->real_device, pVersionInfo, pCompatibility);
}

void VKAPI_CALL vkGetMicromapBuildSizesEXT(VkDevice device, VkAccelerationStructureBuildTypeKHR buildType, const VkMicromapBuildInfoEXT *pBuildInfo, VkMicromapBuildSizesInfoEXT *pSizeInfo)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetMicromapBuildSizesEXT(d->real_device, buildType, pBuildInfo, pSizeInfo);
}

void VKAPI_CALL vkSetDeviceMemoryPriorityEXT(VkDevice device, VkDeviceMemory memory, float priority)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkSetDeviceMemoryPriorityEXT(d->real_device, memory, priority);
}

void VKAPI_CALL vkGetDescriptorSetLayoutHostMappingInfoVALVE(VkDevice device, const VkDescriptorSetBindingReferenceVALVE *pBindingReference, VkDescriptorSetLayoutHostMappingInfoVALVE *pHostMapping)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetDescriptorSetLayoutHostMappingInfoVALVE(d->real_device, pBindingReference, pHostMapping);
}

void VKAPI_CALL vkGetDescriptorSetHostMappingVALVE(VkDevice device, VkDescriptorSet descriptorSet, void **ppData)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetDescriptorSetHostMappingVALVE(d->real_device, descriptorSet, ppData);
}

void VKAPI_CALL vkGetShaderModuleIdentifierEXT(VkDevice device, VkShaderModule shaderModule, VkShaderModuleIdentifierEXT *pIdentifier)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetShaderModuleIdentifierEXT(d->real_device, shaderModule, pIdentifier);
}

void VKAPI_CALL vkGetShaderModuleCreateInfoIdentifierEXT(VkDevice device, const VkShaderModuleCreateInfo *pCreateInfo, VkShaderModuleIdentifierEXT *pIdentifier)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetShaderModuleCreateInfoIdentifierEXT(d->real_device, pCreateInfo, pIdentifier);
}

VkResult VKAPI_CALL vkCreateOpticalFlowSessionNV(VkDevice device, const VkOpticalFlowSessionCreateInfoNV *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkOpticalFlowSessionNV *pSession)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCreateOpticalFlowSessionNV(d->real_device, pCreateInfo, pAllocator, pSession);
}

void VKAPI_CALL vkDestroyOpticalFlowSessionNV(VkDevice device, VkOpticalFlowSessionNV session, const VkAllocationCallbacks *pAllocator)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkDestroyOpticalFlowSessionNV(d->real_device, session, pAllocator);
}

VkResult VKAPI_CALL vkBindOpticalFlowSessionImageNV(VkDevice device, VkOpticalFlowSessionNV session, VkOpticalFlowSessionBindingPointNV bindingPoint, VkImageView view, VkImageLayout layout)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkBindOpticalFlowSessionImageNV(d->real_device, session, bindingPoint, view, layout);
}

VkResult VKAPI_CALL vkCreateShadersEXT(VkDevice device, uint32_t createInfoCount, const VkShaderCreateInfoEXT *pCreateInfos, const VkAllocationCallbacks *pAllocator, VkShaderEXT *pShaders)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCreateShadersEXT(d->real_device, createInfoCount, pCreateInfos, pAllocator, pShaders);
}

void VKAPI_CALL vkDestroyShaderEXT(VkDevice device, VkShaderEXT shader, const VkAllocationCallbacks *pAllocator)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkDestroyShaderEXT(d->real_device, shader, pAllocator);
}

VkResult VKAPI_CALL vkGetShaderBinaryDataEXT(VkDevice device, VkShaderEXT shader, size_t *pDataSize, void *pData)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetShaderBinaryDataEXT(d->real_device, shader, pDataSize, pData);
}

VkResult VKAPI_CALL vkGetFramebufferTilePropertiesQCOM(VkDevice device, VkFramebuffer framebuffer, uint32_t *pPropertiesCount, VkTilePropertiesQCOM *pProperties)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetFramebufferTilePropertiesQCOM(d->real_device, framebuffer, pPropertiesCount, pProperties);
}

VkResult VKAPI_CALL vkGetDynamicRenderingTilePropertiesQCOM(VkDevice device, const VkRenderingInfo *pRenderingInfo, VkTilePropertiesQCOM *pProperties)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetDynamicRenderingTilePropertiesQCOM(d->real_device, pRenderingInfo, pProperties);
}

VkResult VKAPI_CALL vkCreateAccelerationStructureKHR(VkDevice device, const VkAccelerationStructureCreateInfoKHR *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkAccelerationStructureKHR *pAccelerationStructure)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCreateAccelerationStructureKHR(d->real_device, pCreateInfo, pAllocator, pAccelerationStructure);
}

void VKAPI_CALL vkDestroyAccelerationStructureKHR(VkDevice device, VkAccelerationStructureKHR accelerationStructure, const VkAllocationCallbacks *pAllocator)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkDestroyAccelerationStructureKHR(d->real_device, accelerationStructure, pAllocator);
}

VkResult VKAPI_CALL vkBuildAccelerationStructuresKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR *pInfos, const VkAccelerationStructureBuildRangeInfoKHR *const *ppBuildRangeInfos)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkBuildAccelerationStructuresKHR(d->real_device, deferredOperation, infoCount, pInfos, ppBuildRangeInfos);
}

VkResult VKAPI_CALL vkCopyAccelerationStructureKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyAccelerationStructureInfoKHR *pInfo)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCopyAccelerationStructureKHR(d->real_device, deferredOperation, pInfo);
}

VkResult VKAPI_CALL vkCopyAccelerationStructureToMemoryKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyAccelerationStructureToMemoryInfoKHR *pInfo)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCopyAccelerationStructureToMemoryKHR(d->real_device, deferredOperation, pInfo);
}

VkResult VKAPI_CALL vkCopyMemoryToAccelerationStructureKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMemoryToAccelerationStructureInfoKHR *pInfo)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCopyMemoryToAccelerationStructureKHR(d->real_device, deferredOperation, pInfo);
}

VkResult VKAPI_CALL vkWriteAccelerationStructuresPropertiesKHR(VkDevice device, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR *pAccelerationStructures, VkQueryType queryType, size_t dataSize, void *pData, size_t stride)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkWriteAccelerationStructuresPropertiesKHR(d->real_device, accelerationStructureCount, pAccelerationStructures, queryType, dataSize, pData, stride);
}

VkDeviceAddress VKAPI_CALL vkGetAccelerationStructureDeviceAddressKHR(VkDevice device, const VkAccelerationStructureDeviceAddressInfoKHR *pInfo)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetAccelerationStructureDeviceAddressKHR(d->real_device, pInfo);
}

void VKAPI_CALL vkGetDeviceAccelerationStructureCompatibilityKHR(VkDevice device, const VkAccelerationStructureVersionInfoKHR *pVersionInfo, VkAccelerationStructureCompatibilityKHR *pCompatibility)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetDeviceAccelerationStructureCompatibilityKHR(d->real_device, pVersionInfo, pCompatibility);
}

void VKAPI_CALL vkGetAccelerationStructureBuildSizesKHR(VkDevice device, VkAccelerationStructureBuildTypeKHR buildType, const VkAccelerationStructureBuildGeometryInfoKHR *pBuildInfo, const uint32_t *pMaxPrimitiveCounts, VkAccelerationStructureBuildSizesInfoKHR *pSizeInfo)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetAccelerationStructureBuildSizesKHR(d->real_device, buildType, pBuildInfo, pMaxPrimitiveCounts, pSizeInfo);
}

VkResult VKAPI_CALL vkCreateRayTracingPipelinesKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoKHR *pCreateInfos, const VkAllocationCallbacks *pAllocator, VkPipeline *pPipelines)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkCreateRayTracingPipelinesKHR(d->real_device, deferredOperation, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
}

VkResult VKAPI_CALL vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void *pData)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(d->real_device, pipeline, firstGroup, groupCount, dataSize, pData);
}

VkDeviceSize VKAPI_CALL vkGetRayTracingShaderGroupStackSizeKHR(VkDevice device, VkPipeline pipeline, uint32_t group, VkShaderGroupShaderKHR groupShader)
{
	auto d = reinterpret_cast<PFNTable *>(device);
	return d->vkGetRayTracingShaderGroupStackSizeKHR(d->real_device, pipeline, group, groupShader);
}

#endif
