# CMakeList.txt: ������ CMake ��� FaceApp; �������� �������� ��� � �����������,
# ������� ����� ������ ��� ����������� �������.
#
cmake_minimum_required (VERSION 3.8)

project(App)

# �������� �������� � ����������� ���� ����� �������.
include_directories("../include")
FILE(COPY "../resources" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
add_executable (App "App.cpp")
target_link_libraries(App FaceApp)

# TODO: �������� ����� � ������� �������, ���� ��� ����������.