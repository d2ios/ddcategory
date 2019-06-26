//
//  UIAlertView+DDBlock.m
//  ddcategory
//
//  Created by lcb on 2019/6/26.
//  Copyright © 2019 lcb. All rights reserved.
//

#import "UIAlertView+DDBlock.h"

#import <objc/runtime.h>
static void *key = "DDBlockAlertView";
@implementation UIAlertView (DDBlock)

- (void)showAlertViewWithBlock:(AlertViewBlock)block
{
    if (block) {
        ////移除所有关联
        objc_removeAssociatedObjects(self);
        objc_setAssociatedObject(self, key, block, OBJC_ASSOCIATION_COPY);
        ////设置delegate
        self.delegate = self;
    }
    ////show
    [self show];
}

- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex {
    ///获取关联的对象，通过关键字。
    AlertViewBlock block = objc_getAssociatedObject(self, key);
    if (block) {
        ///block传值
        block(buttonIndex);
    }
}
@end
