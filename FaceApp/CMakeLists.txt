# CMakeList.txt: проект CMake для FaceApp; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project(FaceApp)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
include (cmake/ide.cmake)
include (cmake/platform.cmake)
add_library(my_library include/FaceApp.h src/FaceApp.cpp)

target_include_directories(my_library PUBLIC "include")
# Добавьте источник в исполняемый файл этого проекта.
add_executable (FaceApp WIN32 "app/START.cpp")
target_link_libraries( FaceApp ${OpenCV_LIBS} )
target_link_libraries(FaceApp
my_library)

# TODO: Добавьте тесты и целевые объекты, если это необходимо.