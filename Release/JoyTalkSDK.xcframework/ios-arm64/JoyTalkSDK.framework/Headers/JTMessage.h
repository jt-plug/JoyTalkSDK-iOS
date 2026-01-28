//
//  JTMessage.h
//  JoyTalkSDK
//
//  Created by yunguang on 2025/12/9.
//

#import <Foundation/Foundation.h>
#import "JTFileModel.h"
#import "JTFaqListModel.h"

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    JTMessageContentTypeText                 = 1,//文字
    JTMessageContentTypeImage                = 2,//图片
    JTMessageContentTypeVideo                = 3,//视频
    JTMessageContentTypeFile                 = 4,//文件
    JTMessageContentTypeFaq                  = 100,//Faq问题
    JTMessageContentTypeTransfer             = 200,//转接
    JTMessageContentTypeUnbind               = 300,//解绑
} JTMessageContentType;

typedef enum : NSUInteger {
    JTMessageSendStatusSending               = 10,//发送中 (sending)
    JTMessageSendStatusArrived               = 20,//发送到达 (arrived)
    JTMessageSendStatusFailed                = 30,//发送失败 (failed)
} JTMessageSendStatus;

typedef enum : NSUInteger {
    JTSendUserTypeAgent                      = 1,//来自 客服
    JTSendUserTypeUser                       = 2,//来自 用户
    JTSendUserTypeAnonymous                  = 3,//来自 匿名
} JTSendUserType;

typedef enum : NSUInteger {
    JTMessageTypeSend                        = 1,//发送
    JTMessageTypeCancel                      = 2,//撤回
    JTMessageTypeEdit                        = 3,//编辑
    JTMessageTypeSystemNotification          = 4,//系统通知
    JTMessageTypeTransfer                    = 5,//转接
    JTMessageTypeIncoming                    = 6,//进线
    JTMessageTypeReply                       = 7,//回复
    JTMessageTypeUnbind                      = 8,//解绑
} JTMessageType;

@interface JTMessage : NSObject

/** msg id（用于lastMsgId字段分页） */
@property (nonatomic, copy, nullable) NSString *msgId;
/** 消息id */
@property (nonatomic, copy, nullable) NSString *messageId;
/** 发送者类型 1.客服 2.用户 3.匿名 */
@property (nonatomic, assign) JTSendUserType sendUserType;
/** 客服昵称 */
@property (nonatomic, copy, nullable) NSString *customerServiceName;
/** 客服id */
@property (nonatomic, copy, nullable) NSString *customerServiceId;
/** 客服头像 */
@property (nonatomic, copy, nullable) NSString *customerServiceAvatar;
/** 用户昵称 */
@property (nonatomic, copy, nullable) NSString *userName;
/** 用户头像 */
@property (nonatomic, copy, nullable) NSString *userAvatar;
/** 操作类型 (1.发送消息 2.撤回 3.编辑 4.系统通知 5.转接 6.进线 7.回复 8.解绑) */
@property (nonatomic, copy, nullable) NSString *msgType;
/** 消息内容类型 1文字 、2图片、3视频、4文件、100Faq问题、200转接、300解绑*/
@property (nonatomic, assign) JTMessageContentType contentType;
/** 创建时间 */
@property (nonatomic, assign) long createTime;
/** 撤回或者编辑的记录ID */
@property (nonatomic, copy, nullable) NSString *editId;
/** 会话ID */
@property (nonatomic, copy, nullable) NSString *sessionId;
/** 消息内容 */
@property (nonatomic, copy, nullable) NSString *content;
/** 是否编辑 */
@property (nonatomic, assign) bool isEdit;
/** 是否撤回 */
@property (nonatomic, assign) bool isCancel;
/** 客服是否已读 */
@property (nonatomic, assign) bool isRead;
/** 是否回复 */
@property (nonatomic, assign) bool isReply;
/** 回复消息 */
@property (nonatomic, copy, nullable) NSString *replyContent;
/** 回复内容类型 1文字 、2图片、3视频、4文件*/
@property (nonatomic, copy, nullable) NSString *replyType;

/** 消息状态 sending：发送中、arrived：发送到达、failed：发送失败 */
@property (nonatomic, assign) JTMessageSendStatus sendStatus;
/** 图片、视频、文件数据模型 */
@property (nonatomic, strong, nullable) JTFileModel *fileData;
/** faq问题列表 */
@property (nonatomic, strong, nullable) NSArray <JTFaqTopicModel *>*faqList;
/** faq图片列表 */
@property (nonatomic, strong, nullable) NSArray <NSString *>*faqImages;
/** 回复消息数据模型 */
@property (nonatomic, strong, nullable) JTFileModel *replyContentModel;

+ (JTMessageContentType)contentTypeFromString:(NSString *)string;
+ (NSString *)stringFromContentType:(JTMessageContentType)contentType;

+ (JTSendUserType)sendUserTypeFromString:(NSString *)string;
+ (NSString *)stringFromSendUserType:(JTSendUserType)sendUserType;

+ (JTMessageSendStatus)sendStatusFromString:(NSString *)string;
+ (NSString *)stringFromSendStatus:(JTMessageSendStatus)sendStatus;

+ (JTMessageType)messageTypeFromString:(NSString *)string;
+ (NSString *)stringFromMessageType:(JTMessageType)messageType;

/**
 * 将消息对象转换为 JSON 字符串
 * @return JSON 字符串
 */
- (NSString *)toJSONString;

@end

NS_ASSUME_NONNULL_END
