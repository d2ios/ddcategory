//
//  UIAlertView+DDBlock.h
//  ddcategory
//
//  Created by lcb on 2019/6/26.
//  Copyright © 2019 lcb. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef void(^AlertViewBlock) (NSInteger buttonIndex);

@interface UIAlertView (DDBlock)
// 用Block的方式回调，这时候会默认用self作为Delegate
- (void)showAlertViewWithBlock:(AlertViewBlock) block;
@end
