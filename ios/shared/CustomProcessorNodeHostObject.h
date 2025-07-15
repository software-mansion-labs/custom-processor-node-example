#pragma once

#include <audioapi/HostObjects/AudioNodeHostObject.h>
#include "MyProcessorNode.h"

#include <memory>
#include <vector>

namespace audioapi {
using namespace facebook;

class CustomProcessorNodeHostObject : public AudioNodeHostObject {
 public:
  explicit CustomProcessorNodeHostObject(const std::shared_ptr<MyProcessorNode> &node)
      : AudioNodeHostObject(node) {
    addGetters(JSI_EXPORT_PROPERTY_GETTER(CustomProcessorNodeHostObject, gain));
    addSetters(JSI_EXPORT_PROPERTY_SETTER(CustomProcessorNodeHostObject, gain));
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
