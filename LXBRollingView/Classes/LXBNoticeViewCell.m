//
//  TPNoticeViewCell.m
//  TEXT
//
//  Created by 刘博 on 2021/3/18.
//  Copyright © 2021 刘博. All rights reserved.
//


#import "LXBNoticeViewCell.h"

@implementation LXBNoticeViewCell

- (instancetype)initWithReuseIdentifier:(NSString *)reuseIdentifier
{
    self = [super initWithFrame:CGRectZero];
    if (self) {
        _reuseIdentifier = reuseIdentifier;
        [self setUpUI];
    }
    return self;
}

- (instancetype)initWithFrame:(CGRect)frame
{
    return [self initWithReuseIdentifier:@""];
}

- (void)setUpUI
{
}

@end
