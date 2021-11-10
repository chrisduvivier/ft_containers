#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP

# include <iostream>
# include <string>
# include <memory>
# include "iterator.hpp"
# include "../../map/rb_tree.hpp"

namespace ft
{
	template<class T>
	struct Node
	{
		typedef T		value_type;	// correspond to Pair

		value_type		data; 		// holds the key/value
		Node			*parent; 	// pointer to the parent
		Node			*left;	  	// pointer to left child
		Node			*right;  	// pointer to right child
		int				color;	  	// 1 -> Red, 0 -> Black
	};

	template <typename T>
	class TreeIterator : public ft::iterator< bidirectional_iterator_tag, T >
	{
		public:
			typedef Node<T>	tree_node;	//tree_node correspond to Node object with the template T.

		protected:
			tree_node *								_node;		// pointer to the node

		public:
			typedef	TreeIterator					It;			// Iterator itself
			typedef T								value_type;	// correspond to Pair
			typedef T*								pointer;	// Pointer to Pair
			typedef T&								reference;	// Reference to Pair

			// typedef	typename ft::iterator_traits<It>::iterator_category	iterator_category;
			// typedef	typename ft::iterator_traits<It>::pointer			pointer;
			// typedef	typename ft::iterator_traits<It>::reference			reference;
			// typedef	typename ft::iterator_traits<It>::value_type		value_type;
			// typedef	typename ft::iterator_traits<It>::difference_type	difference_type;
			
			/* iterator Constructor: default, parameter, copy, assign */
			TreeIterator() : _node() {}

			// TreeIterator(pointer node) : _node(node) {}

			// TreeIterator(const It& ref) : _node(ref._node) {}

			virtual ~TreeIterator() {}

			// It & operator=(const It& ref){
			// 	if (*this != ref)
			// 		this->_node = ref._node;
			// 	return (*this);
			// }

			// /* Can be dereferenced as an rvalue (if in a dereferenceable state). */
			// reference 			operator*() { return *_node; }
			// const reference 	operator*() const { return *_node; }
			// pointer 			operator->()  { return _node; }

			// // Prefix increment
			// It& operator++() { 
				
			// 	return *this; 
			// }

			// // Postfix increment
			// It operator++(int) { 
			// 	It tmp = *this; 
			// 	return (tmp);
			// }

			// // Prefix decrement
			// It& operator--() {
				
			// 	return *this;
			// }
			// // Postfix decrement
			// It operator--(int) {
			// 	It tmp = *this;

			// 	return (tmp);
			// }

			// // comparable with another iterator
			// friend bool operator== (const It& a, const It& b) { return (a._node == b._node); }
			// friend bool operator!= (const It& a, const It& b) { return (a._node != b._node); }
	};
}

#endif