//
//  LXBViewController.m
//  LXBRollingView
//
//  Created by liuboliu on 06/01/2021.
//  Copyright (c) 2021 liuboliu. All rights reserved.
//

#import "LXBViewController.h"
#import "KKView.h"

@interface LXBViewController ()

@end

@implementation LXBViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    KKView  *v  = [[KKView alloc] initWithFrame:CGRectMake(0, 0, 100, 100)];
    [self.view addSubview:v];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
