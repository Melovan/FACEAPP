#include <iostream>
#include "FaceApp.h"
#include <gtest/gtest.h>
/*! \file */
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


TEST_F(FaceAppTest, resources_test) {
    EXPECT_EQ(flag, 0);
    std::string faceCascadeName = "resources//face.xml";
    cv::CascadeClassifier faceCascade;

    EXPECT_EQ(!faceCascade.load(faceCascadeName), 0);
}
TEST_F(FaceAppTest, camera_test)
{
    cv::VideoCapture cap(0);


    EXPECT_EQ(!cap.isOpened(), 0);
}

//TEST_F(HashTableTest, EraseWorks) {
//    bool r = t1.erase("Clark Kent");
//    EXPECT_EQ(r, true);
//    EXPECT_EQ(t1["Clark Kent"].weight, 70);
//}