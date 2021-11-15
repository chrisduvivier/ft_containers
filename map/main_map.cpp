#include <iostream>
#include "map.hpp"

#define RST  "\x1B[0m"
#define KGRN  "\x1B[32m"
void	set_color(void)	{ std::cout << KGRN; }
void	reset_color(void)	{ std::cout << RST; }
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
		test_name("	MODIFIERS FUNCTION	");
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

	{
		// test_name("	OPERATIONS FUNCTION	");

		// ft::map<std::string, int> 	tmp_map;
		// ft::pair<std::string, int>	tmp_pair("42", 19);

		// tmp_map.insert(tmp_pair);
		// test_name("find");
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

	{
		test_name("	ITERATORS ");
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
		test_name("	ITERATORS bigger tests ");
		ft::map<int, int> map;
		for (int i = 1 ; i < 10; i++)
		{
			map[i] = i;
		}
		ft::map<int,int>::iterator it(map.begin());
		std::cout << it->first << "\n";
		ft::map<int,int>::iterator it2(map.end());

		map.getTree().prettyPrint();
		while ( it != it2 )
		{
			std::cout << "currently on " << it->first << "\n";
			it++;
		}
	}

	{
		test_name("	CAPACITY FUNCTION	");
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
		test_name("--- ERASE FUNCTIONS ---");

		ft::map<char,int> mymap;

		// insert some values:
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		mymap['d']=40;
		mymap['e']=50;
		mymap['f']=60;
		mymap._tree.prettyPrint();

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
		mymap._tree.prettyPrint();

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
		mymap._tree.prettyPrint();

		test_name("--- iterator range erase ---");

		mymap.insert ( ft::pair<char,int>('x', 100) );
		mymap.insert ( ft::pair<char,int>('z', 131) );
		std::cout << "BEFORE\n";
		mymap._tree.prettyPrint();
		mymap.erase (mymap.find('c'), mymap.find('x'));     // erasing by iterator range
		std::cout << "\n";
		std::cout << "AFTER\n";
		mymap._tree.prettyPrint();
	}


	return (0);
}
