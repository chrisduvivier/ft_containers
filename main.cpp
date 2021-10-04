#include <iostream>
#include <string>
#include <deque>
// #if 0 //CREATE A REAL STL EXAMPLE
// 	#include <map>
// 	#include <stack>
// 	#include <vector>
// 	namespace ft = std;
// #else
// 	// #include <map.hpp>
// 	// #include <stack.hpp>
#include "vector/vector.hpp"
// #endif

#include <stdlib.h>

int main(void)
{
	std::cout << "TEST\n";
	
	//=========== try to recreate something like this =========//
	std::allocator<int> myAllocator;		// empty allocator of ints
    int* arr = myAllocator.allocate(5);		// allocate space for five ints
	myAllocator.construct(arr, 100);
    arr[3] = 10;
    std::cout << arr[3] << std::endl;
    std::cout << arr[0] << std::endl;
    myAllocator.deallocate(arr, 5);			// deallocate space for five ints
	std::cout << "=======" << std::endl;
	//===================================//

	ft::vector<int> empty_vector;    	// empty vector of ints
	ft::vector<int> five_vector(5, 5);	// size of 5 with values 5

	std::cout << five_vector[0] << std::endl;
    return (0);
}
