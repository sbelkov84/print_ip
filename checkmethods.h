#pragma once
//------------------------------------------------------------------------
#include <type_traits>
#include <utility>
//------------------------------------------------------------------------

/*! \brief With help of these struct we detect: std:string, std:vector, std::list (if false).*/
/*! HasIterators(false_type) */
template <typename Type, typename = void>
struct HasIterators : std::false_type {}; /*!< If Iterators doesn't exist inside "Type"-class*/ 

/*! \brief With help of these struct we detect: std:string, std:vector, std::list (it true).*/
/*! HasIterators(true_type) */
template <typename Type>
struct HasIterators<Type, std::void_t<decltype(std::declval<Type>().begin()),
                                      decltype(std::declval<Type>().end())>> :
				      std::true_type{}; /*!< If Iterators exists inside "Type"-class*/  

template <typename T>
constexpr bool HasIterators_v = HasIterators<T>::value;
//------------------------------------------------------------------------


/*! \brief If we can't use on "Type"-class "tuple_size"-method
 * With help of these structs we detect std::tuple*/
/*! CanUsedByStdTupleSize(false_type)
 */
template <typename Type, typename = void>
struct CanUsedByStdTupleSize : std::false_type{};

/*! \brief If we can use on "Type"-class "tuple_size"-method
 * With help of these structs we detect std::tuple*/
/*! CanUsedByStdTupleSize(true_type)
 */
template <typename Type>
struct CanUsedByStdTupleSize<Type, std::void_t<decltype(std::tuple_size<Type>::value)>> : std::true_type{};

template <typename T>
constexpr bool CanUsedByStdTupleSize_v = CanUsedByStdTupleSize<T>::value;
//------------------------------------------------------------------------