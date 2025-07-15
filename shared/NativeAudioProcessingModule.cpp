#include "NativeAudioProcessingModule.h"
#include <iostream>
#include <audioapi/HostObjects/AudioContextHostObject.h>
#include <audioapi/jsi/JsiHostObject.h>
#include "CustomProcessorNodeHostObject.h"
#include <functional>
#include <memory>

namespace facebook::react {

NativeAudioProcessingModule::NativeAudioProcessingModule(std::shared_ptr<CallInvoker> jsInvoker)
    : NativeAudioProcessingModuleCxxSpec(std::move(jsInvoker)) {}

    // jsi::Object NativeAudioProcessingModule::createCustomProcessor(jsi::Runtime &runtime,
    //                                                                jsi::Value audioContextJSIValue) {
    //   auto context = audioContextJSIValue.asObject(runtime).getHostObject<audioapi::BaseAudioContextHostObject>(runtime);
    //   auto node = std::make_shared<audioapi::MyProcessorNode>(context->context_.get());
    //   auto nodeHostObject = std::make_shared<audioapi::CustomProcessorNodeHostObject>(node);
    //   return jsi::Object::createFromHostObject(runtime, nodeHostObject);
    // }
void NativeAudioProcessingModule::injectCustomProcessorInstaller(jsi::Runtime &runtime) {
  auto installer = createInstaller(runtime);
  runtime.global().setProperty(runtime, "createCustomProcessorNode", installer);
}

jsi::Function NativeAudioProcessingModule::createInstaller(jsi::Runtime &runtime) {
  return jsi::Function::createFromHostFunction(
      runtime,
      jsi::PropNameID::forAscii(runtime, "createCustomProcessorNode"),
      0,
      [](jsi::Runtime &runtime, const jsi::Value &thisVal, const jsi::Value *args, size_t count) {
          auto object = args[0].getObject(runtime);
          auto context = object.getHostObject<jsi::HostObject>(runtime);
          auto ctx2 = std::static_pointer_cast<audioapi::AudioContextHostObject>(context);
        if (ctx2 != nullptr) {
          auto node = std::make_shared<audioapi::MyProcessorNode>(ctx2->context_.get());
          auto nodeHostObject = std::make_shared<audioapi::AudioNodeHostObject>(node);
          return jsi::Object::createFromHostObject(runtime, nodeHostObject);
        }
        return jsi::Object::createFromHostObject(runtime, nullptr);
      });
    }
} // namespace facebook::react
