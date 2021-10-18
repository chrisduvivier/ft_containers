#include <iostream>
#include <string>
#include <deque>
#if 0 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	// #include <map.hpp>
	// #include <stack.hpp>
	#include "vector/vector.hpp"
#endif

#include <stdlib.h>

int main(void)
{
	std::cout << "===================TEST REVERSE ITER======================\n";
    ft::vector<int> v;
    unsigned int_arr[] = {14, 52, 5, 35, 64, 2, 1124, 4, 10, 110};
    for (unsigned i = 0; i < 10; i++)
        v.push_back (int_arr[i]);
 
    using RevIt = ft::reverse_iterator<ft::vector<int>::iterator>;
 
    ft::vector<int>::iterator it = v.begin() + v.size();
    RevIt r_it{it};
 
    std::cout << "*it == " << *it << '\n'
              << "*r_it == " << *r_it << '\n'
              << "*r_it.base() == " << *r_it.base() << '\n'
              << "*(r_it.base()-1) == " << *(r_it.base() - 1) << '\n';
 
    RevIt r_end{v.begin()};
    RevIt r_begin{v.end()};
 
    for (int it = r_end.base(); it != r_begin.base(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';
 
    for (int it = r_begin; it != r_end; ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';
}