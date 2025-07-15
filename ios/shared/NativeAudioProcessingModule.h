#pragma once

#include <AudioApiTurboModulesJSI.h>
#include <audioapi/HostObjects/AudioNodeHostObject.h>
#include <audioapi/core/AudioContext.h>
#include <audioapi/core/AudioNode.h>

#include <jsi/jsi.h>
#include <memory>
#include <string>

namespace facebook::react {

class NativeAudioProcessingModule
    : public NativeAudioProcessingModuleCxxSpec<NativeAudioProcessingModule> {
public:
  NativeAudioProcessingModule(std::shared_ptr<CallInvoker> jsInvoker);
  void injectCustomProcessorInstaller(jsi::Runtime &runtime);

private:
  jsi::Function createInstaller(jsi::Runtime &runtime);
};

} // namespace facebook::react
