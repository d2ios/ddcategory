//
//  UIColor+DDUtil.h
//  ddcategory
//
//  Created by lcb on 2019/6/26.
//  Copyright © 2019 lcb. All rights reserved.
//

#import <UIKit/UIKit.h>

/*****************************************
 *  rgbValue
 *  例如 RGBOF(0xffffff)
 *  例如 RGBA_OF(0xffffffff)
 *  例如 RGBAOF(0xffffff,1.0f)
 ******************************************/
#define RGBOF(rgbValue)     [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
green:((float)((rgbValue & 0xFF00) >> 8))/255.0 \
blue:((float)(rgbValue & 0xFF))/255.0 \
alpha:1.0]

#define RGBA_OF(rgbValue)   [UIColor colorWithRed:((float)(((rgbValue) & 0xFF000000) >> 24))/255.0 \
green:((float)(((rgbValue) & 0x00FF0000) >> 16))/255.0 \
blue:((float)(rgbValue & 0x0000FF00) >> 8)/255.0 \
alpha:((float)(rgbValue & 0x000000FF))/255.0]

#define RGBAOF(v, a)        [UIColor colorWithRed:((float)(((v) & 0xFF0000) >> 16))/255.0 \
green:((float)(((v) & 0x00FF00) >> 8))/255.0 \
blue:((float)(v & 0x0000FF))/255.0 \
alpha:a]

@interface UIColor (DDUtil)

UIColor *ColorRGBAFor255(CGFloat r, CGFloat g, CGFloat b);

UIColor *ColorRGBA(CGFloat r, CGFloat g, CGFloat b, CGFloat a);

UIColor *ColorHex(NSString *hexString);

UIColor *ColorClear(void);

UIColor *ColorRandom(void);

+ (UIColor *)randomColor;

+ (UIColor *)colorWithHexString:(NSString *)hexString;

+ (UIColor*)colorWithHex:(NSInteger)hexValue alpha:(CGFloat)alphaValue;

+ (UIColor*)colorWithHex:(NSInteger)hexValue;

- (NSDictionary *)dictionaryComponentsRGB;

- (NSDictionary *)dictionaryComponentsHSB;

- (NSArray *)arrayComponentsRGB;

- (NSArray *)arrayComponentsHSB;

@end
