#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <string>
#include <memory>
#include "pair.hpp"
#include "rb_tree.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T>>>
	class map;
	{
	public:
		/****************************
		*	   Member types  		*
		****************************/

		/* Type of the elements allocated by the object (aliased as member type value_type). */
		typedef Key key_type;
		typedef T mapped_type;
		typedef ft::pair<const Key, T> value_type;
		typedef Compare key_compare;
		typedef size_t	size_type;


		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;

		// iterator
		// const_iterator
		// reverse_iterator
		// const_reverse_iterator
		// difference_type

		/****************************
		*	   Member functions		*
		****************************/

		/*
		**	(1) empty container constructor (default constructor)
		**	Constructs an empty container, with no elements.
		*/
		explicit map(	const key_compare &comp = key_compare(), 
						const allocator_type &alloc = allocator_type());

		/*
		**	(2) fill constructor
		**	Constructs a container with n elements. Each element is a copy of val.
		*/
		template <class InputIterator>
		map(InputIterator first, 
			InputIterator last,
			const key_compare &comp = key_compare(),
			const allocator_type &alloc = allocator_type());

		/*
		**	(3) range constructor
		**	Constructs a container with as many elements as the range [first,last),
		**	with each element constructed from its corresponding element in that range, in the same order.
		*/

		// TODO once we have an iterator
		// template <class InputIterator>
		// vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());

		/*
			**	(4) copy constructor
			**	Constructs a container with a copy of each of the elements in x, in the same order.
			*/

		map(const map &x)
		{
			(void)x;
		}

		/*	Think of the _alloc object as an array of objects. Therefore we need to destroy each obj in the array,
			*	and then destroy the array itself. */
		~vector()
		{
		}

		/****************************
		*	   	   Iterators		*
		****************************/

		//Return iterator to beginning (public member function )
		begin();
		//Return iterator to end (public member function )
		end();
		//Return reverse iterator to reverse beginning (public member function )
		rbegin();
		//Return reverse iterator to reverse end (public member function )
		rend();


		/****************************
		*	   	   Capacity			*
		****************************/

		//Test whether container is empty (public member function )
		empty();

		/* Returns the number of elements in the vector. */
		size_type size() const { return (this->_size); }

		/*	Returns the maximum number of elements that the vector can hold.
			*	This is the maximum potential size the container can reach due to known system or library implementation limitations,
			*	but the container is by no means guaranteed to be able to reach that size:
			*	it can still fail to allocate storage at any point before that size is reached. */
		size_type maxsize() const { return (this->_size); }


		/****************************
		*		Element access		*
		****************************/

		// Access element (public member function )
		// operator[]

		/****************************
		*		  Modifiers			*
		****************************/

		//Insert elements (public member function )
		insert();
		//Erase elements (public member function )
		erase();
		//Swap content (public member function )
		swap();
		//Clear content (public member function )
		clear();

		/****************************
		*		  Observers			*
		****************************/

		//Return key comparison object (public member function )
		key_comp();
		//Return value comparison object (public member function )
		value_comp();

		/****************************
		*		  Operations		*
		****************************/

		//Get iterator to element (public member function )
		find();
		//Count elements with a specific key (public member function )
		count();
		//Return iterator to lower bound (public member function )
		lower_bound();
		//Return iterator to upper bound (public member function )
		upper_bound();
		//Get range of equal elements (public member function )
		equal_range();

		/****************************
		*		  Allocator			*
		****************************/

		/*	Returns a copy of the allocator object associated with the vector. */
		allocator_type get_allocator() const
		{
		}

	private:
		allocator_type _alloc; /*	allocator class holding object	*/
		RBTree<value_type>	_rbt;
	};

} 

#endif /* ********************************************************** MAP_H */