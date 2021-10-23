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
			typedef				reverse_iterator									rev_iter;

			typedef	typename	ft::iterator_traits<Iter>::iterator_category		iterator_category;
			typedef	typename	ft::iterator_traits<Iter>::value_type				value_type;
			typedef	typename 	ft::iterator_traits<Iter>::difference_type			difference_type;
			typedef	typename 	ft::iterator_traits<Iter>::pointer					pointer;
			typedef	typename 	ft::iterator_traits<Iter>::reference				reference;
			
			/* iterator Constructor: default, parameter, copy, assign */
			reverse_iterator() : _it(nullptr) {}

			/* The underlying iterator is initialized with x. */
			explicit reverse_iterator( iterator_type x ) : _it(x - 1) {}
			
			/* The underlying iterator is initialized with that of other rev_iter */
			template< class U >
			reverse_iterator( const reverse_iterator<U>& other ) : _it(other - 1) {}


			/* 	Return base iterator
			** 	The base iterator is an iterator of the same type as the one used to construct the reverse_iterator,
			**	but pointing to the element next to the one the reverse_iterator is currently pointing to
			**	(a reverse_iterator has always an offset of -1 with respect to its base iterator).
			*/
			iterator_type base() const { return this->_it + 1; }
			
			// reverse_iterator(pointer ptr) : _ptr(ptr) {}
			// reverse_iterator(const It& ref) : _ptr(ref._ptr) {}

			rev_iter & operator=(const rev_iter& ref){
				if (*this != ref)
					this->_it = ref.base();
				return (*this);
			}

			// Prefix increment in reverse -> decrement
			rev_iter& operator++() { _it--; return *this; }
			// Postfix increment
			rev_iter operator++(int) { rev_iter tmp = *this; --(_it); return (tmp); }
			// Prefix decrement in reverse -> increment
			rev_iter& operator--() { _it++; return *this; }
			// Postfix decrement
			rev_iter operator--(int) { rev_iter tmp = *this; ++(_it); return (tmp); }

			/* Returns a reverse iterator pointing to the element located n positions away from the element the iterator currently points to. */
			reverse_iterator operator+( difference_type n ) const { return reverse_iterator(this->_it - n); }
			reverse_iterator operator-( difference_type n ) const { return reverse_iterator(this->_it + n); }
			
			reverse_iterator& operator+=( difference_type n ) {
				this->_it -= n;
				return (*this);
			}
			reverse_iterator& operator-=( difference_type n ) {
				this->_it += n;
				return (*this);
			}

			reference 			operator*() { return *_it; }
			const reference 	operator*() const { return *_it; }
			pointer 			operator->() const { return &(operator*()); }

			reference operator[] (difference_type n) const { return this->base()[-n-1]; }

		private:
			iterator_type	_it;
	};

	template <class Iterator>
  	bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return lhs.base() == rhs.base(); };

	template <class Iterator>
	bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return lhs.base() != rhs.base(); }
	
	template <class Iterator>
	bool operator< (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return lhs.base() > rhs.base(); }
	
	template <class Iterator>
	bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return lhs.base() >= rhs.base(); }
	
	template <class Iterator>
	bool operator> (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return lhs.base() < rhs.base(); }
	
	template <class Iterator>
	bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return lhs.base() <= rhs.base(); }

	// template <class Iterator>
  	// reverse_iterator<Iterator> operator+ (
    //          typename reverse_iterator<Iterator>::difference_type n,
    //          const reverse_iterator<Iterator>& rev_it);

	// template <class Iterator>
  	// typename reverse_iterator<Iterator>::difference_type operator- (
    // 	const reverse_iterator<Iterator>& lhs,
    // 	const reverse_iterator<Iterator>& rhs);
}

#endif