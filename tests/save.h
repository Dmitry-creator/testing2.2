
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <string>

#include "common.h"
#include "text.h"
#include "_text.h"
using namespace std;
TEST(save_fun, multiple_lines)
{
    std::string output_text = "";
    text txt = create_text();
    txt->myList->push_back("Hello world1");
    txt->myList->push_back("Hello world2");
    txt->length=2;

    txt->cursor->line_num = 0;
    txt->cursor->position = 0;
    save(txt, "save_fun.txt");

    text txt2 = create_text();
    load(txt2, "save_fun.txt");

    EXPECT_EQ(txt->myList->size(), txt2->myList->size());

    string* txt_arr = new string[txt->myList->size()];
    string* txt2_arr = new string[txt2->myList->size()];
    copy(txt->myList->begin(), txt->myList->end(), txt_arr);
    copy(txt2->myList->begin(), txt2->myList->end(), txt2_arr);

    for(unsigned int i = 0; i < txt->myList->size(); i++)
        EXPECT_STREQ(txt_arr[i].c_str(), txt2_arr[i].c_str());

    free(txt);
    free(txt2);
}

TEST(save_fun, one_line)
{
    text txt = create_text();
    txt->myList->push_back("Hello world1");
    txt->length=1;

    txt->cursor->line_num = 0;
    txt->cursor->position = 0;
    save(txt, "save_funn.txt");

    text txt2 = create_text();
    load(txt2, "save_funn.txt");

    EXPECT_EQ(txt->myList->size(), txt2->myList->size());

    string* txt_arr = new string[txt->myList->size()];
    string* txt2_arr = new string[txt2->myList->size()];
    copy(txt->myList->begin(), txt->myList->end(), txt_arr);
    copy(txt2->myList->begin(), txt2->myList->end(), txt2_arr);

    for(unsigned int i = 0; i < txt->myList->size(); i++)
        EXPECT_STREQ(txt_arr[i].c_str(), txt2_arr[i].c_str());

    free(txt);
    free(txt2);
}

TEST(save_fun, empty_file)
{
    text txt = create_text();
    txt->cursor->line_num = 0;
    txt->cursor->position = 0;
    txt->length=0;
    save(txt, "save_funnn.txt");

    text txt2 = create_text();
    load(txt2, "save_funnn.txt");

    EXPECT_EQ(txt->myList->size(), txt2->myList->size());

    string* txt_arr = new string[txt->myList->size()];
    string* txt2_arr = new string[txt2->myList->size()];

    copy(txt->myList->begin(), txt->myList->end(), txt_arr);
    copy(txt2->myList->begin(), txt2->myList->end(), txt2_arr);

    for(unsigned int i = 0; i < txt->myList->size(); i++)
        EXPECT_STREQ(txt_arr[i].c_str(), txt2_arr[i].c_str());

    free(txt);
    free(txt2);
}
