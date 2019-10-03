#pragma once
//------------------------------------------------------------------------
#include "checkmethods.h"
//------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <tuple>
//------------------------------------------------------------------------

/*! \brief Recursive template that using to put std::tuple elements to std::vector*/ 
/*! TTuplePrinter (n) */
template <std::size_t n, typename T, std::vector<unsigned char>* PrintedIp>
struct TTuplePrinter
{ 
  //*! \brief Function that fill std::vector, which elements will be printed as ip-octets. For [1st; (n-1)th] std::tuple elements 
  
  static void FillPrintedVec(T Tuple)
  { 
    TTuplePrinter<n - 1, T, PrintedIp>::FillPrintedVec(Tuple);
    PrintedIp->emplace_back((unsigned char) std::get<n>(Tuple));  
  }
};
//------------------------------------------------------------------------

/*! \brief Last recursive template to put 0th std::tuple element to std::vector*/
/*! TTuplePrinter (0) */
template <typename T, std::vector<unsigned char>* PrintedIp>
struct TTuplePrinter<0, T, PrintedIp> 
{
  //*! \brief Function that fill std::vector, which elements will be printed as ip-octets. For 0th std::tuple element
  static void FillPrintedVec(T Tuple)
  {
    PrintedIp->emplace_back((unsigned char) std::get<0>(Tuple));
  }
};
//------------------------------------------------------------------------

/*! \brief Prints ip-addresses stored inside std containers and std::tuples */
/*! void Print(...) */
template <typename T>
typename std::enable_if<HasIterators_v<T> || CanUsedByStdTupleSize_v<T>, void>::type
Print(T Value)
{
  if constexpr(std::is_same<std::string, typename std::remove_reference_t<std::remove_const_t<T>>>::value) 
  {
    for (auto It = Value.begin(); It != Value.end(); ++It)
      std::cout << *It;
    std::cout << std::endl;
  }
  else if constexpr(HasIterators_v<T>)
  {
    //*! \brief Counter using for detect last ip-octet
    //*! size_t Count
    size_t Count = 0; 
    for (auto It = Value.begin(); It != Value.end(); ++It)
    {
      std::cout << (int) *It;
      if (Count != Value.size() - 1) 
        std::cout << ".";
      //---
      ++Count;
    }
    std::cout << std::endl;
  }
  else if constexpr(CanUsedByStdTupleSize_v<T>)
  {
    //*! \brief std::vector to store and print ip-octets
    //*! std::vector<unsigned char> PrintedIp
    static std::vector<unsigned char> PrintedIp; 
    TTuplePrinter<(std::size_t) std::tuple_size<T>::value - 1, T, &PrintedIp>::FillPrintedVec(Value); //! Put std::tuple elements to std::vector
    //*! \brief Counter using for detect last ip-octet
    //*! size_t Count
    size_t Count = 0; 
    for (auto It = PrintedIp.begin(); It != PrintedIp.end(); ++It)
    {
      std::cout << (int) *It;
      if (Count != PrintedIp.size() - 1) 
        std::cout << ".";
      //---
      ++Count;
    }
    std::cout << std::endl;
  };
}
//------------------------------------------------------------------------

//*! \brief Prints ip-addresses stored inside integral types
//*! void Print(...)

template <typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
Print(T Value)
{
  //*! \brief std::vector to store and print ip-octets
  //*! std::vector<unsigned char> PrintedIp    
  std::vector<unsigned char> PrintedIp;

  //*! \brief Getting type-size in bytes
  //*! int Size
  int Size = sizeof(T) / sizeof(unsigned char);  

  //*! \brief Getting in cycle each byte of input integral Value with help of raw-pointer 
  for (int i = 0; i < Size; ++i) 
  {
    unsigned char CurChar = *(((unsigned char*)&Value) + i);
    PrintedIp.emplace_back(CurChar);
  }
  //---
  //*! \brief Counter using for detect last ip-octet
  //*! size_t COunt
  size_t Count = 0; 
  for (auto It = PrintedIp.crbegin(); It != PrintedIp.crend(); ++It)
  {
    std::cout << (int) *It;
    if (Count != PrintedIp.size() - 1)  
      std::cout << ".";
    //---
    ++Count;
  }
  std::cout << std::endl; 
}
//------------------------------------------------------------------------
