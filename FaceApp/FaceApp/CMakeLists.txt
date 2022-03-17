# CMakeList.txt: проект CMake для FaceApp; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project(FaceApp)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
# Добавьте источник в исполняемый файл этого проекта.
add_executable (FaceApp "FaceApp.cpp")
target_link_libraries( FaceApp ${OpenCV_LIBS} )
# TODO: Добавьте тесты и целевые объекты, если это необходимо.
