# CMakeList.txt: проект CMake для FaceApp; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

project(Tests)

set(CMAKE_CXX_STANDARD 11)
#find_package( OpenCV REQUIRED )
#include_directories( ${OpenCV_INCLUDE_DIRS} )

FILE(COPY "../resources" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

include_directories("../include")
add_executable(Tests CMakeTest.cpp)
target_link_libraries(Tests FaceApp gtest_main)
#target_link_libraries(Tests ${OpenCV_LIBS} FaceApp)



# TODO: Добавьте тесты и целевые объекты, если это необходимо.