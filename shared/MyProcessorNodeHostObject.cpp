#include "MyProcessorNodeHostObject.h"

namespace audioapi {
    MyProcessorNodeHostObject::~MyProcessorNodeHostObject() {
        __android_log_print(ANDROID_LOG_INFO, "my_processor_node_host", "Destroying MyProcessorNodeHostObject");
    }
}