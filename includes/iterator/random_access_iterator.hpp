#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include <iostream>
# include <string>
# include <memory>
# include "iterator.hpp"

/*
	This is a base class template that can be used to derive iterator classes from it.
	It is not an iterator class and does not provide any of the functionality an iterator is expected to have.
	This base class only provides some member types, which in fact are not required to be present in any iterator type
	(iterator types have no specific member requirements), but they might be useful, since they define the members 
	needed for the default iterator_traits class template to generate 
	the appropriate instantiation automatically (and such instantiation is required to be valid for all iterator types).
*/
namespace ft
{

	template <typename T>
	class random_access_iterator : public ft::iterator< random_access_iterator_tag, T >
	{
		public:
			
			typedef 		random_access_iterator			It;
			typedef	typename ft::iterator<random_access_iterator_tag, T>::iterator_category	iterator_category;
			typedef	typename ft::iterator<random_access_iterator_tag, T>::pointer			pointer;
			typedef	typename ft::iterator<random_access_iterator_tag, T>::reference			reference;
			typedef	typename ft::iterator<random_access_iterator_tag, T>::value_type		value_type;
			typedef	typename ft::iterator<random_access_iterator_tag, T>::difference_type	difference_type;

			//typedef	typename ft::iterator_traits<It>::iterator_category	iterator_category;
			//typedef	typename ft::iterator_traits<It>::pointer			pointer;
			//typedef	typename ft::iterator_traits<It>::reference			reference;
			//typedef	typename ft::iterator_traits<It>::value_type		value_type;
			//typedef	typename ft::iterator_traits<It>::difference_type	difference_type;
			
			/* iterator Constructor: default, parameter, copy, assign */
			random_access_iterator() : _ptr(nullptr) {}
			random_access_iterator(pointer ptr) : _ptr(ptr) {}
			random_access_iterator(const It& ref) : _ptr(ref._ptr) {}
			virtual ~random_access_iterator() {}

			It & operator=(const It& ref){
				if (*this != ref)
					this->_ptr = ref._ptr;
				return (*this);
			}
			It & operator+=(difference_type n){
				this->_ptr += n;
				return (*this);
			}
			It & operator-=(difference_type n){
				this->_ptr -= n;
				return (*this);
			}
			
			pointer				base() const { return this->_ptr; }

			/* Can be dereferenced as an rvalue (if in a dereferenceable state). */
			reference 			operator*() { return *_ptr; }
			const reference 	operator*() const { return *_ptr; }
			pointer 			operator->()  { return _ptr; }
			reference			operator[](int i) { return this->_ptr[i]; }

			// Prefix increment
			It& operator++() { _ptr++; return *this; }
			// Postfix increment
			It operator++(int) { It tmp = *this; ++(_ptr); return (tmp); }
			// Prefix decrement
			It& operator--() { _ptr--; return *this; }
			// Postfix decrement
			It operator--(int) { It tmp = *this; --(_ptr); return (tmp); }

			// arithmetics
			friend It	operator+(const It& a, difference_type b) { return It(a._ptr + b); }
			friend It	operator+(difference_type b, const It& a) { return It(a._ptr + b); }
			friend It	operator-(const It& a, difference_type b) { return It(a._ptr - b); }
			friend It	operator-(difference_type b, const It& a) { return It(a._ptr - b); }
			friend difference_type	operator-(const It& a, const It& b) { return (a._ptr - b._ptr); }

			// comparable with another iterator
			friend bool operator== (const It& a, const It& b) { return (a._ptr == b._ptr); }
			friend bool operator!= (const It& a, const It& b) { return (a._ptr != b._ptr); }
			friend bool operator<= (const It& a, const It& b) { return (a._ptr <= b._ptr); }
			friend bool operator>= (const It& a, const It& b) { return (a._ptr >= b._ptr); }
			friend bool operator< (const It& a, const It& b) { return (a._ptr < b._ptr); }
			friend bool operator> (const It& a, const It& b) { return (a._ptr > b._ptr); }
		private:
			pointer				_ptr;

	};
}

#endif