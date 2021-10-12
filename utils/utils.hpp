#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <string>
# include <memory>

/* If B is true, std::enable_if has a public member typedef type, equal to T; otherwise, there is no member typedef. */
template < bool B, class T = void >
struct enable_if {};
 
template < class T >
struct enable_if<true, T> { typedef T type; };

/*
*   Returns true if T is an integral, false otherwise.
*/
template < class T >
struct is_integral { static const bool value = false };

template <>
struct is_integral<bool> { static const bool value = true };

template <>
struct is_integral<char> { static const bool value = true };

template <>
struct is_integral<char16_t> { static const bool value = true };

template <>
struct is_integral<char32_t> { static const bool value = true };

template <>
struct is_integral<wchar_t> { static const bool value = true };

template <>
struct is_integral<short> { static const bool value = true };

template <>
struct is_integral<int> { static const bool value = true };

template <>
struct is_integral<long> { static const bool value = true };

template <>
struct is_integral<long long> { static const bool value = true };

template <>
struct is_integral<int> { static const bool value = true };

template <>
struct is_integral<unsigned char> { static const bool value = true; };

template <>
struct is_integral<unsigned short> { static const bool value = true; };

template <>
struct is_integral<unsigned int> { static const bool value = true; };

template <>
struct is_integral<unsigned long> { static const bool value = true; };

template <>
struct is_integral<unsigned long long> { static const bool value = true; };

typedef	

#endif