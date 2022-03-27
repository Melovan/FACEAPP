# CMakeList.txt: проект CMake для FaceApp; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project(App)

# Добавьте источник в исполняемый файл этого проекта.
include_directories("../include")

add_executable (App "App.cpp")
target_link_libraries(App FaceApp)

# TODO: Добавьте тесты и целевые объекты, если это необходимо.