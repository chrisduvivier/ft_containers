# ft_containers
Recreate C++ containers (vector, map, stack) using C++98

## Steps I took
0. Copy paste the generic template from vector reference
`template < class T, class Alloc = allocator<T> > class vector; // generic template` (https://www.cplusplus.com/reference/vector/vector/)
We will essentially implement one by one the members attributes/functions etc. This of this as your list of TODOs.

1. What the heck is an allocator: 
It seems that all STL container uses Allocator class for memory allocation + generalize the process with different data types. Based on this, I took `allocator_type  _alloc;` as the main attribute to hold the data structure (beware that `allocator_type` is just an typedef of `Alloc`, which in turn, is the class `class Alloc = std::allocator<T>`). 
https://en.cppreference.com/w/cpp/named_req/Allocator


## Reference

- https://www.cplusplus.com/
- https://en.cppreference.com/w/ 