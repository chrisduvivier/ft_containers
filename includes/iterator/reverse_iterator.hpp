#ifndef reverse_iterator_HPP
# define reverse_iterator_HPP

# include <iostream>
# include <string>
# include <memory>
# include "iterator.hpp"

/*************************************************************************
**     https://en.cppreference.com/w/cpp/iterator/reverse_iterator      **
**     https://www.cplusplus.com/reference/iterator/reverse_iterator    **
**************************************************************************/

namespace ft
{
	template <typename Iter>
	class reverse_iterator
	{

		/********************************
		 *          MEMBER TYPE
		**********************************/
		public:

		typedef				Iter											iterator_type;
		typedef	typename	ft::iterator_traits<Iter>::iterator_category	iterator_category;
		typedef	typename	ft::iterator_traits<Iter>::value_type			value_type;
		typedef	typename	ft::iterator_traits<Iter>::difference_type		difference_type;
		typedef	typename	ft::iterator_traits<Iter>::pointer				pointer;
		typedef	typename	ft::iterator_traits<Iter>::reference			reference;

		/*************************************
		 *          MEMBER FUNCTIONS
		**************************************/
		
		/*****---------------- CONSTRUCTOR ----------------*****/

		/* (1) Default constructor. The underlying iterator is value-initialized. 
		** Operations on the resulting iterator have defined behavior if and only if 
		** the corresponding operations on a value-initialized 
		** Iter also have defined behavior. */
		reverse_iterator() : _it() {}

		/* (2) initalization constructor. The underlying iterator is initialized with x. */
		explicit reverse_iterator( iterator_type x ) { this->_it = x;}
		
		/* (3) copy / type-cast constructor
		** Constructs a reverse iterator from some other reverse iterator.
		** The constructed object keeps the same sense of iteration as rev_it. */
		template< class U >
		reverse_iterator( const reverse_iterator<U>& other ): _it(other.base()) {}

		/*****---------------- BASE ----------------*****/

		/* 	Return a copy of the base iterator
		** 	The base iterator is an iterator of the same type as the one used to construct the reverse_iterator,
		**	but pointing to the element next to the one the reverse_iterator is currently pointing to
		**	(a reverse_iterator has always an offset of -1 with respect to its base iterator).
		*/
		iterator_type base() const {
			return this->_it;
		}

		/*****---------------- OPERATOR ----------------*****/

		/* operator=
		** Assigns rev_it's base iterator to the object's base iterator, replacing its current value. 
		*/
		template <class U>
		reverse_iterator& operator=(const reverse_iterator<U>& rev_it){
			if (this->base() == rev_it.base())
				return (*this);
			this->_it = rev_it.base();
			return (*this);
		}

		/* operator*()
		** Returns a reference to the element pointed to by the iterator.
		*/
		reference operator*() const {
			iterator_type tmp = this->_it;
			return *(--tmp);
		}

		/* operator+
		** Returns a reverse iterator pointing to the element located n positions away 
		** from the element the iterator currently points to.
		*/
		reverse_iterator operator+ (difference_type n) const{
			return (reverse_iterator(this->base() - n));
		}

		/* (1)
		** Prefix increment in reverse -> decrement
		*/
		reverse_iterator& operator++() {--_it; return (*this);};

		/* (2)
		** Postfix increment
		*/	
		reverse_iterator  operator++(int){reverse_iterator tmp = *this; --_it; return (tmp);};

		/* Advances the reverse_iterator by n element positions. */
		reverse_iterator& operator+= (difference_type n){
			this->_it -= n;
			return (*this);
		}

		/* operator-
		** Returns a reverse iterator pointing to the element located n positions before 
		** the element the iterator currently points to.
		*/
		reverse_iterator operator- (difference_type n) const{
			return (reverse_iterator(this->base() + n));
		}

		/* (1)
		** Prefix decrement in reverse -> increment
		*/
		reverse_iterator& operator--() {++_it; return (*this);};

		/* (2)
		** Postfix decrement
		*/	
		reverse_iterator  operator--(int){reverse_iterator tmp = *this; ++_it; return (tmp);};

		/* Descreases the reverse_iterator by n element positions. */
		reverse_iterator& operator-= (difference_type n){
			this->_it += n;
			return (*this);
		}

		/* Returns a pointer to the element pointed to by the iterator (in order to access one of its members). */
		pointer operator->() { return &(operator*()); }

		/* Accesses the element located n positions away from the element currently pointed to by the iterator. */
		reference operator[] (difference_type n) const{
			return (this->base()[-n-1]);
		}

		private:

		/*************************************
		 *          MEMBER ATTRIBUTE
		**************************************/

		iterator_type	_it;

	};

	/*************************************
	 *       NON-MEMBER FUNCTIONS
	**************************************/

	/*****---------------- RELATIONAL OPERATOR ----------------*****/

	template< class Iterator1, class Iterator2 >
	bool operator==( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs ){
		return (rhs.base() == lhs.base());
	}
	template< class Iterator1, class Iterator2 >
	bool operator!=( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs ){
		return (rhs.base() != lhs.base());
	}
	template< class Iterator1, class Iterator2 >
	bool operator<( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs ){
		return (rhs.base() < lhs.base());
	}
	template< class Iterator1, class Iterator2 >
	bool operator<=( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs ){
		return (rhs.base() <= lhs.base());
	}
	template< class Iterator1, class Iterator2 >
	bool operator>( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs ){
		return (rhs.base() > lhs.base());
	}
	template< class Iterator1, class Iterator2 >
	bool operator>=( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs ){
		return (rhs.base() >= lhs.base());
	}

	/*****---------------- OPERATOR ----------------*****/

	/* Return value: the incremented iterator, that is reverse_iterator<Iter>(it.base() - n) */
	template< class Iter >
	reverse_iterator<Iter> operator+ (typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it ){
		return (reverse_iterator<Iter>(it.base() - n));
	}

	/* Return value: rhs.base() - lhs.base() */
	template< class Iterator >
	typename reverse_iterator<Iterator>::difference_type operator-( const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs ){
		return (rhs.base() - lhs.base());
	}

	template <class It1, class It2>
	typename reverse_iterator<It1>::difference_type operator-( const reverse_iterator<It1>& lhs, const reverse_iterator<It2>& rhs)
	{ return rhs.base() - lhs.base(); }
}

#endif