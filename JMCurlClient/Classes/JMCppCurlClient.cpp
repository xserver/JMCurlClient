//
//  JMCppCurlClient.cpp
//  testcurl
//
//  Created by Macro on 2017/5/2.
//  Copyright © 2017年 Macro. All rights reserved.
//

#include "JMCppCurlClient.hpp"
#include "curl/curl.h"
#include <string>

JMCppCurlClient::JMCppCurlClient(void) :
m_bDebug(false)
{
    
}

JMCppCurlClient::~JMCppCurlClient(void)
{
    
}

void JMCppCurlClient::SetDebug(bool bDebug)
{
    m_bDebug = bDebug;
}

static int OnDebug(CURL *, curl_infotype itype, char * pData, size_t size, void *)
{
    if(itype == CURLINFO_TEXT)
    {
        //printf("[TEXT]%s\n", pData);
    }
    else if(itype == CURLINFO_HEADER_IN)
    {
        printf("[HEADER_IN]%s\n", pData);
    }
    else if(itype == CURLINFO_HEADER_OUT)
    {
        printf("[HEADER_OUT]%s\n", pData);
    }
    else if(itype == CURLINFO_DATA_IN)
    {
        printf("[DATA_IN]%s\n", pData);
    }
    else if(itype == CURLINFO_DATA_OUT)
    {
        printf("[DATA_OUT]%s\n", pData);
    }
    return 0;
}

static size_t OnWriteData(void* buffer, size_t size, size_t nmemb, void* lpVoid)
{
    std::string* str = dynamic_cast<std::string*>((std::string *)lpVoid);
    if( NULL == str || NULL == buffer )
    {
        return -1;
    }
    
    char* pData = (char*)buffer;
    str->append(pData, size * nmemb);
    return nmemb;
}


#pragma mark - Post
//int JMCppCurlClient::Post(const std::string& strUrl, const std::string& strPost, std::string& strResponse) {
//    return this->Post(strUrl, strPost, strResponse, NULL);
//}

int JMCppCurlClient::Post(const std::string& strUrl, const std::string& strPost, std::string& strResponse, const char * pCaPath)
{
    CURLcode res;
    CURL* curl = curl_easy_init();
    if(NULL == curl)
    {
        return CURLE_FAILED_INIT;
    }
    if(m_bDebug)
    {
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
        curl_easy_setopt(curl, CURLOPT_DEBUGFUNCTION, OnDebug);
    }
    curl_easy_setopt(curl, CURLOPT_URL, strUrl.c_str());
    curl_easy_setopt(curl, CURLOPT_POST, 1);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, strPost.c_str());
    curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, OnWriteData);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&strResponse);
    curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);
    
    if(NULL == pCaPath)
    {
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, false);
    }
    else
    {
        //缺省情况就是PEM，所以无需设置，另外支持DER
        //curl_easy_setopt(curl,CURLOPT_SSLCERTTYPE,"PEM");
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, true);
        curl_easy_setopt(curl, CURLOPT_CAINFO, pCaPath);
    }
    curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 3);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 3);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    return res;
    
    
    // header custom
    //    struct curl_slist *headers = NULL;
    //    headers = curl_slist_append(headers, "Content-Type: text/xml");
    //    headers = curl_slist_append(headers, "Accept: text/html, */*;q=0.01");
    //    headers = curl_slist_append(headers, "Content-Type:application/json;charset=UTF-8");
    //    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, plist);
    
    //  上传文件
    //    curl_formadd(&post, &last,
    //                 CURLFORM_COPYNAME, "file",
    //                 CURLFORM_BUFFER, "unnamed.png",
    //                 CURLFORM_BUFFERPTR, memblock,
    //                 CURLFORM_BUFFERLENGTH, memblock_length,
    //                 CURLFORM_CONTENTTYPE, "image/png",
    //                 CURLFORM_END);
    
    
    //    curl_formadd(&post, &last,
    //                 CURLFORM_COPYNAME, "file",
    //                 CURLFORM_BUFFER, "unnamed.png",
    //                 CURLFORM_BUFFERPTR, memblock,
    //                 CURLFORM_BUFFERLENGTH, memblock_length,
    //                 CURLFORM_CONTENTTYPE, "image/png",
    //                 CURLFORM_END);
}

#pragma mark - Get
//int JMCppCurlClient::Get(const std::string& strUrl, std::string& strResponse)
//{
//    return this->Get(strUrl, strResponse, NULL);
//}

int JMCppCurlClient::Get(const std::string& strUrl, std::string& strResponse, const char * pCaPath)
{
    CURLcode res;
    CURL* curl = curl_easy_init();
    if(NULL == curl) {
        return CURLE_FAILED_INIT;
    }
    if(m_bDebug) {
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
        curl_easy_setopt(curl, CURLOPT_DEBUGFUNCTION, OnDebug);
    }
    
    curl_easy_setopt(curl, CURLOPT_URL, strUrl.c_str());
    curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, OnWriteData);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&strResponse);
    
    /**
     * 当多个线程都使用超时处理的时候，同时主线程中有sleep或是wait等操作。
     * 如果不设置这个选项，libcurl将会发信号打断这个wait从而导致程序退出。
     */
    curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);
    
    if(NULL == pCaPath) {
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, false);
    }
    else {
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, true);
        curl_easy_setopt(curl, CURLOPT_CAINFO, pCaPath);
    }
    
    curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 3);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 3);
    
    
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    return res;
}
