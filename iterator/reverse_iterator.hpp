#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include <iostream>
# include <string>
# include <memory>
# include "iterator.hpp"


/* 
**	https://en.cppreference.com/w/cpp/iterator/reverse_iterator
*/
namespace ft
{
	template <typename Iter>
	class reverse_iterator
	{
		public:
			
			/* Member types */
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
			
			/* The underlying iterator is initialized with that of other rev_iter */
			template< class It >
			reverse_iterator( const reverse_iterator<It>& rev_iter ) : _it(rev_iter.base()) {}

			iterator_type base() const { return this->_it; }
			
			// reverse_iterator(pointer ptr) : _ptr(ptr) {}
			// reverse_iterator(const It& ref) : _ptr(ref._ptr) {}
			virtual ~reverse_iterator() {}
		
		private:
			iterator_type	_it;

	};
}

#endif