# ifndef MAP_ITERATOR_HPP

/*
**		MAP ITERATOR
*/

template <	class Category, class T, class not_const_T = T>
class map_iterator
{
	public:
		typedef typename T::value_type				value_type;
		typedef typename not_const_T::Node			Node;
		typedef typename T::key_type				key_type;
		typedef typename T::mapped_type				mapped_type;
		typedef	typename T::key_compare				key_compare;
		typedef typename T::pointer   				pointer;
		typedef typename T::reference 				reference;
		typedef ptrdiff_t							difference_type;
		typedef Category							iterator_category;

		map_iterator() {}
		map_iterator(const map_iterator<Category, not_const_T> &toCopy) : _ptr(toCopy.base()), _end(toCopy.end()) {}
		map_iterator(Node* node, Node* end) 
		{
			this->_ptr = node;
			this->_end = end;
		}
		virtual ~map_iterator() {}

		Node*			base() const { return this->_ptr; }
		Node*			end() const { return this->_end; }
		
		// operators : assignment
		// map_iterator&	operator=(Node* ptr) { this->_ptr = ptr; return *this; }
		map_iterator&	operator=(const map_iterator<Category, not_const_T> &toCopy) 
		{
			this->_ptr = toCopy._ptr;
			this->_end = toCopy._end;
			return *this;
		}

		// operators : member access
		reference   	operator*() const { return this->_ptr->value; }
		pointer     	operator->() const { return &(operator*()); }

		// operators : increment / decrement
		map_iterator&   operator++()
		{
			// find the smallest greater
			if (this->_ptr->right)
			{
				this->_ptr = this->_ptr->right->min();
				return *this;
			}
			else if (this->_ptr->parent)
			{
				// find first previous greater node
				key_type key = this->_ptr->value.first;
				Node *tmp = this->_ptr->parent;
				while (tmp && this->_key_comp(tmp->value.first, key))
					tmp = tmp->parent;
				if (tmp)
				{
					this->_ptr = tmp;
					return *this;
				}
			}
			this->_ptr = this->_end;
			return *this;
		}
		map_iterator    operator++(int) { map_iterator tmp = *this; ++*this; return tmp; }
		map_iterator&   operator--()
		{
			// find the greatest smaller
			if (this->_ptr == this->_end)
			{
				this->_ptr = this->_ptr->parent;
				return *this;
			}
			else if (this->_ptr->left)
			{
				this->_ptr = this->_ptr->left->max();
				return *this;
			}
			else if (this->_ptr->parent)
			{
				// find first previous smaller node
				key_type key = this->_ptr->value.first;
				Node *tmp = this->_ptr->parent;
				while (tmp && this->_key_comp(key, tmp->value.first))
					tmp = tmp->parent;
				if (tmp)
				{
					this->_ptr = tmp;
					return *this;
				}
			}
			else
			{
				// undefined
			}
			
			return *this;
		}
		map_iterator    operator--(int) { map_iterator tmp = *this; --*this; return tmp; }
		// operators : comparison
		friend bool		operator== (const map_iterator& lhs, const map_iterator& rhs) {
			return lhs._ptr == rhs._ptr; }
		friend bool 	operator!= (const map_iterator& lhs, const map_iterator& rhs) {
			return lhs._ptr != rhs._ptr; }

	private:
		Node*		_ptr;
		Node*		_end;
		key_compare	_key_comp;
};

#endif