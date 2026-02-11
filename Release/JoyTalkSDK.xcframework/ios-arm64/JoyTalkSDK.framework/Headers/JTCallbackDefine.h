//
//  JTCallbackDefine.h
//  Pods
//
//  Created by yunguang on 2026/1/19.
//

#import "JTDefinition.h"
#import "JTMessage.h"

NS_ASSUME_NONNULL_BEGIN

@class JTConsultationItemModel, JTMutuallyBindingInfoModel, JTAuthRespData;

#ifndef JTCallbackDefine_h
#define JTCallbackDefine_h

/**
 * 1. 极简成功 / 失败回调（无业务数据）
 *
 * 适用场景：发送消息、心跳包、标记已读、登出、状态上报等只关心接口是否成功的操作。
 *
 * @param success YES 表示成功，NO 表示失败
 * @param error   失败时的错误对象，成功时为 nil
 */
typedef void (^JTOnSimpleCallback)(BOOL success, NSError * _Nullable error);

/**
 * 2. 获取咨询列表回调
 *
 * 对应接口：获取咨询项 / 问题列表等。
 *
 * @param consultationList  咨询项列表，元素为 JTConsultationItemModel
 * @param welcomeSentence   欢迎语文案（可直接展示在会话顶部）
 * @param countdownSeconds  自动选择倒计时秒数
 */
typedef void (^JTOnGetConsultationListCallback)(NSArray<JTConsultationItemModel *> *consultationList, NSString *welcomeSentence, NSInteger countdownSeconds);

/**
 * 3. 统一失败回调（仅返回错误）
 *
 * 常用于只关心失败原因、不需要成功结果数据的接口。
 *
 * @param error 错误信息对象
 */
typedef void (^JTOnFailureCallback)(NSError *error);

/**
 * 4. 账号绑定 / 互绑结果回调
 *
 * 适用：用户与客服账号、业务账号之间的绑定/解绑等操作。
 *
 * @param bindingInfo  绑定结果信息模型，失败或无数据时为 nil
 * @param error        失败时的错误对象，成功时为 nil
 * @param isNewCustomerService 是否新客服
 */
typedef void (^JTOnBindingCallback)(JTMutuallyBindingInfoModel * _Nullable bindingInfo, NSError * _Nullable error, BOOL isNewCustomerService);

/**
 * 5. 消息发送结果回调
 *
 * 适用：发送文本、图片、视频、文件等消息后，获取最终发送结果。
 *
 * @param sendedMessage 发送后的消息对象（已包含服务端返回的最终状态）
 * @param error         失败时的错误对象，成功时为 nil
 */
typedef void (^JTOnMessageSendCallback)(JTMessage *sendedMessage, NSError * _Nullable error);

/**
 * 6. 历史消息拉取回调
 *
 * 用于分页拉取历史消息记录。
 *
 * @param messagesArray 历史消息数组，元素为 JTMessage
 * @param hasMore       是否还有更多历史消息可以继续拉取
 */
typedef void (^JTOnHistoryMessageCallback)(NSArray<JTMessage *> *messagesArray, BOOL hasMore);

/**
 * 7. WebSocket 连接状态回调
 *
 * 用于监听 SDK 内部 WebSocket 的连接 / 断开 / 重连结果。
 *
 * @param webSocketState 当前 WebSocket 状态枚举
 * @param message           描述当前状态的文案，可用于日志或 UI 提示
 */
typedef void (^JTOnWebSocketStateCallback)(JTWebSocketState webSocketState, NSString *message);

/**
 * 8. 实时消息接收回调
 *
 * 当有新消息（包括系统消息）到达时触发。
 *
 * @param jtMessage    收到的消息对象
 * @param jtActionType 消息操作类型枚举（如发送消息、系统消息等）
 */
typedef void (^JTOnReceiveMessageCallback)(JTMessage *jtMessage, JTMessageType jtActionType);


/**
 * 9. 匿名用户认证成功回调
 *
 * 对应接口：anonymousAuthWithAppKey:entranceId:success:failure: 的成功回调。
 *
 * @param authRespData 认证响应数据（含 jwtToken、uuid、nickname、avatar、expiresAt），失败时为 nil
 */
typedef void (^JTOnAnonymousAuthCallback)(JTAuthRespData * _Nullable authRespData);

/**
 * 10. SDK 状态变化回调
 *
 * 用于 addStateObserverWithBlock:withKey: 注册的状态观察者，当 SDK 状态变化时触发。
 *
 * @param oldState 上一状态
 * @param newState 当前新状态
 * @param value    附加数据（可选，视状态而定）
 * @param error    状态变化伴随的错误信息，无错误时为 nil
 */
typedef void (^JTStateChangeBlock)(JTState oldState, JTState newState, NSDictionary *value, NSError * _Nullable error);

#endif /* JTCallbackDefine_h */


NS_ASSUME_NONNULL_END
