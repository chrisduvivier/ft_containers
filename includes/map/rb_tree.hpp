#ifndef RB_TREE_H
# define RB_TREE_H

// Red Black Tree implementation in C++
// Author: Algorithm Tutor
// Tutorial URL: https://algorithmtutor.com/Data-Structures/Tree/Red-Black-Trees/

# include <iostream>
# include "pair.hpp"
# include "node.hpp"
# include "../utils/utils.hpp"

namespace ft
{

// class RBTree implements the operations in Red Black Tree
template<class T, class Compare = std::less<typename T::first_type>, class Alloc = std::allocator<T> >
class RBTree
{
	public:

		typedef T							value_type;		//correspond to `pairs` in our case
		typedef ft::Node<value_type>		Node;
		typedef size_t						size_type;
		typedef	Alloc						allocator_type;

		typedef typename T::first_type 		key_type;
		typedef typename T::second_type 	mapped_type;
		typedef typename T::second_type 	pair;
		
		typedef	Compare						key_compare;
		typedef value_type&					reference;
		typedef const value_type&			const_reference;
		typedef	value_type*					pointer;
		typedef	const value_type*			const_pointer;

		typedef Node*						node_ptr;
		typedef const Node*					const_node_ptr;

	private:
		typename allocator_type::template rebind<Node>::other	_node_alloc;
		allocator_type											_alloc;
		node_ptr												_root;
		node_ptr												_tnull;
		key_compare												_comp;

	public:

		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
			class RBTree;
			private:
				key_compare comp;
			public:
				value_compare(const key_compare &x) : comp(x) {}
				bool operator()(const value_type &x, const value_type &y) const
				{
					return comp(x.first, y.first);
				}
		};

	public:

