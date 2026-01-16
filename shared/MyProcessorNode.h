#pragma once
#include <audioapi/core/AudioNode.h>

namespace audioapi {
class AudioBus;

class MyProcessorNode : public AudioNode {
public:
  explicit MyProcessorNode(std::shared_ptr<BaseAudioContext> context);
  float getGain() const;
  void setGain(float value);

protected:
  std::shared_ptr<AudioBus> processNode(const std::shared_ptr<AudioBus> &bus,
                   int framesToProcess) override;

private:
  float gain_;
};
} // namespace audioapi