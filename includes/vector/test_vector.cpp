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
	std::cout << "===================TEST======================\n";

	{
		std::cout << "\n==== CONSTRUCTOR ====\n";
		ft::vector<int> empty_vector;    	// empty vector of ints
		ft::vector<int> five_vector(5, 5);	// size of 5 with values 5
		ft::vector<int> myvector (5);   // 10 zero-initialized ints
		// assign some values:
		for (unsigned i=0; i<myvector.size(); i++)
			myvector.at(i)=i;

		// std::cout << "myvector.front() is now " << myvector.front() << '\n';
		// std::cout << "myvector.back() is now " << myvector.back() << '\n';
		std::cout << "myvector contains:";
		for (unsigned i = 0; i < myvector.size(); i++)
			std::cout << ' ' << myvector.at(i);
		std::cout << '\n';

		std::cout << "\n==== IS_EMPTY ====\n";
		std::cout << empty_vector.empty() << "\n";
	}

	{
		std::cout << "\n==== ASSIGN CONSTRUCTOR ====\n";
		ft::vector<int> foo (3, 0);
		ft::vector<int> bar (5, 0);

		bar = foo;
		foo = ft::vector<int>();

		std::cout << "Size of foo: " << int(foo.size()) << '\n';
		std::cout << "Size of bar: " << int(bar.size()) << '\n';
	}

	{
		std::cout << "\n==== PUSH_BACK ====\n";
		ft::vector<int> myvector;

		unsigned int_arr[] = {14, 52, 5, 35, 64, 2, 1124, 4, 10, 110};
		for (unsigned i = 0; i < 10; i++)
			myvector.push_back (int_arr[i]);

		std::cout << "myvector contains:";
		for (unsigned i = 0; i < myvector.size(); i++)
			std::cout << ' ' << myvector.at(i);
		std::cout << '\n';
	}

	{
		std::cout << "\n==== POP_BACK ====\n";
		ft::vector<int> myvector;
		int sum (0);
		myvector.push_back (100);
		myvector.push_back (200);
		myvector.push_back (300);

		std::cout << myvector[0];
		std::cout << ' ' << myvector[1];
		std::cout << ' ' << myvector[2] << "\n";

		while (!myvector.empty())
		{
			sum+=myvector.back();
			myvector.pop_back();
		}
		std::cout << "The elements of myvector add up to " << sum << '\n';
	}

	{
		std::cout << "\n==== RESERVE ====\n";
		ft::vector<int>::size_type sz;

		ft::vector<int> foo;
		sz = foo.capacity();
		std::cout << "making foo grow:\n";
		for (int i=0; i<100; ++i) {
			foo.push_back(i);
			if (sz != foo.capacity()) {
				sz = foo.capacity();
				std::cout << "capacity changed: " << sz << '\n';
			}
		}

		ft::vector<int> bar;
		sz = bar.capacity();
		bar.reserve(100);   // this is the only difference with foo above
		std::cout << "making bar grow:\n";
		for (int i=0; i<100; ++i) {
			bar.push_back(i);
			if (sz!=bar.capacity()) {
				sz = bar.capacity();
				std::cout << "capacity changed: " << sz << '\n';
			}
		}
	}

	{
		std::cout << "\n==== RESIZE ====\n";
		// set some initial content:
		ft::vector<int> myvector (5);   // 10 zero-initialized ints
		// assign some values:
		for (unsigned i=0; i<myvector.size(); i++)
		{
			myvector.at(i)=i;
		}
		myvector.resize(5);
		myvector.resize(8,100);
		myvector.resize(12);

		std::cout << "myvector contains:";
		for (unsigned i=0; i < myvector.size(); i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';

		std::cout << "\n==== MAX_SIZE ====\n\n";
		std::cout << myvector.max_size() << "\n";
	}

	{	// clear test
		std::cout << "\n=== CLEAR ====\n";
		ft::vector<int> myvector;
		myvector.push_back (100);
		std::cout << myvector[0];
		myvector.push_back (200);
		std::cout << ' ' << myvector[1];
		myvector.push_back (300);
		std::cout << ' ' << myvector[2] << "\n";

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';

		myvector.clear();
		myvector.push_back (1101);
		myvector.push_back (2202);

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}

	{	// swap test
		std::cout << "\n==== SWAP ====\n";
		ft::vector<int> foo (3,100);   // three ints with a value of 100
		ft::vector<int> bar (5,200);   // five ints with a value of 200

		foo.swap(bar);

		std::cout << "foo contains:";
		for (unsigned i=0; i < foo.size(); i++)
			std::cout << ' ' << foo[i];
		std::cout << '\n';

		std::cout << "bar contains:";
		for (unsigned i=0; i < bar.size(); i++)
			std::cout << ' ' << bar[i];
		std::cout << '\n';
	}
    return (0);
}