/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduvivie <cduvivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:48:56 by rlinkov           #+#    #+#             */
/*   Updated: 2021/11/08 14:31:13 by cduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rb_tree.hpp"
#include "pair.hpp"
#include <iostream>
#include <vector>

int main()
{
	std::cout << "---------- TEST RBT & PRBT----------" << std::endl << std::endl;

	// std::cout << std::endl << "---------- TEST RBT<int> ----------" << std::endl << std::endl;
	// {
	// 	ft::RBTree<int, std::less<int> >		rbt;

	// 	for (size_t i = 0; i < 20; i++)
	// 	{
	// 		rbt.insert(i);
	// 	}
	// 	rbt.prettyPrint();
		
	// }

	std::cout << std::endl << "---------- TEST PRBT<pair<int, int>> ----------" << std::endl << std::endl;
	{
		ft::RBTree<ft::pair<int, int>, std::less<ft::pair<int, int> > >		rbt;
		ft::pair<int, int> p;
		for (size_t i = 0; i < 20; i++)
		{
			p = ft::pair<int, int>(i, 20 - i);
			rbt.insert(p);
		}
		rbt.prettyPrint();
	}

	std::cout << std::endl << "---------- TEST PRBT<pair<string, int>> ----------" << std::endl << std::endl;
	{
		ft::RBTree<ft::pair<std::string, int>, std::less<ft::pair<std::string, int> > >		rbt;
		ft::pair<std::string, int> p;
		for (size_t i = 0; i < 20; i++)
		{
			p = ft::pair<std::string, int>("Helo " + std::to_string(i) + " !", 20 - i);
			rbt.insert(p);
		}
		rbt.prettyPrint();
	}

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
		
		ft::RBTree<ft::pair<std::string, std::string>, std::less<ft::pair<std::string, std::string> > >		rbt;

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
		rbt.prettyPrint();
	}

	return (0);
}