#include "rb_tree.hpp"
#include "pair.hpp"
#include <iostream>
#include <vector>

int main()
{
	// std::cout << std::endl << "---------- TEST PRBT<pair<int, int>> ----------" << std::endl << std::endl;
	// {
	// 	ft::RBTree<ft::pair<int, int> >		rbt;
	// 	ft::pair<int, int> p;
	// 	for (size_t i = 0; i < 20; i++)
	// 	{
	// 		p = ft::pair<int, int>(i, 20 - i);
	// 		rbt.insert(p);
	// 	}
	// 	rbt.prettyPrint();
	// }

	// std::cout << std::endl << "---------- TEST PRBT<pair<string, int>> ----------" << std::endl << std::endl;
	// {
	// 	ft::RBTree<ft::pair<std::string, int> >		rbt;
	// 	ft::pair<std::string, int> p;
	// 	for (size_t i = 0; i < 20; i++)
	// 	{
	// 		p = ft::pair<std::string, int>("Helo " + std::to_string(i) + " !", 20 - i);
	// 		rbt.insert(p);
	// 	}
	// 	rbt.prettyPrint();
	// }

	std::cout << std::endl << "---------- TEST PRBT<pair<string, string>> ----------" << std::endl << std::endl;
	{
		std::vector< ft::pair<std::string, std::string> > v;

		v.push_back(ft::pair<std::string, std::string>("1", "2"));
		v.push_back(ft::pair<std::string, std::string>("salut", "coucou"));
		v.push_back(ft::pair<std::string, std::string>("hello", "hola"));
		v.push_back(ft::pair<std::string, std::string>("42", "19"));
		v.push_back(ft::pair<std::string, std::string>("key", "value"));
		v.push_back(ft::pair<std::string, std::string>("4", "5"));
		v.push_back(ft::pair<std::string, std::string>("0", "100"));
		v.push_back(ft::pair<std::string, std::string>("Chris", "Nathan"));
		
		ft::RBTree<ft::pair<std::string, std::string> >		rbt;

		for (std::vector<ft::pair<std::string, std::string> >::iterator it = v.begin(); it != v.end() ; ++it)
		{
			rbt.insert(*it);
		}
		rbt.prettyPrint();

		std::cout << rbt.searchTree(ft::pair<std::string, std::string>("1", "2"))->data.first << std::endl;
		std::cout << rbt.searchTreeKey("salut")->data.second << std::endl;

		rbt.deleteNode(ft::pair<std::string, std::string>("1", "2"));
		std::cout << rbt.searchTree(ft::pair<std::string, std::string>("1", "2"))->data.first << std::endl;

		rbt.prettyPrint();
		
		rbt.deleteNodeKey("salut");
		std::cout << rbt.searchTreeKey("salut")->data.second << std::endl;
		std::cout << std::endl << "================" << std::endl << std::endl;
		rbt.prettyPrint();

		std::cout << "1     : " << rbt["1"] << std::endl;
		std::cout << "salut : " << rbt["salut"] << std::endl;
		std::cout << "hello : " << rbt["hello"] << std::endl;
		std::cout << "42    : " << rbt["42"] << std::endl;
		std::cout << "key   : " << rbt["key"] << std::endl;
		std::cout << "4     : " << rbt["4"] << std::endl;
		std::cout << "0     : " << rbt["0"] << std::endl;
		std::cout << "Chris : " << rbt["Chris"] << std::endl << std::endl;

		rbt.prettyPrint();

		std::cout << std::endl << "Max of RBT : " << rbt.maximum(rbt.getRoot())->data.first << std::endl;
		std::cout << "Min of RBT : " << rbt.minimum(rbt.getRoot())->data.first << std::endl << std::endl;

		std::cout << "Size of RBT     : " << rbt.size() << std::endl;
		std::cout << "Max size of RBT : " << rbt.max_size() << std::endl;
	}

	return (0);
}