#include "print.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <list>
//------------------------------------------------------------------------

TEST(Print_IP, OnCharType)
{
  std::string Printed;
  testing::internal::CaptureStdout();

  char CharIp = -1;
  Print(CharIp);
  Printed = testing::internal::GetCapturedStdout();
  EXPECT_EQ(Printed, (std::string) "255");    
}
//------------------------------------------------------------------------

TEST(Print_IP, OnShortType)
{
  std::string Printed;
  testing::internal::CaptureStdout();

  short ShortIp = 0;
  Print(ShortIp);
  Printed = testing::internal::GetCapturedStdout();
  EXPECT_EQ(Printed, (std::string) "0.0");   
}
//------------------------------------------------------------------------

TEST(Print_IP, OnIntType)
{
  std::string Printed;
  testing::internal::CaptureStdout();
  
  int IntIp = 2130706433;
  Print(IntIp);
  Printed = testing::internal::GetCapturedStdout();
  EXPECT_EQ(Printed, (std::string) "127.0.0.1"); 

}
//------------------------------------------------------------------------

TEST(Print_IP, OnLongType)
{
  std::string Printed;
  testing::internal::CaptureStdout();
  
  long long LongIp = 8875824491850138409;
  Print(LongIp);
  Printed = testing::internal::GetCapturedStdout();
  EXPECT_EQ(Printed, (std::string) "123.45.67.89.101.112.131.41"); 

}
//------------------------------------------------------------------------

TEST(Print_IP, OnStringType)
{
  std::string Printed;
  testing::internal::CaptureStdout();

  std::string StrIp = "255.144.0.1";
  Print(StrIp);
  Printed = testing::internal::GetCapturedStdout();
  EXPECT_EQ(Printed, StrIp); 
}
//------------------------------------------------------------------------

TEST(Print_IP, OnVectorType)
{
  std::string Printed;
  testing::internal::CaptureStdout();
  
  std::vector<unsigned char> VecIp {192, 168, 0, 1};
  Print(VecIp);  
  Printed = testing::internal::GetCapturedStdout();
  EXPECT_EQ(Printed, (std::string) "192.168.0.1"); 
}
//------------------------------------------------------------------------

TEST(Print_IP, OnListType)
{  
  std::string Printed;
  testing::internal::CaptureStdout();
  
  std::list<int> ListIp {99, 100, 101, 102};
  Print(ListIp);  
  Printed = testing::internal::GetCapturedStdout();
  EXPECT_EQ(Printed, (std::string) "99.100.101.102");
}
//------------------------------------------------------------------------

TEST(Print_IP, OnTupleType)
{
  std::string Printed;
  testing::internal::CaptureStdout();
  
  auto TupIp = std::make_tuple(10, 30, 0, 9);
  Print(TupIp);
  Printed = testing::internal::GetCapturedStdout();
  EXPECT_EQ(Printed, (std::string) "10.30.0.9");
}
//------------------------------------------------------------------------

TEST(Print_IP, OnEmptyVector)
{
  std::string Printed;
  testing::internal::CaptureStdout();
  
  std::vector<unsigned char> EmptyVecIp;
  Print(EmptyVecIp);  
  Printed = testing::internal::GetCapturedStdout();
  EXPECT_EQ(Printed, (std::string) ""); 
}
//------------------------------------------------------------------------

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  int Res = RUN_ALL_TESTS();
  return Res;
}
//------------------------------------------------------------------------
