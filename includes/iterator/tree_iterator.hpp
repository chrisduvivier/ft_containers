#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP

# include <iostream>
# include <string>
# include <memory>
# include "iterator.hpp"
# include "../map/rb_tree.hpp"
# include "../map/node.hpp"
# include "../utils/utils.hpp"

namespace ft
{
	template < class Category, class Tree , class not_const_Tree = Tree>
	class TreeIterator : public ft::iterator< Category, Tree >
	{
		public:
			typedef typename Tree::value_type					value_type;	// correspond to Pair
			typedef typename Tree::key_type						key_type;
			typedef typename Tree::mapped_type					mapped_type;
			typedef	typename Tree::key_compare					key_compare;

			typedef	typename not_const_Tree::Node				Node;	//tree_node correspond to Node object with the template T.

			typedef typename Tree::reference					reference;
			typedef const value_type&							const_reference;
			typedef	typename Tree::pointer						pointer;
			typedef	const value_type*							const_pointer;
			
			/* iterator Constructor: default, parameter, copy, assign */
			TreeIterator() {
				this->_node_ptr = nullptr;
				this->_root = nullptr;
			}

			TreeIterator(Node* node, Node* root) { 
				this->_node_ptr = node;
				this->_root = root;
			}

			TreeIterator(const TreeIterator<Category, not_const_Tree> & ref) : _node_ptr(ref.getNode()), _root(ref.getRoot()) {}

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

			Node *	getNode() const {
				return (this->_node_ptr);
			}

			Node *	getRoot() const {
				return (this->_root);
			}
			
		private:
			Node *	_node_ptr;		// pointer to the node
			Node *	_root;			// pointer to the root of tree
	};
}

#endif