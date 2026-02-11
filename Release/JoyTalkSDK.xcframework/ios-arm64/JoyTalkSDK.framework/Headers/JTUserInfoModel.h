//
//  JTUserInfoModel.h
//  JoyTalkSDK
//
//  Created by yunguang on 2026/1/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * 用户信息模型
 */
@interface JTUserInfoModel : NSObject

/** Joytalk 内部用户 UUID（cs_user_id） */
@property (nonatomic, copy, nullable) NSString *uuid;

/** 商户ID */
@property (nonatomic, assign) NSInteger merchantId;

/** 用户昵称 */
@property (nonatomic, copy, nullable) NSString *nickname;

/** 用户头像URL */
@property (nonatomic, copy, nullable) NSString *avatar;

/** 用户来源：web/H5/App/iOS/Android/MiniProgram */
@property (nonatomic, copy, nullable) NSString *userSource;

/** 用户IP */
@property (nonatomic, copy, nullable) NSString *userIp;

/** 商户系统内的用户ID（登录用户才有，匿名用户为空） */
@property (nonatomic, copy, nullable) NSString *externalUserId;

/** 是否是匿名用户（true-匿名用户，false-登录用户） */
@property (nonatomic, assign) BOOL isAnonymous;

@end

NS_ASSUME_NONNULL_END
