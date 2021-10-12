#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>
# include <memory>

# include "../iterator/random_access_iterator.hpp"

# define MAX_SIZE_64BIT 4611686018427387903
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
			typedef				T											value_type;
			typedef				Alloc										allocator_type;
			typedef typename	allocator_type::reference					reference;
			typedef typename	allocator_type::const_reference				const_reference;
			typedef typename	allocator_type::pointer						pointer;
			typedef typename	allocator_type::const_pointer				const_pointer;

			typedef			ft::random_access_iterator<value_type>			iterator;
			typedef			ft::random_access_iterator<const value_type>	const_iterator;

			// reverse_iterator
			// const_reverse_iterator
			// difference_type

			typedef typename	allocator_type::size_type					size_type;

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
					this->clear();
					this->_alloc.deallocate(this->_array, this->capacity());

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
				this->clear();
				_alloc.deallocate(_array, this->capacity());
			}

			/****************************
			*	   	   Iterators		*
			****************************/

			/*	Returns an iterator pointing to the first element in the vector.
			*	returns a random access iterator pointing to it.
			*	If the container is empty, the returned iterator value shall not be dereferenced. */
			iterator begin() { return (iterator( &_array[0] )); }
			const_iterator begin() const { return (iterator(&_array[0] )); }
			iterator end() { return (iterator( &_array[0 + this->size()] )); }
			const_iterator end() const { return (iterator(&_array[0 + this->size()] )); }

			/****************************
			*	   	   Capacity			*
			****************************/

			/* Returns the number of elements in the vector. */
			size_type size() const { return (this->_size); }
			
			/*	Returns the maximum number of elements that the vector can hold.
			*	This is the maximum potential size the container can reach due to known system or library implementation limitations,
			*	but the container is by no means guaranteed to be able to reach that size:
			*	it can still fail to allocate storage at any point before that size is reached.
			*	4611686018427387903 if built as 64-bit target  */

			size_type max_size() const { return (MAX_SIZE_64BIT); }

			/*	Resizes the container so that it contains n elements.
			*	If n < container size, the content is reduced to its first n elements, removing those beyond (and destroying them).
			*	If n > container size, the content is expanded by inserting at the end as many elements as needed to reach a size of n.
			*	If val is specified, the new elements are initialized as copies of val, otherwise, they are value-initialized.
			*	If n > container capacity, an automatic reallocation of the allocated storage space takes place. */
			void resize (size_type n, value_type val = value_type()) 
			{
				if (n < _size)	// shrink size
				{
					while ( n < _size )
						pop_back();
				}
				else if (n > _size && n < _capacity)	// add element but don't change capacity
				{
					for (size_type i = _size; i < n; i++)
						push_back(val);
				}
				else	// create an _array with twice the previous capacity
				{
					size_type new_capacity = _capacity;
					while (new_capacity < n)		// double up until it fits 'n'
						new_capacity *= 2;
					this->reserve(new_capacity);
					for (size_type i = _size; i < n; i++)
						_alloc.construct(&_array[i], val);
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
				if (n > this->max_size())
					throw std::length_error("size requested is greater than the maximum size (vector::max_size)\n");
				if (n > this->capacity())
					reallocateVec( n );
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
			
			/* Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly */
			/* range (1) */
			// template <class InputIterator>
			// void assign (InputIterator first, InputIterator last) 
			// {

			// }

			// /* fill (2)	*/
			// void assign (size_type n, const value_type& val);

			/*	Adds a new element at the end of the vector, after its current last element.
				The content of val is copied (or moved) to the new element. This effectively increases the container size by one,
				which causes an automatic reallocation of the allocated storage space if -and only if-
				the new vector size surpasses the current vector capacity. */
			void push_back (const value_type& val)
			{
				if (_size + 1 > _capacity)
					(_capacity == 0) ? reallocateVec(1) : reallocateVec( _capacity * 2 );
				_alloc.construct(&_array[_size++], val);
			}

			/* Removes the last element in the vector, effectively reducing the container size by one. */
			void pop_back()
			{
				if (_size > 0)
				{
					_alloc.destroy(&_array[_size - 1]);
					_size--;
				}
			}
			
			/*	Removes all elements from the vector (which are destroyed), leaving the container with a size of 0.
				A reallocation is not guaranteed to happen, and the vector capacity is not guaranteed to change due to calling this function.
				A typical alternative that forces a reallocation is to use swap: */
			void clear()
			{
				while (_size > 0)
					pop_back();
			}

			void swap (vector& x)
			{
				std::swap(this->_alloc, x._alloc);
				std::swap(this->_array, x._array);
				std::swap(this->_size, x._size);
				std::swap(this->_capacity, x._capacity);
			}

			/****************************
			*		  Allocator			*
			****************************/

			/*	Returns a copy of the allocator object associated with the vector. */
			allocator_type get_allocator() const { return (this->_alloc); } 

		private:

			allocator_type  _alloc;						/*	allocator calss holding object	*/
			pointer			_array;						/*	Pointer on an array of T values	*/
			size_type		_size;						/*	current size of the obj 		*/
			size_type		_capacity;					/*	current capacity of the obj 	*/
		

			/*	Reallocate a vector with the newCapacity, and copy previous contents to the new one. 
				Previous allocator is destroyed calling the destrcutor */
			void	reallocateVec( size_type newCapacity )
			{
				pointer tmp = _alloc.allocate(newCapacity);
				size_type size = _size;
				for (size_type i = 0; i < size; i++)
					_alloc.construct(&tmp[i], _array[i]);
				this->~vector();
				this->_array = tmp;
				this->_size = size;
				this->_capacity = newCapacity;
			}
	};

	/********************************
	* Non-member function overloads	*
	********************************/

	// template <class T, class Alloc>
	// void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
	// {
	// 	swap(x->_alloc, y->_alloc);
	// 	swap(x->_array, y->_array);
	// 	swap(x->_size, y->_size);
	// 	swap(x->_capacity, y->_capacity);
	// }

	// std::ostream &			operator<<( std::ostream & o, vector const & i );
	
}
#endif
