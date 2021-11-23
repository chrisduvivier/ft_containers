#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <string>
# include <memory>
# include <map>
# include "pair.hpp"
# include "rb_tree.hpp"
# include "../iterator/tree_iterator.hpp"
# include "../iterator/reverse_iterator.hpp"
# include "../utils/utils.hpp"
# include "node.hpp"

/*

template <class Key, class T, class Compare = less<Key>,
          class Allocator = allocator<pair<const Key, T>>>
class map
{
	*****************************
	*	   Member types  		*
	*****************************

public:

✅    typedef Key                                      key_type;
✅    typedef T                                        mapped_type;
✅    typedef pair<const key_type, mapped_type>        value_type;
✅    typedef Compare                                  key_compare;
✅    typedef Allocator                                allocator_type;
✅    typedef typename allocator_type::reference       reference;
✅    typedef typename allocator_type::const_reference const_reference;
✅    typedef typename allocator_type::pointer         pointer;
✅    typedef typename allocator_type::const_pointer   const_pointer;
✅    typedef typename allocator_type::size_type       size_type;
✅    typedef typename allocator_type::difference_type difference_type;

✅    typedef implementation-defined                   iterator;
✅    typedef implementation-defined                   const_iterator;
✅    typedef ft::reverse_iterator<iterator>          reverse_iterator;
✅    typedef ft::reverse_iterator<const_iterator>    const_reverse_iterator;

✅    class value_compare (inside tree)

✅    explicit map(const key_compare& comp, const allocator_type& a);
✅    template <class InputIterator>
        map(InputIterator first, InputIterator last,
            const key_compare& comp, const allocator_type& a);
✅    map(const map& m);
✅    ~map();

✅     map& operator=(const map& m); // We should implement operator= for the rb for this to work as a deep copy

    // iterators:
✅    iterator begin() ;
✅    const_iterator begin() const;
✅    iterator end();
✅   const_iterator end()   const;

✅    reverse_iterator rbegin();
✅    const_reverse_iterator rbegin() const;
✅    reverse_iterator rend();
✅    const_reverse_iterator rend() const;

    // capacity:
✅    bool      empty()    const noexcept;
✅    size_type size()     const noexcept;
✅    size_type max_size() const noexcept;

    // element access:
✅    mapped_type& operator[](const key_type& k);

    // modifiers:
✅    pair<iterator, bool> insert(const value_type& v);
✅    iterator insert(const_iterator position, const value_type& v);
✅    template <class InputIterator>
✅    void insert(InputIterator first, InputIterator last);
✅    void erase(iterator position);
✅    size_type erase(const key_type& k);
✅    void  erase(iterator first, iterator last);
✅    void clear();

✅    void swap(map& m);

    // observers:
✅    allocator_type get_allocator() const noexcept;
✅    key_compare    key_comp()      const;
✅    value_compare  value_comp()    const;

    // map operations:
✅    iterator find(const key_type& k);
✅    const_iterator find(const key_type& k) const;

✅    size_type      count(const key_type& k) const;
✅    iterator lower_bound(const key_type& k);
✅    const_iterator lower_bound(const key_type& k) const;


✅    iterator upper_bound(const key_type& k);
✅    const_iterator upper_bound(const key_type& k) const;


✅    pair<iterator,iterator>             equal_range(const key_type& k);
✅    pair<const_iterator,const_iterator> equal_range(const key_type& k) const;
};

template <class Key, class T, class Compare, class Allocator>
bool
operator==(const map<Key, T, Compare, Allocator>& x,
           const map<Key, T, Compare, Allocator>& y);

template <class Key, class T, class Compare, class Allocator>
bool
operator< (const map<Key, T, Compare, Allocator>& x,
           const map<Key, T, Compare, Allocator>& y);

template <class Key, class T, class Compare, class Allocator>
bool
operator!=(const map<Key, T, Compare, Allocator>& x,
           const map<Key, T, Compare, Allocator>& y);

template <class Key, class T, class Compare, class Allocator>
bool
operator> (const map<Key, T, Compare, Allocator>& x,
           const map<Key, T, Compare, Allocator>& y);

template <class Key, class T, class Compare, class Allocator>
bool
operator>=(const map<Key, T, Compare, Allocator>& x,
           const map<Key, T, Compare, Allocator>& y);

template <class Key, class T, class Compare, class Allocator>
bool
operator<=(const map<Key, T, Compare, Allocator>& x,
           const map<Key, T, Compare, Allocator>& y);

// specialized algorithms:
template <class Key, class T, class Compare, class Allocator>
void
swap(map<Key, T, Compare, Allocator>& x, map<Key, T, Compare, Allocator>& y)
    noexcept(noexcept(x.swap(y)));
 
 */



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
		typedef Key 											key_type;
		typedef T 												mapped_type;
		typedef ft::pair<const Key, T> 							value_type;
		typedef Compare 										key_compare;
		typedef Alloc 											allocator_type;
		typedef typename allocator_type::reference 				reference;
		typedef typename allocator_type::const_reference 		const_reference;
		typedef typename allocator_type::pointer 				pointer;
		typedef typename allocator_type::const_pointer 			const_pointer;
		typedef typename allocator_type::size_type				size_type;
		typedef typename allocator_type::difference_type		difference_type;
		
	private:
		typedef RBTree<value_type, key_compare, allocator_type> 				tree;
		typedef ft::Node<value_type>											Node;
		typedef Node*															node_ptr;
		typedef RBTree<const value_type, key_compare, allocator_type>			const_tree;
		
	public:
		typedef typename tree::value_compare								value_compare;

		typedef TreeIterator<bidirectional_iterator_tag, tree> 				iterator;
		typedef TreeIterator<bidirectional_iterator_tag, const_tree, tree>	const_iterator;

		typedef ft::reverse_iterator<iterator> 						reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> 				const_reverse_iterator;

		/****************************
		*	   Member functions		*
		****************************/

		/*
		**	(1) empty container constructor (default constructor)
		**	Constructs an empty container, with no elements.
		*/

		explicit map(const key_compare &comp = key_compare(), 
					const allocator_type &alloc = allocator_type()) : _tree(comp, alloc)
		{ }

		/*
		**	(2) range constructor
		**	Constructs a container with as many elements as the range [first,last),
		**	with each element constructed from its corresponding element in that range, in the same order.
		*/

		template <class InputIterator>
		map(InputIterator first, InputIterator last,
			const key_compare &comp = key_compare(),
			const allocator_type &alloc = allocator_type()) : _tree(comp, alloc) 
		{
				this->insert(first, last);
		}

		/*
		**	(3) copy constructor
		**	Constructs a container with a copy of each of the elements in x, in the same order.
		*/

		map(const map &x): _tree(x._tree)
		{ }

		/*
		**	(1) operator= overloading
		**	Replaces the contents of the container.
		*/

		map& operator=( const map& other ){
			if (this != &other)
				_tree = other._tree;
			return *this;
		}

		/*	Think of the _alloc object as an array of objects. Therefore we need to destroy each obj in the array,
			*	and then destroy the array itself. */

		~map()
		{ }

		/****************************
		*	   	   Iterators		*
		****************************/

		//Return iterator to beginning (public member function )
		iterator begin() { return (iterator( this->_tree.begin_node(), this->_tree.getRoot() ) ); }
		const_iterator begin() const { return (const_iterator( this->_tree.begin_node(), this->_tree.getRoot() ) ); }

		//Return iterator to end (public member function )
		iterator end() { return (iterator( this->_tree.end_node(), this->_tree.getRoot() )); }
		const_iterator end() const { return (const_iterator( this->_tree.end_node(), this->_tree.getRoot() )); }

		//Return reverse iterator to reverse beginning (public member function )
		reverse_iterator rbegin() { return (reverse_iterator( this->end() )); }
		const_reverse_iterator rbegin() const { return (const_reverse_iterator( this->end() )); }

		//Return reverse iterator to reverse end (public member function )
		reverse_iterator rend() { return (reverse_iterator( this->begin() )); }
		const_reverse_iterator rend() const { return (const_reverse_iterator( this->begin() )); }



		/****************************
		*	   	   Capacity			*
		****************************/

		// Test whether container is empty (public member function )
		bool empty() const { return (this->size() == 0); }

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

		ft::pair<iterator, bool> insert (const value_type& val)
		{
			ft::pair<node_ptr, bool> tmp = this->_tree.insert_single_elem(val);
			ft::pair<iterator, bool> res(iterator(tmp.first, this->_tree.getRoot()), tmp.second);
			return res;
		}

		/* The versions with a hint (2) return an iterator pointing to either the newly inserted element or to the element that already had an equivalent key in the map. */
		iterator insert (iterator position, const value_type& val){
			node_ptr node = this->_tree.searchTree(val);
			if (!node->is_tnull())
				return (iterator(node, this->_tree.getRoot()));
			(void)position;
			return this->insert(val).first;
		}

		template <class InputIterator>
		void insert (InputIterator first, InputIterator last){
			while (first != last)
			{
				this->_tree.insert(*first);
				first++;
			}
		}

		// (1) Erase elements (public member function )
		void erase (iterator position) { this->erase(position->first); }

		/* (2) For the key-based version, the function returns the number of elements erased. */
		size_type erase(const key_type& k){	
			size_type check = this->size();
			this->_tree.deleteNodeKey(k);
			return (check != this->size());
		}

		// (3) Erase with range of iterator
		void erase (iterator first, iterator last) {
			iterator temp;
			while (first != last)
			{
				temp = first;
				++first;
				this->erase(temp);
			}
		}

		//Swap content (public member function )
		void	swap(map &x){ this->_tree.swap(x._tree); }

		// Removes all elements from the map container (which are destroyed), leaving the container with a size of 0.
		void clear() { this->_tree.clear(); }

		// /****************************
		// *		  Observers			*
		// ****************************/

		//Return key comparison object (public member function )
		key_compare key_comp() const { return (this->_tree.get_key_comp()); }
		//Return value comparison object (public member function )
		value_compare value_comp() const { return (this->_tree.get_value_comp()); }

		// /****************************
		// *		  Operations		*
		// ****************************/

		// Get iterator to element (public member function )
		iterator find (const key_type& k){
			node_ptr node = this->_tree.searchTreeKey(k);
			if (node->is_tnull())
				return (this->end());
			return (iterator(node, this->_tree.getRoot()));
		}

		const_iterator find (const key_type& k) const{
			node_ptr node = this->_tree.searchTreeKey(k);
			if (node->is_tnull())
				return (this->end());
			return (const_iterator(node, this->_tree.getRoot()));
		}

		// Searches the container for elements with a key equivalent to k and returns the number of matches.
		size_type count (const key_type& k) const
		{
			node_ptr node = this->_tree.searchTreeKey(k);
			return ( node->is_tnull() ? 0 : 1 );
		}

		/*
			Returns an iterator pointing to the first element in the container whose key is not considered to go before k (i.e., either it is equivalent or goes after).
			The function uses its internal comparison object (key_comp) to determine this, returning an iterator to the first element for which key_comp(element_key,k) would return false.
		*/
		iterator lower_bound (const key_type& k)
		{
			return (iterator(this->_tree.lower_bound(k), this->_tree.getRoot() ));
		}

		const_iterator lower_bound (const key_type& k) const{
			return (const_iterator(this->_tree.lower_bound(k), this->_tree.getRoot() ));
		}

		/*
			Returns an iterator pointing to the first element in the container whose key is considered to go after k.
			The function uses its internal comparison object (key_comp) to determine this, returning an iterator to the first element for which key_comp(k,element_key) would return true.
		*/
		iterator upper_bound (const key_type& k)
		{
			return (iterator(this->_tree.upper_bound(k), this->_tree.getRoot() ));
		}

		const_iterator upper_bound (const key_type& k) const{
			return (const_iterator(this->_tree.upper_bound(k), this->_tree.getRoot() ));
		}

		//Get range of equal elements (public member function )
		pair<iterator,iterator>	equal_range (const key_type& k)
		{
			return (pair<iterator, iterator>(this->lower_bound(k), this->upper_bound(k)));
		}
		
		pair<const_iterator, const_iterator>	equal_range (const key_type& k) const
		{
			return (pair<const_iterator, const_iterator>(this->lower_bound(k), this->upper_bound(k)));
		}

		/****************************
		*		  Allocator			*
		****************************/

		/*	Returns a copy of the allocator object associated with the map. */
		allocator_type get_allocator() const { return (allocator_type(this->_tree.get_allocator())); }

		RBTree<value_type, Compare, Alloc>	&getTree() { return _tree; }

	private:
		RBTree<value_type, Compare, Alloc>	_tree;
	};

} 

#endif /* ********************************************************** MAP_H */