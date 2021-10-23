#include "../includes/tests/tests.hpp"

void check(std::string name, bool good)
{
	std::string margin(32 - name.length(), ' ');
	if (good)
		std::cout << name << margin << GOOD << std::endl;
	else
		std::cout << name << margin << FAIL << std::endl;
};

template<typename T>
void debug(std::string test, T value)
{
	std::cout << YELLOW << test << BOLD << value << RESET << std::endl;
}

template <typename T>
bool operator==(ft::vector<T> & a, std::vector<T> & b)
{
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
	for (size_t i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
			return (false);
	}
	return (true);
};

static void default_constructor()
{
	std::cout << BLUE << "\n>Constructor" << RESET << std::endl;
	int test[] = {0, 1, 2, 3};

	ft::vector<int> v1;
	std::vector<int> v2;
	check("default", v1 == v2);

	ft::vector<int> l3((size_t)10);
	std::vector<int> l4((size_t)10);
	check("fill with default value", l3 == l4);

	ft::vector<int> l5((size_t)10, 42);
	std::vector<int> l6((size_t)10, 42);
	check("fill", l5 == l6);

	ft::vector<int> l7(test, test + 4);
	std::vector<int> l8(test, test + 4);
	check("range", l7 == l8);

	ft::vector<int> l9(l7);
	std::vector<int> l10(l8);
	check("copy", l9 == l10);

	ft::vector<int> v11(l9.begin(), l9.end());
	std::vector<int> v12(l10.begin(), l10.end());
	check("Iterators", v11 == v12);
}

static void capacity()
{
	std::cout << BLUE << "\n>capacity" << RESET << std::endl;
	ft::vector<int> v1;
	std::vector<int> v2;

	check("empty() on empty vector", (v1.empty() == v2.empty()));
	check("size() on empty vector", (v1.size() == v2.size()));
	v1.push_back(1);
	v1.push_back(2);
	v2.push_back(1);
	v2.push_back(2);
	check("empty()", (v1.empty() == v2.empty()));
	check("size()", (v1.size() == v2.size()));
	check("maxsize()", (v1.max_size() == v2.max_size()));
	check("capacity()", (v1.capacity() == v2.capacity()));

	v1.resize(100);
	v2.resize(100);
	check("resize()", (v1 == v2));

	debug("v1.size() after resize " , v1.size());
	debug("v2.size() after resize " , v2.size());
	debug("v1.capacity() after resize " , v1.capacity());
	debug("v2.capacity() after resize " , v2.capacity());

	check("capacity() after resize()", (v1.capacity() == v2.capacity()));

	v1.reserve(1000);
	v2.reserve(1000);
	debug("v1.size() after reserve ",v1.size());
	debug("v2.size() after reserve ",v2.size());
	debug("v1.capacity() after reserve ",v1.capacity());
	debug("v2.capacity() after reserve ",v2.capacity());

	check("reserve()", (v1 == v2));
}


static void copy_operator()
{
	std::cout << BLUE << "\n>Operator =" << RESET << std::endl;
	ft::vector<int> v1;
	std::vector<int> v2;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	ft::vector<int> v3;
	std::vector<int> v4;
	v3 = v1;
	v4 = v2;
	check("source", (v1 == v3));
	check("copy", (v2 == v4));
	v1.push_back(42);
	check("modified source", (v1 != v3));
}

static void push_pop()
{
	std::cout << BLUE << "\n>Push / Pop" << RESET << std::endl;
	ft::vector<int> v1;
	std::vector<int> v2;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	check("push back", v1 == v2);
	v1.pop_back();
	v2.pop_back();
	check("pop back", (v1 == v2));
	v1.pop_back();
	v2.pop_back();
	v1.pop_back();
	v2.pop_back();
	check("pop empty", (v1 == v2));
}

static void max_size()
{
	std::cout << BLUE << "\n>Max size" << RESET << std::endl;
	ft::vector<std::string> v1;
	std::vector<std::string> v2;
	check("string", v1.max_size() == v2.max_size());
	ft::vector<int> v3;
	std::vector<int> v4;
	check("int", v3.max_size() == v4.max_size());
}

static void resize()
{
	std::cout << BLUE << "\n>Resize" << RESET << std::endl;
	ft::vector<std::string> v1;
	std::vector<std::string> v2;
	v1.resize(10, "test");
	v2.resize(10, "test");
	check("longer", (v1 == v2));
	v1.resize(2, "42");
	v2.resize(2, "42");
	check("shorter", (v1 == v2));
}

