#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include <iostream>
# include <string>
# include <memory>
# include "iterator.hpp"

namespace ft
{
	template <typename Iter>
	class reverse_iterator
	{
		public:
			
			typedef				Iter												iterator_type;
			typedef	typename	ft::iterator_traits<Iter>::iterator_category		iterator_category;
			typedef	typename	ft::iterator_traits<Iter>::value_type				value_type;
			typedef	typename 	ft::iterator_traits<Iter>::difference_type			difference_type;
			typedef	typename 	ft::iterator_traits<Iter>::pointer					pointer;
			typedef	typename 	ft::iterator_traits<Iter>::reference				reference;
			
			/* iterator Constructor: default, parameter, copy, assign */
			reverse_iterator() : _it(nullptr) {}

			/* The underlying iterator is initialized with x. */
			explicit reverse_iterator( iterator_type x ) : _it(x.base()) {}
			
			/* The underlying iterator is initialized with that of other */
			template< class U >
			reverse_iterator( const reverse_iterator<U>& other ) {

			}
			
			reverse_iterator(pointer ptr) : _ptr(ptr) {}
			reverse_iterator(const It& ref) : _ptr(ref._ptr) {}
			virtual ~reverse_iterator() {}

			// It & operator=(const It& ref){
			// 	if (*this != ref)
			// 		this->_ptr = ref._ptr;
			// 	return (*this);
			// }

			// /* Returns the underlying base iterator. That is std::reverse_iterator(it).base() == it */
			// iterator_type base() const { return (_it); }

			// // ==
			// // +=
			// // -=
			
			// /* Can be dereferenced as an rvalue (if in a dereferenceable state). */
			// reference 			operator*() { return *_ptr; }
			// const reference 	operator*() const { return *_ptr; }
			// pointer 			operator->()  { return _ptr; }
			// reference			operator[](int i) { return this->_ptr[i]; }

			// // Prefix increment
			// It& operator++() { _ptr++; return *this; }
			// // Postfix increment
			// It operator++(int) { It tmp = *this; ++(_ptr); return (tmp); }
			// // Prefix decrement
			// It& operator--() { _ptr--; return *this; }
			// // Postfix decrement
			// It operator--(int) { It tmp = *this; --(_ptr); return (tmp); }

			// // arithmetics
			// friend It	operator+(const It& a, difference_type b) { return vector_iterator(a._ptr + b); }
			// friend It	operator+(difference_type b, const It& a) { return vector_iterator(a._ptr + b); }
			// friend It	operator-(const It& a, difference_type b) { return vector_iterator(a._ptr - b); }
			// friend It	operator-(difference_type b, const It& a) { return vector_iterator(a._ptr - b); }
			// friend difference_type	operator-(const It& a, const It& b) { return (a._ptr - b._ptr); }

			// // comparable with another iterator
			// friend bool operator== (const It& a, const It& b) { return (a._ptr == b._ptr); }
			// friend bool operator!= (const It& a, const It& b) { return (a._ptr != b._ptr); }
			// friend bool operator<= (const It& a, const It& b) { return (a._ptr <= b._ptr); }
			// friend bool operator>= (const It& a, const It& b) { return (a._ptr >= b._ptr); }
			// friend bool operator< (const It& a, const It& b) { return (a._ptr < b._ptr); }
			// friend bool operator> (const It& a, const It& b) { return (a._ptr > b._ptr); }
		
		private:
			iterator_type	_it;

	};
}

#endif