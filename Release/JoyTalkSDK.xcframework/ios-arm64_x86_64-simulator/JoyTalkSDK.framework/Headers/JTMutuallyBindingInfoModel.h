//
//  JTMutuallyBindingInfoModel.h
//  JoyTalkSDK
//
//  Created by yunguang on 2026/1/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 相互绑定信息
@interface JTMutuallyBindingInfoModel : NSObject

/** 客服id */
@property (nonatomic, copy, nullable) NSString *cid;

/** 客服头像 */
@property (nonatomic, copy, nullable) NSString *customerAvatar;

/** 客服昵称 */
@property (nonatomic, copy, nullable) NSString *customerName;

/** 接线类型id */
@property (nonatomic, assign) NSInteger groupId;

/** 接线类型组名 */
@property (nonatomic, copy, nullable) NSString *groupName;

/** 会话id */
@property (nonatomic, copy, nullable) NSString *sessionId;

/** 原本旧的会话id */
@property (nonatomic, copy, nullable) NSString *oldSessionId;

@end

NS_ASSUME_NONNULL_END
