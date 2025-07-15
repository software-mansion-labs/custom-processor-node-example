#pragma once

#include <AudioApiTurboModulesJSI.h>

#include <jsi/jsi.h>
#include <memory>
#include <string>

namespace facebook::react {

class NativeAudioProcessingModule
    : public NativeAudioProcessingModuleCxxSpec<NativeAudioProcessingModule> {
public:
  explicit NativeAudioProcessingModule(std::shared_ptr<CallInvoker> jsInvoker);
  void injectCustomProcessorInstaller(jsi::Runtime &runtime);

private:
  jsi::Function createInstaller(jsi::Runtime &runtime);
};

} // namespace facebook::react
