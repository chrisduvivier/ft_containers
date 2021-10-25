/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:48:56 by rlinkov           #+#    #+#             */
/*   Updated: 2021/10/25 16:04:48 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rb_tree.hpp"
#include "pair.hpp"
#include <iostream>

int main()
{
	std::cout << "---------- TEST RBT ----------" << std::endl << std::endl;
	
	{
		ft::RBTree<int, std::less<int> >		rbt;

		for (size_t i = 0; i < 20; i++)
		{
			rbt.insert(i);
		}
		rbt.prettyPrint();
		
	}

	
	return (0);
}