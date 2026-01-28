//
//  JTFileModel.h
//  JoyTalkSDK
//
//  Created by yunguang on 2026/1/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * 文件模型
 * 用于表示文件信息
 */
@interface JTFileModel : NSObject

/** 文件url */
@property (nonatomic, copy, nullable) NSString *fileUrl;
/** 文件名称 */
@property (nonatomic, copy, nullable) NSString *fileName;
/** 文件大小（字节） */
@property (nonatomic, assign) long fileSize;
/** video 第一帧的图片url  */
@property (nonatomic, copy, nullable) NSString *thumbnailUrl;

/**
 * 将文件对象转换为 JSON 字符串
 * @return JSON 字符串
 */
- (NSString *)toJSONString;

@end

NS_ASSUME_NONNULL_END
