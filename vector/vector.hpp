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
			explicit 	vector (const allocator_type& alloc = allocator_type()) :
				_alloc(alloc),
				_start(nullptr),
				_end(nullptr),
				_capacity(0)
			{ }


			/*
			**	Think of the _alloc object as an array of objects. Therefore we need to destroy each obj in the array,
			**	and then destroy the array itself.
			*/
			~vector()
			{
				pointer tmp = this->_start;
				for (size_type i = 0; i < _size; i++)
				{
					_alloc.destroy(tmp);
					tmp++;
				}
				_size = 0;
				_alloc.deallocate(_start, _capacity);
			}


		private:

			allocator_type  _alloc;						/*	allocator calss holding object	*/
			pointer         _start;						/*	pointer to the first object		*/
			pointer         _end;						/*	pointer to the last object		*/
			u_int32_t		_size;						/*	current size of the obj 		*/
			u_int32_t		_capacity;					/*	current capacity of the obj 	*/
	};

	// std::ostream &			operator<<( std::ostream & o, vector const & i );

}

#endif /* ********************************************************** VECTOR_H */