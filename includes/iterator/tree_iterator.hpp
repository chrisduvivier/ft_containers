#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP

# include <iostream>
# include <string>
# include <memory>
# include "iterator.hpp"
# include "../map/rb_tree.hpp"
# include "../map/node.hpp"

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
			
			/* iterator Constructor: default, parameter, copy, assign */
			TreeIterator() { }

			TreeIterator(Node* node, Node* root) { 
				this->_node_ptr = node;
				this->_root = root;
			}

			TreeIterator(const TreeIterator& ref) : 
				_node_ptr(ref._node_ptr),
				_root(ref._root)
			{}

			virtual ~TreeIterator() {}
			
			// For mutable iterators (non-constant iterators):
			TreeIterator & operator=(const TreeIterator& ref) {
			 	if (*this != ref)
			 		this->_node_ptr = ref._node_ptr;
			 		this->_root = ref._root;
			 	return (*this);
			}

			/* Can be dereferenced as an rvalue (if in a dereferenceable state). */
			reference 			operator*() { return (_node_ptr->data); }
			const_reference 	operator*() const { return (_node_ptr->data); }
			
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

			// Prefix decrement
			TreeIterator& operator--() {
				this->_node_ptr = backward(this->_node_ptr);
				return *this;
			}
			// Postfix decrement
			TreeIterator operator--(int) {
				TreeIterator tmp(*this);
				this->_node_ptr = backward(this->_node_ptr);
				return (tmp); 
			}

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
				else
				{
					Node * ref_to_tnull = cursor->right;
					// else it is the lowest ancestor of x whose
					// left child is also an ancestor of x.
					Node * p = cursor->parent;
					while (p && !p->is_tnull() && cursor == p->right)
					{
						cursor = p;
						p = p->parent;
					}
					// if we were previously at the right-most node in
					// the tree, cursor = nullptr, and the iterator specifies
					// the end of the list
					cursor = p;
					if (cursor == nullptr)
					{
						return (ref_to_tnull);
					}
				}
				return cursor;
			}

			Node *  backward(Node * cursor)
			{
				// At initialization, backward is called on end object (t_null node)
				if (cursor->is_tnull())
				{
					if (!this->_root->is_tnull())
						return (this->_root->rightMost());
					return (cursor);
				}

				// if the left subtree is not null,
				// the predecessor is the rightmost node in the
				// left subtree
				if (cursor && cursor->left && !cursor->left->is_tnull())
				{
					return (cursor->left->rightMost());
				}
				else
				{
					Node * ref_to_tnull = cursor->left;
					Node * p = cursor->parent;
					while (p && !p->is_tnull() && cursor == p->left)
					{
						cursor = p;
						p = p->parent;
					}
					// if we were previously at the right-most node in
					// the tree, cursor = nullptr, and the iterator specifies
					// the end of the list
					cursor = p;
					if (cursor == nullptr)
					{
						return (ref_to_tnull);
					}
				}
				return cursor;
			}
			
		private:
			Node *	_node_ptr;		// pointer to the node
			Node *	_root;			// pointer to the root of tree
	};
}

#endif