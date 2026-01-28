//
//  JTFaqModel.h
//  JoyTalkSDK
//
//  Created by yunguang on 2025/12/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * FAQ 问题模型
 */
@interface JTFaqModel : NSObject

/** FAQ ID */
@property (nonatomic, copy) NSString *faqId;

/** FAQ 内容 */
@property (nonatomic, copy) NSString *content;

@end

NS_ASSUME_NONNULL_END

