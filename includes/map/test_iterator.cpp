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
	test_category_name("	REVERSE ITERATOR TEST	");
	{
		test_name("		CONSTRUCTOR		");
		ft::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		typedef ft::vector<int>::iterator iter_type;
		iter_type from (myvector.begin());
		iter_type until (myvector.end());
		ft::reverse_iterator<iter_type> rev_until (from);
		ft::reverse_iterator<iter_type> rev_from (until);
		std::cout << "myvector:";
		while (rev_from != rev_until)
			std::cout << ' ' << *rev_from++;
		std::cout << '\n';

		test_output("myvector: 9 8 7 6 5 4 3 2 1 0");
	}

	{
		test_name("		BASE		");
		ft::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		typedef ft::vector<int>::iterator iter_type;

		ft::reverse_iterator<iter_type> rev_end (myvector.begin());
		ft::reverse_iterator<iter_type> rev_begin (myvector.end());

		std::cout << "myvector:";
		for (iter_type it = rev_end.base(); it != rev_begin.base(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		test_output("myvector: 0 1 2 3 4 5 6 7 8 9");
	}

	{
		test_name("		OPERATOR=		");
		ft::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);
		ft::vector<int>::const_reverse_iterator from,until;
		// reverse_iterator assignments:
		from = myvector.rbegin();
		until = myvector.rend();
		std::cout << "reversed myvector:";
		while (from != until)
			std::cout << ' ' << *from++;
		std::cout << '\n';
		test_output("reversed myvector: 9 8 7 6 5 4 3 2 1 0");	
	}

	{
		test_name("		OPERATOR*()		");
		ft::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		typedef ft::vector<int>::iterator iter_type;
		iter_type from (myvector.begin());              										
		iter_type until (myvector.end());               								
		ft::reverse_iterator<iter_type> rev_until (from);								
		ft::reverse_iterator<iter_type> rev_from (until);
		std::cout << "myvector:";
		while (rev_from != rev_until)
			std::cout << ' ' << *rev_from++;
		std::cout << '\n';
		test_output("myvector: 9 8 7 6 5 4 3 2 1 0");
	}

	{
		test_name("		OPERATOR+		");
		ft::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);
		typedef ft::vector<int>::iterator iter_type;
		ft::reverse_iterator<iter_type> rev_it;
		rev_it = myvector.rbegin() + 3;
		std::cout << "The fourth element from the end is: " << *rev_it << '\n';
		test_output("The fourth element from the end is: 6");
	}

	{
		test_name("		OPERATOR++() & OPERATOR++(int)	");
		ft::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		typedef ft::vector<int>::iterator iter_type;	
		iter_type from (myvector.begin());                 
		iter_type until (myvector.end());                  		
		ft::reverse_iterator<iter_type> rev_until (from); 	
		ft::reverse_iterator<iter_type> rev_from (until);

		std::cout << "myvector:";
		while (rev_from != rev_until) {
			std::cout << ' ' << *rev_from;
			++rev_from;
		}
		std::cout << '\n';
		test_output("myvector: 9 8 7 6 5 4 3 2 1 0");
	}

	{
		test_name("		OPERATOR+=(difference_type n)	");
		ft::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);
		typedef ft::vector<int>::iterator iter_type;
		ft::reverse_iterator<iter_type> rev_iterator = myvector.rbegin();

		rev_iterator += 2;
		std::cout << "The third element from the end is: " << *rev_iterator << '\n';
		test_output("The third element from the end is: 7");
	}

	{
		test_name("		OPERATOR-		");
		ft::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);
		typedef ft::vector<int>::iterator iter_type;
		ft::reverse_iterator<iter_type> rev_iterator;
		rev_iterator = myvector.rend() - 3;
		std::cout << "myvector.rend()-3 points to: " << *rev_iterator << '\n';
		test_output("myvector.rend()-3 points to: 2");
	}

	{
		test_name("		OPERATOR--		");
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
		test_output("9 8 7 6 5 4 3 2 1 0\n0 1 2 3 4 5 6 7 8 9");
	}

	{
		test_name("		OPERATOR-=(difference_type n)	");
		ft::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);
		typedef ft::vector<int>::iterator iter_type;
		ft::reverse_iterator<iter_type> rev_iterator = myvector.rend();
		rev_iterator -= 4;
		std::cout << "rev_iterator now points to: " << *rev_iterator << '\n';
		test_output("rev_iterator now points to: 3");
	}

	{
		test_name("		OPERATOR->()	");

		// /* test with a vector */
		// ft::vector<std::pair<int, std::string> > numbers;
		// numbers.push_back (ft::make_pair(1,"one"));
		// numbers.push_back (ft::make_pair(2,"two"));
		// numbers.push_back (ft::make_pair(3,"three"));
		// typedef ft::vector<std::pair<int, std::string> >::iterator vector_iter;
		// ft::reverse_iterator<vector_iter> rev_end (numbers.begin());
		// ft::reverse_iterator<vector_iter> rev_iterator (numbers.end());
		// for ( ; rev_iterator != rev_end ; ++rev_iterator )
		// 	std::cout << rev_iterator->first << ' ' << rev_iterator->second << '\n';
		// test_output("3 three\n2 two\n1 one");
		// std::cout << "\n-----------\n";

		/* test with a map */
		ft::map<int,std::string> number;
		number.insert (ft::make_pair(1,"one"));
		number.insert (ft::make_pair(2,"two"));
		number.insert (ft::make_pair(3,"three"));
		typedef ft::map<int,std::string>::iterator map_iter;
		ft::reverse_iterator<map_iter> re_end (number.begin());
		ft::reverse_iterator<map_iter> re_iterator (number.end());
		for ( ; re_iterator != re_end ; ++re_iterator )
			std::cout << re_iterator->first << ' ' << re_iterator->second << '\n';
		test_output("3 three\n2 two\n1 one");
	}

	{
		test_name("		OPERATOR[]		");
		ft::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);
		typedef ft::vector<int>::iterator iter_type;
		ft::reverse_iterator<iter_type> rev_iterator = myvector.rbegin();
		std::cout << "The fourth element from the end is: " << rev_iterator[3] << '\n';
		test_output("The fourth element from the end is: 6");
	}
	
	{
		test_name("		RELATIONAL OPERATOR !=		");
		ft::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		typedef ft::vector<int>::iterator iter_type;
		iter_type from (myvector.begin());                  
		iter_type until (myvector.end());                  	
		ft::reverse_iterator<iter_type> rev_until (from);  
		ft::reverse_iterator<iter_type> rev_from (until);  
		std::cout << "myvector:";
		while (rev_from != rev_until)
			std::cout << ' ' << *rev_from++;
		std::cout << '\n';
		test_output("myvector: 9 8 7 6 5 4 3 2 1 0");
	}

	{
		test_name("	NON-MEMBER OPERATOR+	");
		ft::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);
		typedef ft::vector<int>::iterator iter_type;
		ft::reverse_iterator<iter_type> rev_it;
		rev_it = 3 + myvector.rbegin();
		std::cout << "The fourth element from the end is: " << *rev_it << '\n';
		test_output("The fourth element from the end is: 6");
	}

	{
		test_name("	NON-MEMBER OPERATOR-	");
		ft::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);
		ft::reverse_iterator<ft::vector<int>::iterator> from,until;
		from = myvector.rbegin();
		until = myvector.rend();
		std::cout << "myvector has " << (until-from) << " elements.\n";
		test_output("myvector has 10 elements.");
	}

	return (0);
}