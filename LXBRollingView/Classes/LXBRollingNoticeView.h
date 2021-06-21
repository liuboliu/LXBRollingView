//
//  RollingCell.m
//  TEXT
//
//  Created by 刘博 on 2021/3/18.
//  Copyright © 2021 刘博. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LXBNoticeViewCell.h"
NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, RollingStyle) {
    RollingStyleDefault = 0, ///默认样式，滚动轮播
    RollingStyleFade = 1, /// 渐变轮播
};

@class LXBRollingNoticeView;

@protocol LXBRollingNoticeViewDataSource <NSObject>

@required
// 轮播视图数量
- (NSInteger)numberOfRowsForRollingNoticeView:(LXBRollingNoticeView *)rollingView;
//返回当前展示的轮播视图
- (LXBNoticeViewCell *)rollingNoticeView:(LXBRollingNoticeView *)rollingView cellAtIndex:(NSUInteger)index;

@end

@protocol LXBRollingNoticeViewDelegate <NSObject>
@optional
//点击方法代理
- (void)didClickRollingNoticeView:(LXBRollingNoticeView *)rollingView forIndex:(NSUInteger)index;

@end

@interface LXBRollingNoticeView : UIView

@property (nonatomic, weak) id<LXBRollingNoticeViewDataSource> dataSource;
@property (nonatomic, weak) id<LXBRollingNoticeViewDelegate> delegate;
@property (nonatomic, assign) NSTimeInterval stayInterval; // 停留 默认2秒
@property (nonatomic, assign) NSTimeInterval animationDuration ; //动画时间，默认0.66秒
@property (nonatomic, assign, readonly) int currentIndex;
@property (nonatomic, assign) CGFloat spaceOfItem;//Item之间的距离，默认为零
@property (nonatomic, assign) CGFloat fadeTranslationY; ///  淡入淡出样式下的位移移动量,默认6

///轮播风格
@property (nonatomic, assign) RollingStyle style;

- (void)registerClass:(Class)cellClass forCellReuseIdentifier:(NSString *)identifier;
- (__kindof LXBNoticeViewCell *)dequeueReusableCellWithIdentifier:(NSString *)identifier;

- (void)reloadDataAndStartRoll;
- (void)stopTimer; // 如果想要释放，请在合适的地方停止timer。 If you want to release, please stop the timer in the right place,for example '-viewDidDismiss'
//暂停
- (void)pause;

//继续
- (void)proceed;

@end

NS_ASSUME_NONNULL_END
