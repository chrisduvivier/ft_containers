/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair_rb_tree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:23:49 by rlinkov           #+#    #+#             */
/*   Updated: 2021/10/25 18:37:52 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_RB_TREE_H
#define PAIR_RB_TREE_H

// Red Black Tree implementation in C++
// Author: Algorithm Tutor
// Tutorial URL: https://algorithmtutor.com/Data-Structures/Tree/Red-Black-Trees/

#include <iostream>
#include "pair.hpp"

namespace ft
{
// class RBTree implements the operations in Red Black Tree
template<class T, class Compare, class Alloc = std::allocator<T> >
class PRBTree
{
	public:
	typedef T			value_type;

	struct Node
	{
		value_type data; // holds the key/value
		Node *parent; // pointer to the parent
		Node *left;	  // pointer to left child
		Node *right;  // pointer to right child
		int color;	  // 1 -> Red, 0 -> Black
	};

	typedef Node *NodePtr;
		PRBTree()
		{
			TNULL = new Node;
			TNULL->color = 0;
			TNULL->left = nullptr;
			TNULL->right = nullptr;
			root = TNULL;
		}

		// Pre-Order traversal
		// Node->Left Subtree->Right Subtree
		void preorder()
		{
			preOrderHelper(this->root);
		}

		// In-Order traversal
		// Left Subtree -> Node -> Right Subtree
		void inorder()
		{
			inOrderHelper(this->root);
		}

		// Post-Order traversal
		// Left Subtree -> Right Subtree -> Node
		void postorder()
		{
			postOrderHelper(this->root);
		}

		// search the tree for the key k
		// and return the corresponding node
		NodePtr searchTree(value_type k)
		{
			return searchTreeHelper(this->root, k);
		}

		// find the node with the minimum key
		NodePtr minimum(NodePtr node)
		{
			while (node->left != TNULL)
			{
				node = node->left;
			}
			return node;
		}

		// find the node with the maximum key
		NodePtr maximum(NodePtr node)
		{
			while (node->right != TNULL)
			{
				node = node->right;
			}
			return node;
		}

		// find the successor of a given node
		NodePtr successor(NodePtr x)
		{
			// if the right subtree is not null,
			// the successor is the leftmost node in the
			// right subtree
			if (x->right != TNULL)
			{
				return minimum(x->right);
			}

			// else it is the lowest ancestor of x whose
			// left child is also an ancestor of x.
			NodePtr y = x->parent;
			while (y != TNULL && x == y->right)
			{
				x = y;
				y = y->parent;
			}
			return y;
		}

		// find the predecessor of a given node
		NodePtr predecessor(NodePtr x)
		{
			// if the left subtree is not null,
			// the predecessor is the rightmost node in the
			// left subtree
			if (x->left != TNULL)
			{
				return maximum(x->left);
			}

			NodePtr y = x->parent;
			while (y != TNULL && x == y->left)
			{
				x = y;
				y = y->parent;
			}

			return y;
		}

		// rotate left at node x
		void leftRotate(NodePtr x)
		{
			NodePtr y = x->right;
			x->right = y->left;
			if (y->left != TNULL)
			{
				y->left->parent = x;
			}
			y->parent = x->parent;
			if (x->parent == nullptr)
			{
				this->root = y;
			}
			else if (x == x->parent->left)
			{
				x->parent->left = y;
			}
			else
			{
				x->parent->right = y;
			}
			y->left = x;
			x->parent = y;
		}

		// rotate right at node x
		void rightRotate(NodePtr x)
		{
			NodePtr y = x->left;
			x->left = y->right;
			if (y->right != TNULL)
			{
				y->right->parent = x;
			}
			y->parent = x->parent;
			if (x->parent == nullptr)
			{
				this->root = y;
			}
			else if (x == x->parent->right)
			{
				x->parent->right = y;
			}
			else
			{
				x->parent->left = y;
			}
			y->right = x;
			x->parent = y;
		}

		// insert the key to the tree in its appropriate position
		// and fix the tree
		void insert(value_type key)
		{
			// Ordinary Binary Search Insertion
			NodePtr node = new Node;
			node->parent = nullptr;
			node->data = key;
			node->left = TNULL;
			node->right = TNULL;
			node->color = 1; // new node must be red

			NodePtr y = nullptr;
			NodePtr x = this->root;

			while (x != TNULL)
			{
				y = x;
				if (node->data < x->data)
				{
					x = x->left;
				}
				else
				{
					x = x->right;
				}
			}

			// y is parent of x
			node->parent = y;
			if (y == nullptr)
			{
				root = node;
			}
			else if (node->data < y->data)
			{
				y->left = node;
			}
			else
			{
				y->right = node;
			}

			// if new node is a root node, simply return
			if (node->parent == nullptr)
			{
				node->color = 0;
				return;
			}

			// if the grandparent is null, simply return
			if (node->parent->parent == nullptr)
			{
				return;
			}

			// Fix the tree
			fixInsert(node);
		}

		NodePtr getRoot()
		{
			return this->root;
		}

		// delete the node from the tree
		void deleteNode(value_type data)
		{
			deleteNodeHelper(this->root, data);
		}

		// print the tree structure on the screen
		void prettyPrint()
		{
			if (root)
			{
				printHelper(this->root, "", true);
			}
		}
private:
	NodePtr root;
	NodePtr TNULL;

	// initializes the nodes with appropirate values
	// all the pointers are set to point to the null pointer
	void initializeNULLNode(NodePtr node, NodePtr parent)
	{
		node->data = 0; //HERE ?
		node->parent = parent;
		node->left = nullptr;
		node->right = nullptr;
		node->color = 0;
	}

	void preOrderHelper(NodePtr node) //HERE2?
	{
		if (node != TNULL)
		{
			std::cout << node->data << " ";
			preOrderHelper(node->left);
			preOrderHelper(node->right);
		}
	}

	void inOrderHelper(NodePtr node)
	{
		if (node != TNULL)
		{
			inOrderHelper(node->left);
			std::cout << node->data << " ";
			inOrderHelper(node->right);
		}
	}

	void postOrderHelper(NodePtr node)
	{
		if (node != TNULL)
		{
			postOrderHelper(node->left);
			postOrderHelper(node->right);
			std::cout << node->data << " ";
		}
	}

	NodePtr searchTreeHelper(NodePtr node, value_type key)
	{
		if (node == TNULL || key == node->data)
		{
			return node;
		}

		if (key < node->data)
		{
			return searchTreeHelper(node->left, key);
		}
		return searchTreeHelper(node->right, key);
	}

	// fix the rb tree modified by the delete operation
	void fixDelete(NodePtr x)
	{
		NodePtr s;
		while (x != root && x->color == 0)
		{
			if (x == x->parent->left)
			{
				s = x->parent->right;
				if (s->color == 1)
				{
					// case 3.1
					s->color = 0;
					x->parent->color = 1;
					leftRotate(x->parent);
					s = x->parent->right;
				}

				if (s->left->color == 0 && s->right->color == 0)
				{
					// case 3.2
					s->color = 1;
					x = x->parent;
				}
				else
				{
					if (s->right->color == 0)
					{
						// case 3.3
						s->left->color = 0;
						s->color = 1;
						rightRotate(s);
						s = x->parent->right;
					}

					// case 3.4
					s->color = x->parent->color;
					x->parent->color = 0;
					s->right->color = 0;
					leftRotate(x->parent);
					x = root;
				}
			}
			else
			{
				s = x->parent->left;
				if (s->color == 1)
				{
					// case 3.1
					s->color = 0;
					x->parent->color = 1;
					rightRotate(x->parent);
					s = x->parent->left;
				}

				if (s->right->color == 0 && s->right->color == 0)
				{
					// case 3.2
					s->color = 1;
					x = x->parent;
				}
				else
				{
					if (s->left->color == 0)
					{
						// case 3.3
						s->right->color = 0;
						s->color = 1;
						leftRotate(s);
						s = x->parent->left;
					}

					// case 3.4
					s->color = x->parent->color;
					x->parent->color = 0;
					s->left->color = 0;
					rightRotate(x->parent);
					x = root;
				}
			}
		}
		x->color = 0;
	}

	void rbTransplant(NodePtr u, NodePtr v)
	{
		if (u->parent == nullptr)
		{
			root = v;
		}
		else if (u == u->parent->left)
		{
			u->parent->left = v;
		}
		else
		{
			u->parent->right = v;
		}
		v->parent = u->parent;
	}

	void deleteNodeHelper(NodePtr node, value_type key)
	{
		// find the node containing key
		NodePtr z = TNULL;
		NodePtr x, y;
		while (node != TNULL)
		{
			if (node->data == key)
			{
				z = node;
			}

			if (node->data <= key)
			{
				node = node->right;
			}
			else
			{
				node = node->left;
			}
		}

		if (z == TNULL)
		{
			std::cout << "Couldn't find key in the tree" << std::endl;
			return;
		}

		y = z;
		int y_original_color = y->color;
		if (z->left == TNULL)
		{
			x = z->right;
			rbTransplant(z, z->right);
		}
		else if (z->right == TNULL)
		{
			x = z->left;
			rbTransplant(z, z->left);
		}
		else
		{
			y = minimum(z->right);
			y_original_color = y->color;
			x = y->right;
			if (y->parent == z)
			{
				x->parent = y;
			}
			else
			{
				rbTransplant(y, y->right);
				y->right = z->right;
				y->right->parent = y;
			}

			rbTransplant(z, y);
			y->left = z->left;
			y->left->parent = y;
			y->color = z->color;
		}
		delete z;
		if (y_original_color == 0)
		{
			fixDelete(x);
		}
	}

	// fix the red-black tree
	void fixInsert(NodePtr k)
	{
		NodePtr u;
		while (k->parent->color == 1)
		{
			if (k->parent == k->parent->parent->right)
			{
				u = k->parent->parent->left; // uncle
				if (u->color == 1)
				{
					// case 3.1
					u->color = 0;
					k->parent->color = 0;
					k->parent->parent->color = 1;
					k = k->parent->parent;
				}
				else
				{
					if (k == k->parent->left)
					{
						// case 3.2.2
						k = k->parent;
						rightRotate(k);
					}
					// case 3.2.1
					k->parent->color = 0;
					k->parent->parent->color = 1;
					leftRotate(k->parent->parent);
				}
			}
			else
			{
				u = k->parent->parent->right; // uncle

				if (u->color == 1)
				{
					// mirror case 3.1
					u->color = 0;
					k->parent->color = 0;
					k->parent->parent->color = 1;
					k = k->parent->parent;
				}
				else
				{
					if (k == k->parent->right)
					{
						// mirror case 3.2.2
						k = k->parent;
						leftRotate(k);
					}
					// mirror case 3.2.1
					k->parent->color = 0;
					k->parent->parent->color = 1;
					rightRotate(k->parent->parent);
				}
			}
			if (k == root)
			{
				break;
			}
		}
		root->color = 0;
	}

	void printHelper(NodePtr root, std::string indent, bool last)
	{
		// print the tree structure on the screen
		if (root != TNULL)
		{
			std::cout << indent;
			if (last)
			{
				std::cout << "R----";
				indent += "     ";
			}
			else
			{
				std::cout << "L----";
				indent += "|    ";
			}

			std::string sColor = root->color ? "RED" : "BLACK";
			std::cout << root->data.first << "," << root->data.second << "(" << sColor << ")" << std::endl;
			printHelper(root->left, indent, false);
			printHelper(root->right, indent, true);
		}
		// cout<<root->left->data<<endl;
	}
	
	/******************************************
	 * New Function on RBT to use with map
	*******************************************/

	/******************************************
	 * Search by key in pair
	*******************************************/
	public :
		// search a node in the tree by giving his key
		NodePtr searchTreeKey(typename T::first_type  k)
		{
			return searchTreeHelperKey(this->root, k);
		}

	private:
		NodePtr searchTreeHelperKey(NodePtr node, typename T::first_type key)
		{
			if (node == TNULL || key == node->data.first)
			{
				return node;
			}

			if (key < node->data.first)
			{
				return searchTreeHelperKey(node->left, key);
			}
			return searchTreeHelperKey(node->right, key);
		}

	/******************************************
	 * Delete by key in pair
	*******************************************/
	public:
		// delete the node from the tree by giving his key
		void deleteNodeKey(typename T::first_type key)
		{
			NodePtr node = searchTreeKey(key);
			deleteNodeHelper(this->root, node->data);
		}

	/******************************************
	 * Insert at given key
	*******************************************/
	public:
		void insertAt(typename T::first_type key, typename T::second_type value)
		{
			NodePtr node = searchTreeKey(key);
			if (node == TNULL)
			{
				value_type p(key, value);
				this->insert(p);
				return ;
			}
			node->data.second = value;
		}
};

}

#endif