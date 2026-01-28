//
//  JTManager.h
//  JoyTalkSDK
//
//  Created by yunguang on 2025/12/9.
//
//  悦聊 SDK 核心管理类
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <JoyTalkSDK/JTMainMessageModel.h>
#import <JoyTalkSDK/JTDefinition.h>
#import <JoyTalkSDK/JTCallbackDefine.h>
#import <JoyTalkSDK/JTErrorCode.h>
#import <JoyTalkSDK/JTConsultationItemModel.h>
@class JTMutuallyBindingInfoModel, JTUserInfoModel;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - JTManager Interface (核心管理类接口)

/**
 * 悦聊 SDK 核心管理类
 * @note 所有方法都是类方法，无需创建实例
 */

@interface JTManager : NSObject
/**
 * 初始化 SDK
 *
 * @param authToken  认证令牌
 * @param entranceId 入口 ID
 * @param completion 完成回调
 * @warning 必须在使用其他 SDK 功能之前调用
 */
+ (void)initWithAuthToken:(NSString *)authToken entranceId:(NSString *)entranceId completion:(JTOnSimpleCallback)completion;

/**
 * 获取咨询类型列表
 *
 * @param success        成功回调，返回咨询类型列表
 * @param failure        失败回调，返回错误信息
 * @warning 需要在初始化成功后调用才有效
 */
+ (void)getConsultationListWithSuccess:(JTOnGetConsultationListCallback)success failure:(JTOnFailureCallback)failure;


/**
 * 开启当前对话
 *
 * @param onWebSocketStateCallback WebSocket 连接状态回调
 * @param onReceiveMessageCallback 消息接收回调
 * @warning 需要在初始化成功后调用
 */
+ (void)startConversationWithOnWebSocketStateCallback:(JTOnWebSocketStateCallback)onWebSocketStateCallback
                             onReceiveMessageCallback:(JTOnReceiveMessageCallback)onReceiveMessageCallback;

/**
 * 进线分配客服
 *
 * @param consultationId 咨询类型ID
 * @param completion    完成回调
 * @warning 需要在初始化成功后，且 WebSocket 已连接时调用
 */
+ (void)incomingLineWithConsultationId:(NSString *)consultationId completion:(JTOnBindingCallback)completion;

/**
 * 获取 FAQ 列表
 *
 * @param completion 完成回调
 * @warning 需要在初始化成功后，且 WebSocket 已连接时调用
 */
+ (void)getFaqListWithCompletion:(JTOnSimpleCallback)completion;

/**
 * 发送 FAQ 问题
 *
 * @param content   问题文案
 * @param questionId 问题 ID
 * @warning 需要在初始化成功后，且用户是在线状态时调用
 */
+ (void)sendJTFaqMessageWithContent:(NSString *)content questionId:(NSInteger)questionId;

/**
 * 发送文字消息
 *
 * @param content 消息内容
 * @return 该条文字消息。此时该消息状态为发送中.
 * @warning 需要在初始化成功后，且用户是在线状态时调用才有效
 */
+ (JTMessage *)sendJTTextMessageWithContent:(NSString *)content
                                  messageId:(NSString *)messageId
                                 completion:(JTOnMessageSendCallback)completion;

/**
 * 发送图片消息
 *
 * @param imagePath 图片路径
 * @return 该条图片消息。此时该消息状态为发送中，message的content属性是本地图片路径
 * @warning SDK不会去限制图片大小，如果开发者需要限制图片大小，需要调整图片大小后，再使用此接口
 * @warning 需要在初始化成功后，且用户是在线状态时调用才有效
 */
+ (JTMessage *)sendJTImageMessageWithImagePath:(NSString *)imagePath
                                     messageId:(NSString *)messageId
                                    completion:(JTOnMessageSendCallback)completion;

/**
 * 发送视频消息
 *
 * @param videoPath 需要发送的视频本地路径
 * @return 该条视频消息。此时该消息状态为发送中，message的content属性是本地视频路径.
 * @warning 使用该接口，会对提供的视频进行压缩，并且转换为MP4格式发送.
 * @warning 需要在初始化成功后，且用户是在线状态时调用才有效
 */
+ (JTMessage *)sendJTVideoMessageWithVideoPath:(NSString *)videoPath
                                     messageId:(NSString *)messageId
                                    completion:(JTOnMessageSendCallback)completion;

/**
 * 发送文件消息
 *
 * @param filePath 需要发送的文件本地路径（fileName 和 fileSize 在内部处理）
 * @return 该条文件消息。此时该消息状态为发送中，message的content属性是本地文件路径.
 * @warning 需要在初始化成功后，且用户是在线状态时调用才有效
 */
+ (JTMessage *)sendJTFileMessageWithFilePath:(NSString *)filePath
                                   messageId:(NSString *)messageId
                                  completion:(JTOnMessageSendCallback)completion;

