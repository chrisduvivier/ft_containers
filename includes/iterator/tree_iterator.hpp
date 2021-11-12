#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP

# include <iostream>
# include <string>
# include <memory>
# include "iterator.hpp"
# include "../../map/rb_tree.hpp"
# include "../../map/node.hpp"

namespace ft
{
	template < class Category, class Tree >
	class TreeIterator
	{
		public:
			typedef typename Tree::value_type					value_type;	// correspond to Pair
			typedef typename value_type::first_type 			key_type;
			typedef typename value_type::second_type 			mapped_type;
			typedef	typename Tree::key_compare					key_compare;

			typedef	typename ft::Node<value_type>				Node;	//tree_node correspond to Node object with the template T.

			typedef value_type&									reference;
			typedef const value_type&							const_reference;
			typedef	value_type*									pointer;
			typedef	const value_type*							const_pointer;

			// typedef	typename ft::iterator_traits<It>::iterator_category	iterator_category;
			// typedef	typename ft::iterator_traits<It>::pointer			pointer;
			// typedef	typename ft::iterator_traits<It>::reference			reference;
			// typedef	typename ft::iterator_traits<It>::value_type		value_type;
			// typedef	typename ft::iterator_traits<It>::difference_type	difference_type;
			
			/* iterator Constructor: default, parameter, copy, assign */
			TreeIterator() {
				//std::cout << "Default TreeIterator constructor\n";
			}

			// TreeIterator(Node *node) : _node_ptr(node) {}

			TreeIterator(Node* node) {
				//std::cout << "Node based TreeIterator constructor\n";
				this->_node_ptr = node;
			}

			TreeIterator(const TreeIterator& ref) : _node_ptr(ref._node_ptr) {}

			virtual ~TreeIterator() {}

			TreeIterator & operator=(const TreeIterator& ref){
			 	if (*this != ref)
			 		this->_node_ptr = ref._node_ptr;
			 	return (*this);
			 }

			// /* Can be dereferenced as an rvalue (if in a dereferenceable state). */
			// reference 			operator*() { return *_node; }
			// const reference 	operator*() const { return *_node; }
			
			pointer 			operator->()  { return &(_node_ptr->data); }

			// Prefix increment
			TreeIterator& operator++() { 
				this->_node_ptr = forward(this->_node_ptr);
				return *this; 
			}

			TreeIterator  operator++(int) {
				TreeIterator tmp(*this);
				this->_node_ptr = forward(this->_node_ptr);
				return (tmp); 
			}


			// bool operator==(const TreeIterator& other)
			// {
			// 	return (_node_ptr == other._node_ptr);
			// }

			// bool operator!=(const TreeIterator& other)
			// {
			// 	return (!(*this == other));
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

			friend bool operator== (const TreeIterator& a, const TreeIterator& b) { return (a._node_ptr == b._node_ptr); }
			friend bool operator!= (const TreeIterator& a, const TreeIterator& b) { return (a._node_ptr != b._node_ptr); }
			friend bool operator<= (const TreeIterator& a, const TreeIterator& b) { return (a._node_ptr <= b._node_ptr); }
			friend bool operator>= (const TreeIterator& a, const TreeIterator& b) { return (a._node_ptr >= b._node_ptr); }
			friend bool operator< (const TreeIterator& a, const TreeIterator& b) { return (a._node_ptr < b._node_ptr); }
			friend bool operator> (const TreeIterator& a, const TreeIterator& b) { return (a._node_ptr > b._node_ptr); }

			Node* getNode(void)
			{
				return this->_node_ptr;
			}

			Node *  forward(Node * cursor)
			{
				// if the right subtree is not null,
				// the successor is the leftmost node in the
				// right subtree
				if (cursor && cursor->right && !cursor->right->is_tnull())
				{
					return (cursor->right->leftMost());
				}

				// else it is the lowest ancestor of x whose
				// left child is also an ancestor of x.
				Node * next = cursor->parent;
				while (next && !next->is_tnull() && cursor == next->right)
				{
					cursor = next;
					next = next->parent;
				}
				return next;
			}
			
		private:
			Node *	_node_ptr;		// pointer to the node
	};
}

#endif