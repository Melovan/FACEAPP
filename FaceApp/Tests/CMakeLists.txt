# CMakeList.txt: ïðîåêò CMake äëÿ FaceApp; âêëþ÷èòå èñõîäíûé êîä è îïðåäåëåíèÿ,
# óêàæèòå çäåñü ëîãèêó äëÿ êîíêðåòíîãî ïðîåêòà.
#

project(Tests)

set(CMAKE_CXX_STANDARD 11)
#find_package( OpenCV REQUIRED )
#include_directories( ${OpenCV_INCLUDE_DIRS} )
find_package(GTest REQUIRED)
#include(FetchContent)
#FetchContent_Declare(
 # googletest
 #URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
#)
FILE(COPY "../resources" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")


# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
#FetchContent_MakeAvailable(googletest)
enable_testing()

include_directories("../include")
add_executable(Tests CMakeTest.cpp)
target_link_libraries(Tests FaceApp gtest_main gtest pthread)
#target_link_libraries(Tests ${OpenCV_LIBS} FaceApp)



# TODO: Äîáàâüòå òåñòû è öåëåâûå îáúåêòû, åñëè ýòî íåîáõîäèìî.
