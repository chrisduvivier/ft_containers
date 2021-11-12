#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <string>
# include <memory>
// # include <map>
# include "pair.hpp"
# include "rb_tree.hpp"
# include "../includes/iterator/tree_iterator.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{
	public:
		/****************************
		*	   Member types  		*
		****************************/

		/* Type of the elements allocated by the object (aliased as member type value_type). */
		typedef Key 						key_type;
		typedef T 							mapped_type;
		typedef ft::pair<const Key, T> 		value_type;
		typedef Compare 					key_compare;
		typedef size_t						size_type;
		typedef ptrdiff_t 					difference_type;

		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
			friend class map;
			private:
				key_compare comp;
			public:
				value_compare(const key_compare &x) : comp(x) {}
				bool operator()(const value_type &x, const value_type &y) const
				{
					return comp(x.first, y.first);
				}
		};

		typedef Alloc 											allocator_type;
		typedef typename allocator_type::reference 				reference;
		typedef typename allocator_type::const_reference 		const_reference;
		typedef typename allocator_type::pointer 				pointer;
		typedef typename allocator_type::const_pointer 			const_pointer;
		typedef RBTree<value_type,value_compare> 				tree;


		/* a bidirectional iterator to value_type */
		typedef TreeIterator<bidirectional_iterator_tag, tree> 	iterator;
		
		// typedef ConstTreeIterator<value_type> 					const_iterator;
		// typedef ft::reverse_iterator<iterator> 					reverse_iterator;
		// typedef ft::reverse_iterator<const_iterator> 			const_reverse_iterator;

		/****************************
		*	   Member functions		*
		****************************/

		/*
		**	(1) empty container constructor (default constructor)
		**	Constructs an empty container, with no elements.
		*/

		explicit map(const key_compare &comp = key_compare(), 
					const allocator_type &alloc = allocator_type())
		{
			this->_tree	= RBTree<value_type, Compare, Alloc>(comp, alloc);
		}

		/*
		**	(2) range constructor
		**	Constructs a container with as many elements as the range [first,last),
		**	with each element constructed from its corresponding element in that range, in the same order.
		*/

		template <class InputIterator>
		map(InputIterator first, 
			InputIterator last,
			const key_compare &comp = key_compare(),
			const allocator_type &alloc = allocator_type()){
				this->_tree = RBTree<value_type, Compare, Alloc>(comp, alloc);
				this->insert(first, last);
		}

		/*
		**	(3) copy constructor
		**	Constructs a container with a copy of each of the elements in x, in the same order.
		*/

		map(const map &x)
		{
			*this = x;
		}

		/*
		**	(1) operator= overloading
		**	Replaces the contents of the container.
		*/

		map& operator=( const map& other ){
			//Need to overload the '=' operator of tree
			if (this == &other)
				return ;
			this->_tree = other._tree;
			return (*this);
		}

		/*	Think of the _alloc object as an array of objects. Therefore we need to destroy each obj in the array,
			*	and then destroy the array itself. */

		~map()
		{
		}

		/****************************
		*	   	   Iterators		*
		****************************/

		//Return iterator to beginning (public member function )
		
		iterator begin() {
			return (iterator( this->_tree.begin_node() ));
		}

		iterator end() {
			return (iterator( this->_tree.end_node() ));
		}


		// //Return iterator to end (public member function )
		// iterator end();
		// //Return reverse iterator to reverse beginning (public member function )
		// iterator rbegin();
		// //Return reverse iterator to reverse end (public member function )
		// iterator rend();


		/****************************
		*	   	   Capacity			*
		****************************/

		// Test whether container is empty (public member function )
		bool empty() { return (this->size() == 0); }

		/* Returns the number of elements in the vector. */
		size_type size() const { return (this->_tree.size()); }

		/*	Returns the maximum number of elements that the vector can hold.
			*	This is the maximum potential size the container can reach due to known system or library implementation limitations,
			*	but the container is by no means guaranteed to be able to reach that size:
			*	it can still fail to allocate storage at any point before that size is reached. */
		size_type max_size() const { return (this->_tree.max_size()); }


		/****************************
		*		Element access		*
		****************************/

		// Access element (public member function )
		mapped_type&	operator[](const key_type &key) {
			return (this->_tree[key]);
		}

		/****************************
		*		  Modifiers			*
		****************************/

		/*
			The single element versions (1) return a pair, with its member pair::first set to an iterator pointing to either,
			the newly inserted element or to the element with an equivalent key in the map.
			The pair::second element in the pair is set to true if a new element was inserted or false if an equivalent key already existed.
		*/

		// pair<iterator, bool> insert (const value_type& val);

		void insert(const value_type& val)	//tmp TODELETE.
		{
			this->_tree.insert(val);
		}
		
		// Erase elements (public member function )
		// void erase (iterator position);		//TODO

		/* For the key-based version (2), the function returns the number of elements erased. */
		size_type erase(const key_type& k)
		{	
			return (this->_tree.deleteNodeKey(k));
		}

		void erase (iterator position);

		void erase (iterator first, iterator last);


		// //Swap content (public member function )
		// swap();
		// //Clear content (public member function )
		// clear();

		// /****************************
		// *		  Observers			*
		// ****************************/

		//Return key comparison object (public member function )
		key_compare key_comp() 
		{
			return this->_tree.key_compare;
		}
		// //Return value comparison object (public member function )
		// value_comp();

		// /****************************
		// *		  Operations		*
		// ****************************/

		// Get iterator to element (public member function )
		// iterator find (const key_type& k);
		// const_iterator find (const key_type& k) const;

		// //Count elements with a specific key (public member function )
		// count();
		// //Return iterator to lower bound (public member function )
		// lower_bound();
		// //Return iterator to upper bound (public member function )
		// upper_bound();
		// //Get range of equal elements (public member function )
		// equal_range();

		/****************************
		*		  Allocator			*
		****************************/

		/*	Returns a copy of the allocator object associated with the vector. */
		allocator_type get_allocator() const
		{
		}

		RBTree<value_type, Compare, Alloc>	&getTree()
		{
			return _tree;
		}
	private:
		RBTree<value_type, Compare, Alloc>	_tree;
	};

} 

#endif /* ********************************************************** MAP_H */