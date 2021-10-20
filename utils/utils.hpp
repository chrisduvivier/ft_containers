#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <string>
#include <memory>

#include <stdint.h>
#include <uchar.h>

namespace ft
{
	/* https://stackoverflow.com/questions/44517556/how-to-define-our-own-nullptr-in-c98 */
	const                         /* this is a const object...     */
	class nullptr_t
	{
		public:
		template<class T>          /* convertible to any type       */
		operator T*() const        /* of null non-member            */
			{ return 0; }           /* pointer...                    */

		template<class C, class T> /* or any type of null           */
			operator T C::*() const /* member pointer...             */
			{ return 0; }   

		private:
		void operator&() const;    /* Can't take address of nullptr */

	} nullptr = {};               /* and whose name is nullptr     */

	/* If B is true, std::enable_if has a public member typedef type, equal to T; otherwise, there is no member typedef. */
	template <bool B, class T = void>
	struct enable_if
	{
	};

	template <class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

	/*
	*   Returns true if T is an integral, false otherwise.
	*/

	template <class T>
	struct is_integral
	{
		static const bool value = false;
	};

	template <>
	struct is_integral<bool>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<char>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<char16_t>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<char32_t>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<wchar_t>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<short>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<int>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<long>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<long long>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<unsigned char>
	{
		static const bool value = true;
	};

	// template <>								// on VM, these 2 defs were causing issue since it's identical to char16_t and char32_t 
	// struct is_integral<unsigned short>
	// {
	// 	static const bool value = true;
	// };

	// template <>
	// struct is_integral<unsigned int>
	// {
	// 	static const bool value = true;
	// };

	template <>
	struct is_integral<unsigned long>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<unsigned long long>
	{
		static const bool value = true;
	};
} // namespace ft

#endif