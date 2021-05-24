#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "common.h"
#include "text.h"
#include "_text.h"

TEST(pn, normal)
{
    std::string output_text = "";

    text txt = create_text();
    txt->myList->push_back("Hello world1");
    txt->myList->push_back("Hello world2");
    txt->myList->push_back("Hello world3");
    txt->length=3;
    output_text += "Hello world1";
    output_text += "|Hello world2";
    output_text += "klll";
    output_text += "Hello world3";

    //захват вывода
    testing::internal::CaptureStdout();
    mklb(txt,1);
    pn(txt,"klll");
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());

    free(txt);

}


TEST(pn, normal2)
{
    std::string output_text = "";

    text txt = create_text();
    txt->myList->push_back("Hello world1");
    txt->myList->push_back("Hello world2");
    txt->myList->push_back("Hello world3");
    txt->length=3;
    output_text += "Hello world1";
    output_text += "Hello world2";
    output_text += "|Hello world3";
    output_text += "";

    //захват вывода
    testing::internal::CaptureStdout();
    mklb(txt,2);
    pn(txt,"");
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), output_text.c_str());

    free(txt);

}
