{
global:
	# Loader-ICD interface functions
	vk_icdGetInstanceProcAddr;
	vk_icdNegotiateLoaderICDInterfaceVersion;

	# Vulkan 1.0 API entry functions
	vkCreateInstance;
	vkDestroyInstance;
	vkEnumeratePhysicalDevices;
	vkGetPhysicalDeviceFeatures;
	vkGetPhysicalDeviceFormatProperties;
	vkGetPhysicalDeviceImageFormatProperties;
	vkGetPhysicalDeviceProperties;
	vkGetPhysicalDeviceQueueFamilyProperties;
	vkGetPhysicalDeviceMemoryProperties;
	vkGetInstanceProcAddr;
	vkGetDeviceProcAddr;
	vkCreateDevice;
	vkDestroyDevice;
	vkEnumerateInstanceExtensionProperties;
	vkEnumerateDeviceExtensionProperties;
	vkEnumerateInstanceLayerProperties;
	vkEnumerateDeviceLayerProperties;
	vkGetDeviceQueue;
	vkQueueSubmit;
	vkQueueWaitIdle;
	vkDeviceWaitIdle;
	vkAllocateMemory;
	vkFreeMemory;
	vkMapMemory;
	vkUnmapMemory;
	vkFlushMappedMemoryRanges;
	vkInvalidateMappedMemoryRanges;
	vkGetDeviceMemoryCommitment;
	vkBindBufferMemory;
	vkBindImageMemory;
	vkGetBufferMemoryRequirements;
	vkGetImageMemoryRequirements;
	vkGetImageSparseMemoryRequirements;
	vkGetPhysicalDeviceSparseImageFormatProperties;
	vkQueueBindSparse;
	vkCreateFence;
	vkDestroyFence;
	vkResetFences;
	vkGetFenceStatus;
	vkWaitForFences;
	vkCreateSemaphore;
	vkDestroySemaphore;
	vkCreateEvent;
	vkDestroyEvent;
	vkGetEventStatus;
	vkSetEvent;
	vkResetEvent;
	vkCreateQueryPool;
	vkDestroyQueryPool;
	vkGetQueryPoolResults;
	vkCreateBuffer;
	vkDestroyBuffer;
	vkCreateBufferView;
	vkDestroyBufferView;
	vkCreateImage;
	vkDestroyImage;
	vkGetImageSubresourceLayout;
	vkCreateImageView;
	vkDestroyImageView;
	vkCreateShaderModule;
	vkDestroyShaderModule;
	vkCreatePipelineCache;
	vkDestroyPipelineCache;
	vkGetPipelineCacheData;
	vkMergePipelineCaches;
	vkCreateGraphicsPipelines;
	vkCreateComputePipelines;
	vkDestroyPipeline;
	vkCreatePipelineLayout;
	vkDestroyPipelineLayout;
	vkCreateSampler;
	vkDestroySampler;
	vkCreateDescriptorSetLayout;
	vkDestroyDescriptorSetLayout;
	vkCreateDescriptorPool;
	vkDestroyDescriptorPool;
	vkResetDescriptorPool;
	vkAllocateDescriptorSets;
	vkFreeDescriptorSets;
	vkUpdateDescriptorSets;
	vkCreateFramebuffer;
	vkDestroyFramebuffer;
	vkCreateRenderPass;
	vkDestroyRenderPass;
	vkGetRenderAreaGranularity;
	vkCreateCommandPool;
	vkDestroyCommandPool;
	vkResetCommandPool;
	vkAllocateCommandBuffers;
	vkFreeCommandBuffers;
	vkBeginCommandBuffer;
	vkEndCommandBuffer;
	vkResetCommandBuffer;
	vkCmdBindPipeline;
	vkCmdSetViewport;
	vkCmdSetScissor;
	vkCmdSetLineWidth;
	vkCmdSetDepthBias;
	vkCmdSetBlendConstants;
	vkCmdSetDepthBounds;
	vkCmdSetStencilCompareMask;
	vkCmdSetStencilWriteMask;
	vkCmdSetStencilReference;
	vkCmdBindDescriptorSets;
	vkCmdBindIndexBuffer;
	vkCmdBindVertexBuffers;
	vkCmdDraw;
	vkCmdDrawIndexed;
	vkCmdDrawIndirect;
	vkCmdDrawIndexedIndirect;
	vkCmdDispatch;
	vkCmdDispatchIndirect;
	vkCmdCopyBuffer;
	vkCmdCopyImage;
	vkCmdBlitImage;
	vkCmdCopyBufferToImage;
	vkCmdCopyImageToBuffer;
	vkCmdUpdateBuffer;
	vkCmdFillBuffer;
	vkCmdClearColorImage;
	vkCmdClearDepthStencilImage;
	vkCmdClearAttachments;
	vkCmdResolveImage;
	vkCmdSetEvent;
	vkCmdResetEvent;
	vkCmdWaitEvents;
	vkCmdPipelineBarrier;
	vkCmdBeginQuery;
	vkCmdEndQuery;
	vkCmdResetQueryPool;
	vkCmdWriteTimestamp;
	vkCmdCopyQueryPoolResults;
	vkCmdPushConstants;
	vkCmdBeginRenderPass;
	vkCmdNextSubpass;
	vkCmdEndRenderPass;
	vkCmdExecuteCommands;
	vkDestroySurfaceKHR;
	vkGetPhysicalDeviceSurfaceSupportKHR;
	vkGetPhysicalDeviceSurfaceCapabilitiesKHR;
	vkGetPhysicalDeviceSurfaceFormatsKHR;

	# VK_KHR_get_surface_capabilities2
	#vkGetPhysicalDeviceSurfaceCapabilities2KHR;
	#vkGetPhysicalDeviceSurfaceFormats2KHR;

	# VK_KHR_surface
	vkGetPhysicalDeviceSurfacePresentModesKHR;
	vkCreateSwapchainKHR;
	vkDestroySwapchainKHR;
	vkGetSwapchainImagesKHR;
	vkAcquireNextImageKHR;
	vkQueuePresentKHR;

	# VK_KHR_display
	#vkGetPhysicalDeviceDisplayPropertiesKHR;
	#vkGetPhysicalDeviceDisplayPlanePropertiesKHR;
	#vkGetDisplayPlaneSupportedDisplaysKHR;
	#vkGetDisplayModePropertiesKHR;
	#vkCreateDisplayModeKHR;
	#vkGetDisplayPlaneCapabilitiesKHR;
	#vkCreateDisplayPlaneSurfaceKHR;

	# VK_KHR_display_swapchain
	#vkCreateSharedSwapchainsKHR;

	# VK_KHR_Xcb_surface
	vkCreateXcbSurfaceKHR;
	vkGetPhysicalDeviceXcbPresentationSupportKHR;

	# VK_KHR_xlib_surface
	vkCreateXlibSurfaceKHR;
	vkGetPhysicalDeviceXlibPresentationSupportKHR;

	# VK_KHR_wayland_surface
	vkCreateWaylandSurfaceKHR;
	vkGetPhysicalDeviceWaylandPresentationSupportKHR;

	# VK_EXT_directfb_surface
	vkCreateDirectFBSurfaceEXT;
	vkGetPhysicalDeviceDirectFBPresentationSupportEXT;

	# Vulkan 1.1 API entry functions
	vkEnumerateInstanceVersion;
	vkEnumeratePhysicalDeviceGroups;
	vkGetPhysicalDeviceFeatures2;
	vkGetPhysicalDeviceProperties2;
	vkGetPhysicalDeviceFormatProperties2;
	vkGetPhysicalDeviceQueueFamilyProperties2;
	vkGetPhysicalDeviceMemoryProperties2;
	vkGetPhysicalDeviceSparseImageFormatProperties2;
	vkGetPhysicalDeviceExternalBufferProperties;
	vkGetPhysicalDeviceExternalSemaphoreProperties;
	vkGetPhysicalDeviceExternalFenceProperties;
	vkBindBufferMemory2;
	vkBindImageMemory2;
	vkGetDeviceGroupPeerMemoryFeatures;
	vkCmdSetDeviceMask;
	vkCmdDispatchBase;
	vkGetImageMemoryRequirements2;
	vkGetBufferMemoryRequirements2;
	vkTrimCommandPool;
	vkGetDeviceQueue2;
	vkCreateSamplerYcbcrConversion;
	vkDestroySamplerYcbcrConversion;
	vkGetDescriptorSetLayoutSupport;
	vkGetDeviceGroupPresentCapabilitiesKHR;
	vkGetDeviceGroupSurfacePresentModesKHR;
	vkGetPhysicalDevicePresentRectanglesKHR;
	vkAcquireNextImage2KHR;
	vkCreateDescriptorUpdateTemplate;
	vkDestroyDescriptorUpdateTemplate;
	vkUpdateDescriptorSetWithTemplate;

	# VK_KHR_get_display_properties2
	#vkGetPhysicalDeviceDisplayProperties2KHR;
	#vkGetPhysicalDeviceDisplayPlaneProperties2KHR;
	#vkGetDisplayModeProperties2KHR;
	#vkGetDisplayPlaneCapabilities2KHR;

	# Vulkan 1.2 API entry functions
	vkGetImageSparseMemoryRequirements2;
	vkGetPhysicalDeviceImageFormatProperties2;

	vkCreateRenderPass2;
	vkCmdBeginRenderPass2;
	vkCmdNextSubpass2;
	vkCmdEndRenderPass2;
	vkCmdDrawIndirectCount;
	vkCmdDrawIndexedIndirectCount;
	vkGetSemaphoreCounterValue;
	vkWaitSemaphores;
	vkSignalSemaphore;
	vkGetBufferDeviceAddress;
	vkGetBufferOpaqueCaptureAddress;
	vkGetDeviceMemoryOpaqueCaptureAddress;
	vkResetQueryPool;

local:
	*;
};
