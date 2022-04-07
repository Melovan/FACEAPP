#include <iostream>
#include "FaceApp.h"
#include <gtest/gtest.h>


class FaceAppTest : public testing::Test {
protected:
    void SetUp() override {
        faceMask = cv::imread("resources/mask.jpg");

        if (!faceMask.data) {
            flag = 1;
        }
    }
    cv::Mat faceMask;
    char flag = 0;

};


TEST_F(FaceAppTest, SwapWorks) {
    EXPECT_EQ(flag, 0);
}
//TEST_F(HashTableTest, EraseWorks) {
//    bool r = t1.erase("Clark Kent");
//    EXPECT_EQ(r, true);
//    EXPECT_EQ(t1["Clark Kent"].weight, 70);
//}