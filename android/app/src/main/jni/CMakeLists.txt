cmake_minimum_required(VERSION 3.13)

# Define the library name here.
project(appmodules)

set(ROOT ${CMAKE_SOURCE_DIR}/../../../../..)

# This file includes all the necessary to let you build your React Native application
include(${REACT_ANDROID_DIR}/cmake-utils/ReactNative-application.cmake)

file(GLOB_RECURSE RNAUDIOAPI_SRC
  CONFIGURE_DEPENDS
  "${ROOT}/node_modules/react-native-audio-api/common/cpp/audioapi/*.cpp"
  "${ROOT}/node_modules/react-native-audio-api/android/src/main/cpp/audioapi/android/core/AudioDecoder.cpp"
)

list(REMOVE_ITEM RNAUDIOAPI_SRC "${ROOT}/node_modules/react-native-audio-api/common/cpp/audioapi/core/AudioContext.cpp")

file(GLOB_RECURSE RNAUDIOAPI_LIBS
  CONFIGURE_DEPENDS
  "${ROOT}/node_modules/react-native-audio-api/common/cpp/audioapi/libs/*.c"
  "${ROOT}/node_modules/react-native-audio-api/common/cpp/audioapi/libs/*.h"
)

add_library(rnaudioapi_c STATIC ${RNAUDIOAPI_LIBS})

target_include_directories(rnaudioapi_c PUBLIC
  ${ROOT}/node_modules/react-native-audio-api/common/cpp
)

# Define where the additional source code lives. We need to crawl back the jni, main, src, app, android folders
target_sources(${CMAKE_PROJECT_NAME} PRIVATE ${ROOT}/shared/NativeAudioProcessingModule.cpp
    ${ROOT}/shared/MyProcessorNode.cpp
    ${RNAUDIOAPI_SRC})

# Define where CMake can find the additional header files. We need to crawl back the jni, main, src, app, android folders
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${ROOT}/shared
    ${ROOT}/node_modules/react-native-audio-api/common/cpp)

target_link_libraries(${CMAKE_PROJECT_NAME} rnaudioapi_c android log)
