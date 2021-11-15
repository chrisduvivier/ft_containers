#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <string>
# include <memory>
# include <map>
# include "pair.hpp"
# include "rb_tree.hpp"
# include "../iterator/tree_iterator.hpp"
# include "..//iterator/reverse_iterator.hpp"
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
❌    typedef implementation-defined                   const_iterator;
❌    typedef std::reverse_iterator<iterator>          reverse_iterator;
❌    typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;

✅    class value_compare
          : public binary_function<value_type, value_type, bool>
      {
          friend class map;
      protected:
          key_compare comp;

          value_compare(key_compare c);
      public:
          bool operator()(const value_type& x, const value_type& y) const;
      };

    // construct/copy/destroy:

    explicit map(const key_compare& comp, const allocator_type& a);
    template <class InputIterator>
        map(InputIterator first, InputIterator last,
            const key_compare& comp = key_compare());
    template <class InputIterator>
        map(InputIterator first, InputIterator last,
            const key_compare& comp, const allocator_type& a);
    map(const map& m);
    map(map&& m)
        noexcept(
            is_nothrow_move_constructible<allocator_type>::value &&
            is_nothrow_move_constructible<key_compare>::value);
    explicit map(const allocator_type& a);
    map(const map& m, const allocator_type& a);
    map(map&& m, const allocator_type& a);
    map(initializer_list<value_type> il, const key_compare& comp = key_compare());
    map(initializer_list<value_type> il, const key_compare& comp, const allocator_type& a);
    template <class InputIterator>
        map(InputIterator first, InputIterator last, const allocator_type& a)
            : map(first, last, Compare(), a) {}  // C++14
    map(initializer_list<value_type> il, const allocator_type& a)
        : map(il, Compare(), a) {}  // C++14
   ~map();

    map& operator=(const map& m);
    map& operator=(map&& m)
        noexcept(
            allocator_type::propagate_on_container_move_assignment::value &&
            is_nothrow_move_assignable<allocator_type>::value &&
            is_nothrow_move_assignable<key_compare>::value);
    map& operator=(initializer_list<value_type> il);

    // iterators:
          iterator begin() noexcept;
    const_iterator begin() const noexcept;
          iterator end() noexcept;
    const_iterator end()   const noexcept;

          reverse_iterator rbegin() noexcept;
    const_reverse_iterator rbegin() const noexcept;
          reverse_iterator rend() noexcept;
    const_reverse_iterator rend()   const noexcept;

    const_iterator         cbegin()  const noexcept;
    const_iterator         cend()    const noexcept;
    const_reverse_iterator crbegin() const noexcept;
    const_reverse_iterator crend()   const noexcept;

    // capacity:
    bool      empty()    const noexcept;
    size_type size()     const noexcept;
    size_type max_size() const noexcept;

    // element access:
    mapped_type& operator[](const key_type& k);
    mapped_type& operator[](key_type&& k);

          mapped_type& at(const key_type& k);
    const mapped_type& at(const key_type& k) const;

    // modifiers:
    template <class... Args>
        pair<iterator, bool> emplace(Args&&... args);
    template <class... Args>
        iterator emplace_hint(const_iterator position, Args&&... args);
    pair<iterator, bool> insert(const value_type& v);
    pair<iterator, bool> insert(      value_type&& v);                                // C++17
    template <class P>
        pair<iterator, bool> insert(P&& p);
    iterator insert(const_iterator position, const value_type& v);
    iterator insert(const_iterator position,       value_type&& v);                   // C++17
    template <class P>
        iterator insert(const_iterator position, P&& p);
    template <class InputIterator>
        void insert(InputIterator first, InputIterator last);
    void insert(initializer_list<value_type> il);

    node_type extract(const_iterator position);                                       // C++17
    node_type extract(const key_type& x);                                             // C++17
    insert_return_type insert(node_type&& nh);                                        // C++17
    iterator insert(const_iterator hint, node_type&& nh);                             // C++17

    template <class... Args>
        pair<iterator, bool> try_emplace(const key_type& k, Args&&... args);          // C++17
    template <class... Args>
        pair<iterator, bool> try_emplace(key_type&& k, Args&&... args);               // C++17
    template <class... Args>
        iterator try_emplace(const_iterator hint, const key_type& k, Args&&... args); // C++17
    template <class... Args>
        iterator try_emplace(const_iterator hint, key_type&& k, Args&&... args);      // C++17
    template <class M>
        pair<iterator, bool> insert_or_assign(const key_type& k, M&& obj);            // C++17
    template <class M>
        pair<iterator, bool> insert_or_assign(key_type&& k, M&& obj);                 // C++17
    template <class M>
        iterator insert_or_assign(const_iterator hint, const key_type& k, M&& obj);   // C++17
    template <class M>
        iterator insert_or_assign(const_iterator hint, key_type&& k, M&& obj);        // C++17

    iterator  erase(const_iterator position);
    iterator  erase(iterator position); // C++14
    size_type erase(const key_type& k);
    iterator  erase(const_iterator first, const_iterator last);
    void clear() noexcept;

    void swap(map& m)
        noexcept(allocator_traits<allocator_type>::is_always_equal::value &&
            is_nothrow_swappable<key_compare>::value); // C++17

    // observers:
    allocator_type get_allocator() const noexcept;
    key_compare    key_comp()      const;
    value_compare  value_comp()    const;

    // map operations:
          iterator find(const key_type& k);
    const_iterator find(const key_type& k) const;
    template<typename K>
        iterator find(const K& x);              // C++14
    template<typename K>
        const_iterator find(const K& x) const;  // C++14
    template<typename K>
      size_type count(const K& x) const;        // C++14

    size_type      count(const key_type& k) const;
          iterator lower_bound(const key_type& k);
    const_iterator lower_bound(const key_type& k) const;
    template<typename K>
        iterator lower_bound(const K& x);              // C++14
    template<typename K>
        const_iterator lower_bound(const K& x) const;  // C++14

          iterator upper_bound(const key_type& k);
    const_iterator upper_bound(const key_type& k) const;
    template<typename K>
        iterator upper_bound(const K& x);              // C++14
    template<typename K>
        const_iterator upper_bound(const K& x) const;  // C++14

    pair<iterator,iterator>             equal_range(const key_type& k);
    pair<const_iterator,const_iterator> equal_range(const key_type& k) const;
    template<typename K>
        pair<iterator,iterator>             equal_range(const K& x);        // C++14
    template<typename K>
        pair<const_iterator,const_iterator> equal_range(const K& x) const;  // C++14
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
		typedef typename allocator_type::difference_type difference_type;
		typedef RBTree<value_type,value_compare> 				tree;
		typedef ft::Node<value_type>							Node;
		typedef Node*											node_ptr;
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
			const allocator_type &alloc = allocator_type()) {
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
		iterator begin() { return (iterator( this->_tree.begin_node(), this->_tree.getRoot() ) ); }
		// const_iterator begin() const;

		//Return iterator to end (public member function )
		iterator end() { return (iterator( this->_tree.end_node(), this->_tree.getRoot() )); }
		// const_iterator end() const;

		//Return reverse iterator to reverse beginning (public member function )
		// reverse_iterator rbegin() { return (reverse_iterator( this->end() )); }
		// // const_reverse_iterator rbegin() const;

		// //Return reverse iterator to reverse end (public member function )
		// reverse_iterator rend() { return (reverse_iterator( this->begin() )); }



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

		/* (2) For the key-based version, the function returns the number of elements erased. */
		size_type erase(const key_type& k){	
			size_type check = this->size();
			this->_tree.deleteNodeKey(k);
			return (check != this->size());
		}

		// (1) Erase elements (public member function )
		void erase (iterator position) {
			this->erase(position->first);
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
		void	swap(map &x){
			this->_tree.swap(x._tree);
		}
		// //Clear content (public member function )
		// clear();

		// /****************************
		// *		  Observers			*
		// ****************************/

		//Return key comparison object (public member function )
		key_compare key_comp() 
		{
			return (this->_tree.key_compare());
		}
		//Return value comparison object (public member function )
		value_compare value_comp() const
		{
			return (this->_tree.value_compare());
		}

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

		// const_iterator find (const key_type& k) const{
		// 	node_ptr node = this->_tree.searchTreeKey(k);
		// 	if (node->is_tnull())
		// 		return (this->end());
		// 	return (const_iterator(node));
		// }

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

		// const_iterator lower_bound (const key_type& k) const;

		/*
			Returns an iterator pointing to the first element in the container whose key is considered to go after k.
			The function uses its internal comparison object (key_comp) to determine this, returning an iterator to the first element for which key_comp(k,element_key) would return true.
		*/
		iterator upper_bound (const key_type& k)
		{
			return (iterator(this->_tree.upper_bound(k), this->_tree.getRoot() ));
		}

		// const_iterator upper_bound (const key_type& k) const;

		//Get range of equal elements (public member function )
		pair<iterator,iterator>	equal_range (const key_type& k)
		{
			return (pair<iterator, iterator>(this->lower_bound(k), this->upper_bound(k)));
		}
		
		// pair<const_iterator,const_iterator> equal_range (const key_type& k) const;

		/****************************
		*		  Allocator			*
		****************************/

		/*	Returns a copy of the allocator object associated with the map. */
		allocator_type get_allocator() const { return (allocator_type(this->_tree.get_allocator())); }

		RBTree<value_type, Compare, Alloc>	&getTree() { return _tree; }

		void	prettyPrint()
		{
			this->_tree.prettyPrint();
		}

	private:
		RBTree<value_type, Compare, Alloc>	_tree;
	};

} 

#endif /* ********************************************************** MAP_H */