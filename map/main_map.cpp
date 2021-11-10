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

int main()
{
	std::cout << "---------- TEST MAP ----------\n\n";

	ft::map<std::string, int> map;
	
	ft::pair<std::string, int>pair("42", 19);
	
	std::cout << pair.first << " | " << pair.second << std::endl;

	ft::pair<std::string, int> pair2(pair);

	std::cout << "----------------\n";
	std::cout << pair.first << std::endl;
	std::cout << pair.second << std::endl;
	std::cout << "----------------\n";
	std::cout << pair2.first << std::endl;
	std::cout << pair2.second << std::endl;

	ft::pair<std::string, int> pair3 = pair;
	std::cout << "----------------\n";
	std::cout << pair3.first << std::endl;
	std::cout << pair3.second << std::endl;
	
	std::cout << std::boolalpha;
	std::cout << map.empty() << std::endl;

	map.insert(pair);

	std::cout << map.size() << std::endl;
	std::cout << map.max_size() << std::endl;

	std::cout << map["42"] << std::endl;

	std::cout << map.empty() << std::endl;

	{
		test_name("	MODIFIERS FUNCTION	");
		ft::map<std::string, int> 	tmp_map;
		ft::pair<std::string, int>	tmp_pair("42", 19);

		test_name("insert");
		tmp_map.insert(tmp_pair);

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

	return (0);
}
