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

			typedef				T		value_type;
			typedef				Alloc	allocator_type;
			typedef typename	allocator_type::reference	reference;
			typedef typename	allocator_type::const_reference	const_reference;
			typedef typename	allocator_type::pointer	pointer;
			typedef typename	allocator_type::const_pointer	const_pointer;

			// iterator
			// const_iterator
			// reverse_iterator
			// const_reverse_iterator
			// difference_type	
			// size_type

			/*
			**	(1) empty container constructor (default constructor)
			**	Constructs an empty container, with no elements.
			*/
			explicit 	vector (const allocator_type& alloc = allocator_type())
			{

			}
			
			~vector();


		private:
			T		*_array;
			size_t	_capacity;
			size_t	_size;
	};

	// std::ostream &			operator<<( std::ostream & o, vector const & i );

}

#endif /* ********************************************************** VECTOR_H */