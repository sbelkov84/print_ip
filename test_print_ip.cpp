#include "print.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <list>
//------------------------------------------------------------------------

TEST(Print_IP, OnIntegralTypes)
{
  std::string Printed;
  testing::internal::CaptureStdout();

  char CharIp = -1;
  Print(CharIp);
  Printed = testing::internal::GetCapturedStdout();
  EXPECT_EQ(Printed, (std::string) "255");    
}
//------------------------------------------------------------------------

TEST(Print_IP, OnString)
{
}
//------------------------------------------------------------------------
/*
TEST(Print_IP, OnVector)
{
 TCustomContainer<int, TCustomAllocator<std::pair<int, int>>> CustContMyAlloc;
  for (int i = 0; i < 10; ++i)
  {
    CustContMyAlloc.push_back(i + 1);
  }

  int i = 1;
  for (auto it = CustContMyAlloc.begin(); it != CustContMyAlloc.end(); ++it)
  {
    EXPECT_EQ(*it, i);    
    ++i;
  }
}
//------------------------------------------------------------------------

TEST(Print_IP, OnList)
{
  std::map<int, int, std::less<int>, TCustomAllocator<std::pair<int, int>>> SomeMap;
  for (int i = 0; i < 11; ++i)
  {
    SomeMap[i] = Factorial(i);
  }

  int i = 0;
  for (auto it = SomeMap.cbegin(); it != SomeMap.end(); ++it)
  {
    EXPECT_EQ(it->second, Factorial(i));    
    ++i;
  }
}
//------------------------------------------------------------------------

TEST(Print_IP, OnTuple)
{
}
//------------------------------------------------------------------------

TEST(Print_IP, OnEmptyVector)
{
}*/
//------------------------------------------------------------------------

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  int Res = RUN_ALL_TESTS();
  return Res;
}
//------------------------------------------------------------------------
