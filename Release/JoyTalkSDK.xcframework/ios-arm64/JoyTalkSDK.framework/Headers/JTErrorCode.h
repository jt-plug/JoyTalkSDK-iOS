//
//  JTErrorCode.h
//  Pods
//
//  Created by yunguang on 2026/1/19.
//

#ifndef JTErrorCode_h
#define JTErrorCode_h

/**
 * 全局业务错误码枚举
 */
typedef NS_ENUM(NSInteger, JTErrorType) {
    JTErrorTypeUninitialized      = 10001, // 未初始化
    JTErrorTypeDisconnected       = 10002, // 未连接
    JTErrorTypeNoCustomerService  = 10003, // 未分配客服
    JTErrorTypeMessageSendFail    = 10004, // 消息发送失败
    JTErrorTypeDataParsingError   = 10005, // 数据解析异常
    JTErrorTypeFileNotExist       = 10006, // 文件不存在
    JTErrorTypeFileParsingError   = 10007, // 文件解析异常
    JTErrorTypeAuthInfoError      = 10008, // 授权信息错误
    JTErrorTypeFileUploadFail     = 10009, // 文件上传失败
    JTErrorTypeParameterError     = 10010, // 参数异常
    JTErrorTypeEmptyData          = 10011, // 数据为空
};

/**
 * 根据错误码获取错误文案
 */
static inline NSString *JTErrorMsgWithType(JTErrorType errorType) {
    NSString *msg = nil;
    switch (errorType) {
        case JTErrorTypeUninitialized: msg = @"未初始化"; break;
        case JTErrorTypeDisconnected: msg = @"未连接"; break;
        case JTErrorTypeNoCustomerService: msg = @"未分配客服"; break;
        case JTErrorTypeMessageSendFail: msg = @"消息发送失败"; break;
        case JTErrorTypeDataParsingError: msg = @"数据解析异常"; break;
        case JTErrorTypeFileNotExist: msg = @"文件不存在"; break;
        case JTErrorTypeFileParsingError: msg = @"文件解析异常"; break;
        case JTErrorTypeAuthInfoError: msg = @"授权信息错误"; break;
        case JTErrorTypeFileUploadFail: msg = @"文件上传失败"; break;
        case JTErrorTypeParameterError: msg = @"参数异常"; break;
        case JTErrorTypeEmptyData: msg = @"数据为空"; break;
        default: msg = @"未知错误"; break;
    }
    return msg;
}

/**
 * 快速创建NSError对象
 */
static inline NSError *JTErrorCreateWithType(JTErrorType errorType) {
    NSDictionary *userInfo = @{NSLocalizedDescriptionKey : JTErrorMsgWithType(errorType)};
    return [NSError errorWithDomain:@"com.jt.sdk.error" code:errorType userInfo:userInfo];
}

#endif /* JTErrorCode_h */