static void access_operator()
{
	std::cout << BLUE << "\n>Operator [], at()" << RESET << std::endl;
	ft::vector<int> v1;
	std::vector<int> v2;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	check("test 1", v1[0] == v2[0]);
	check("test 2", v1[2] == v2[2]);
	try
	{
		std::cout << "over: " << v1.at(100) << " :" << FAIL << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::string(8, ' ') << BOLD << GREEN << GOOD << RESET << std::endl;
	}
	try
	{
		std::cout << "negative: "<< v1.at(-1) << ": " << FAIL  << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::string(4, ' ') << BOLD << GREEN << GOOD << RESET << std::endl;
	}
}

static void front_back()
{
	std::cout << BLUE << "\n>Front / Back" << RESET << std::endl;
	ft::vector<int> v1;
	std::vector<int> v2;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	check("front", v1.front() == v2.front());
	check("back", v1.front() == v2.front());
}

static void assign()
{
	std::cout << BLUE << "\n>Assign" << RESET << std::endl;
	std::string test[] = {"Hey", "what's", "up", "?"};
	ft::vector<std::string> v1;
	std::vector<std::string> v2;
	v1.assign(test, test + 4);
	v2.assign(test, test + 4);
	check("range", v1 == v2);
	v1.assign(10, "?");
	v2.assign(10, "?");
	check("fill", v1 == v2);
}

static void insert()
{
	std::cout << BLUE << "\n>Insert" << RESET << std::endl;
	int test[] = {1, 2, 3};
	ft::vector<int> v1;
	std::vector<int> v2;
	v1.insert(v1.begin(), 42);
	v1.insert(v1.end(), 21);
	v1.insert(v1.begin(), 10);
	v1.insert(v1.begin() + 1, 11);
	v2.insert(v2.begin(), 42);
	v2.insert(v2.end(), 21);
	v2.insert(v2.begin(), 10);
	v2.insert(v2.begin() + 1, 11);
	check("single element", v1 == v2);
	v1.insert(v1.begin() + 2, (size_t)3, 0);
	v2.insert(v2.begin() + 2, (size_t)3, 0);
	check("fill", v1 == v2);
	v1.insert(v1.begin() + 1, test, test + 3);
	v2.insert(v2.begin() + 1, test, test + 3);
	check("range", v1 == v2);
}

static void erase()
{
	std::cout << BLUE << "\n>Erase / Clear" << RESET << std::endl;
	std::string test[] = {"Hey", "what's", "up", "?"};
	ft::vector<std::string> v1;
	std::vector<std::string> v2;
	v1.assign(test, test + 4);
	v2.assign(test, test + 4);
	v1.erase(v1.begin() + 2);
	v2.erase(v2.begin() + 2);
	check("erase", v1 == v2);
	v1.clear();
	v2.clear();
	check("clear", v1 == v2);
}

static void swap()
{
	std::cout << BLUE << "\n>Swap" << RESET << std::endl;
	ft::vector<int> v1;
	std::vector<int> v2;
	ft::vector<int> v3;
	std::vector<int> v4;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v3.push_back(42);
	v3.push_back(43);
	v4.push_back(42);
	v4.push_back(43);
	v1.swap(v3);
	v2.swap(v4);
	check("first vector", v1 == v2);
	check("second vector", v3 == v4);
}

static void operators()
{
	std::cout << BLUE << "\n>Operators" << RESET << std::endl;
	ft::vector<int> v1;
	std::vector<int> v2;
	ft::vector<int> v3;
	std::vector<int> v4;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v3 = v1;
	v4 = v2;
	check("==", (v1 == v3) == (v2 == v4));
	check("!=", (v1 != v3) == (v2 != v4));
	check(">", (v1 > v3) == (v2 > v4));
	check("<", (v1 < v3) == (v2 < v4));
	check(">=", (v1 >= v3) == (v2 >= v4));
	check("<=", (v1 <= v3) == (v2 <= v4));
}

void	test_vector()
{
	std::cout << MAGENTA << BOLD << "\n------------- vector ------------" << RESET << std::endl;

	default_constructor();
	copy_operator();
	capacity();
	push_pop();
	max_size();
	resize();
	access_operator();
	front_back();
	assign();
	insert();
	erase();
	swap();
	operators();
}