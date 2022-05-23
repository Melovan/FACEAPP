# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project ("FaceAppApp")
# Включите подпроекты.
add_subdirectory ("FaceApp/Tests")
add_subdirectory ("FaceApp/app")
add_subdirectory ("FaceApp/src")
add_subdirectory ("docs")