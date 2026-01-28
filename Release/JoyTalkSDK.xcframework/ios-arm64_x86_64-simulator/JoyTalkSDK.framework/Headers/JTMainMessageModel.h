//
//  JTMainMessageModel.h
//  JoyTalkSDK
//
//  Created by yunguang on 2025/12/22.
//

#import <Foundation/Foundation.h>
#import "JTMessage.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * WebSocket 消息模型
 * 用于解析 WebSocket 收到的消息
 */
@interface JTMainMessageModel : NSObject

/** 聊天类型 (1.文字 2.图片 3.视频 4.文件) */
@property (nonatomic, copy, nullable) NSString *chatType;
/** 错误码 */
@property (nonatomic, strong, nullable) NSNumber *code;
/** 消息内容 */
@property (nonatomic, copy, nullable) NSString *msg;
/** 撤回或者编辑的记录ID */
@property (nonatomic, copy, nullable) NSString *editId;
/** 操作类型 (1.发送消息 2.撤回 3.编辑 4.系统通知 5.转接 6.进线 7.回复 8.解绑) */
@property (nonatomic, assign) JTMessageType msgType;
/** 接受者用户id */
@property (nonatomic, copy, nullable) NSString *toUid;
/** JTMessage 对象，元数据是 JTMessage 的 JSON 字符串 */
@property (nonatomic, strong, nullable) JTMessage *data;
/** 扩展字段 */
@property (nonatomic, copy, nullable) NSString *ext;

/**
 * 从字典创建模型
 * @param dictionary 字典数据
 * @return JTMainMessageModel 实例
 */
+ (instancetype)modelWithDictionary:(NSDictionary *)dictionary;

/**
 * 获取 chat_type 的整数值
 * @return chat_type 的整数值，如果无效返回 0
 */
- (NSInteger)chatTypeIntegerValue;

/**
 * 获取 code 的整数值
 * @return code 的整数值，如果无效返回 0
 */
- (NSInteger)codeIntegerValue;

/**
 * 判断是否是成功码
 * @return YES 表示成功，NO 表示失败或错误
 */
- (BOOL)isSuccess;

/**
 * 判断是否是错误码
 * @return YES 表示错误，NO 表示成功或未知
 */
- (BOOL)isError;

@end

NS_ASSUME_NONNULL_END

