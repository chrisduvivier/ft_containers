#include <iostream>
#include "map.hpp"

#include <map>

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

template<typename T>
void print_helper(std::string description, T value)
{
	std::cout << description << "	:	" << value << std::endl;
}

int main()
{
	std::cout << "---------- TEST MAP ----------\n";
	{
		test_category_name("	MODIFIERS FUNCTION	");
		ft::map<std::string, int> 	tmp_map;
		ft::pair<std::string, int>	tmp_pair("42", 19);

		test_name("insert");
		std::cout << "insert pair" << "\n";
		tmp_map.insert(tmp_pair);

		test_name("erase");
		std::cout << "erase's result: " << tmp_map.erase("42") << "\n";
		std::cout << "erase's result: " << tmp_map.erase("42") << "\n";
	}

	{
		test_name("insert single parameter");
		ft::map<char,int> tmp_map;

		// first insert function version (single parameter):
		tmp_map.insert ( ft::pair<char,int>('a', 100) );
		tmp_map.insert ( ft::pair<char,int>('z', 200) );

		ft::pair<ft::map<char,int>::iterator, bool> ret;
		ret = tmp_map.insert ( ft::pair<char,int>('z', 500) );
		if (ret.second == false) {
			std::cout << "element 'z' already existed";
			std::cout << " with a value of " << ret.first->second << '\n';
		}
	}

	// test_category_name("	OBSERVATIONS	");
	// {	
	// 	test_name("key_compare");
	// 	ft::map<char,int> mymap;
	// 	ft::map<char,int>::key_compare mycomp = mymap.key_comp();
	// 	mymap['a']=100;
	// 	mymap['b']=200;
	// 	mymap['c']=300;
	// 	std::cout << "mymap contains:\n";
	// 	char highest = mymap.rbegin()->first;     // key value of last element

	// 	ft::map<char,int>::iterator it = mymap.begin();
	// 	do {
	// 		std::cout << it->first << " => " << it->second << '\n';
	// 	} while ( mycomp((*it++).first, highest) );
	// 	std::cout << '\n';

	// 	/* expected:
	// 		mymap contains:
	// 		a => 100
	// 		b => 200
	// 		c => 300
	// 	*/
	// }

	// {
	// 	test_name("value_compare");
	// 	ft::map<char,int> mymap;
	// 	mymap['x']=1001;
	// 	mymap['y']=2002;
	// 	mymap['z']=3003;
	// 	std::cout << "mymap contains:\n";
	// 	ft::pair<char,int> highest = *mymap.rbegin();          // last element
	// 	ft::map<char,int>::iterator it = mymap.begin();
	// 	do {
	// 		std::cout << it->first << " => " << it->second << '\n';
	// 	} while ( mymap.value_comp()(*it++, highest) );

	// 	/* expected:
	// 		mymap contains:
	// 		x => 1001
	// 		y => 2002
	// 		z => 3003
	// 	*/
	// }

	test_category_name("	OPERATIONS FUNCTION	");
	{
		ft::map<char,int> tmp_map;
		tmp_map['b'] = 100;
		tmp_map['a'] = 200;
		tmp_map['d'] = 400;
		
		test_name("find");
		ft::map<char,int>::iterator it = tmp_map.find('b');
		std::cout << it->first << " => " << it->second << '\n';

		test_name("count");
		for (char c = 'a'; c <= 'e'; c++)
		{
			std::cout << c;
			if (tmp_map.count(c) > 0)
				std::cout << " is an element of map.\n";
			else 
				std::cout << " is not an element of map.\n";
		}
	}
	
	{
		test_name("lower_bound/upper_bond");
		ft::map<char,int> tmp_map;
		ft::map<char,int>::iterator itlow,itup;

		tmp_map['a']=20;
		tmp_map['b']=40;
		tmp_map['c']=60;
		tmp_map['d']=80;
		tmp_map['e']=100;

		itlow = tmp_map.lower_bound ('b');  // itlow points to b
		itup = tmp_map.upper_bound ('d');   // itup points to e (not d!)

		std::cout << "itlow: " << itlow->first << " => " << itlow->second << '\n';
		std::cout << "itup: " << itup->first << " => " << itup->second << '\n';

		tmp_map.erase(itlow, itup);        // erases [itlow,itup)

		// print content:
		for (ft::map<char,int>::iterator it = tmp_map.begin(); it != tmp_map.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
		// expected: "a => 20; e => 100"
	}

	{
		test_name("equal_range");
		ft::map<char,int> mymap;

		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;

		ft::pair<ft::map<char,int>::iterator, ft::map<char,int>::iterator> ret;
		ret = mymap.equal_range('b');

		std::cout << "lower bound points to: ";
		std::cout << ret.first->first << " => " << ret.first->second << '\n';

		std::cout << "upper bound points to: ";
		std::cout << ret.second->first << " => " << ret.second->second << '\n';
		/* expected: 
			lower bound points to: 'b' => 20
			upper bound points to: 'c' => 30
		*/
	}

	{
		test_name("	Element access	");

		ft::map<char,int> tmp_map;
		test_name("[] operator");
		tmp_map['b'] = 100;
		tmp_map['a'] = 200;
		tmp_map['c'] = 300;
		std::cout << "size: " << tmp_map.size() << std::endl;
	}

	test_category_name("	ITERATORS ");
	{
		ft::map<char,int> tmp_map;

		tmp_map['b'] = 100;
		tmp_map['a'] = 200;
		tmp_map['c'] = 300;

		ft::map<char,int>::iterator it_empty;
		ft::map<char,int>::iterator it(tmp_map.begin());
		std::cout << it.getNode()->data.first << "\n";
		ft::map<char,int>::iterator it2(tmp_map.end());
		std::cout << it2.getNode()->data.first << "\n";

	}
	
	{
		test_name("	iter begin ");
		ft::map<char,int> tmp_map;
		tmp_map['b'] = 100;
		tmp_map['a'] = 200;
		tmp_map['c'] = 300;

		// show content:
		for (ft::map<char,int>::iterator it = tmp_map.begin(); it != tmp_map.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

	}

	{
		test_name("	iterator STD -- ");
		std::map<char,int> tmp_map;
		tmp_map['b'] = 100;
		tmp_map['a'] = 200;
		tmp_map['c'] = 300;

		// show content:
		std::map<char,int>::iterator it = tmp_map.end();

		for (; it != tmp_map.begin(); --it)
			std::cout << it->first << " => " << it->second << '\n';
	}

	{
		test_name("	iterator FT -- ");
		ft::map<char,int> tmp_map;
		tmp_map['b'] = 100;
		tmp_map['a'] = 200;
		tmp_map['c'] = 300;

		// show content:
		ft::map<char,int>::iterator it = tmp_map.end();

		for (; it != tmp_map.begin(); --it)
			std::cout << it->first << " => " << it->second << '\n';
	}

	test_category_name("	REVERSE ITERATORS	");

	// {
	// 	test_name(" reverse iterator");
	// 	ft::map<char,int> mymap;

	// 	mymap['x'] = 100;
	// 	mymap['y'] = 200;
	// 	mymap['z'] = 300;

	// 	// show content:
	// 	ft::map<char,int>::reverse_iterator rit;
	// 	for (rit = mymap.rbegin(); rit != mymap.rend(); ++rit)
	// 		std::cout << rit->first << " => " << rit->second << '\n';

	// 	return 0;
	// }

	test_category_name("	CAPACITY FUNCTION	");
	{
		ft::map<std::string, int> 	tmp_map;
		ft::pair<std::string, int>	tmp_pair("42", 19);

		test_name("empty");
		std::cout << "is_empty: " << tmp_map.empty() << std::endl;
		test_name("size");
		std::cout << "size: " << tmp_map.size() << std::endl;

		tmp_map.insert(tmp_pair);

		std::cout << "is_empty: " << tmp_map.empty() << std::endl;
		std::cout << "size: " << tmp_map.size() << std::endl;

		test_name("max_size");
		std::cout << "max_size: " << tmp_map.max_size() << std::endl;

	}

	{
		test_category_name("	ERASE FUNCTIONS	FROM Cplusplus	");
		ft::map<char,int> mymap;
		ft::map<char,int>::iterator it;

		// insert some values:
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		mymap['d']=40;
		mymap['e']=50;
		mymap['f']=60;

		it=mymap.find('b');
		mymap.erase (it);                   // erasing by iterator

		mymap.erase ('c');                  // erasing by key

		it=mymap.find ('e');
		mymap.erase ( it, mymap.end() );    // erasing by range

		// show content:
		for (it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}

	{
		test_category_name("	ERASE FUNCTIONS	");

		ft::map<char,int> mymap;

		// insert some values:
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		mymap['d']=40;
		mymap['e']=50;
		mymap['f']=60;
		mymap.prettyPrint();

		mymap.erase('f');		//erase by key
		test_name("--- erase by key ---");
		ft::map<char,int>::iterator it(mymap.begin());
		ft::map<char,int>::iterator it2(mymap.end());
		while ( it != it2 )
		{
			std::cout << it->first << " => " << it->second << '\n';
			it++;
		}
		std::cout << "\n";
		mymap.prettyPrint();

		test_name("--- iterator erase ---");
		ft::map<char,int>::iterator tmp = mymap.find('b');
		mymap.erase (tmp);     // erasing by iterator

		it = mymap.begin();
		it2 = mymap.end();
		while ( it != it2 )
		{
			std::cout << it->first << " => " << it->second << '\n';
			it++;
		}
		std::cout << "\n";
		mymap.prettyPrint();

		test_name("--- iterator range erase ---");

		mymap.insert ( ft::pair<char,int>('x', 100) );
		mymap.insert ( ft::pair<char,int>('z', 131) );
		std::cout << "BEFORE\n";
		mymap.prettyPrint();
		mymap.erase (mymap.find('c'), mymap.find('x'));     // erasing by iterator range
		std::cout << "\n";
		std::cout << "AFTER\n";
		mymap.prettyPrint();
	}

	{
		test_category_name("	ALLOCATOR	");
		int psize;
		ft::map<char,int> mymap;
		ft::pair<const char,int>* p;

		// allocate an array of 5 elements using mymap's allocator:
		p = mymap.get_allocator().allocate(5);

		// assign some values to array
		psize = sizeof(ft::map<char,int>::value_type)*5;

		std::cout << "The allocated array has a size of " << psize << " bytes.\n";

		mymap.get_allocator().deallocate(p,5);
	}

	{
		test_category_name("	SWAP : ITERATOR VALIDITY & TEST	");

		ft::map<char,int> foo,bar;

		foo['x']=100;
		foo['y']=200;

		bar['a']=11;
		bar['b']=22;
		bar['c']=33;

		std::cout << "foo contains:\n";
		for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		std::cout << "bar contains:\n";
		for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		ft::map<char, int>::iterator itFoo = foo.begin();
		ft::map<char, int>::iterator itFooE = foo.end();
		ft::map<char, int>::iterator itBar = bar.begin();
		ft::map<char, int>::iterator itBarE = bar.end();

		std::cout << "\nSWAP FOO/BAR\n\n";
		foo.swap(bar);

		std::cout << "itFoo contains:\n";
		for (; itFoo != itFooE; ++itFoo)
			std::cout << itFoo->first << " => " << itFoo->second << '\n';

		std::cout << "itBar contains:\n";
		for (; itBar != itBarE ; ++itBar)
			std::cout << itBar->first << " => " << itBar->second << '\n';
		std::cout << std::endl;

		std::cout << "foo contains:\n";
		for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		std::cout << "bar contains:\n";
		for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

	}

	{
		test_category_name("	INSERT from Cpluscplus	");
		ft::map<char,int> mymap;

		// first insert function version (single parameter):
		mymap.insert ( ft::pair<char,int>('a',100) );
		mymap.insert ( ft::pair<char,int>('z',200) );

		ft::pair<ft::map<char,int>::iterator,bool> ret;
		ret = mymap.insert ( ft::pair<char,int>('z',500) );
		if (ret.second==false) {
			std::cout << "element 'z' already existed";
			std::cout << " with a value of " << ret.first->second << '\n';
		}

		// second insert function version (with hint position):
		ft::map<char,int>::iterator it = mymap.begin();
		mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
		mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting

		// third insert function version (range insertion):
		ft::map<char,int> anothermap;
		anothermap.insert(mymap.begin(),mymap.find('c'));

		// showing contents:
		std::cout << "mymap contains:\n";
		for (it=mymap.begin(); it!=mymap.end(); ++it)
		{
			std::cout << it->first << " => " << it->second << '\n';
		}
			

		std::cout << "anothermap contains:\n";
		for (it=anothermap.begin(); it!=anothermap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}

	{
		test_category_name("	CITERATOR	");
		ft::map<char,int> mymap;

		// first insert function version (single parameter):
		mymap.insert ( ft::pair<char,int>('a',100) );
		mymap.insert ( ft::pair<char,int>('z',200) );

		ft::map<char, int>::const_iterator cIt = mymap.begin();
		ft::map<char, int>::const_iterator cItE = mymap.end();

		while (cIt != cItE)
		{
			// cIt->second = 42;
			// (*cIt).second = 42;
			std::cout << cIt->first << " => " << cIt->second << std::endl;
			cIt++;
		}
	}

	return (0);
}
