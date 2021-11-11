#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP

# include <iostream>
# include <string>
# include <memory>
# include "iterator.hpp"
# include "../../map/rb_tree.hpp"

namespace ft
{
	template < class Category, class Tree >
	class TreeIterator
	{
		public:
			typedef typename	Tree::Node				Node;	//tree_node correspond to Node object with the template T.

		protected:
			Node *									_node_ptr;		// pointer to the node

		public:
			typedef typename Tree::value_type					value_type;	// correspond to Pair

			typedef typename value_type::first_type 				key_type;
			typedef typename value_type::second_type 			mapped_type;
			typedef	typename Tree::key_compare								key_compare;
			typedef value_type&							reference;
			typedef const value_type&					const_reference;
			typedef	value_type*							pointer;
			typedef	const value_type*					const_pointer;

			// typedef	typename ft::iterator_traits<It>::iterator_category	iterator_category;
			// typedef	typename ft::iterator_traits<It>::pointer			pointer;
			// typedef	typename ft::iterator_traits<It>::reference			reference;
			// typedef	typename ft::iterator_traits<It>::value_type		value_type;
			// typedef	typename ft::iterator_traits<It>::difference_type	difference_type;
			
			/* iterator Constructor: default, parameter, copy, assign */
			TreeIterator() {}

			// TreeIterator(Node *node) : _node_ptr(node) {}

			TreeIterator(Node* node) {
				this->_node_ptr = node;
			}

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