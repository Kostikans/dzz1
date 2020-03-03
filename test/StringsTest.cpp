//
// Created by kostikan on 01.03.2020.
//

#include "gtest/gtest.h"
extern "C" {
#include "DateString.h"
}

TEST(string1,str1)
{
    StringData str1;
    StringData temp1;
    str1.size = 1;
    str1.data = (char **) malloc(str1.size * sizeof(char *));
    str1.data[0] = (char*)"rewklrewkl";
    ASSERT_EQ(getDateStringsReg(&str1,&temp1),0);
    FreeTestStrings(&str1);
    FreeStrings(&temp1);
}

TEST(string2,str2)
{
    StringData str2;
    StringData temp2;
    str2.size = 1;
    str2.data = (char **) malloc(str2.size * sizeof(char *));
    str2.data[0] = (char*)"g 23:50:40 tkrekt";
    ASSERT_EQ(getDateStringsReg(&str2,&temp2),1);
    FreeTestStrings(&str2);
    FreeStrings(&temp2);
}

TEST(string3,str3)
{
    StringData str3;
    StringData temp3;
    str3.size = 1;
    str3.data = (char **) malloc(str3.size * sizeof(char *));
    str3.data[0] = (char*)"4534 23:65:1 r";
    ASSERT_EQ(getDateStringsReg(&str3,&temp3),0);
    FreeTestStrings(&str3);
    FreeStrings(&temp3);
}

TEST(string4,str4)
{
    StringData str4;
    StringData temp4;
    str4.size = 1;
    str4.data = (char **) malloc(str4.size * sizeof(char *));
    str4.data[0] = (char*)"00:50:40";
    ASSERT_EQ(getDateStringsReg(&str4,&temp4),1);
    FreeTestStrings(&str4);
    FreeStrings(&temp4);
 }

TEST(string5,str5)
{
    StringData str5;
    StringData temp5;
    str5.size = 1;
    str5.data = (char **) malloc(str5.size * sizeof(char *));
    str5.data[0] = (char*)"rtr 23:20:43 t";
    ASSERT_EQ(getDateStringsReg(&str5,&temp5),1);
    FreeTestStrings(&str5);
    FreeStrings(&temp5);
}

TEST(string6,str6)
{
    StringData str;
    StringData temp;
    str.size = 1;
    str.data = (char **) malloc(str.size * sizeof(char *));
    str.data[0] = (char*)"r 01:10:20 t";
    ASSERT_EQ(getDateStringsReg(&str,&temp),1);
    FreeTestStrings(&str);
    FreeStrings(&temp);
}

TEST(string7,str7)
{
    StringData str;
    StringData temp;
    str.size = 1;
    str.data = (char **) malloc(str.size * sizeof(char *));
    str.data[0] = (char*)"tre23:10:30";
    ASSERT_EQ(getDateStringsReg(&str,&temp),1);
    FreeTestStrings(&str);
    FreeStrings(&temp);
}

TEST(string8,str8)
{
    StringData str;
    StringData temp;
    str.size = 1;
    str.data = (char **) malloc(str.size * sizeof(char *));
    str.data[0] = (char*)"25:23:12";
    ASSERT_EQ(getDateStringsReg(&str,&temp),0);
    FreeTestStrings(&str);
    FreeStrings(&temp);
}

TEST(string9,str9)
{
    StringData str;
    StringData temp;
    str.size = 1;
    str.data = (char **) malloc(str.size * sizeof(char *));
    str.data[0] = (char*)"23:1:2";
    ASSERT_EQ(getDateStringsReg(&str,&temp),0);
    FreeTestStrings(&str);
    FreeStrings(&temp);
}

TEST(string10,str10)
{
    StringData str;
    StringData temp;
    str.size = 1;
    str.data = (char **) malloc(str.size * sizeof(char *));
    str.data[0] = (char*)"23:70:70";
    ASSERT_EQ(getDateStringsReg(&str,&temp),0);
    FreeTestStrings(&str);
    FreeStrings(&temp);
}
