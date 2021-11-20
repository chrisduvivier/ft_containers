#ifndef NODE_HPP
# define NODE_HPP

# include <iostream>
# include <string>
# include <memory>
# include "pair.hpp"
# include "../utils/utils.hpp"

namespace ft
{
    template<class T>
    struct Node
    {
        typedef T							value_type;

        value_type		data; 		// holds the key/value
        Node			*parent; 	// pointer to the parent
        Node			*left;	  	// pointer to left child
        Node			*right;  	// pointer to right child
        int				color;	  	// 1 -> Red, 0 -> Black
        bool			dummy;	  	// 1 -> TNULL node, 0 -> Valid node

        Node* leftMost()
        {
            Node *cursor = this;
            if (cursor->is_tnull())
            {
                return (nullptr);
            }
            while (cursor->left && !cursor->left->is_tnull())
			{
                cursor = cursor->left;
			}
            return (cursor);
        }

        Node* rightMost()
        {
            Node *cursor = this;
            if (cursor == nullptr)
                return (nullptr);
            while (cursor->right && !cursor->right->is_tnull())
                cursor = cursor->right;
            return (cursor);
        }

        Node* getParent()
        {
            Node *cursor = this;
            if (cursor == nullptr)
                return (nullptr);
            return (cursor->parent);
        }

        Node* getRoot()
        {
            Node *cursor = this;
            if (cursor == nullptr)
                return (nullptr);
            while (cursor->parent)
                cursor = cursor->parent;
            return (cursor);
        }

        bool is_tnull() { return (this->dummy); }
    };
};

#endif