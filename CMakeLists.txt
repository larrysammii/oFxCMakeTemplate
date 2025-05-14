cmake_minimum_required(VERSION 3.30)

# Edit project name for each project
project(mySketch)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define the openFrameworks path Edit OF_PATH accordingly if you want to use
# this template. (I'm too lazy to get it like an actual template ykwim)
set(OF_PATH "/Users/Larry/repo/of_v0.12.0_osx_release")
set(OF_LIBS_PATH "${OF_PATH}/libs")
set(OF_COMPILED_LIBS_PATH "${OF_LIBS_PATH}/openFrameworksCompiled/lib/osx")

# Include directories
include_directories(
  ${OF_PATH}/libs/openFrameworks
  ${OF_PATH}/libs/openFrameworks/3d
  ${OF_PATH}/libs/openFrameworks/app
  ${OF_PATH}/libs/openFrameworks/communication
  ${OF_PATH}/libs/openFrameworks/events
  ${OF_PATH}/libs/openFrameworks/gl
  ${OF_PATH}/libs/openFrameworks/graphics
  ${OF_PATH}/libs/openFrameworks/math
  ${OF_PATH}/libs/openFrameworks/sound
  ${OF_PATH}/libs/openFrameworks/types
  ${OF_PATH}/libs/openFrameworks/utils
  ${OF_PATH}/libs/openFrameworks/video
  ${OF_LIBS_PATH}/boost/include
  ${OF_LIBS_PATH}/cairo/include/cairo
  ${OF_LIBS_PATH}/curl/include
  ${OF_LIBS_PATH}/fmod/include
  ${OF_LIBS_PATH}/FreeImage/include
  ${OF_LIBS_PATH}/freetype/include
  ${OF_LIBS_PATH}/glew/include
  ${OF_LIBS_PATH}/glfw/include
  ${OF_LIBS_PATH}/glm/include
  ${OF_LIBS_PATH}/json/include
  ${OF_LIBS_PATH}/pugixml/include
  ${OF_LIBS_PATH}/rtAudio/include
  ${OF_LIBS_PATH}/tess2/include
  ${OF_LIBS_PATH}/uriparser/include
  ${OF_LIBS_PATH}/utf8/include)

# Source files
file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE HEADERS src/*.h)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Link libraries
target_link_libraries(
  ${PROJECT_NAME}
  "${OF_COMPILED_LIBS_PATH}/libopenFrameworksDebug.a"
  "${OF_LIBS_PATH}/boost/lib/osx/boost_filesystem.a"
  "${OF_LIBS_PATH}/boost/lib/osx/boost_system.a"
  "${OF_LIBS_PATH}/cairo/lib/osx/cairo.a"
  "${OF_LIBS_PATH}/curl/lib/osx/curl.a"
  "${OF_LIBS_PATH}/fmod/lib/osx/libfmod.dylib"
  "${OF_LIBS_PATH}/FreeImage/lib/osx/freeimage.a"
  "${OF_LIBS_PATH}/freetype/lib/osx/freetype.a"
  "${OF_LIBS_PATH}/glew/lib/osx/glew.a"
  "${OF_LIBS_PATH}/glfw/lib/osx/glfw3.a"
  "${OF_LIBS_PATH}/pugixml/lib/osx/pugixml.a"
  "${OF_LIBS_PATH}/rtAudio/lib/osx/rtaudio.a"
  "${OF_LIBS_PATH}/tess2/lib/osx/tess2.a"
  "${OF_LIBS_PATH}/uriparser/lib/osx/uriparser.a"
  "-framework Cocoa"
  "-framework OpenGL"
  "-framework IOKit"
  "-framework CoreVideo"
  "-framework CoreFoundation"
  "-framework CoreAudio"
  "-framework AudioToolbox"
  "-framework CoreServices"
  "-framework Security")

# Add Ons include_directories(${OF_DIRECTORY}/addons/ofxGui/src)

# Create Frameworks directory and copy libfmod.dylib
add_custom_command(
  TARGET ${PROJECT_NAME}
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_SOURCE_DIR}/Frameworks
  COMMAND
    ${CMAKE_COMMAND} -E copy_if_different
    ${OF_LIBS_PATH}/fmod/lib/osx/libfmod.dylib ${CMAKE_SOURCE_DIR}/Frameworks/)
