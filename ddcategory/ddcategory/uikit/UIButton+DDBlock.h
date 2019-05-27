//
//  UIButton+DDBlock.h
//  ddcategory
//
//  Created by lcb on 2019/5/27.
//  Copyright © 2019 lcb. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^ButtonBlock)(UIButton *button);

@interface UIButton (DDBlock)

- (void)addAction:(ButtonBlock)block;
- (void)addAction:(ButtonBlock)block forControlEvents:(UIControlEvents)controlEvents;

@end

NS_ASSUME_NONNULL_END
