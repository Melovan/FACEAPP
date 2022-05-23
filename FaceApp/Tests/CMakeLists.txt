# CMakeList.txt: проект CMake для FaceApp; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

project(Tests)

set(CMAKE_CXX_STANDARD 11)
#find_package( OpenCV REQUIRED )
#include_directories( ${OpenCV_INCLUDE_DIRS} )
find_package(GTest REQUIRED)
FILE(COPY "../resources" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")


# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

enable_testing()

include_directories("../include")
add_executable(Tests CMakeTest.cpp)
target_link_libraries(Tests FaceApp gtest_main gtest pthread)
#target_link_libraries(Tests ${OpenCV_LIBS} FaceApp)



# TODO: Добавьте тесты и целевые объекты, если это необходимо.