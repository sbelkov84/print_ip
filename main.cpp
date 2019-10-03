#include "print.h"
//------------------------------------------------------------------------
#include <iostream>
#include <list>
//------------------------------------------------------------------------

int main()
{
  char Ch = -1;
  Print(Ch);
  short Sh = 0;
  Print(Sh);
  int a = 2130706433;
  Print(a);
  long long Lo = 8875824491850138409;
  Print(Lo);
  std::string s = "255.144.0.1";
  Print(s);
  std::vector<unsigned char> Vec {192, 168, 0, 1};
  Print(Vec);
  std::list<int> List {99, 100, 101, 102};
  Print(List); 
  auto Tup = std::make_tuple(10, 30, 0, 9);
  Print(Tup);

  return 0;
}
//------------------------------------------------------------------------
