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
    addGetters(JSI_EXPORT_PROPERTY_GETTER(CustomProcessorNodeHostObject, getGain));
    addSetters(JSI_EXPORT_PROPERTY_SETTER(CustomProcessorNodeHostObject, setGain));
  }

  JSI_PROPERTY_GETTER(getGain) {
    auto processorNode = std::static_pointer_cast<MyProcessorNode>(node_);
    return {processorNode->getGain()};
  }

  JSI_PROPERTY_SETTER(setGain) {
    auto processorNode = std::static_pointer_cast<MyProcessorNode>(node_);
    processorNode->setGain(value.getNumber());
  }
};
} // namespace audioapi
