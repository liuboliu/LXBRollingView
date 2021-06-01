# LXBRollingView

[![CI Status](https://img.shields.io/travis/liuboliu/LXBRollingView.svg?style=flat)](https://travis-ci.org/liuboliu/LXBRollingView)
[![Version](https://img.shields.io/cocoapods/v/LXBRollingView.svg?style=flat)](https://cocoapods.org/pods/LXBRollingView)
[![License](https://img.shields.io/cocoapods/l/LXBRollingView.svg?style=flat)](https://cocoapods.org/pods/LXBRollingView)
[![Platform](https://img.shields.io/cocoapods/p/LXBRollingView.svg?style=flat)](https://cocoapods.org/pods/LXBRollingView)

## Example

To run the example project, clone the repo, and run `pod install` from the Example directory first.

## Requirements

## Installation

LXBRollingView is available through [CocoaPods](https://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
pod 'LXBRollingView'
```
## 使用方法
```创建自定义cell 继承于 TPNoticeViewCell
@interface TPFianceRollTextCell : TPNoticeViewCell

- (void)updateWithModel:(listContObjectVO *)model;

@end
初始化

- (TPRollingNoticeView *)rollingView
{
    if (!_rollingView) {
        _rollingView = [[TPRollingNoticeView alloc] initWithFrame:CGRectMake(70 * rectScale(), 14 * rectScale(), 265 * rectScale(), 40 * rectScale())];
        _rollingView.style = RollingStyleFade; ///动画样式
        _rollingView.stayInterval = 3; ///停留时间
        _rollingView.animationDuration = 0.4; /// 动画时间
        注册cell
        [_rollingView registerClass:[TPFianceRollTextCell class] forCellReuseIdentifier:NSStringFromClass([TPFianceRollTextCell class])];
        ///设置数据源
        _rollingView.dataSource = self;
        ///设置代理
        _rollingView.delegate = self;
    }
    return _rollingView;
}

实现数据源和代理方法
- (TPNoticeViewCell *)rollingNoticeView:(TPRollingNoticeView *)rollingView cellAtIndex:(NSUInteger)index
{
    TPFianceRollTextCell *cell = [rollingView dequeueReusableCellWithIdentifier:NSStringFromClass([TPFianceRollTextCell class])];
    listContObjectVO *childModel = self.listBO.childListArray[index];
    [cell updateWithModel:childModel];
    return cell;
}

- (NSInteger)numberOfRowsForRollingNoticeView:(TPRollingNoticeView *)rollingView
{
    return self.listBO.childListArray.count;
}

- (void)didClickRollingNoticeView:(TPRollingNoticeView *)rollingView forIndex:(NSUInteger)index
{
    UINavigationController *currentNav =getCurrentNavgationCotroller();
    listContObjectVO *childModel = self.listBO.childListArray[index];
    childModel.isComeFromEconomicChannel = YES;
    pushContentWithListContentObject(currentNav, childModel);
}


目前支持两种样式
typedef NS_ENUM(NSUInteger, RollingStyle) {
    RollingStyleDefault = 0, ///默认样式，滚动轮播
    RollingStyleFade = 1, /// 渐变轮播
};
```
## Author

liuboliu, 2534660131@qq.com

## License

LXBRollingView is available under the MIT license. See the LICENSE file for more info.
