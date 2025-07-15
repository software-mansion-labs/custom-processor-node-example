#import "NativeAudioProcessingModuleProvider.h"
#import <ReactCommon/CallInvoker.h>
#import <ReactCommon/TurboModule.h>
#import "NativeAudioProcessingModule.h"

@implementation NativeAudioProcessingModuleProvider

- (std::shared_ptr<facebook::react::TurboModule>)getTurboModule:
    (const facebook::react::ObjCTurboModule::InitParams &)params
{
  return std::make_shared<facebook::react::NativeAudioProcessingModule>(params.jsInvoker);
}

@end
