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
			
			/****************************
			*	   Member types  		*
			****************************/

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

			/****************************
			*	   Member functions		*
			****************************/

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
				_alloc(alloc), _size(0), _capacity(n)
			{
				_array = _alloc.allocate(n);
				for (size_type i = 0; i < n; i++)
				{
					_alloc.construct(&_array[i], val);
					_size++;
				}
			}

			/*
			**	(3) range constructor
			**	Constructs a container with as many elements as the range [first,last),
			**	with each element constructed from its corresponding element in that range, in the same order.
			*/
			
			// TODO once we have an iterator
			// template <class InputIterator>
         	// vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());

			/*
			**	(4) copy constructor
			**	Constructs a container with a copy of each of the elements in x, in the same order.
			*/
			
			vector (const vector& x)
			{
				(void)x;
			}

			/* Assigns new contents to the container, replacing its current contents, and modifying its size accordingly. */
			vector& operator= (const vector& x)
			{
				// if (*this != x)			// TODO
				{
					this->_array = this->_alloc.allocate(x.capacity());
					this->_size = x.size();
					this->_capacity = x.capacity();
					for (size_type i = 0; i < x.size(); i++)
						this->_alloc.construct(&(this->_array[i]), x[i]);
				}
				return (*this);
			}
			 

			/*	Think of the _alloc object as an array of objects. Therefore we need to destroy each obj in the array,
			*	and then destroy the array itself. */
			~vector()
			{
				for (size_type i = 0; i < this->size(); i++)
				{
					_alloc.destroy(&_array[i]);
				}
				// deallocate space for five ints
				_alloc.deallocate(_array, this->capacity());
			}

			/****************************
			*	   	   Iterators		*
			****************************/



			/****************************
			*	   	   Capacity			*
			****************************/

			/* Returns the number of elements in the vector. */
			size_type size() const { return (this->_size); }
			
			/*	Returns the maximum number of elements that the vector can hold.
			*	This is the maximum potential size the container can reach due to known system or library implementation limitations,
			*	but the container is by no means guaranteed to be able to reach that size:
			*	it can still fail to allocate storage at any point before that size is reached. */
			// size_type max_size() const { return (this->_size); }

			/*	Resizes the container so that it contains n elements.
			*	If n < container size, the content is reduced to its first n elements, removing those beyond (and destroying them).
			*	If n > container size, the content is expanded by inserting at the end as many elements as needed to reach a size of n.
			*	If val is specified, the new elements are initialized as copies of val, otherwise, they are value-initialized.
			*	If n > container capacity, an automatic reallocation of the allocated storage space takes place. */
			void resize (size_type n, value_type val = value_type()) 
			{
				if (n < this->size())	// shrink size
				{
					size_type i = n;
					while ( i < this->size() )
					{
						_alloc.destroy(&_array[i]);
						i++;
					}
					this->_size = n;
				}
				else if (n > this->size() && n < this->capacity())	// add element but don't change capacity
				{
					for (size_type i = this->size(); i < n; i++)
					{
						_alloc.construct(&_array[i], val);
						this->_size++;
					}
				}
				else	// create an _array with twice the previous capacity
				{
					size_type new_capacity = this->capacity();
					while (new_capacity < n)		// double up until it fits 'n'
						new_capacity *= 2;
					this->reserve(new_capacity);
					for (size_type i = this->size(); i < n; i++)
						this->_alloc.construct(&this->_array[i], val);
				}
			}

			size_type capacity() const { return (this->_capacity); }

			/*	Returns whether the vector is empty (i.e. whether its size is 0). */
			bool empty() const { return (this->size() == 0); }

			/*	Requests that the vector capacity be at least enough to contain n elements.
				If n is greater than the current vector capacity, the function causes the container to reallocate its storage increasing its capacity to n (or greater).
				In all other cases, the function call does not cause a reallocation and the vector capacity is not affected.
				This function has no effect on the vector size and cannot alter its elements.	*/
			void reserve (size_type n)
			{
				if (n > this->capacity())
				{
					if (n > this->max_size())
					{
						throw std::length_error("size requested is greater than the maximum size (vector::max_size)\n");
					}
					copy = this;
					for (size_type i = 0; i < this->size(); i++)
						this->_alloc.destroy(&this->_array[i]);
					this->_alloc.deallocate(this->_array, this->capacity());

					this->_array = this->_alloc.allocate(n);
					this->_capacity = n;
					for (size_type i = 0; i < copy.size(); i++)
						this->_alloc.construct(&this->_array[i], copy[i]);
				}
			}


			/****************************
			*		Element access		*
			****************************/

			/*	Returns a reference to the element at position n in the vector container.
				Behavior is undefined when accessing out-of-range.	*/
			reference operator[] (size_type n) { return (_array[n]); }

			const_reference operator[] (size_type n) const { return (_array[n]); }
			
			/*	Returns a reference to the element at position n in the vector. 
				The function automatically checks whether n is within the bounds of valid elements in the vector,
				throwing an out_of_range exception if it is not (i.e., if n is greater than, or equal to, its size).
				This is in contrast with member operator[], that does not check against bounds. */
			reference at (size_type n)
			{
				if (n < 0 || n >= this->size())
					throw std::out_of_range("Accessing out of range element in vector\n");
				return (_array[n]);
			}

			const_reference at (size_type n) const
			{
				if (n < 0 || n >= this->size())
					throw std::out_of_range("Accessing out of range element in vector\n");
				return (_array[n]);
			}
			
			/*	Returns a reference to the first element in the vector.
				Unlike member vector::begin, which returns an iterator to this same element, this function returns a direct reference.
				Calling this function on an empty container causes undefined behavior. */
			reference front() { return (_array[0]); }
			const_reference front() const { return (_array[0]); }

			/*	Returns a reference to the last element in the vector.
				Unlike member vector::end, which returns an iterator just past this element, this function returns a direct reference.
				Calling this function on an empty container causes undefined behavior. */
			reference back()  { return (_array[(this->size() - 1)]); }
			const_reference back() const { return (_array[(this->size() - 1)]); }

			/****************************
			*		  Modifiers			*
			****************************/
			
			/****************************
			*		  Allocator			*
			****************************/

			/*	Returns a copy of the allocator object associated with the vector. */
			allocator_type get_allocator() const
			{

			}

		private:

			allocator_type  _alloc;						/*	allocator calss holding object	*/
			pointer			_array;						/*	Pointer on an array of T values	*/
			size_type		_size;						/*	current size of the obj 		*/
			size_type		_capacity;					/*	current capacity of the obj 	*/
	};

	// std::ostream &			operator<<( std::ostream & o, vector const & i );

}
#endif
