//
//  JTAuthRespData.h
//  JoyTalkSDK
//
//  Created by yunguang on 2026/1/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface JTAuthRespData : NSObject

/** JWT Token */
@property (nonatomic, copy, nullable) NSString *jwtToken;

/** Token过期时间戳（毫秒级Unix时间戳）  */
@property (nonatomic, strong, nullable) NSNumber *expiresAt;

/** Joytalk 内部用户 UUID */
@property (nonatomic, copy, nullable) NSString *uuid;

/** 用户信息 - 头像URL */
@property (nonatomic, copy, nullable) NSString *avatar;

/** 用户信息 - 昵称 */
@property (nonatomic, copy, nullable) NSString *nickname;

@end

NS_ASSUME_NONNULL_END
