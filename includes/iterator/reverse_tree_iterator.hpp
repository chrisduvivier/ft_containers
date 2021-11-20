#ifndef REVERSE_TREE_ITERATOR_HPP
# define REVERSE_TREE_ITERATOR_HPP

# include <iostream>
# include <string>
# include <memory>
# include "iterator.hpp"
# include "tree_iterator.hpp"
# include "../utils/utils.hpp"
/* 
**	https://en.cppreference.com/w/cpp/iterator/reverse_iterator
*/
namespace ft
{
	template <typename Iter>
	class reverse_tree_iterator
	{
		public:
			
			typedef				Iter											iterator_type;
			typedef	typename 	iterator_type::difference_type					difference_type;
			typedef	typename 	iterator_type::pointer							pointer;
			typedef	typename 	iterator_type::reference						reference;
			typedef	typename 	iterator_type::const_reference					const_reference;
			
			/* iterator Constructor: default, parameter, copy, assign */
			reverse_tree_iterator() : _it(nullptr, nullptr) {};

			/* The underlying iterator is initialized with x. */
			explicit reverse_tree_iterator( iterator_type x ) {
				x--;
				this->_it = x;
			}
			
			/* The underlying iterator is initialized with that of other reverse_tree_iterator */
			template< class U >
			reverse_tree_iterator( const reverse_tree_iterator<U>& other ) {
				this->_it = other->_it;
			}

			/* 	Return base iterator
			** 	The base iterator is an iterator of the same type as the one used to construct the reverse_iterator,
			**	but pointing to the element next to the one the reverse_iterator is currently pointing to
			**	(a reverse_iterator has always an offset of -1 with respect to its base iterator).
			*/
			iterator_type base() const { 
				iterator_type tmp(this->_it);
				tmp++;
				return tmp; 
			}

			reverse_tree_iterator & operator=(const reverse_tree_iterator& ref){
				if (*this != ref)
					this->_it = ref._it;
				return (*this);
			}

			// Prefix increment in reverse -> decrement
			reverse_tree_iterator& operator++() { _it--; return *this; }
			// Postfix increment
			reverse_tree_iterator operator++(int) { reverse_tree_iterator tmp = *this; --(_it); return (tmp); }
			// Prefix decrement in reverse -> increment
			reverse_tree_iterator& operator--() { _it++; return *this; }
			// Postfix decrement
			reverse_tree_iterator operator--(int) { reverse_tree_iterator tmp = *this; ++(_it); return (tmp); }

			reference 			operator*() { return *_it; }
			const_reference 	operator*() const { return *_it; }
			pointer 			operator->() { return &(operator*()); }

		private:
			iterator_type	_it;
	};

	template <class Iterator>
  	bool operator== (const reverse_tree_iterator<Iterator>& lhs, const reverse_tree_iterator<Iterator>& rhs) { return lhs.base() == rhs.base(); };

	template <class Iterator>
	bool operator!= (const reverse_tree_iterator<Iterator>& lhs, const reverse_tree_iterator<Iterator>& rhs) { return lhs.base() != rhs.base(); }

	template <typename Iter>
	class const_reverse_tree_iterator
	{
		public:
			
			typedef				Iter											iterator_type;
			typedef	typename 	iterator_type::difference_type					difference_type;
			typedef	typename 	iterator_type::pointer							pointer;
			typedef	typename 	iterator_type::reference						reference;
			typedef	typename 	iterator_type::const_reference					const_reference;
			
			/* iterator Constructor: default, parameter, copy, assign */
			const_reverse_tree_iterator() : _it(nullptr, nullptr) {};

			/* The underlying iterator is initialized with x. */
			explicit const_reverse_tree_iterator(const iterator_type x ) {
				iterator_type tmp(x);
				tmp--;
				this->_it = tmp;
			}
			
			/* The underlying iterator is initialized with that of other reverse_tree_iterator */
			template< class U >
			const_reverse_tree_iterator( const const_reverse_tree_iterator<U>& other ) {
				this->_it = other->_it;
			}

			const_reverse_tree_iterator & operator=(const const_reverse_tree_iterator& ref){
				if (*this != ref)
					this->_it = ref._it;
				return (*this);
			}

			/* 	Return base iterator
			** 	The base iterator is an iterator of the same type as the one used to construct the reverse_iterator,
			**	but pointing to the element next to the one the reverse_iterator is currently pointing to
			**	(a reverse_iterator has always an offset of -1 with respect to its base iterator).
			*/
			iterator_type base() const { 
				iterator_type tmp(this->_it);
				tmp++;
				return tmp; 
			}


			// Prefix increment in reverse -> decrement
			const_reverse_tree_iterator& operator++() { _it--; return *this; }
			// Postfix increment
			const_reverse_tree_iterator operator++(int) { const_reverse_tree_iterator tmp = *this; --(_it); return (tmp); }
			// Prefix decrement in reverse -> increment
			const_reverse_tree_iterator& operator--() { _it++; return *this; }
			// Postfix decrement
			const_reverse_tree_iterator operator--(int) { const_reverse_tree_iterator tmp = *this; ++(_it); return (tmp); }

			reference 			operator*() { return *_it; }
			const_reference 	operator*() const { return *_it; }
			pointer 			operator->() { return &(operator*()); }

		private:
			iterator_type	_it;
	};
	
	template <class Iterator>
  	bool operator== (const const_reverse_tree_iterator<Iterator>& lhs, const const_reverse_tree_iterator<Iterator>& rhs) { return lhs.base() == rhs.base(); };

	template <class Iterator>
	bool operator!= (const const_reverse_tree_iterator<Iterator>& lhs, const const_reverse_tree_iterator<Iterator>& rhs) { return lhs.base() != rhs.base(); }
}

#endif