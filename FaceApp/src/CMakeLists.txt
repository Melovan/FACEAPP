# CMakeList.txt: ������ CMake ��� FaceApp; �������� �������� ��� � �����������,
# ������� ����� ������ ��� ����������� �������.
#
cmake_minimum_required (VERSION 3.8)

project(FaceApp)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

# �������� �������� � ����������� ���� ����� �������.
add_library(FaceApp STATIC ../include/FaceApp.h "FaceApp.cpp")
target_link_libraries(FaceApp ${OpenCV_LIBS})
# TODO: �������� ����� � ������� �������, ���� ��� ����������.