		/* Constructor */
		RBTree(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
			_alloc(alloc),
			_comp(comp) 
		{
			_tnull = _node_alloc.allocate(1);
			_tnull->dummy = 1;
			_tnull->color = 0;
			_tnull->left = nullptr;
			_tnull->right = nullptr;
			this->_root = _tnull;
		}

		RBTree(const RBTree& x)
		{
			this->_alloc = x._alloc;
			this->_node_alloc = x._node_alloc;
			this->_comp = x._comp;
			
			_tnull = _node_alloc.allocate(1);
			_tnull->dummy = 1;
			_tnull->color = 0;
			_tnull->left = nullptr;
			_tnull->right = nullptr;
			this->_root = _tnull;

			this->_root = this->copy_tree(nullptr, this->_root, x._root);
		}

		RBTree &		operator=(const RBTree& x)
		{		
			if (this == &x)
				return *this;
			
			// clean previous content
			this->clear();
			
			this->_alloc = x._alloc;
			this->_node_alloc = x._node_alloc;
			this->_comp = x._comp;
			
			this->_root = _tnull;
			this->_root = this->copy_tree(nullptr, this->_root, x._root);

			return *this;
		}

		node_ptr	copy_tree(node_ptr parent, node_ptr node, const node_ptr ref)
		{
			if (ref && !ref->dummy)
			{
				node = copy_node(parent, node, ref);
				if (ref->left && !ref->left->dummy)
					node->left = copy_tree(node, node->left, ref->left);
				if (ref->right && !ref->right->dummy)
					node->right = copy_tree(node, node->right, ref->right);
			}
			return (node);
		}

		// called when ref is valid and node is needed to be created
		node_ptr	copy_node(node_ptr parent, node_ptr node, const node_ptr ref)
		{
			node = this->_node_alloc.allocate(1);
			node->parent = parent;
			node->dummy = 0;
			node->left = this->_tnull;
			node->right = this->_tnull;
			node->color = ref->color;
			this->_alloc.construct(&node->data, ref->data); //construct the key into data
			return (node);
		}

		/* Need a destructor ? */
		~RBTree()
		{
			this->clear();
			this->_node_alloc.deallocate(this->_tnull, 1);
		}

		void	clear() {
			this->destroy_tree(this->_root);
			this->_root = this->_tnull;
		}

		void	destroy_tree(node_ptr node)
		{
			if (node && !node->dummy)
			{
				// recursive call to both child node
				if (node->left && !node->left->dummy)
					destroy_tree(node->left);
				if (node->right && !node->right->dummy)
					destroy_tree(node->right);
				
				// delete current node and its pair
				this->_alloc.destroy(&node->data);		// pair
				this->_node_alloc.deallocate(node, 1);	// node itself
			}
		}

		node_ptr	begin_node() const
		{
			if (this->_root && this->_root != this->_tnull)
				return (this->minimum(this->_root));
			return (this->_tnull);
		}
		
		node_ptr	end_node() const
		{
			return (this->_tnull);
		}

		// Pre-Order traversal
		// Node->Left Subtree->Right Subtree
		void preorder()
		{
			preOrderHelper(this->_root);
		}

		// In-Order traversal
		// Left Subtree -> Node -> Right Subtree
		void inorder()
		{
			inOrderHelper(this->_root);
		}

		// Post-Order traversal
		// Left Subtree -> Right Subtree -> Node
		void postorder()
		{
			postOrderHelper(this->_root);
		}
		
		// search the tree for the key k
		// and return the corresponding node
		node_ptr searchTree(value_type k)
		{
			return searchTreeHelper(this->_root, k);
		}

		// find the node with the minimum key
		node_ptr minimum(node_ptr node) const
		{
			while (node->left != _tnull)
			{
				node = node->left;
			}
			return node;
		}

		// find the node with the maximum key
		node_ptr maximum(node_ptr node) const
		{
			while (node->right != _tnull)
			{
				node = node->right;
			}
			return node;
		}

		// find the successor of a given node
		node_ptr successor(node_ptr x)
		{
			// if the right subtree is not null,
			// the successor is the leftmost node in the
			// right subtree
			if (x->right != _tnull)
			{
				return minimum(x->right);
			}

			// else it is the lowest ancestor of x whose
			// left child is also an ancestor of x.
			node_ptr y = x->parent;
			while (y != _tnull && x == y->right)
			{
				x = y;
				y = y->parent;
			}
			return y;
		}

		// find the predecessor of a given node
		node_ptr predecessor(node_ptr x)
		{
			// if the left subtree is not null,
			// the predecessor is the rightmost node in the
			// left subtree
			if (x->left != _tnull)
			{
				return maximum(x->left);
			}

			node_ptr y = x->parent;
			while (y != _tnull && x == y->left)
			{
				x = y;
				y = y->parent;
			}

			return y;
		}

		// rotate left at node x
		void leftRotate(node_ptr x)
		{
			node_ptr y = x->right;
			x->right = y->left;
			if (y->left != _tnull)
			{
				y->left->parent = x;
			}
			y->parent = x->parent;
			if (x->parent == nullptr)
			{
				this->_root = y;
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
		void rightRotate(node_ptr x)
		{
			node_ptr y = x->left;
			x->left = y->right;
			if (y->right != _tnull)
			{
				y->right->parent = x;
			}
			y->parent = x->parent;
			if (x->parent == nullptr)
			{
				this->_root = y;
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
		node_ptr insert(const value_type & key)
		{
			// Ordinary Binary Search Insertion

			// check if key exists before proceeding to insertion. If exists already, return that node
			node_ptr tmp = searchTree(key);
			if (tmp != _tnull)
				return tmp;

			node_ptr node = _node_alloc.allocate(1);
			node->parent = nullptr;
			node->dummy = 0;

			this->_alloc.construct(&node->data, key); //construct the key into data
			
			node->left = _tnull;
			node->right = _tnull;
			node->color = 1; // new node must be red

			node_ptr y = nullptr;
			node_ptr x = this->_root;

			while (x != _tnull)
			{
				y = x;
				if (node->data < x->data)
				//if (this->_comp(key.first, node->left->data.first)) //if key.first < node->left->data.first using compare as std::less
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
				_root = node;
			}
			else if (node->data < y->data)
			//else if (this->_comp(key.first, node->left->data.first))
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
				return node;
			}

			// if the grandparent is null, simply return
			if (node->parent->parent == nullptr)
			{
				return node;
			}

			// Fix the tree
			fixInsert(node);
			return node;
		}

		ft::pair<node_ptr, bool> insert_single_elem(const value_type & key)
		{
			node_ptr tmp = searchTreeKey(key.first);
			if (tmp != _tnull)	// key already in tree
			{
				ft::pair<node_ptr, bool> res_pair(tmp, false);
				return (res_pair);
			}
			else
			{
				tmp = insert(key);
				ft::pair<node_ptr, bool> res_pair(tmp, true);
				return (res_pair);
			}
		}

		node_ptr getRoot() const
		{
			return this->_root;
		}

		// delete the node from the tree
		void deleteNode(value_type data)
		{
			deleteNodeHelper(this->_root, data);
		}

		// print the tree structure on the screen
		void prettyPrint()
		{
			if (_root)
			{
				printHelper(this->_root, "", true);
			}
		}

	private:

		// initializes the nodes with appropirate values
		// all the pointers are set to point to the null pointer
		void initializeNULLNode(node_ptr node, node_ptr parent)
		{
			node->data = 0; //HERE ?
			node->parent = parent;
			node->left = nullptr;
			node->right = nullptr;
			node->color = 0;
		}

		void preOrderHelper(node_ptr node) //HERE2?
		{
			if (node != _tnull)
			{
				std::cout << node->data << " ";
				preOrderHelper(node->left);
				preOrderHelper(node->right);
			}
		}

		void inOrderHelper(node_ptr node)
		{
			if (node != _tnull)
			{
				inOrderHelper(node->left);
				std::cout << node->data << " ";
				inOrderHelper(node->right);
			}
		}

		void postOrderHelper(node_ptr node)
		{
			if (node != _tnull)
			{
				postOrderHelper(node->left);
				postOrderHelper(node->right);
				std::cout << node->data << " ";
			}
		}

		// either reach the end of tree, so no hit and a _tnull is returned. Otherwise, the corresponding node is return.
		node_ptr searchTreeHelper(node_ptr node, value_type key)
		{
			if (node == _tnull || key == node->data)
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
		void fixDelete(node_ptr x)
		{
			node_ptr s;
			while (x != _root && x->color == 0)
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
						x = _root;
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
						x = _root;
					}
				}
			}
			x->color = 0;
		}

		void rbTransplant(node_ptr u, node_ptr v)
		{
			if (u->parent == nullptr)
			{
				_root = v;
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

		bool deleteNodeHelper(node_ptr node, value_type key)
		{
			// find the node containing key
			node_ptr z = _tnull;
			node_ptr x, y;
			while (node != _tnull)
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

			if (z == _tnull)
			{
				// std::cout << "Couldn't find key in the tree" << std::endl;
				return (false);
			}

			y = z;
			int y_original_color = y->color;
			if (z->left == _tnull)
			{
				x = z->right;
				rbTransplant(z, z->right);
			}
			else if (z->right == _tnull)
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
			// delete z;
			_alloc.destroy(&z->data);		// pair
			_node_alloc.deallocate(z, 1);	// node itself
			
			if (y_original_color == 0)
			{
				fixDelete(x);
			}
			return (true);
		}

		// fix the red-black tree
		void fixInsert(node_ptr k)
		{
			node_ptr u;
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
				if (k == _root)
				{
					break;
				}
			}
			_root->color = 0;
		}

		void printHelper(node_ptr root, std::string indent, bool last)
		{
			// print the tree structure on the screen
			if (root != _tnull)
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
			node_ptr searchTreeKey(key_type  k) const {
				return searchTreeHelperKey(this->_root, k);
			}

		private:
			node_ptr searchTreeHelperKey(node_ptr node, key_type key) const{
				if (node == _tnull || key == node->data.first)
				{
					return node;
				}

				if (key < node->data.first)
				//if (this->_comp(key, node->data.first))
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
			size_type deleteNodeKey(key_type key)
			{
				node_ptr node = searchTreeKey(key);
				return (deleteNodeHelper(this->_root, node->data));
			}

		/******************************************
		 * Insert at given key
		*******************************************/
		public:
			void insertAt(key_type key, mapped_type value)
			{
				node_ptr node = searchTreeKey(key);
				if (node == _tnull)
				{
					value_type p(key, value);
					this->insert(p);
					return ;
				}
				node->data.second = value;
			}

		/******************************************
		 * Access mapped type by []
		*******************************************/
		public:
		mapped_type& 	operator[](const key_type& key) {
			node_ptr node = this->searchTreeKey(key);
			if (node != _tnull)
			{
				return node->data.second;
			}

			this->insert(ft::make_pair<const key_type, mapped_type>(key, mapped_type()));
			return (*this)[key];
		}

		/******************************************
		 * Max_size of RBTree
		*******************************************/
		public:
		size_type 	max_size() const {
			return this->_node_alloc.max_size();
		}

		/******************************************
		 * size of RBTree
		*******************************************/
		public:
		size_type 	size() const {
			return (sizeCalc(this->getRoot()));
		}

		size_type	sizeCalc(node_ptr node) const {
			size_type s = 0;
			if (node != _tnull)
			{
				s += sizeCalc(node->left);
				s += sizeCalc(node->right);
				s++;
			}
			return s;
		}

		/******************************************
		 * Swap Tree
		*******************************************/
		public:
		/* Swap _root AND _tnull*/
		void 	swap(RBTree &x) {
			node_ptr temp = this->_root;
			this->_root = x._root;
			x._root = temp;

			temp = this->_tnull;
			this->_tnull = x._tnull;
			x._tnull = temp;
		}
		/******************************************
		 * Get key_compare
		*******************************************/
		public:
		key_compare 	get_key_comp() const {
			return (this->_comp);
		}
		/******************************************
		 * Get value_compare
		*******************************************/
		public:
		value_compare 	get_value_comp() const {
			return (value_compare(this->_comp));
		}

		// Returns an iterator pointing to the first element in the container whose key is not considered to go before k (i.e., either it is equivalent or goes after).
		// x >= k
		node_ptr lower_bound (const key_type& k)
		{
			node_ptr cursor = this->_root;
			node_ptr res = this->_tnull;
			while (cursor != _tnull)
			{
				if (this->_comp(cursor->data.first, k) == false)
				{
					res = cursor;
					cursor = cursor->left;	//look for smaller element that satisfy the condition
				}
				else
					cursor = cursor->right;
			}
			return (res);
		}

		// Returns an iterator pointing to the first element in the container whose key is considered to go after k.
		// x < k
		node_ptr upper_bound (const key_type& k)
		{
			node_ptr cursor = this->_root;
			node_ptr res = this->_tnull;
			while (cursor != _tnull)
			{
				if (this->_comp(k, cursor->data.first))
				{
					res = cursor;
					cursor = cursor->left;	//look for bigger element that satisfy the condition
				}
				else
					cursor = cursor->right;
			}
			return (res);
		}

		allocator_type get_allocator() const { 
			return (this->_alloc);
		}

};	// end of RBTree
}	// end of namespace ft

#endif