#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <string>
#include <memory>

#include "../iterator/random_access_iterator.hpp"
#include "../iterator/reverse_iterator.hpp"
#include "../utils/utils.hpp"

#define MAX_SIZE_64BIT 4611686018427387903

/*
    vector synopsis

namespace ft
{

template <class T, class Allocator = allocator<T> >
class vector
{
public:
	*****************************
	*	   Member types  		*
	*****************************

✅    typedef T                                        value_type; 
✅    typedef Allocator                                allocator_type;
✅    typedef typename allocator_type::reference       reference;
✅    typedef typename allocator_type::const_reference const_reference;
✅    typedef implementation-defined                   iterator;
✅    typedef implementation-defined                   const_iterator;
✅    typedef typename allocator_type::size_type       size_type;
✅    typedef typename allocator_type::difference_type difference_type;
✅    typedef typename allocator_type::pointer         pointer;
✅    typedef typename allocator_type::const_pointer   const_pointer;
✅    typedef std::reverse_iterator<iterator>          reverse_iterator;
✅    typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;


	*****************************
	*	   Member functions		*
	*****************************


✅    explicit vector(const allocator_type&);
✅    explicit vector(size_type n, const value_type& value, const allocator_type& = allocator_type());
✅    template <class InputIterator>
          vector(InputIterator first, InputIterator last, const allocator_type& = allocator_type());
✅    vector(const vector& x);
✅    ~vector();
✅    vector& operator=(const vector& x);

	*****************************
	*	   	   Iterators		*
	*****************************

✅    iterator               begin();
✅    const_iterator         begin()		const;
✅    iterator               end();
✅    const_iterator         end()		const;

    reverse_iterator       rbegin();
    const_reverse_iterator rbegin()		const;
    reverse_iterator       rend();
    const_reverse_iterator rend()		const;

	*****************************
	*	   	   Capacity			*
	*****************************
    
✅    size_type	size(		const;
✅    size_type	max_size()	const;
✅    void		resize (size_type n, value_type val = value_type());
✅    size_type	capacity()	const;
✅    bool		empty()		const;
✅    void		reserve(size_type n);

	*****************************
	*		Element access		*
	*****************************

✅    reference       operator[](size_type n);
✅    const_reference operator[](size_type n) const;
✅    reference       at(size_type n);
✅    const_reference at(size_type n) const;

✅    reference       front();
✅    const_reference front() const;
✅    reference       back();
✅    const_reference back() const;
	
	*****************************
	*		  Modifiers			*
	*****************************
    
✅    template <class InputIterator>
        void assign(InputIterator first, InputIterator last);
✅    void assign(size_type n, const value_type& u);
✅    void push_back(const value_type& x);
✅    void pop_back();

🏗️    iterator insert(const_iterator position, const value_type& x);
🏗️    template <class InputIterator>
        void insert (iterator position, size_type n, const value_type& val);
🏗️    iterator insert(iterator position, InputIterator first, InputIterator last);

    iterator erase(iterator position);
    iterator erase(iterator first, iterator last);

✅    void clear() ;

✅    void swap(vector& x);

	*****************************
	*		  Allocator			*
	*****************************

✅    allocator_type get_allocator() const ;
};

	*************************************
	*	Non-member function overloads	*
	*************************************


*/

namespace ft
{
	template <class T, class Alloc = std::allocator<T> > // generic template
	class stack
	{
	public:
		/****************************
		*	   Member types  		*
		****************************/

		/* Type of the elements allocated by the object (aliased as member type value_type). */
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::size_type size_type;
		typedef typename allocator_type::difference_type difference_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef ft::random_access_iterator<value_type> iterator;
		typedef ft::random_access_iterator<const value_type> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

		/****************************
		*	   Member functions		*
		****************************/

		/****************************
		*	   	   Iterators		*
		****************************/

		/****************************
		*	   	   Capacity			*
		****************************/

		/****************************
		*		Element access		*
		****************************/

		/****************************
		*		  Modifiers			*
		****************************/

	private:

	};

	/********************************
	* Non-member function overloads	*
	********************************/

	/********************************
	* Non-member operators overloads*
	********************************/

} // namespace ft

#endif