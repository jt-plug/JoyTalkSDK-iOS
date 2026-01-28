//
//  JTLog.h
//  JoyTalkSDK
//
//  Created by yunguang on 2025/12/9.
//

#ifndef JTLog_h
#define JTLog_h

static BOOL JTIsLogEnabled = YES; //发布时默认关闭NO
#define FILENAME [[[NSString alloc] initWithUTF8String:__FILE__] lastPathComponent]

//#define JTInfo(str, ...) {\
//if(JTIsLogEnabled){\
//NSLog(@"✅ 悦聊SDK [%@:%d] → " str, FILENAME, __LINE__, ##__VA_ARGS__);\
//}\
//}

#define JTInfo(str, ...) {\
if(JTIsLogEnabled){\
NSString *logContent = [NSString stringWithFormat:@"✅ 悦聊SDK [%@:%d] → " str, FILENAME, __LINE__, ##__VA_ARGS__]; \
printf("%s\n", [logContent UTF8String]); \
}\
}

#define JTError(str, ...){\
if(JTIsLogEnabled){\
NSLog(@"❌ 悦聊SDK [%@:%d] → " str, FILENAME, __LINE__, ##__VA_ARGS__);\
}\
}

#endif /* JTLog_h */
