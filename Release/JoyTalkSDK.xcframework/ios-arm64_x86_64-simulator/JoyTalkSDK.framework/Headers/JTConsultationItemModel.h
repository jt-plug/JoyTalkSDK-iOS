//
//  JTConsultationItemModel.h
//  JoyTalkSDK
//
//  Created by yunguang on 2025/12/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * 咨询类型项模型
 */
@interface JTConsultationItemModel : NSObject

/** 咨询类型名称 */
@property (nonatomic, copy) NSString *name;

/** 引导文案 */
@property (nonatomic, copy) NSString *guideText;

/** 客户组ID */
@property (nonatomic, copy) NSString *customerGroupId;

/** 咨询类型ID */
@property (nonatomic, copy) NSString *consultationId;

/** 是否默认 */
@property (nonatomic, assign) bool isDefault;

/**
 * 从字典创建模型
 * @param dictionary 字典数据
 * @return JTConsultationItemModel 实例
 */
+ (instancetype)modelWithDictionary:(NSDictionary *)dictionary;

@end

NS_ASSUME_NONNULL_END
