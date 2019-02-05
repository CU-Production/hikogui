//
//  MoltenVKView.h
//  TTauri
//
//  Created by Tjienta Vara on 2019-01-31.
//  Copyright © 2019 Pokitec. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#include <vulkan/vulkan.hpp>

@interface MoltenVKView : NSView
-(vk::SurfaceKHR)makeVulkanLayer:(vk::Instance)instance;
@end
