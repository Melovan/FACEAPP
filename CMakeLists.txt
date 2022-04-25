# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)

project ("FaceAppApp")

# Add the cmake folder so the FindSphinx module is found
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/FaceApp/cmake" ${CMAKE_MODULE_PATH})

# Включите подпроекты.
add_subdirectory ("FaceApp/Tests")
add_subdirectory ("FaceApp/app")
add_subdirectory ("FaceApp/src")
add_subdirectory ("FaceApp/docs")
