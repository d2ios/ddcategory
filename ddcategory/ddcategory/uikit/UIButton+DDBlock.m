//
//  UIButton+DDBlock.m
//  ddcategory
//
//  Created by lcb on 2019/5/27.
//  Copyright © 2019 lcb. All rights reserved.
//

#import "UIButton+DDBlock.h"
#import <objc/runtime.h>

static void * ActionTag = &ActionTag;
@implementation UIButton (DDBlock)

- (void)addAction:(ButtonBlock)block
{
    objc_setAssociatedObject(self, ActionTag, block, OBJC_ASSOCIATION_COPY_NONATOMIC);
    [self addTarget:self action:@selector(action:) forControlEvents:UIControlEventTouchUpInside];
}

- (void)addAction:(ButtonBlock)block forControlEvents:(UIControlEvents)controlEvents
{
    objc_setAssociatedObject(self,ActionTag, block, OBJC_ASSOCIATION_COPY_NONATOMIC);
    [self addTarget:self action:@selector(action:) forControlEvents:controlEvents];
}

- (void)action:(id)sender
{
    ButtonBlock blockAction = (ButtonBlock)objc_getAssociatedObject(self, ActionTag);
    if (blockAction)
    {
        blockAction(self);
    }
}

@end
