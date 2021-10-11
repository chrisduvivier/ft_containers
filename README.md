# ft_containers
Recreate C++ containers (vector, map, stack) using C++98 (which means, many stuff are deprecated/deleted by now in the current C++)
## Steps I took
0. Copy paste the generic template from vector reference
`template < class T, class Alloc = allocator<T> > class vector; // generic template` (https://www.cplusplus.com/reference/vector/vector/)
We will essentially implement one by one the members attributes/functions etc. This of this as your list of TODOs.

1. What the heck is an allocator: 
In a nutshell: using `new`, `delete` is very handy because it automates the construction process of the memory. With Allocator, the 2 process are seperated. You have to allocate memory (using `allocate`), and then construct it (using `construct`).

All STL container use Allocator class for memory allocation. The allocator will be the object holding the data for our STLs: `allocator_type  _alloc;` the main attribute to hold the data structure (beware that `allocator_type` is just an typedef of `Alloc`, which in turn, is the class `class Alloc = std::allocator<T>`). 

Some example here: https://www.geeksforgeeks.org/stdallocator-in-cpp-with-examples/
To check functions/return types etc: https://en.cppreference.com/w/cpp/named_req/Allocator

2. cry

3. Implement all functions except iterator:
All function templates are given, so prety straitforward. Just be careful with the order in which you implement the functions, because some of them depend on other member functions. (e.g. resize)

## Reference

- https://www.cplusplus.com/
- https://en.cppreference.com/w/ 
- The bible of custom iterator: "Writing a custom iterator in modern C++" [https://internalpointers.com/post/writing-custom-iterators-modern-cpp]