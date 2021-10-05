#ifndef PAIR_HPP
#define PAIR_HPP

#include <utility>

// https://gcc.gnu.org/onlinedocs/libstdc++/libstdc++-html-USERS-4.3/a02030.html

template <class T1, class T2>
struct pair
{
	/****************************
	*	   Member types  		*
	****************************/

	typedef T1 first_type;
	typedef T2 second_type;

	/****************************
	*	   Member variables  	*
	****************************/

	T1 first;
	T2 second;

	/****************************
	*	   Member functions		*
	****************************/

	pair(): first(), second() {}

	template <class U, class V>
	pair(const pair<U, V> &other): first(other.first), second(other.second) {}

	pair(const first_type &a, const second_type &b): first(a), second(b) {}

	/****************************
	*	   Operator overloads   *
	****************************/

	pair &operator=(const pair &other)
	{
		if (this == &other)
			return *this;
		this->first = other.first;
		this->second = other.second;
		return *this;
	}

	bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) { return lhs.first == rhs.first && lhs.second == rhs.second; }
	bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) { return !(lhs == rhs); }
	bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) { return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);}
	bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) { return (rhs < lhs); }
	bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) { return !(rhs < lhs) }
	bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) { return !(lhs < rhs)}
	
};

template <class T1, class T2>
pair<T1, T2> make_pair(T1 x, T2 y)
{
	return (pair<T1, T2>(x, y));
}

#endif