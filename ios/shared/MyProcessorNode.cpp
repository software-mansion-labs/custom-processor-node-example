#include "MyProcessorNode.h"
#include <audioapi/dsp/VectorMath.h>
#include <audioapi/utils/AudioArray.h>
#include <audioapi/utils/AudioBus.h>

namespace audioapi {
MyProcessorNode::MyProcessorNode(BaseAudioContext *context)
    : AudioNode(context), gain_(0.1) {
  isInitialized_ = true;
}

float MyProcessorNode::getGain() const { return gain_; }

void MyProcessorNode::setGain(float value) { gain_ = value; }

void MyProcessorNode::processNode(const std::shared_ptr<AudioBus> &bus,
                                  int framesToProcess) {
  for (int i = 0; i < bus->getNumberOfChannels(); ++i) {
    auto channel = bus->getChannel(i);
    dsp::multiplyByScalar(channel->getData(), gain_, channel->getData(),
                          framesToProcess);
  }
}
} // namespace audioapi