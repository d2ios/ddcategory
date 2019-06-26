//
//  UIView+DDBadge.m
//  ddcategory
//
//  Created by lcb on 2019/6/26.
//  Copyright © 2019 lcb. All rights reserved.
//

#import "UIView+DDBadge.h"
#import <objc/runtime.h>
static char badgeViewKey;
static NSInteger const pointWidth = 6; //小红点的宽高
static NSInteger const rightRange = 0; //距离控件右边的距离
//static CGFloat const badgeFont = 9; //字体的大小
@implementation UIView (DDBadge)
- (void)showBadgeWithTopMagin:(CGFloat)magin
{
    if (self.badge == nil) {
        CGRect frame = CGRectMake(CGRectGetWidth(self.frame) + rightRange, magin, pointWidth, pointWidth);
        self.badge = [[UILabel alloc] initWithFrame:frame];
        self.badge.backgroundColor = [UIColor redColor];
        //圆角为宽度的一半
        self.badge.layer.cornerRadius = pointWidth / 2;
        //确保可以有圆角
        self.badge.layer.masksToBounds = YES;
        [self addSubview:self.badge];
        [self bringSubviewToFront:self.badge];
    }
}
- (void)hidenBadge
{
    //从父视图上面移除
    [self.badge removeFromSuperview];
    self.badge=nil;
}
#pragma mark - GetterAndSetter
- (UILabel *)badge
{
    //通过runtime创建一个UILabel的属性
    return objc_getAssociatedObject(self, &badgeViewKey);
}
- (void)setBadge:(UILabel *)badge
{
    objc_setAssociatedObject(self, &badgeViewKey, badge, OBJC_ASSOCIATION_RETAIN);
}
@end
