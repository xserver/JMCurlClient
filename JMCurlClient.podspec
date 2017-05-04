Pod::Spec.new do |s|
  s.name             = 'MetCurlClient'
  s.version          = '0.1.0'
  s.summary          = 'A short description of MetCurlClient.'
  s.description      = 'Nothing'
  s.homepage         = 'https://github.com/xserver/MetCurlClient'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'Jim' => '965502512@qq.com' }
  s.ios.deployment_target = '7.0'

  s.source       = { :git => "https://github.com/xserver/JMCurlClient.git"}
  s.source_files = 'MetCurlClient/Classes/**/*'
  # s.source_files = 'Classes/*'
  
  # s.resource_bundles = {
  #   '${POD_NAME}' => ['${POD_NAME}/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
end
