#include "../iterator/reverse_iterator.hpp"
#include <iostream>
#include <map>
#include <vector>
#include "map.hpp"
#include "../vector/vector.hpp"

#include "map.hpp"

#define RST  "\x1B[0m"
#define KGRN  "\x1B[32m"
#define KMAG  "\x1B[35m"

void	set_color(void)	{ std::cout << KGRN; }
void	set_cat_color(void)	{ std::cout << KMAG; }
void	reset_color(void)	{ std::cout << RST; }

void	test_category_name(std::string name)
{
	set_cat_color();
	std::cout << "---------- " << name << ": ----------\n";
	reset_color();
}

void	test_name(std::string name)
{
	set_color();
	std::cout << "---------- " << name << ": ----------\n";
	reset_color();
}

void	test_output(std::string output)
{
	std::cout << std::endl << "Expected output:" << std::endl << output << std::endl;
}

template<typename T>
void print_helper(std::string description, T value)
{
	std::cout << description << "	:	" << value << std::endl;
}

int main()
{
// 	test_category_name("	REVERSE ITERATOR TEST	");
// 	{
// 		test_name("		CONSTRUCTOR		");
// 		ft::vector<int> myvector;
// 		for (int i=0; i<10; i++) myvector.push_back(i);

// 		typedef ft::vector<int>::iterator iter_type;
// 		iter_type from (myvector.begin());
// 		iter_type until (myvector.end());
// 		ft::reverse_iterator<iter_type> rev_until (from);
// 		ft::reverse_iterator<iter_type> rev_from (until);
// 		std::cout << "myvector:";
// 		while (rev_from != rev_until)
// 			std::cout << ' ' << *rev_from++;
// 		std::cout << '\n';

// 		test_output("myvector: 9 8 7 6 5 4 3 2 1 0");
// 	}

// 	{
// 		test_name("		BASE		");
// 		ft::vector<int> myvector;
// 		for (int i=0; i<10; i++) myvector.push_back(i);

// 		typedef ft::vector<int>::iterator iter_type;

// 		ft::reverse_iterator<iter_type> rev_end (myvector.begin());
// 		ft::reverse_iterator<iter_type> rev_begin (myvector.end());

// 		std::cout << "myvector:";
// 		for (iter_type it = rev_end.base(); it != rev_begin.base(); ++it)
// 			std::cout << ' ' << *it;
// 		std::cout << '\n';

// 		test_output("myvector: 0 1 2 3 4 5 6 7 8 9");
// 	}

// 	{
// 		test_name("		OPERATOR=		");
// 		ft::vector<int> myvector;
// 		for (int i=0; i<10; i++) myvector.push_back(i);
// 		ft::vector<int>::const_reverse_iterator from,until;
// 		// reverse_iterator assignments:
// 		from = myvector.rbegin();
// 		until = myvector.rend();
// 		std::cout << "reversed myvector:";
// 		while (from != until)
// 			std::cout << ' ' << *from++;
// 		std::cout << '\n';
// 		test_output("reversed myvector: 9 8 7 6 5 4 3 2 1 0");	
// 	}

// 	{
// 		test_name("		OPERATOR*()		");
// 		ft::vector<int> myvector;
// 		for (int i=0; i<10; i++) myvector.push_back(i);

// 		typedef ft::vector<int>::iterator iter_type;
// 		iter_type from (myvector.begin());              										
// 		iter_type until (myvector.end());               								
// 		ft::reverse_iterator<iter_type> rev_until (from);								
// 		ft::reverse_iterator<iter_type> rev_from (until);
// 		std::cout << "myvector:";
// 		while (rev_from != rev_until)
// 			std::cout << ' ' << *rev_from++;
// 		std::cout << '\n';
// 		test_output("myvector: 9 8 7 6 5 4 3 2 1 0");
// 	}

// 	{
// 		test_name("		OPERATOR+		");
// 		ft::vector<int> myvector;
// 		for (int i=0; i<10; i++) myvector.push_back(i);
// 		typedef ft::vector<int>::iterator iter_type;
// 		ft::reverse_iterator<iter_type> rev_it;
// 		rev_it = myvector.rbegin() + 3;
// 		std::cout << "The fourth element from the end is: " << *rev_it << '\n';
// 		test_output("The fourth element from the end is: 6");
// 	}

// 	{
// 		test_name("		OPERATOR++() & OPERATOR++(int)	");
// 		ft::vector<int> myvector;
// 		for (int i=0; i<10; i++) myvector.push_back(i);

// 		typedef ft::vector<int>::iterator iter_type;	
// 		iter_type from (myvector.begin());                 
// 		iter_type until (myvector.end());                  		
// 		ft::reverse_iterator<iter_type> rev_until (from); 	
// 		ft::reverse_iterator<iter_type> rev_from (until);

// 		std::cout << "myvector:";
// 		while (rev_from != rev_until) {
// 			std::cout << ' ' << *rev_from;
// 			++rev_from;
// 		}
// 		std::cout << '\n';
// 		test_output("myvector: 9 8 7 6 5 4 3 2 1 0");
// 	}

// 	{
// 		test_name("		OPERATOR+=(difference_type n)	");
// 		ft::vector<int> myvector;
// 		for (int i=0; i<10; i++) myvector.push_back(i);
// 		typedef ft::vector<int>::iterator iter_type;
// 		ft::reverse_iterator<iter_type> rev_iterator = myvector.rbegin();

// 		rev_iterator += 2;
// 		std::cout << "The third element from the end is: " << *rev_iterator << '\n';
// 		test_output("The third element from the end is: 7");
// 	}

// 	{
// 		test_name("		OPERATOR-		");
// 		ft::vector<int> myvector;
// 		for (int i=0; i<10; i++) myvector.push_back(i);
// 		typedef ft::vector<int>::iterator iter_type;
// 		ft::reverse_iterator<iter_type> rev_iterator;
// 		rev_iterator = myvector.rend() - 3;
// 		std::cout << "myvector.rend()-3 points to: " << *rev_iterator << '\n';
// 		test_output("myvector.rend()-3 points to: 2");
// 	}

// 	{
// 		test_name("		OPERATOR--		");
// 		ft::vector<int> myvector;
// 		for (int i=0; i<10; i++) myvector.push_back(i);
// 		typedef ft::vector<int>::iterator iter_type;
// 		ft::reverse_iterator<iter_type> rev_begin (myvector.end());
// 		ft::reverse_iterator<iter_type> rev_end (myvector.begin());
// 		ft::reverse_iterator<iter_type> rev_iterator = rev_begin;
// 		while ( rev_iterator != rev_end )
// 			std::cout << *rev_iterator++ << ' ';
// 		std::cout << '\n';
// 		while ( rev_iterator != rev_begin )
// 			std::cout << *(--rev_iterator) << ' ';
// 		std::cout << '\n';
// 		test_output("9 8 7 6 5 4 3 2 1 0\n0 1 2 3 4 5 6 7 8 9");
// 	}

// 	{
// 		test_name("		OPERATOR-=(difference_type n)	");
// 		ft::vector<int> myvector;
// 		for (int i=0; i<10; i++) myvector.push_back(i);
// 		typedef ft::vector<int>::iterator iter_type;
// 		ft::reverse_iterator<iter_type> rev_iterator = myvector.rend();
// 		rev_iterator -= 4;
// 		std::cout << "rev_iterator now points to: " << *rev_iterator << '\n';
// 		test_output("rev_iterator now points to: 3");
// 	}

// 	{
// 		test_name("		OPERATOR->()	");

// 		// /* test with a vector */
// 		// ft::vector<std::pair<int, std::string> > numbers;
// 		// numbers.push_back (ft::make_pair(1,"one"));
// 		// numbers.push_back (ft::make_pair(2,"two"));
// 		// numbers.push_back (ft::make_pair(3,"three"));
// 		// typedef ft::vector<std::pair<int, std::string> >::iterator vector_iter;
// 		// ft::reverse_iterator<vector_iter> rev_end (numbers.begin());
// 		// ft::reverse_iterator<vector_iter> rev_iterator (numbers.end());
// 		// for ( ; rev_iterator != rev_end ; ++rev_iterator )
// 		// 	std::cout << rev_iterator->first << ' ' << rev_iterator->second << '\n';
// 		// test_output("3 three\n2 two\n1 one");
// 		// std::cout << "\n-----------\n";

// 		/* test with a map */
// 		ft::map<int,std::string> number;
// 		number.insert (ft::make_pair(1,"one"));
// 		number.insert (ft::make_pair(2,"two"));
// 		number.insert (ft::make_pair(3,"three"));
// 		typedef ft::map<int,std::string>::iterator map_iter;
// 		ft::reverse_iterator<map_iter> re_end (number.begin());
// 		ft::reverse_iterator<map_iter> re_iterator (number.end());
// 		for ( ; re_iterator != re_end ; ++re_iterator )
// 			std::cout << re_iterator->first << ' ' << re_iterator->second << '\n';
// 		test_output("3 three\n2 two\n1 one");
// 	}

// 	{
// 		test_name("		OPERATOR[]		");
// 		ft::vector<int> myvector;
// 		for (int i=0; i<10; i++) myvector.push_back(i);
// 		typedef ft::vector<int>::iterator iter_type;
// 		ft::reverse_iterator<iter_type> rev_iterator = myvector.rbegin();
// 		std::cout << "The fourth element from the end is: " << rev_iterator[3] << '\n';
// 		test_output("The fourth element from the end is: 6");
// 	}
	
// 	{
// 		test_name("		RELATIONAL OPERATOR !=		");
// 		ft::vector<int> myvector;
// 		for (int i=0; i<10; i++) myvector.push_back(i);

// 		typedef ft::vector<int>::iterator iter_type;
// 		iter_type from (myvector.begin());                  
// 		iter_type until (myvector.end());                  	
// 		ft::reverse_iterator<iter_type> rev_until (from);  
// 		ft::reverse_iterator<iter_type> rev_from (until);  
// 		std::cout << "myvector:";
// 		while (rev_from != rev_until)
// 			std::cout << ' ' << *rev_from++;
// 		std::cout << '\n';
// 		test_output("myvector: 9 8 7 6 5 4 3 2 1 0");
// 	}

// 	{
// 		test_name("	NON-MEMBER OPERATOR+	");
// 		ft::vector<int> myvector;
// 		for (int i=0; i<10; i++) myvector.push_back(i);
// 		typedef ft::vector<int>::iterator iter_type;
// 		ft::reverse_iterator<iter_type> rev_it;
// 		rev_it = 3 + myvector.rbegin();
// 		std::cout << "The fourth element from the end is: " << *rev_it << '\n';
// 		test_output("The fourth element from the end is: 6");
// 	}

// 	{
// 		test_name("	NON-MEMBER OPERATOR-	");
// 		ft::vector<int> myvector;
// 		for (int i=0; i<10; i++) myvector.push_back(i);
// 		ft::reverse_iterator<ft::vector<int>::iterator> from,until;
// 		from = myvector.rbegin();
// 		until = myvector.rend();
// 		std::cout << "myvector has " << (until-from) << " elements.\n";
// 		test_output("myvector has 10 elements.");

// 		ft::vector<int> v;
// 		v.push_back(1);
// 		v.push_back(2);
// 		v.push_back(3);
// 		ft::vector<int>::const_iterator c_it1 = v.begin();
// 		ft::vector<int>::const_iterator c_it2 = v.begin() + 1;
// 		std::cout << std::boolalpha << "c_it1 = v.begin() & c_it2 = v.begin() + 1\n\n";
// 		std::cout << "(c_it1 == c_it2): " << (c_it1 == c_it2) << std::endl;
// 		std::cout << "(c_it1 >= c_it2): " << (c_it1 >= c_it2) << std::endl;
// 		std::cout << "(c_it1 <= c_it2): " << (c_it1 <= c_it2) << std::endl;
// 		std::cout << "(c_it1 < c_it2): " << (c_it1 < c_it2) << std::endl;
// 		std::cout << "(c_it1 > c_it2): " << (c_it1 > c_it2) << std::endl;
// 		std::cout << "(c_it1 - c_it2): " << (c_it1 - c_it2) << std::endl;

// 		std::vector<int> ve;
// 		ve.push_back(1);
// 		ve.push_back(2);
// 		ve.push_back(3);
// 		std::vector<int>::const_iterator c_it1e = ve.begin();
// 		std::vector<int>::const_iterator c_it2e = ve.begin() + 1;
// 		std::cout << std::boolalpha << "c_it1 = v.begin() & c_it2 = v.begin() + 1\n\n";
// 		std::cout << "(c_it1 == c_it2): " << (c_it1e == c_it2e) << std::endl;
// 		std::cout << "(c_it1 >= c_it2): " << (c_it1e >= c_it2e) << std::endl;
// 		std::cout << "(c_it1 <= c_it2): " << (c_it1e <= c_it2e) << std::endl;
// 		std::cout << "(c_it1 < c_it2): " << (c_it1e < c_it2e) << std::endl;
// 		std::cout << "(c_it1 > c_it2): " << (c_it1e > c_it2e) << std::endl;
// 		std::cout << "(c_it1 - c_it2): " << (c_it1e - c_it2e) << std::endl;
// 	}

// {
// 	test_name("FT");
// 	ft::vector<int> v;
// 	v.push_back(1);
// 	v.push_back(2);
// 	v.push_back(3);
	
// 	ft::vector<int>::reverse_iterator r_it = v.rbegin();
// 	ft::vector<int>::const_reverse_iterator c_r_it = v.rbegin() + 1;
// 	std::cout << std::boolalpha << "(c_r_it == r_it): " << (c_r_it == r_it) << std::endl;
// 	std::cout << "(c_r_it >= r_it): " << (c_r_it >= r_it) << std::endl;
// 	std::cout << "(c_r_it <= r_it): " << (c_r_it <= r_it) << std::endl;
// 	std::cout << "(c_r_it < r_it): " << (c_r_it < r_it) << std::endl;
// 	std::cout << "(c_r_it > r_it): " << (c_r_it > r_it) << std::endl;
// 	std::cout << "(c_r_it - r_it): " << (c_r_it - r_it) << std::endl;

// 	std::cout << "(r_it == c_r_it): " << (r_it == c_r_it) << std::endl;
// 	std::cout << "(r_it >= c_r_it): " << (r_it >= c_r_it) << std::endl;
// 	std::cout << "(r_it <= c_r_it): " << (r_it <= c_r_it) << std::endl;
// 	std::cout << "(r_it < c_r_it): " << (r_it < c_r_it) << std::endl;
// 	std::cout << "(r_it > c_r_it): " << (r_it > c_r_it) << std::endl;
// 	std::cout << "(r_it - c_r_it): " << (r_it - c_r_it) << std::endl;

// 	ft::vector<int>::const_reverse_iterator c_r_it2 = v.rbegin() + 2;
// 	std::cout << "(c_r_it == c_r_it2): " << (c_r_it == c_r_it2) << std::endl;
// 	std::cout << "(c_r_it >= c_r_it2): " << (c_r_it >= c_r_it2) << std::endl;
// 	std::cout << "(c_r_it <= c_r_it2): " << (c_r_it <= c_r_it2) << std::endl;
// 	std::cout << "(c_r_it < c_r_it2): " << (c_r_it < c_r_it2) << std::endl;
// 	std::cout << "(c_r_it > c_r_it2): " << (c_r_it > c_r_it2) << std::endl;
// 	std::cout << "(c_r_it - c_r_it2): " << (c_r_it - c_r_it2) << std::endl;

// 	std::cout << "(c_r_it2 == c_r_it): " << (c_r_it2 == c_r_it) << std::endl;
// 	std::cout << "(c_r_it2 >= c_r_it): " << (c_r_it2 >= c_r_it) << std::endl;
// 	std::cout << "(c_r_it2 <= c_r_it): " << (c_r_it2 <= c_r_it) << std::endl;
// 	std::cout << "(c_r_it2 < c_r_it): " << (c_r_it2 < c_r_it) << std::endl;
// 	std::cout << "(c_r_it2 > c_r_it): " << (c_r_it2 > c_r_it) << std::endl;
// 	std::cout << "(c_r_it2 - c_r_it): " << (c_r_it2 - c_r_it) << std::endl;
// }

// {
// 	test_name("STD");
// 	std::vector<int> v;
// 	v.push_back(1);
// 	v.push_back(2);
// 	v.push_back(3);
	
// 	std::vector<int>::reverse_iterator r_it = v.rbegin();
// 	std::vector<int>::const_reverse_iterator c_r_it = v.rbegin() + 1;
// 	std::cout << std::boolalpha << "(c_r_it == r_it): " << (c_r_it == r_it) << std::endl;
// 	std::cout << "(c_r_it >= r_it): " << (c_r_it >= r_it) << std::endl;
// 	std::cout << "(c_r_it <= r_it): " << (c_r_it <= r_it) << std::endl;
// 	std::cout << "(c_r_it < r_it): " << (c_r_it < r_it) << std::endl;
// 	std::cout << "(c_r_it > r_it): " << (c_r_it > r_it) << std::endl;
// 	std::cout << "(c_r_it - r_it): " << (c_r_it - r_it) << std::endl;

// 	std::cout << "(r_it == c_r_it): " << (r_it == c_r_it) << std::endl;
// 	std::cout << "(r_it >= c_r_it): " << (r_it >= c_r_it) << std::endl;
// 	std::cout << "(r_it <= c_r_it): " << (r_it <= c_r_it) << std::endl;
// 	std::cout << "(r_it < c_r_it): " << (r_it < c_r_it) << std::endl;
// 	std::cout << "(r_it > c_r_it): " << (r_it > c_r_it) << std::endl;
// 	std::cout << "(r_it - c_r_it): " << (r_it - c_r_it) << std::endl;

// 	std::vector<int>::const_reverse_iterator c_r_it2 = v.rbegin() + 2;
// 	std::cout << "(c_r_it == c_r_it2): " << (c_r_it == c_r_it2) << std::endl;
// 	std::cout << "(c_r_it >= c_r_it2): " << (c_r_it >= c_r_it2) << std::endl;
// 	std::cout << "(c_r_it <= c_r_it2): " << (c_r_it <= c_r_it2) << std::endl;
// 	std::cout << "(c_r_it < c_r_it2): " << (c_r_it < c_r_it2) << std::endl;
// 	std::cout << "(c_r_it > c_r_it2): " << (c_r_it > c_r_it2) << std::endl;
// 	std::cout << "(c_r_it - c_r_it2): " << (c_r_it - c_r_it2) << std::endl;

// 	std::cout << "(c_r_it2 == c_r_it): " << (c_r_it2 == c_r_it) << std::endl;
// 	std::cout << "(c_r_it2 >= c_r_it): " << (c_r_it2 >= c_r_it) << std::endl;
// 	std::cout << "(c_r_it2 <= c_r_it): " << (c_r_it2 <= c_r_it) << std::endl;
// 	std::cout << "(c_r_it2 < c_r_it): " << (c_r_it2 < c_r_it) << std::endl;
// 	std::cout << "(c_r_it2 > c_r_it): " << (c_r_it2 > c_r_it) << std::endl;
// 	std::cout << "(c_r_it2 - c_r_it): " << (c_r_it2 - c_r_it) << std::endl;
// }

{
		test_name("FT ");
		
		ft::vector<int> v;
		v.push_back(1);
		v.push_back(3);
		v.push_back(6);

		ft::vector<int>::iterator it = v.begin();
		// 1, 3, 6
		//^
		//1
		// 1, 1, 3, 6
		v.insert(it, v.begin(), v.begin() + 1);

		for (it = v.begin(); it != v.end(); it++)
			std::cout << *it << ", ";
		std::cout << std::endl;

		it = v.begin() + 3;
		v.insert(it, v.begin() + 1, v.end());
		// 1, 1, 3, 6
		//         ^
		//         1, 3, 6
		// 1, 1, 3, 1, 3, 6, 6

		for (it = v.begin(); it != v.end(); it++)
			std::cout << *it << ", ";
		std::cout << std::endl;

		it = v.end();
		v.insert(it, v.begin() + 1, v.end() - 1);
		// 1, 1, 3, 1, 3, 6, 6
		//                    ^
		// 					  1, 3, 1, 3, 6
		// 1, 1, 3, 1, 3, 6, 6, 1, 3, 1, 3, 6

		for (it = v.begin(); it != v.end(); it++)
			std::cout << *it << ", ";
		std::cout << std::endl;
	}

{
		test_name("STD");
		
		std::vector<int> v;
		v.push_back(1);
		v.push_back(3);
		v.push_back(6);

		std::vector<int>::iterator it = v.begin();
		// 1, 3, 6
		//^
		//1
		// 1, 1, 3, 6
		v.insert(it, v.begin(), v.begin() + 1);

		for (it = v.begin(); it != v.end(); it++)
			std::cout << *it << ", ";
		std::cout << std::endl;

		it = v.begin() + 3;
		v.insert(it, v.begin() + 1, v.end());
		// 1, 1, 3, 6
		//         ^
		//         1, 3, 6
		// 1, 1, 3, 1, 3, 6, 6

		for (it = v.begin(); it != v.end(); it++)
			std::cout << *it << ", ";
		std::cout << std::endl;

		it = v.end();
		v.insert(it, v.begin() + 1, v.end() - 1);
		// 1, 1, 3, 1, 3, 6, 6
		//                    ^
		// 					  1, 3, 1, 3, 6
		// 1, 1, 3, 1, 3, 6, 6, 1, 3, 1, 3, 6

		for (it = v.begin(); it != v.end(); it++)
			std::cout << *it << ", ";
		std::cout << std::endl;
	}

	// {
	// 	test_name("Cplusplus insert");
	// 	ft::vector<int> myvector (3,100);
	// 	ft::vector<int>::iterator it;

	// 	it = myvector.begin();
	// 	it = myvector.insert ( it , 200 );
	// 	myvector.insert (it,2,300);

	// 	// "it" no longer valid, get a new one:
	// 	it = myvector.begin();

	// 	ft::vector<int> anothervector (2,400);
	// 	myvector.insert (it+2,anothervector.begin(),anothervector.end());

	// 	int myarray [] = { 501,502,503 };
	// 	myvector.insert (myvector.begin(), myarray, myarray+3);

	// 	std::cout << "myvector contains:";
	// 	for (it=myvector.begin(); it<myvector.end(); it++)
	// 		std::cout << ' ' << *it;
	// 	std::cout << '\n';
	// 	test_output("myvector contains: 501 502 503 300 300 400 400 200 100 100 100");

	// }

	// {
	// 	test_name("FT INSERT (1)");
	// 	ft::vector<int> myvector (3,100);
	// 	ft::vector<int>::iterator it;

	// 	it = myvector.begin();
	// 	it = myvector.insert ( it , 200 );
	// 	it = myvector.insert (it, 1);
	// 	it = myvector.insert (it, 3);
	// 	it = myvector.insert (it, 2);

	// 	std::cout << "myvector contains:";
	// 	for (it=myvector.begin(); it<myvector.end(); it++)
	// 		std::cout << ' ' << *it;
	// 	std::cout << '\n';
	// }
	// {
	// 	test_name("STD INSERT (1)");
	// 	std::vector<int> myvector (3,100);
	// 	std::vector<int>::iterator it;

	// 	it = myvector.begin();
	// 	it = myvector.insert ( it , 200 );
	// 	it = myvector.insert(it, 1);
	// 	it = myvector.insert(it, 3);
	// 	it = myvector.insert(it, 2);

	// 	std::cout << "myvector contains:";
	// 	for (it=myvector.begin(); it<myvector.end(); it++)
	// 		std::cout << ' ' << *it;
	// 	std::cout << '\n';
	// }

	// {
	// 	test_name("FT INSERT (2)");
	// 	ft::vector<int> myvector (3,100);
	// 	ft::vector<int>::iterator it;

	// 	it = myvector.begin();
	// 	myvector.insert ( it , 2,  200 );
	// 	it = myvector.begin();
	// 	myvector.insert (it, 3, 1);
	// 	it = myvector.begin();
	// 	myvector.insert (it, 4, 3);
	// 	it = myvector.begin();
	// 	myvector.insert (it, 5, 2);

	// 	std::cout << "myvector contains:";
	// 	for (it=myvector.begin(); it<myvector.end(); it++)
	// 		std::cout << ' ' << *it;
	// 	std::cout << '\n';
	// }
	// {
	// 	test_name("STD INSERT (2)");
	// 	std::vector<int> myvector (3,100);
	// 	std::vector<int>::iterator it;

	// 	it = myvector.begin();
	// 	myvector.insert ( it , 2,  200 );
	// 	it = myvector.begin();
	// 	myvector.insert (it, 3, 1);
	// 	it = myvector.begin();
	// 	myvector.insert (it, 4, 3);
	// 	it = myvector.begin();
	// 	myvector.insert (it, 5, 2);

	// 	std::cout << "myvector contains:";
	// 	for (it=myvector.begin(); it<myvector.end(); it++)
	// 		std::cout << ' ' << *it;
	// 	std::cout << '\n';
	// }

	// {
	// 	test_name("FT INSERT (3)");
	// 	ft::vector<int> myvector (3,100);
	// 	ft::vector<int>::iterator it;

	// 	it = myvector.begin();

	// 	ft::vector<int> anothervector (2,400);
	// 	myvector.insert (it+2,anothervector.begin(),anothervector.end());

	// 	int myarray [] = { 501,502,503 };
	// 	myvector.insert (myvector.begin(), myarray, myarray+3);

	// 	std::cout << "myvector contains:";
	// 	for (it=myvector.begin(); it<myvector.end(); it++)
	// 		std::cout << ' ' << *it;
	// 	std::cout << '\n';

	// }
	// {
	// 	test_name("STD INSERT (3)");
	// 	std::vector<int> myvector (3,100);
	// 	std::vector<int>::iterator it;

	// 	it = myvector.begin();

	// 	std::vector<int> anothervector (2,400);
	// 	myvector.insert (it+2,anothervector.begin(),anothervector.end());

	// 	int myarray [] = { 501,502,503 };
	// 	myvector.insert (myvector.begin(), myarray, myarray+3);

	// 	std::cout << "myvector contains:";
	// 	for (it=myvector.begin(); it<myvector.end(); it++)
	// 		std::cout << ' ' << *it;
	// 	std::cout << '\n';
	// }

	return (0);
}