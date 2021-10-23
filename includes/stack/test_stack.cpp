#include <iostream>
#include <string>
#include <deque>
#if 0 //CREATE A REAL STL EXAMPLE
	#include <vector>
	namespace ft = std;
#else
	#include "stack.hpp"
	#include <iterator>    // std::reverse_iterator
	#include <utility>     // std::make_pair
	#include <deque>       // std::deque
#endif

/* comment this line to diable assert */
// #define NDEBUG = false;

#ifndef NDEBUG
# define NDEBUG
# include <cassert>		// assert
#endif

int main(void)
{
	std::cout << "===================TEST STACK ======================\n";
	{
		std::deque<int> mydeque (3,100);          // deque with 3 elements
		ft::vector<int> myvector (2,200);        // vector with 2 elements

		ft::stack<int> first;                    // empty stack
		ft::stack<int> second (mydeque);         // stack initialized to copy of deque

		ft::stack<int,ft::vector<int> > third;  // empty stack using vector
		ft::stack<int,ft::vector<int> > fourth (myvector);

		std::cout << "size of first: " << first.size() << '\n';
		std::cout << "size of second: " << second.size() << '\n';
		std::cout << "size of third: " << third.size() << '\n';
		std::cout << "size of fourth: " << fourth.size() << '\n';
		/* expected: myvector: 9 8 7 6 5 4 3 2 1 0 */
	}
	{
		std::cout << "============== TEST EMPTY ================\n";
		// ft::stack<int> mystack;
		// int sum (0);
		// for (int i=1;i<=10;i++) mystack.push(i);
		// while (!mystack.empty())
		// {
		// 	sum += mystack.top();
		// 	mystack.pop();
		// }
		// std::cout << "total: " << sum << '\n';
	}
}