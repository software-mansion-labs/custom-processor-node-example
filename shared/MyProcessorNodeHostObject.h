#pragma once

#include "MyProcessorNode.h"
#include <audioapi/HostObjects/AudioNodeHostObject.h>

#include <memory>
#include <vector>
#include <android/log.h>

namespace audioapi {
using namespace facebook;

class MyProcessorNodeHostObject : public AudioNodeHostObject {
public:
  explicit MyProcessorNodeHostObject(
      const std::shared_ptr<MyProcessorNode> &node)
      : AudioNodeHostObject(node) {
    __android_log_print(ANDROID_LOG_INFO, "my_processor_node_host", "Creating MyProcessorNodeHostObject");
    addGetters(JSI_EXPORT_PROPERTY_GETTER(MyProcessorNodeHostObject, gain));
    addSetters(JSI_EXPORT_PROPERTY_SETTER(MyProcessorNodeHostObject, gain));
  }

  ~MyProcessorNodeHostObject() override;

  JSI_PROPERTY_GETTER(gain) {
    auto processorNode = std::static_pointer_cast<MyProcessorNode>(node_);
    return {processorNode->getGain()};
  }

  JSI_PROPERTY_SETTER(gain) {
      __android_log_print(ANDROID_LOG_INFO, "my_processor_node_host", "Setting gain to %f", value.getNumber());
    auto processorNode = std::static_pointer_cast<MyProcessorNode>(node_);
    processorNode->setGain(value.getNumber());
  }
};
} // namespace audioapi
