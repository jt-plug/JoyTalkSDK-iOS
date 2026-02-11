Pod::Spec.new do |s|
    s.name             = 'JoyTalkSDK'
    s.version          = '0.1.0'
    s.summary          = 'JoyTalk customer service SDK'
    s.description      = <<-DESC
    JoyTalkSDK 是一个客户服务 SDK，提供完整的客服功能。
    DESC
    s.homepage         = 'https://github.com/jt-plug/JoyTalk-iOS'
    s.license          = { :type => 'Commercial', :text => 'Copyright (c) jt-plug' }
    s.author           = { 'jt-plug' => 'alex@halaladmin.vip' }
    s.source           = { :git => 'https://github.com/jt-plug/JoyTalk-iOS.git', :tag => s.version.to_s }
    s.module_name      = 'JoyTalkSDK'
    s.ios.deployment_target = '15.0'
    s.static_framework = true
  
    # # 开发调试阶段使用源码
    # s.source_files = 'JoyTalkSDK/**/*.{h,m,mm,swift}'
    # s.public_header_files = 'JoyTalkSDK/**/*.h'
    # # 开发调试阶段三方依赖
    # s.dependency 'MJExtension',  '~> 3.4.2'
    # s.dependency 'SocketRocket', '~> 0.7.1'
    
    # 发布阶段使用二进制框架
    s.vendored_frameworks = 'Release/JoyTalkSDK.xcframework'
    
    # 系统框架依赖
    s.frameworks = 'UIKit', 'Foundation', 'SystemConfiguration'
  end
