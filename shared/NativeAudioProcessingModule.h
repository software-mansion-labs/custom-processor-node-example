#pragma once

#include <AudioApiTurboModulesJSI.h>
#include <audioapi/core/AudioNode.h>
#include <audioapi/core/AudioContext.h>
#include <audioapi/HostObjects/AudioNodeHostObject.h>

#include <memory>
#include <string>
#include <jsi/jsi.h>

namespace facebook::react {

class NativeAudioProcessingModule : public NativeAudioProcessingModuleCxxSpec<NativeAudioProcessingModule>  {
public:
  NativeAudioProcessingModule(std::shared_ptr<CallInvoker> jsInvoker);
  // jsi::Object createCustomProcessor(jsi::Runtime &runtime, jsi::Value audioContextJSIValue);
  void injectCustomProcessorInstaller(jsi::Runtime &runtime);

private:
  jsi::Function createInstaller(jsi::Runtime &runtime);
};

} // namespace facebook::react
