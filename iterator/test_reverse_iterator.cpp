#include <iostream>
#include <string>
#include <deque>
#if 0 //CREATE A REAL STL EXAMPLE
	#include <vector>
	namespace ft = std;
#else
	#include "../vector/vector.hpp"
	
	#include <vector>
	#include <iterator>     // std::reverse_iterator
	#include <utility>      // std::make_pair
	#include <map>          // std::maps
#endif

/* comment this line to diable assert */
// #define NDEBUG = false;

#ifndef NDEBUG
# define NDEBUG
# include <cassert>		// assert
#endif

int main(void)
{
	std::cout << "===================TEST REVERSE ITER======================\n";
	{
		/* https://www.cplusplus.com/reference/iterator/reverse_iterator/reverse_iterator/ */
		std::cout << "=====[ TEST CONSTRUCTOR ]=====\n";
		ft::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		typedef ft::vector<int>::iterator iter_type;
																// ? 0 1 2 3 4 5 6 7 8 9 ?
		iter_type from (myvector.begin());                      //   ^
																//         ------>
		iter_type until (myvector.end());                       //                       ^
																//
		ft::reverse_iterator<iter_type> rev_until (from);       // ^
																//         <------
		ft::reverse_iterator<iter_type> rev_from (until);       //                     ^

		std::cout << "myvector:";
		while (rev_from != rev_until)
			std::cout << ' ' << *rev_from++;
		std::cout << '\n';

		/* expected: myvector: 9 8 7 6 5 4 3 2 1 0 */
	}

	{
		std::cout << "=====[ BASE() ]=====\n";
		// reverse_iterator::base example
		ft::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		typedef ft::vector<int>::iterator iter_type;

		ft::reverse_iterator<iter_type> rev_end (myvector.begin());
		ft::reverse_iterator<iter_type> rev_begin (myvector.end());

		std::cout << "myvector:";
		for (iter_type it = rev_end.base(); it != rev_begin.base(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
		/* expected: myvector: 0 1 2 3 4 5 6 7 8 9 */
	}
	
	{
		std::cout << "=====[ * operator ]=====\n";
		ft::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		typedef ft::vector<int>::iterator iter_type;
																// ? 9 8 7 6 5 4 3 2 1 0 ?
		iter_type from (myvector.begin());                     	//   ^
																//         ------>
		iter_type until (myvector.end());                      	//                       ^
																//
		ft::reverse_iterator<iter_type> rev_until (from);     	// ^
																//         <------
		ft::reverse_iterator<iter_type> rev_from (until);     	//                     ^

		std::cout << "myvector:";
		while (rev_from != rev_until)
			std::cout << ' ' << *rev_from++;
		std::cout << '\n';
		/* expected: myvector: 9 8 7 6 5 4 3 2 1 0 */
	}

	{
		std::cout << "=====[ + and - operator ]=====\n";
		ft::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9
		typedef ft::vector<int>::iterator iter_type;
		
																// ? 0 1 2 3 4 5 6 7 8 9 ?
		iter_type from (myvector.begin());                      //   ^
		std::cout << "from: " << *from << "\n";                 //
																//         ------>
		iter_type until (myvector.end());                       //                       ^
		std::cout << "until: " << *(until - 1) << "\n";         //
																//
		ft::reverse_iterator<iter_type> rev_until (from);       // ^
																//         <------
		ft::reverse_iterator<iter_type> rev_from (until);       //                     ^

		std::cout << "The 1st element from the end is: " << *rev_from << '\n';
		rev_from = rev_from + 3;
		std::cout << "The fourth element from the end is: " << *rev_from << '\n';
		/* exoxpected: 6 */

		rev_until = rev_until - 3;
  		std::cout << "rev_until now points to: " << *rev_until << '\n';
		/* expected: myvector.rend()-3 points to: 2 */
	}

	{
		std::cout << "=====[ ++ operator ]=====\n";
		ft::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);
		typedef ft::vector<int>::iterator iter_type;
																// ? 0 1 2 3 4 5 6 7 8 9 ?
		iter_type from (myvector.begin());                      //   ^
																//         ------>
		iter_type until (myvector.end());                       //                       ^
																//
		ft::reverse_iterator<iter_type> rev_until (from);       // ^
																//         <------
		ft::reverse_iterator<iter_type> rev_from (until);       //                     ^

		std::cout << "myvector:";
		while (rev_from != rev_until) {
			std::cout << ' ' << *rev_from;
			++rev_from;
		}
		std::cout << '\n';
		/* expected: myvector: 9 8 7 6 5 4 3 2 1 0 */
	}

	{
		std::cout << "=====[ -- operator ]=====\n";
		ft::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		typedef ft::vector<int>::iterator iter_type;

		ft::reverse_iterator<iter_type> rev_begin (myvector.end());
		ft::reverse_iterator<iter_type> rev_end (myvector.begin());

		ft::reverse_iterator<iter_type> rev_iterator = rev_begin;
		while ( rev_iterator != rev_end )
			std::cout << *rev_iterator++ << ' ';
		std::cout << '\n';

		while ( rev_iterator != rev_begin )
			std::cout << *(--rev_iterator) << ' ';
		std::cout << '\n';
		/* expected: myvector:	9 8 7 6 5 4 3 2 1 0 
								0 1 2 3 4 5 6 7 8 9 */
	}

	{
		std::cout << "=====[ += operator ]=====\n";
		ft::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

		typedef ft::vector<int>::iterator iter_type;

		ft::reverse_iterator<iter_type> rev_iterator (myvector.end());
		rev_iterator += 2;
		std::cout << "The third element from the end is: " << *rev_iterator << '\n';
		/* expected: myvector:	The third element from the end is: 7 */

		ft::reverse_iterator<iter_type> rev_iterator_two (myvector.begin());
		rev_iterator_two -= 4;
		std::cout << "rev_iterator_2 now points to: " << *rev_iterator_two << '\n';
		/* expected: myvector:	The third element from the end is: 3 */

		rev_iterator -= 2;
		std::cout << "=====[ [n] operator ]=====\n";
		std::cout << "The fourth element from the end is: " << rev_iterator[3] << '\n';
		/* expected: myvector:	The third element from the end is: 6 */
	}

	{
		/*  SET UP STD VERSION */
		std::cout << "=====[ relational operator ]=====\n";
		std::vector<int> std_myvector;
  		for (int i=0; i<10; i++) std_myvector.push_back(i);
  		typedef std::vector<int>::iterator std_iter_type;
		                                                					// ? 9 8 7 6 5 4 3 2 1 0 ?
		std_iter_type std_from (std_myvector.begin());                  	//   ^
																			//         ------>
		std_iter_type std_until (std_myvector.end());                   	//                       ^
																			//
		std::reverse_iterator<std_iter_type> std_rev_until (std_from);		// ^
																			//         <------
		std::reverse_iterator<std_iter_type> std_rev_from (std_until);		//                     ^

		/*  SET UP MINE FT VERSION */
		ft::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9
		typedef ft::vector<int>::iterator iter_type;
																// ? 9 8 7 6 5 4 3 2 1 0 ?
		iter_type from (myvector.begin());                     	//   ^
																//         ------>
		iter_type until (myvector.end());                   	//                       ^
																//
		ft::reverse_iterator<iter_type> rev_until (from);     	// ^
																//         <------
		ft::reverse_iterator<iter_type> rev_from (until);     	//                     ^

		/* > */
		std::cout << "(std_rev_from > std_rev_until)=	" << (std_rev_from > std_rev_until) << std::endl;
		std::cout << "(rev_from > rev_until)=		" << (rev_from > rev_until) << std::endl;
		assert((std_rev_from > std_rev_until) == (rev_from > rev_until));
		/* < */
		std::cout << "(std_rev_from < std_rev_until)=	" << (std_rev_from < std_rev_until) << std::endl;
		std::cout << "(rev_from < rev_until)=		" << (rev_from < rev_until) << std::endl;
		assert((std_rev_from < std_rev_until) == (rev_from < rev_until));
		/* == */
		std::cout << "(std_rev_from == std_rev_from)=	" << (std_rev_from == std_rev_from) << std::endl;
		std::cout << "(rev_from == rev_from)=		" << (rev_from == rev_from) << std::endl;
		assert((std_rev_from == std_rev_from) == (rev_from == rev_from));
		/* != */
		std::cout << "(std_rev_from != std_rev_from)=	" << (std_rev_from != std_rev_from) << std::endl;
		std::cout << "(rev_from != rev_from)=		" << (rev_from != rev_from) << std::endl;
		assert((std_rev_from != std_rev_from) == (rev_from != rev_from));
		/* >= */
		std::cout << "(std_rev_from >= std_rev_until)=" << (std_rev_from >= std_rev_until) << std::endl;
		std::cout << "(rev_from >= rev_until)=	" << (rev_from >= rev_until) << std::endl;
		assert((std_rev_from >= std_rev_until) == (rev_from >= rev_until));
		/* <= */
		std::cout << "(std_rev_from <= std_rev_until)=" << (std_rev_from <= std_rev_until) << std::endl;
		std::cout << "(rev_from <= rev_until)=	" << (rev_from <= rev_until) << std::endl;
		assert((std_rev_from <= std_rev_until) == (rev_from <= rev_until));
	}

	{
		// std::cout << "\n==== CONST RBEGIN/REND OPERATIONS ====\n\n";
		// ft::vector<int> myvector;
		// for (int i=0; i<10; i++) myvector.push_back(i);

		// typedef ft::vector<int>::iterator iter_type;
		// 														// ? 0 1 2 3 4 5 6 7 8 9 ?
		// iter_type from (myvector.begin());                      //   ^
		// 														//         ------>
		// iter_type until (myvector.end());                       //                       ^
		// 														//
		// ft::reverse_iterator<iter_type> rev_until (from);       // ^
		// 														//         <------
		// ft::reverse_iterator<iter_type> rev_from (until);       //                     ^

		// std::cout << "myvector:";
		// while (rev_from != rev_until)
		// 	std::cout << ' ' << *rev_from++;
		// std::cout << '\n';
	}


	{
		/* no need for -> for now with vector. */
		// std::map<int,std::string> numbers;
		// numbers.insert (std::make_pair(1,"one"));
		// numbers.insert (std::make_pair(2,"two"));
		// numbers.insert (std::make_pair(3,"three"));

		// typedef std::map<int,std::string>::iterator map_iter;

		// ft::reverse_iterator<map_iter> rev_end (numbers.begin());

		// ft::reverse_iterator<map_iter> rev_iterator (numbers.end());

		// for ( ; rev_iterator != rev_end ; ++rev_iterator )
		// 	std::cout << rev_iterator->first << ' ' << rev_iterator->second << '\n';
	}
}