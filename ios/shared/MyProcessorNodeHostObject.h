#pragma once

#include "MyProcessorNode.h"
#include <audioapi/HostObjects/AudioNodeHostObject.h>

#include <memory>
#include <vector>

namespace audioapi {
using namespace facebook;

class MyProcessorNodeHostObject : public AudioNodeHostObject {
public:
  explicit MyProcessorNodeHostObject(
      const std::shared_ptr<MyProcessorNode> &node)
      : AudioNodeHostObject(node) {
    addGetters(JSI_EXPORT_PROPERTY_GETTER(MyProcessorNodeHostObject, gain));
    addSetters(JSI_EXPORT_PROPERTY_SETTER(MyProcessorNodeHostObject, gain));
  }

  JSI_PROPERTY_GETTER(gain) {
    auto processorNode = std::static_pointer_cast<MyProcessorNode>(node_);
    return {processorNode->getGain()};
  }

  JSI_PROPERTY_SETTER(gain) {
    auto processorNode = std::static_pointer_cast<MyProcessorNode>(node_);
    processorNode->setGain(value.getNumber());
  }
};
} // namespace audioapi
