Pod::Spec.new do |s|
  s.name             = 'JMCurlClient'
  s.version          = '0.2.2'
  s.summary          = 'A short description of JMCurlClient.'
  s.description      = 'Nothing'
  s.homepage         = 'https://github.com/xserver/JMCurlClient'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'Jim' => '965502512@qq.com' }
  s.ios.deployment_target = '7.0'

  s.source       = { :git => "https://github.com/xserver/JMCurlClient.git"}
  s.source_files = 'JMCurlClient/Classes/*'
  s.libraries = "curl", "z"
  s.public_header_files = 'JMCurlClient/Classes/curl/*.h'
  

  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
end
