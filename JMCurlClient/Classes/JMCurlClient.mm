//
//  JMCurlClient.m
//  testcurl
//
//  Created by Macro on 2017/5/4.
//  Copyright © 2017年 Macro. All rights reserved.
//

#import "JMCurlClient.h"
#include "JMCppCurlClient.hpp"

@interface JMCurlClient ()

@end


@implementation JMCurlClient

int CURLE_OK = 0;

+ (instancetype)shared {
    static id obj;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        obj = [[self alloc] init];
    });
    return obj;
}

- (NSString *)getWithUrl:(NSString *)url error:(NSError **)error {
    
    NSInteger code = -1;
    if (url.length > 0) {
        std::string strUrl = [url UTF8String];
        std::string response;
        
        code = JMCppCurlClient::getInstance().Get(strUrl, response);
        if (code == CURLE_OK) {
            return [NSString stringWithUTF8String:response.c_str()];
        }
    }
    
    if (*error) {
        *error = [[NSError alloc] initWithDomain:@"JMCurlClient" code:code userInfo:nil];
    }
    
    return @"";
}


- (void)getWithUrl:(NSString *)url callback:(void(^)(NSString *))callback {
    __weak typeof(self) weakself = self;
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^(){
        
        NSString *res = [weakself getWithUrl:url error:nil];
        if (callback && res) {
            callback(res);
        }
    });
}

@end
