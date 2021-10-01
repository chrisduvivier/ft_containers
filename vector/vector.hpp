#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>
# include <memory>

namespace ft
{
	template < class T, class Alloc = std::allocator<T> > // generic template
	class vector
	{
		public:

			/* Type of the elements allocated by the object (aliased as member type value_type). */
			typedef				T									value_type;
			
			typedef				Alloc								allocator_type;
			typedef typename	allocator_type::reference			reference;
			typedef typename	allocator_type::const_reference		const_reference;
			typedef typename	allocator_type::pointer				pointer;
			typedef typename	allocator_type::const_pointer		const_pointer;

			// iterator
			// const_iterator
			// reverse_iterator
			// const_reverse_iterator
			// difference_type

			typedef typename	allocator_type::size_type		size_type;

			/*
			**	(1) empty container constructor (default constructor)
			**	Constructs an empty container, with no elements.
			*/
			explicit 	vector(const allocator_type& alloc = allocator_type()) :
				_alloc(alloc), _size(0), _capacity(0)
            {
                _array = _alloc.allocate(_capacity);
			}

			/*
			**	(2) fill constructor
			**	Constructs a container with n elements. Each element is a copy of val.
			*/
			explicit	vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : 
				_alloc(alloc), _size(n), _capacity(n)
			{
				_array = _alloc.allocate(n);
				for (size_type i = 0; i < n; i++)
				{
					_alloc.construct(&_array[i], val);
				}
			}

			/*
			**	Think of the _alloc object as an array of objects. Therefore we need to destroy each obj in the array,
			**	and then destroy the array itself.
			*/
			~vector()
			{
				for (size_type i = 0; i < this->size(); i++)
				{
					_alloc.destroy(&_array[i]);
				}
			}

			u_int32_t	capacity()
			{
				return (this->_capacity);
			}

			u_int32_t	size()
			{
				return (this->_size);
			}

		private:

			allocator_type  _alloc;						/*	allocator calss holding object	*/
			pointer			_array;						/*	Pointer on an array of T values	*/
			size_type		_size;						/*	current size of the obj 		*/
			size_type		_capacity;					/*	current capacity of the obj 	*/
	};

	// std::ostream &			operator<<( std::ostream & o, vector const & i );

}

#endif /* ********************************************************** VECTOR_H */