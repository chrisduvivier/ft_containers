#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iostream>
# include <string>
# include <memory>

/*
	This is a base class template that can be used to derive iterator classes from it.
	It is not an iterator class and does not provide any of the functionality an iterator is expected to have.
	This base class only provides some member types, which in fact are not required to be present in any iterator type
	(iterator types have no specific member requirements), but they might be useful, since they define the members 
	needed for the default iterator_traits class template to generate 
	the appropriate instantiation automatically (and such instantiation is required to be valid for all iterator types).
*/
namespace ft
{
	template <
		class Category,               	// iterator::iterator_category
		class T,                        // iterator::value_type
		class Distance = ptrdiff_t,     // iterator::difference_type
		class Pointer = T*,             // iterator::pointer
		class Reference = T&            // iterator::reference
	>
	class iterator
	{
		public:

			/****************************
			*	   Member types  		*
			****************************/
			typedef				T									value_type;
			typedef				Distance							difference_type;
			typedef				Pointer								pointer;
			typedef				Reference							reference;
			typedef				Category							iterator_category;

			/****************************
			*	 iterator categories	*
			****************************/
			/* Empty class to identify the category of an iterator as a <name of category> iterator: */
			struct input_iterator_tag {};
			struct output_iterator_tag {};
			struct forward_iterator_tag {};
			struct bidirectional_iterator_tag {};
			struct random_access_iterator_tag {};

			/****************************
			*	 iterator Constructor	*
			****************************/
			iterator(pointer ptr) : m_ptr(ptr) {}

			/* Can be dereferenced as an rvalue (if in a dereferenceable state). */
			reference operator*() const { return *m_ptr; }
			pointer operator->()  { return m_ptr; }
		
			// Prefix increment
			iterator& operator++() { 
				m_ptr++;
				return *this;
			}

			// Postfix increment
			iterator& operator++(int) {
				iterator tmp = *this;
				++(*this);
				return (tmp);
			}

			// comparable with another iterator
			friend bool operator== (const iterator& a, const iterator& b) { return (a.m_ptr == b.m_ptr); }
			friend bool operator!= (const iterator& a, const iterator& b) { return (a.m_ptr != b.m_ptr); }

		private:
			pointer				m_ptr;

	};
}

#endif
