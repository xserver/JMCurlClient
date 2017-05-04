//
//  JMCurlClient.h
//  testcurl
//
//  Created by Macro on 2017/5/4.
//  Copyright © 2017年 Macro. All rights reserved.
//

#import <Foundation/Foundation.h>

//  扩展性不好
@interface JMCurlClient : NSObject

+ (instancetype)shared;

- (NSString *)getWithUrl:(NSString *)url
                   error:(NSError **)error;

//- (void)getWithUrl:(NSString *)url
//          callback:(void(^)(NSString *))callback;
//
//- (NSString *)getWithUrl:(NSString *)url
//               parameter:(NSDictionary *)para
//                   error:(NSError **)error;
//
//
//
//- (NSString *)postWithUrl:(NSString *)url
//                parameter:(NSDictionary *)para
//                    error:(NSError **)error;
//
////  上传流
//- (NSString *)postWithUrl:(NSString *)url
//                     data:(NSData *)data
//                    error:(NSError *__autoreleasing *)error;

@end
