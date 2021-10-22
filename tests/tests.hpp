   
#ifndef TESTS_HPP
# define TESTS_HPP

# include <vector>
# include <list>
# include <map>
# include <stack>
# include <queue>
# include <iostream>
# include "../vector/vector.hpp"

#define RESET "\e[0m"
#define GREEN "\e[92m"
#define BLUE "\e[94m"
#define MAGENTA "\e[35m"
#define BOLD "\e[1m"

#define GOOD "✅"
#define FAIL "❌"

void	test_vector();

void check(std::string name, bool good);

#endif