//
//  JTDefinition.h
//  JoyTalkSDK
//
//  Created by yunguang on 2025/12/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#ifndef JTDefinition_h
#define JTDefinition_h

/**
 sdk 状态
 */
typedef NS_ENUM(NSUInteger, JTState) {
    JTStateUninitialized,    // 未初始化
    JTStateInitialized,      // 已初始化
    JTStateUnallocatedAgent, // 未分配客服
    JTStateAllocatingAgent,  // 正在分配客服
    JTStateAllocatedAgent,   // 已分配客服
};

/**
 WebSocket 连接状态
 */
typedef NS_ENUM(NSUInteger, JTWebSocketState) {
    JTWebSocketStateDisconnected    = 10, // 未连接（初始状态）
    JTWebSocketStateConnecting      = 11, // 正在连接
    JTWebSocketStateConnected       = 12, // 已连接
    JTWebSocketStateReconnecting    = 13, // 正在重连
    JTWebSocketStateFailed          = 14, // 连接失败
    JTWebSocketStateClosed          = 15, // 已关闭
    JTWebSocketStateReconnectFailed = 16  // 重连失败
};

/**
 当websocket连接的状态改变时发送的通知
 */
#define JT_NOTIFICATION_SOCKET_STATUS_CHANGE @"JT_NOTIFICATION_SOCKET_STATUS_CHANGE"

/**
 当网络状态改变时发送的通知
 */
#define JT_NOTIFICATION_NETWORK_STATUS_CHANGE @"JT_NOTIFICATION_NETWORK_STATUS_CHANGE"

/**
 * 统一的错误域
 */
FOUNDATION_EXPORT NSString * const JTErrorDomain;

#endif /* JTDefinition_h */

NS_ASSUME_NONNULL_END
