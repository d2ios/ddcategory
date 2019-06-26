//
//  UIView+DDBadge.h
//  ddcategory
//
//  Created by lcb on 2019/6/26.
//  Copyright © 2019 lcb. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIView (DDBadge)

/**
 *  通过创建label，显示小红点；
 */
@property (nonatomic, strong) UILabel *badge;

/**
 *  显示小红点
 *  @magin 小红点距离控件上方距离
 */
- (void)showBadgeWithTopMagin:(CGFloat)magin;

/**
 *  隐藏小红点
 */
- (void)hidenBadge;
@end

