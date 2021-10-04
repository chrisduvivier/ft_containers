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

	{
		ft::vector<int> myvector (5);   // 10 zero-initialized ints
		// assign some values:
		for (unsigned i=0; i<myvector.size(); i++)
		{
			myvector.at(i)=i;
		}

		// std::cout << "myvector.front() is now " << myvector.front() << '\n';
		// std::cout << "myvector.back() is now " << myvector.back() << '\n';
		std::cout << "myvector contains:";
		for (unsigned i = 0; i < myvector.size(); i++)
			std::cout << ' ' << myvector.at(i);
		std::cout << '\n';
	}

	{
		ft::vector<int> foo (3, 0);
		ft::vector<int> bar (5, 0);

		bar = foo;
		foo = ft::vector<int>();

		std::cout << "Size of foo: " << int(foo.size()) << '\n';
		std::cout << "Size of bar: " << int(bar.size()) << '\n';
	}

	// {
	// 	// // set some initial content:
	// 	ft::vector<int> myvector (5);   // 10 zero-initialized ints
	// 	// assign some values:
	// 	for (unsigned i=0; i<myvector.size(); i++)
	// 	{
	// 		myvector.at(i)=i;
	// 	}
	// 	// myvector.resize(5);
	// 	// myvector.resize(8,100);
	// 	// myvector.resize(12);

	// 	std::cout << "myvector contains:";
	// 	for (unsigned i=0; i < myvector.size(); i++)
	// 		std::cout << ' ' << myvector[i];
	// 	std::cout << '\n';
	// }
    return (0);
}
