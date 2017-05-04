//
//  ViewController.m
//  JMCurlClient
//
//  Created by Macro on 2017/5/4.
//  Copyright © 2017年 Macro. All rights reserved.
//

#import "ViewController.h"
#import "JMCurlClient.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    [JMCurlClient shared];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
