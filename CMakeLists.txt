# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)

project ("FaceAppApp")

# Включите подпроекты.
add_subdirectory ("FaceApp/Tests")
add_subdirectory ("FaceApp/app")
add_subdirectory ("FaceApp/src")