///**
// * 发送商品卡片消息
// *
// * @param pictureUrl 商品图片的url。不能为空，否则不执行发送操作。
// * @param title 商品标题。不能为空，否则不执行发送操作。
// * @param descripation 商品描述内容。不能为空，否则不执行发送操作。
// * @param productUrl 商品链接。不能为空，否则不执行发送操作。
// * @param salesCount 销售量。不设置就默认为0。
// *
// * @return 该条商品卡片消息。此时该消息状态为发送中.
// * @warning 需要在初始化成功后，且用户是在线状态时调用才有效
// */
//+ (JTMessage *)sendProductCardMessageWithPictureUrl:(NSString *)pictureUrl
//                                         title:(NSString *)title
//                                         descripation:(NSString *)descripation
//                                         productUrl:(NSString *)productUrl
//                                         salesCount:(long)salesCount
//                               completion:(void (^)(JTMessage *sendedMessage, NSError * _Nullable error))completion;

/**
 * 获取历史消息
 *
 * @param sessionId 会话 ID
 * @param lastMsgId 上一页最后一条消息 ID，首次加载传 nil
 * @param size      每页加载数量
 * @param success   成功回调
 * @param failure   失败回调
 * @warning 需要在初始化成功后调用
 */
+ (void)getUserHistoryMessagesWithSessionId:(NSString *)sessionId
                                  lastMsgId:(NSString * _Nullable)lastMsgId
                                       size:(NSInteger)size
                                    success:(JTOnHistoryMessageCallback)success
                                    failure:(JTOnFailureCallback)failure;

/**
 * 下载多媒体内容
 *
 * @param urlString     文件 URL
 * @param progressBlock 下载进度回调（0.0-1.0）
 * @param completion    完成回调
 */
+ (void)downloadMediaWithUrlString:(NSString *)urlString
                          progress:(void (^)(float progress))progressBlock
                        completion:(void (^)(NSData *mediaData, NSError * _Nullable error))completion;

/**
 * 取消下载
 *
 * @param urlString 文件 URL
 */
+ (void)cancelDownloadForUrl:(NSString *)urlString;

/**
 * 清除所有多媒体缓存
 *
 * @param completion 完成回调，返回清除前缓存大小（MB）
 * @warning 此操作不可逆
 */
+ (void)removeAllMediaDataWithCompletion:(void (^)(float mediaSize))completion;

/**
 * 设置用户离线
 *
 * @warning 离线后需要重新调用 startConversation 才能重新上线
 */
+ (void)setClientOffline;

/**
 * 注册状态观察者
 *
 * @param block 状态变化回调
 * @param key   观察者唯一标识符
 * @warning 不要使用 self，避免循环引用
 * @note 需要在不需要时调用 removeStateChangeObserverWithKey: 移除
 */
+ (void)addStateObserverWithBlock:(StateChangeBlock)block withKey:(NSString *)key;

/**
 * 移除状态观察者
 *
 * @param key 观察者唯一标识符
 */
+ (void)removeStateChangeObserverWithKey:(NSString *)key;

/**
 * 获取当前状态
 *
 * @return 当前状态枚举值
 */
+ (JTState)getCurrentState;

/**
 * 获取当前用户是否分配了聊天
 *
 * @return YES 表示已分配客服，NO 表示未分配
 */
+ (BOOL)haveConversation;

/**
 * 获取当前会话 ID
 *
 * @return 会话 ID
 */
+ (NSString *)getSessionId;

/**
 * 获取当前用户 ID
 *
 * @return 用户 ID
 */
+ (NSString *)getCurrentClientId;

/**
 * 获取当前绑定信息
 *
 * @return 绑定信息模型
 */
+ (JTMutuallyBindingInfoModel *)getCurrentBindingInfo;

/**
 * 获取当前用户信息
 *
 * @return 用户信息模型
 */
+ (JTUserInfoModel *)getCurrentUserInfo;

/**
 * 获取当前客服 ID
 *
 * @return 客服 ID
 */
+ (NSString *)getCurrentAgentId;

/**
 * 获取当前咨询类型 ID
 *
 * @return 咨询类型 ID
 */
+ (NSString *)getCurrentConsultationId;

/**
 * 获取当前客服组名称
 *
 * @return 客服组名称
 */
+ (NSString *)getCurrentAgentGroupName;

/**
 * 获取 SDK 版本号
 *
 * @return 版本号字符串
 */
+ (NSString *)getJoyTalkSDKVersion;

/**
 * 获取登录状态
 *
 * @return YES 表示已登录，NO 表示未登录
 */
+ (BOOL)getLoginStatus;

/**
 * 获取网络是否可用
 *
 * @return YES 表示网络可用，NO 表示不可用
 */
+ (BOOL)obtainNetIsReachable;

@end

NS_ASSUME_NONNULL_END
