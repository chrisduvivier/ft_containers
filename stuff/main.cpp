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
	#include <vector>
	#define RESET "\e[0m"
	#define GREEN "\e[92m" 
	#define BLUE "\e[94m"
	#define MAGENTA "\e[35m"
	#define BOLD "\e[1m"
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
		for (int i=0; i<30; ++i) {
			foo.push_back(i);				// resizing is done in push_back.
			if (sz != foo.capacity()) {		// previous cap is now unequal to current cap.
				sz = foo.capacity();
				std::cout << "foo: ";
				for (unsigned i=0; i < foo.size(); i++)
					std::cout << foo[i] << ' ';
				std::cout << std::endl;
				std::cout << "capacity changed: " << foo.capacity() << '\n';
				std::cout << " - - - - - - - - - - " << '\n';
			}
		}
		std::cout << "foo: " << '\n';
		for (unsigned i=0; i < foo.size(); i++)
			std::cout << foo[i] << ' ';
		std::cout << std::endl;

		ft::vector<int> bar;
		sz = bar.capacity();
		bar.reserve(30);   // this is the only difference with foo above
		std::cout << "making bar grow:\n";
		for (int i=0; i<30; ++i) {
			bar.push_back(i);
			if (sz!=bar.capacity()) {
				sz = bar.capacity();
				std::cout << "capacity changed: " << sz << '\n';
			}
		}
		std::cout << "bar: " << '\n';
		for (unsigned i=0; i < bar.size(); i++)
			std::cout << bar[i] << ' ';
		std::cout << std::endl;
	}

	{
		std::cout << "\n==== RESIZE ====\n";
		ft::vector<int> myvector;

		// set some initial content:
		for (int i=1;i<10;i++) myvector.push_back(i);

		myvector.resize(5);
		myvector.resize(8,100);
		myvector.resize(12);

		std::cout << "myvector contains:";
		for (size_t i=0;i < myvector.size(); i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';

		/* expected: myvector contains: 1 2 3 4 5 100 100 100 0 0 0 0 */

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

	{	// begin iterator test
		std::cout << "\n==== BEGIN/END ====\n";
		ft::vector<int> myvector;
		for (int i=1; i<=5; i++) myvector.push_back(i);

		std::cout << "myvector contains:";
		for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}

	{
		std::cout << "\n==== ITERATOR OPERATIONS ====\n\n";
		ft::vector<int> foo;
		for (int i = 0; i < 10; i++)
			foo.push_back(i);
		std::cout << "size " << foo.size() << std::endl;
		std::cout << "capacity " << foo.capacity() << std::endl;
		std::cout << "end " << *(--foo.end()) << std::endl;
		
		std::cout << "Vector foo countains: ";
		for (unsigned i=0; i < foo.size(); i++)
			std::cout << foo[i] << ' ';
		std::cout << std::endl << "iterator it_begin = foo.begin()"<< std::endl;
		std::cout << 			  "iterator it_end = foo.end()"<< std::endl << std::endl;
		ft::vector<int>::iterator it_begin;
		ft::vector<int>::iterator it_end;
		it_begin = foo.begin();
		it_end = foo.end();
		std::cout << "size " << foo.size() << std::endl;
		//std::cout << "array" << foo.size() << std::endl;
		
		std::cout << "--(*it_end) = " << *(--it_end) << std::endl; // 9
		std::cout << "front " << foo.front()<< std::endl;;
		std::cout <<  "back " << foo.back()<< std::endl;;
		std::cout << "\n--increment/decrement--\n\n";

		std::cout << "*it_begin = " << *it_begin << std::endl; // 0 
		std::cout << "*(++it_begin) = " << *(++it_begin) << std::endl; // 1
		std::cout << "*(it_begin++) = " << *(it_begin++) << std::endl; // 1 
		std::cout << "*it_begin = " << *it_begin << std::endl; //2

		std::cout << "foo.end() points to the memory that is adjacent to the last element of the vector\nWe have to decrement it to access the last element" << std::endl;
		std::cout << "*(--it_end) = " << *(--it_end) << std::endl; // 9 
		std::cout << "*(it_end--) = " << *(it_end--) << std::endl; // 9
		std::cout << "*it_end = " << *it_end << std::endl; // 8

		std::cout << "\n--comparisons--\n\n";

		std::cout << std::boolalpha; // outputs booleans as 'true' or 'false' instead of 1's or 0's
		std::cout << "it_begin > it_end:	" << (it_begin > it_end) << std::endl;
		std::cout << "it_begin < it_end:	" << (it_begin < it_end) << std::endl;
		std::cout << "it_begin <= it_end:	" << (it_begin <= it_end) << std::endl;
		std::cout << "it_begin >= it_end:	" << (it_begin >= it_end) << std::endl;
		std::cout << "it_begin == it_end:	" << (it_begin == it_end) << std::endl;
		std::cout << "it_end = it_begin" <<  std::endl;
		
		it_end = it_begin;
		
		std::cout << "it_begin > it_end:	" << (it_begin > it_end) << std::endl;
		std::cout << "it_begin < it_end:	" << (it_begin < it_end) << std::endl;
		std::cout << "it_begin <= it_end:	" << (it_begin <= it_end) << std::endl;
		std::cout << "it_begin >= it_end:	" << (it_begin >= it_end) << std::endl;
		std::cout << "it_begin == it_end:	" << (it_begin == it_end) << std::endl << std::endl;
		
		std::cout << "back to normal : ";
		std::cout << "it_end = foo.end(), it_begin = foo.begin() " <<  std::endl;
		it_end = foo.end();
		it_begin = foo.begin();
		std::cout << "\n--accessors--\n\n";

		for (size_t i = 0; i < foo.size(); i++)
			std::cout << it_begin[i] << " ";
		std::cout << std::endl;
		for (size_t i = 1; i <= foo.size(); i++)
			std::cout << it_end[-i] << " ";

		std::cout << "\n--range construct--\n\n";
		ft::vector<int> bar(it_begin, it_end);

		std::cout << "Vector bar size: " << bar.size() << std::endl;
		std::cout << "Vector bar capacity: " << bar.capacity() << std::endl;
		bar.push_back(50);
			std::cout << "Vector bar size: " << bar.size() << std::endl;
		std::cout << "Vector bar capacity: " << bar.capacity() << std::endl;
		std::cout << "Vector bar countains: ";

		for (unsigned i=0; i < bar.size(); i++)
			std::cout << bar[i] << ' ';
		std::cout << "\n--copy construct--\n\n";

		ft::vector<int> test(bar);
		std::cout << "Vector test size: " << test.size() << std::endl;
		std::cout << "Vector test capacity: " << test.capacity() << std::endl;
		std::cout << "Vector test countains: ";

		for (unsigned i=0; i < test.size(); i++)
			std::cout << test[i] << ' ';
		std::cout << "\n--assign--\n\n";
		ft::vector<int> test2(2,2);
		test2.assign(it_begin, it_end);
		for (unsigned i=0; i < test2.size(); i++)
			std::cout << test2[i] << ' ';
		std::cout << std::endl;
		
		test2.insert(test2.begin(),9, 9);
		for (unsigned i=0; i < test2.size(); i++)
			std::cout << test2[i] << ' ';
		std::cout << std::endl;
		
		test2.erase(test2.begin(), test2.begin() + 5);
		for (unsigned i=0; i < test2.size(); i++)
			std::cout << test2[i] << ' ';
			std::cout << std::endl;
	}
	{
		std::cout << "\n==== RBEGIN/REND OPERATIONS ====\n\n";

		ft::vector<int> myvector (5);  // 5 default-constructed ints

		int i=0;

		ft::vector<int>::reverse_iterator rit = myvector.rbegin();
		for (; rit!= myvector.rend(); ++rit)
		*rit = ++i;

		std::cout << "myvector contains:";
		for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
		std::cout << '\n';




	}
	{
		std::cout << BLUE << "\n>Resize" << RESET << std::endl;
		ft::vector<int> v1;
		std::vector<int> v2;

		std::cout << "v1 ft: \n";
		std::cout << "v1.size(): " << v1.size() << " v1.capacity(): " << v1.capacity() << "\n";

		std::cout << "v2 std: \n";
		std::cout << "v2.size(): " << v2.size() << " v2.capacity(): " << v2.capacity() << "\n";

		v1.resize(10, 8);
		v2.resize(10, 8);

		std::cout << "v1.size(): " << v1.size() << " v1.capacity(): " << v1.capacity() << "\n";
		for (unsigned i=0; i < v1.size(); i++)
			std::cout << v1[i] << ' ';
			std::cout << std::endl;
		std::cout << "v2.size(): " << v2.size() << " v2.capacity(): " << v2.capacity() << "\n";
		for (unsigned i=0; i < v2.size(); i++)
			std::cout << v2[i] << ' ';
			std::cout << std::endl;

		
	}
    return (0);
}
