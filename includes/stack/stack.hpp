#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>
# include <string>
# include <memory>
# include "../vector/vector.hpp"
# include "../iterator/reverse_iterator.hpp"
# include "../iterator/iterator.hpp"
# include "../utils/utils.hpp"
# include <list>

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack {
		public:
			/****************************
			*	   Member types  		*
			****************************/

			/* Type of the elements allocated by the object (aliased as member type value_type). */
			typedef T 				value_type;
			typedef Container 		container_type;
			typedef size_t			size_type;

			/****************************
			*	   Member functions		*
			****************************/

			/* Constructs a stack container adaptor object. */
			explicit stack (const container_type& ctnr = container_type()) : c(ctnr) {}

			bool empty() const { return ( c.empty() ); }

			size_type size() const { return ( c.size() ); }
			
			/* Returns a reference to the top element in the stack. */
			value_type& top() { return (c.back()); }

			const value_type& top() const { return (c.back()); }

			void push (const value_type& val) { return (c.push_back(val)); }

			void pop() { return (c.pop_back()); }
		
		protected:
			container_type	c;
		
		private:
			// this part comes from stl_stack.h
			template<typename _T, typename C>
			friend bool operator==(const stack<_T, C>&, const stack<_T, C>&);

			template<typename _T, typename C>
			friend bool operator<(const stack<_T, C>&, const stack<_T, C>&);
	};

	/********************************
	* Non-member operators overloads*
	********************************/
	// stl_stack.h
	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {return (lhs.c == rhs.c);};
	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {return !(lhs == rhs);};
	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {return (lhs.c < rhs.c);};
	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {return !(rhs < lhs);};
	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {return (rhs < lhs); };
	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {return !(lhs < rhs);};

} // namespace ft

#endif