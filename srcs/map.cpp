#include "../includes/tests/tests.hpp"

#include <iostream>
#include <map>

#define RST  "\x1B[0m"
#define KGRN  "\x1B[32m"
#define KMAG  "\x1B[35m"
void	set_color(void)	{ std::cout << KGRN; }
void	set_cat_color(void)	{ std::cout << KMAG; }
void	reset_color(void)	{ std::cout << RST; }

void check_map(std::string name, bool good)
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

template <typename T, typename S>
bool operator==(ft::map<T, S> & a, std::map<T, S> & b)
{
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
	typename ft::map<T, S>::iterator it = a.begin();
	typename std::map<T, S>::iterator it2 = b.begin();
	// while (it != a.end())
	// {
	// 	if (it->first != it2->first || it->second != it2->second)
	// 		return (false);
	// 	++it;
	// 	++it2;
	// }
	return (true);
};


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

/*

    explicit map(const key_compare& comp, const allocator_type& a);
    template <class InputIterator>
        map(InputIterator first, InputIterator last,
            const key_compare& comp, const allocator_type& a);
    map(const map& m);
    ~map();

    map& operator=(const map& m); // We should implement operator= for the rb for this to work as a deep copy

    // iterators:
    iterator begin() ;
    const_iterator begin() const;
    iterator end();
    const_iterator end()   const;

    reverse_iterator rbegin();
    const_reverse_iterator rbegin() const;
    reverse_iterator rend();
❌    const_reverse_iterator rend() const;

    // capacity:
    bool      empty()    const noexcept;
    size_type size()     const noexcept;
    size_type max_size() const noexcept;

    // element access:
    mapped_type& operator[](const key_type& k);

    // modifiers:
    pair<iterator, bool> insert(const value_type& v);
    iterator insert(const_iterator position, const value_type& v);
    template <class InputIterator>
    void insert(InputIterator first, InputIterator last);
    void erase(iterator position);
    size_type erase(const key_type& k);
    void  erase(iterator first, iterator last);
    void clear();

    void swap(map& m);

    // observers:
    allocator_type get_allocator() const noexcept;
    key_compare    key_comp()      const;
    value_compare  value_comp()    const;

    // map operations:
    iterator find(const key_type& k);
    const_iterator find(const key_type& k) const;

    size_type      count(const key_type& k) const;
    iterator lower_bound(const key_type& k);
    const_iterator lower_bound(const key_type& k) const;


    iterator upper_bound(const key_type& k);
    const_iterator upper_bound(const key_type& k) const;


    pair<iterator,iterator>             equal_range(const key_type& k);
    pair<const_iterator,const_iterator> equal_range(const key_type& k) const;
};

template <class Key, class T, class Compare, class Allocator>
bool
operator==(const map<Key, T, Compare, Allocator>& x,
           const map<Key, T, Compare, Allocator>& y);

template <class Key, class T, class Compare, class Allocator>
bool
operator< (const map<Key, T, Compare, Allocator>& x,
           const map<Key, T, Compare, Allocator>& y);

template <class Key, class T, class Compare, class Allocator>
bool
operator!=(const map<Key, T, Compare, Allocator>& x,
           const map<Key, T, Compare, Allocator>& y);

template <class Key, class T, class Compare, class Allocator>
bool
operator> (const map<Key, T, Compare, Allocator>& x,
           const map<Key, T, Compare, Allocator>& y);

template <class Key, class T, class Compare, class Allocator>
bool
operator>=(const map<Key, T, Compare, Allocator>& x,
           const map<Key, T, Compare, Allocator>& y);

template <class Key, class T, class Compare, class Allocator>
bool
operator<=(const map<Key, T, Compare, Allocator>& x,
           const map<Key, T, Compare, Allocator>& y);

// specialized algorithms:
template <class Key, class T, class Compare, class Allocator>
void
swap(map<Key, T, Compare, Allocator>& x, map<Key, T, Compare, Allocator>& y)
    noexcept(noexcept(x.swap(y)));
*/



static void constructors(void)
{
	std::cout << BLUE << "\n>Constructor" << RESET << std::endl;
	std::pair<int, int> a[] = {std::make_pair(0, 1), std::make_pair(1, 0), std::make_pair(2, 1)};
	ft::map<int, int> m1;
	std::map<int, int> m2;
	check_map("default", (m1 == m2));
// 	ft::map<int, int> m3(a, a + 3);
// 	std::map<int, int> m4(a, a + 3);
// 	check("range", (m3 == m4));
// // 	ft::map<int, int> m5(m3);
// // 	std::map<int, int> m6(m4);
// // 	check("copy", (m5 == m6));
}
void test_map(void)
{
	constructors();
}