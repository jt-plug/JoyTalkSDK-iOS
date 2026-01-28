//
//  JTFaqListModel.h
//  JoyTalkSDK
//
//  Created by yunguang on 2025/12/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * FAQ 列表模型
 */
@class JTFaqTopicModel, JTFaqItemModel;
@interface JTFaqListModel : NSObject

/** FAQ 名称 */
@property (nonatomic, copy, nullable) NSString *faqName;
/** 引导文本 */
@property (nonatomic, copy, nullable) NSString *guideText;
/** ID */
@property (nonatomic, assign) int faqId;
/** 商户ID */
@property (nonatomic, assign) int merchantId;
/** 显示延迟秒数 */
@property (nonatomic, assign) int showDelaySeconds;
/** 一级问题数组 */
@property (nonatomic, strong, nullable) NSArray<JTFaqTopicModel *> *topic;

@end


@interface JTFaqTopicModel : NSObject

/** FAQ ID */
@property (nonatomic, assign) int faqId;
/** ID */
@property (nonatomic, assign) int questionId;
/** 是否多选 (0:单选 1:多选) */
@property (nonatomic, assign) BOOL isMulti;
/** 选项数组 */
@property (nonatomic, strong, nullable) NSArray<JTFaqTopicModel *> *item;
/** 商户ID */
@property (nonatomic, assign) int merchantId;
/** 问题 */
@property (nonatomic, copy, nullable) NSString *question;
/** 序列号 */
@property (nonatomic, assign) int serialNum;

/** 答案 */
@property (nonatomic, copy, nullable) NSString *answer;
/** 图片URL数组 */
@property (nonatomic, strong, nullable) NSArray<NSString *> *imageUrl;

@end

NS_ASSUME_NONNULL_END
