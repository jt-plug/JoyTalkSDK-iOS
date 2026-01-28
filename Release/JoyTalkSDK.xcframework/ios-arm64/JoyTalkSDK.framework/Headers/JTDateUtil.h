//
//  JTDateUtil.h
//  JoyTalkSDK
//
//  Created by yunguang on 2025/12/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * 日期工具类
 * 提供UTC时区和本地时区之间的日期转换，以及ISO8601格式的日期字符串处理
 */
@interface JTDateUtil : NSObject

/**
 * 将UTC日期转换为ISO8601格式字符串
 * 格式：yyyy-MM-dd'T'HH:mm:ss.SSS'Z'
 *
 * @param date 要转换的UTC日期对象
 * @return ISO8601格式的日期字符串，如果date为nil则返回空字符串
 */
+ (NSString *)iso8601StringFromUTCDate:(NSDate *)date;

/**
 * 从UTC日期字符串转换为UTC日期对象
 * 支持的格式：yyyy-MM-dd'T'HH:mm:ss.SSS'Z'
 *
 * @param dateString UTC格式的日期字符串
 * @return 转换后的UTC日期对象，如果dateString为空或格式不正确则返回nil
 */
+ (NSDate *)convertToUtcDateFromUTCDateString:(NSString *)dateString;

/**
 * 将UTC日期转换为本地时区日期
 * 根据设备当前时区自动计算时差并转换
 *
 * @param anyDate 要转换的UTC日期对象
 * @return 转换后的本地时区日期对象，如果anyDate为nil则返回nil
 */
+ (NSDate *)convertToLoaclDateFromUTCDate:(NSDate *)anyDate;

/**
 * 将本地时区日期转换为UTC日期
 * 根据设备当前时区自动计算时差并转换
 *
 * @param fromDate 要转换的本地时区日期对象
 * @return 转换后的UTC日期对象，如果fromDate为nil则返回nil
 */
+ (NSDate *)convertToUTCDateFromLocalDate:(NSDate *)fromDate;

/**
 * 验证字符串是否为有效的ISO8601格式
 * 支持的格式：yyyy-MM-dd'T'HH:mm:ss.SSS'Z'
 *
 * @param dateString 要验证的日期字符串
 * @return 如果字符串是有效的ISO8601格式返回YES，否则返回NO
 */
+ (BOOL)isValidISO8601Format:(NSString *)dateString;

/**
 * 从日期字符串转换为日期对象，支持多种ISO8601格式
 * 会依次尝试以下格式：
 * - yyyy-MM-dd'T'HH:mm:ss.SSS'Z'
 * - yyyy-MM-dd'T'HH:mm:ss'Z'
 * - yyyy-MM-dd'T'HH:mm:ss.SSSZ
 * - yyyy-MM-dd'T'HH:mm:ssZ
 * - yyyy-MM-dd HH:mm:ss
 *
 * @param dateString 要转换的日期字符串
 * @return 转换后的日期对象（UTC时区），如果所有格式都无法解析则返回nil
 */
+ (NSDate *)convertISODateFromDateString:(NSString *)dateString;

@end

NS_ASSUME_NONNULL_END
