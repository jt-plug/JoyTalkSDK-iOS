//
//  JTObsAuthInfoModel.h
//  JoyTalkSDK
//
//  Created by yunguang on 2025/12/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * OBS 授权信息数据模型
 */
@interface JTObsAuthInfoModel : NSObject

/** 访问密钥ID */
@property (nonatomic, copy) NSString *accessKeyId;

/** 文件键（路径） */
@property (nonatomic, copy) NSString *key;

/** 策略（Base64编码的JSON字符串） */
@property (nonatomic, copy) NSString *policy;

/** 签名 */
@property (nonatomic, copy) NSString *signature;

/**
 * 从字典创建模型
 * @param dictionary 字典数据
 * @return JTObsAuthInfoModel 实例
 */
+ (instancetype)modelWithDictionary:(NSDictionary *)dictionary;

@end

NS_ASSUME_NONNULL_END

