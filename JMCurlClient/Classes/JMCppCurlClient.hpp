//
//  JMCppCurlClient.hpp
//  testcurl
//
//  Created by Macro on 2017/5/2.
//  Copyright © 2017年 Macro. All rights reserved.
//

#ifndef JMCppCurlClient_hpp
#define JMCppCurlClient_hpp

#include <stdio.h>
#include <string>

class JMCppCurlClient
{
public:
    JMCppCurlClient(void);
    ~JMCppCurlClient(void);
    
public:
    
    static JMCppCurlClient& getInstance(){
        static JMCppCurlClient instance;
        return instance;
    }
    
    /**
     * @brief HTTPS POST请求
     * @param strUrl 输入参数,请求的Url地址,如:https://www.alipay.com
     * @param strPost 输入参数,使用如下格式para1=val1&para2=val2&…
     * @param strResponse 输出参数,返回的内容
     * @param pCaPath 输入参数,为CA证书的路径.如果输入为NULL,则不验证服务器端证书的有效性.
     * @return 返回是否Post成功
     */
    int Post(const std::string& strUrl, const std::string& strPost, std::string& strResponse, const char * pCaPath = NULL);
    
    
    
    /**
     * @brief HTTPS GET请求
     * @param strUrl 输入参数,请求的Url地址,如:https://www.alipay.com
     * @param strResponse 输出参数,返回的内容
     * @param pCaPath 输入参数,为CA证书的路径.如果输入为NULL,则不验证服务器端证书的有效性.
     * @return 返回是否Post成功
     */
    int Get(const std::string& strUrl, std::string& strResponse, const char * pCaPath = NULL);
    
public:
    void SetDebug(bool bDebug);
    
private:
    bool m_bDebug;
};


#endif /* JMCppCurlClient_hpp */
