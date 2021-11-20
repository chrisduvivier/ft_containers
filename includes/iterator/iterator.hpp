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
		class Distance = std::ptrdiff_t,     // iterator::difference_type
		class Pointer = T*,             // iterator::pointer
		class Reference = T&            // iterator::reference
	>
	class iterator
	{
		public:
			/****************************
			*	   Member types  		*
			****************************/
			typedef			T								value_type;
			typedef			Distance						difference_type;
			typedef			Pointer							pointer;
			typedef			Reference						reference;
			typedef			Category						iterator_category;
	};

	/****************************
	*	 iterator categories	*
	****************************/
	/* Empty class to identify the category of an iterator as a <name of category> iterator: */
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};
	
	/*
	* std::iterator_traits is the type trait class that provides uniform interface to the properties of LegacyIterator types.
	* This makes it possible to implement algorithms only in terms of iterators.
	* @param: Iter = the iterator type to retrieve properties for.
	*/
	template< class Iter >
	struct iterator_traits
	{
		typedef	typename	Iter::difference_type				difference_type;
		typedef	typename	Iter::value_type					value_type;
		typedef	typename	Iter::pointer						pointer;
		typedef	typename	Iter::reference						reference;
		typedef	typename	Iter::iterator_category				iterator_category;
	};

	template< class T >
	struct iterator_traits<T*> 
	{
		typedef			std::ptrdiff_t						difference_type;
		typedef			T									value_type;
		typedef			T*									pointer;
		typedef			T&									reference;
		typedef			std::random_access_iterator_tag		iterator_category;
	};

	template< class T >
	struct iterator_traits<const T*>
	{
		typedef			std::ptrdiff_t						difference_type;
		typedef			T									value_type;
		typedef			const T*							pointer;
		typedef			const T&							reference;
		typedef			std::random_access_iterator_tag		iterator_category;
	};
}

#endif
