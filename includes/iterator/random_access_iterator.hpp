#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include <iostream>
# include <string>
# include <memory>
# include "iterator.hpp"
# include "../utils/utils.hpp"

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

	template <typename T, class not_const_T = T>
	class random_access_iterator : public ft::iterator< random_access_iterator_tag, T >
	{
		public:
			
			typedef	typename ft::iterator<random_access_iterator_tag, T>::iterator_category			iterator_category;
			typedef	typename ft::iterator<random_access_iterator_tag, T>::pointer					pointer;
			typedef	typename ft::iterator<random_access_iterator_tag, T>::reference					reference;
			typedef	typename ft::iterator<random_access_iterator_tag, not_const_T>::value_type		value_type;
			typedef	typename ft::iterator<random_access_iterator_tag, T>::difference_type			difference_type;
			
			/* iterator Constructor: default, parameter, copy, assign */
			random_access_iterator() : _ptr(nullptr) {}
			random_access_iterator(pointer ptr) : _ptr(ptr) {}
			random_access_iterator(const random_access_iterator<not_const_T>& ref) : _ptr(ref.base()) {}
			virtual ~random_access_iterator() {}

			random_access_iterator & operator=(const random_access_iterator<not_const_T>& ref){
				if (this->base() != ref.base())
					this->_ptr = ref.base();
				return (*this);
			}
			random_access_iterator & operator+=(difference_type n){
				this->_ptr += n;
				return (*this);
			}
			random_access_iterator & operator-=(difference_type n){
				this->_ptr -= n;
				return (*this);
			}
			
			pointer				base() const { return this->_ptr; }

			/* Can be dereferenced as an rvalue (if in a dereferenceable state). */
			reference 			operator*() const { return *_ptr; }
			pointer 			operator->()  { return _ptr; }
			reference			operator[](int i) { return this->_ptr[i]; }

			// Prefix increment
			random_access_iterator& operator++() { _ptr++; return *this; }
			// Postfix increment
			random_access_iterator operator++(int) { random_access_iterator tmp = *this; ++(_ptr); return (tmp); }
			// Prefix decrement
			random_access_iterator& operator--() { _ptr--; return *this; }
			// Postfix decrement
			random_access_iterator operator--(int) { random_access_iterator tmp = *this; --(_ptr); return (tmp); }

			// arithmetics
			friend random_access_iterator	operator+(const random_access_iterator& a, difference_type b) { return random_access_iterator(a.base() + b); }
			friend random_access_iterator	operator+(difference_type b, const random_access_iterator& a) { return random_access_iterator(a.base() + b); }
			friend random_access_iterator	operator-(const random_access_iterator& a, difference_type b) { return random_access_iterator(a.base() - b); }
			friend random_access_iterator	operator-(difference_type b, const random_access_iterator& a) { return random_access_iterator(a.base() - b); }
			friend difference_type	operator-(const random_access_iterator& a, const random_access_iterator& b) { return (a.base() - b.base()); }

			// comparable with another iterator
			friend bool operator== (const random_access_iterator& a, const random_access_iterator& b) { return (a.base() == b.base()); }
			friend bool operator!= (const random_access_iterator& a, const random_access_iterator& b) { return (a.base() != b.base()); }
			friend bool operator<= (const random_access_iterator& a, const random_access_iterator& b) { return (a.base() <= b.base()); }
			friend bool operator>= (const random_access_iterator& a, const random_access_iterator& b) { return (a.base() >= b.base()); }
			friend bool operator< (const random_access_iterator& a, const random_access_iterator& b) { return (a.base() < b.base()); }
			friend bool operator> (const random_access_iterator& a, const random_access_iterator& b) { return (a.base() > b.base()); }
		private:
			pointer				_ptr;

	};
}

#endif