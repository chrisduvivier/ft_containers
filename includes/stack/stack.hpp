#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>
# include <string>
# include <memory>
# include <algorithm>
# include "../vector/vector.hpp"
# include "../iterator/reverse_iterator.hpp"
# include "../iterator/iterator.hpp"
# include "../utils/utils.hpp"

# define MAX_SIZE_64BIT 4611686018427387903

/*
    vector synopsis

namespace ft
{

template <class T, class Allocator = allocator<T> >
class vector
{
public:
	*****************************
	*	   Member types  		*
	*****************************

✅    typedef T                                        value_type; 
✅    typedef Allocator                                allocator_type;
✅    typedef typename allocator_type::reference       reference;
✅    typedef typename allocator_type::const_reference const_reference;
✅    typedef implementation-defined                   iterator;
✅    typedef implementation-defined                   const_iterator;
✅    typedef typename allocator_type::size_type       size_type;
✅    typedef typename allocator_type::difference_type difference_type;
✅    typedef typename allocator_type::pointer         pointer;
✅    typedef typename allocator_type::const_pointer   const_pointer;
✅    typedef std::reverse_iterator<iterator>          reverse_iterator;
✅    typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;


	*****************************
	*	   Member functions		*
	*****************************


✅    explicit vector(const allocator_type&);
✅    explicit vector(size_type n, const value_type& value, const allocator_type& = allocator_type());
✅    template <class InputIterator>
          vector(InputIterator first, InputIterator last, const allocator_type& = allocator_type());
✅    vector(const vector& x);
✅    ~vector();
✅    vector& operator=(const vector& x);

	*****************************
	*	   	   Iterators		*
	*****************************

✅    iterator               begin();
✅    const_iterator         begin()		const;
✅    iterator               end();
✅    const_iterator         end()		const;

    reverse_iterator       rbegin();
    const_reverse_iterator rbegin()		const;
    reverse_iterator       rend();
    const_reverse_iterator rend()		const;

	*****************************
	*	   	   Capacity			*
	*****************************
    
✅    size_type	size(		const;
✅    size_type	max_size()	const;
✅    void		resize (size_type n, value_type val = value_type());
✅    size_type	capacity()	const;
✅    bool		empty()		const;
✅    void		reserve(size_type n);

	*****************************
	*		Element access		*
	*****************************

✅    reference       operator[](size_type n);
✅    const_reference operator[](size_type n) const;
✅    reference       at(size_type n);
✅    const_reference at(size_type n) const;

✅    reference       front();
✅    const_reference front() const;
✅    reference       back();
✅    const_reference back() const;
	
	*****************************
	*		  Modifiers			*
	*****************************
    
✅    template <class InputIterator>
        void assign(InputIterator first, InputIterator last);
✅    void assign(size_type n, const value_type& u);
✅    void push_back(const value_type& x);
✅    void pop_back();

🏗️    iterator insert(const_iterator position, const value_type& x);
🏗️    template <class InputIterator>
        void insert (iterator position, size_type n, const value_type& val);
🏗️    iterator insert(iterator position, InputIterator first, InputIterator last);

    iterator erase(iterator position);
    iterator erase(iterator first, iterator last);

✅    void clear() ;

✅    void swap(vector& x);

	*****************************
	*		  Allocator			*
	*****************************

✅    allocator_type get_allocator() const ;
};

	*************************************
	*	Non-member function overloads	*
	*************************************


*/

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
			explicit stack (const container_type& ctnr = container_type()) : _ctnr(ctnr) {}

			bool empty() const { return ( _ctnr.empty() ); }

			size_type size() const { return ( _ctnr.size() ); }
			
			/* Returns a reference to the top element in the stack. */
			value_type& top() { return (_ctnr.back()); }

			const value_type& top() const { return (_ctnr.back()); }

			void push (const value_type& val) { return (_ctnr.push_back(val)); }

			void pop() { return (_ctnr.pop_back()); }


			// this part comes from stl_stack.h

			template<typename _T, typename C>
			friend bool operator==(const stack<_T, C>&, const stack<_T, C>&);

			template<typename _T, typename C>
			friend bool operator<(const stack<_T, C>&, const stack<_T, C>&);
		
		protected:
			container_type	_ctnr;
	};

	/********************************
	* Non-member operators overloads*
	********************************/
	// stl_stack.h
	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {return (lhs._ctnr == rhs._ctnr);};
	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {return !(lhs == rhs);};
	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {return (lhs._ctnr < rhs._ctnr);};
	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {return !(rhs < lhs);};
	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {return (rhs < lhs); };
	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {return !(lhs < rhs);};

} // namespace ft

#endif