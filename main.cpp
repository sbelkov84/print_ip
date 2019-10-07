#include "print.h"
//------------------------------------------------------------------------
#include <iostream>
#include <list>
//------------------------------------------------------------------------

int main()
{
  char Ch = -1;
  Print(Ch);
  std::cout << std::endl;

  short Sh = 0;
  Print(Sh);
  std::cout << std::endl;

  int a = 2130706433;
  Print(a);
  std::cout << std::endl;

  long long Lo = 8875824491850138409;
  Print(Lo);
  std::cout << std::endl;

  std::string s = "255.144.0.1";
  Print(s);
  std::cout << std::endl;

  std::vector<unsigned char> Vec {192, 168, 0, 1};
  Print(Vec);
  std::cout << std::endl;

  std::list<int> List {99, 100, 101, 102};
  Print(List);
  std::cout << std::endl;
 
  auto Tup = std::make_tuple(10, 30, 0, 9);
  Print(Tup);
  std::cout << std::endl;

  return 0;
}
//------------------------------------------------------------------------
