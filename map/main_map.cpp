#include <iostream>
#include "map.hpp"

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

	map.insert(pair);

	std::cout << map.size() << std::endl;
	std::cout << map.max_size() << std::endl;

	return (0);
}
