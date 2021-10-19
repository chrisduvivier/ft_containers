#include <iostream>
#include <string>
#include <deque>
#if 0 //CREATE A REAL STL EXAMPLE
	#include <vector>
	namespace ft = std;
#else
	#include "../vector/vector.hpp"
#endif

int main(void)
{
    std::cout << "===================TEST REVERSE ITER======================\n";
    {
        /* https://www.cplusplus.com/reference/iterator/reverse_iterator/reverse_iterator/ */
        std::cout << "=====[ TEST CONSTRUCTOR ]=====\n";
        ft::vector<int> myvector;
        for (int i=0; i<10; i++) myvector.push_back(i);

        typedef ft::vector<int>::iterator iter_type;
                                                                // ? 0 1 2 3 4 5 6 7 8 9 ?
        iter_type from (myvector.begin());                      //   ^
                                                                //         ------>
        iter_type until (myvector.end());                       //                       ^
                                                                //
        ft::reverse_iterator<iter_type> rev_until (from);       // ^
                                                                //         <------
        ft::reverse_iterator<iter_type> rev_from (until);       //                     ^

        std::cout << "myvector:";
        while (rev_from != rev_until)
            std::cout << ' ' << *rev_from++;
        std::cout << '\n';

        /* expected: myvector: 9 8 7 6 5 4 3 2 1 0 */
    }

    {
        std::cout << "=====[ BASE ]=====\n";
        // reverse_iterator::base example
        ft::vector<int> myvector;
        for (int i=0; i<10; i++) myvector.push_back(i);

        typedef ft::vector<int>::iterator iter_type;

        ft::reverse_iterator<iter_type> rev_end (myvector.begin());
        ft::reverse_iterator<iter_type> rev_begin (myvector.end());

        std::cout << "myvector:";
        for (iter_type it = rev_end.base(); it != rev_begin.base(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
        /* expected: myvector: 0 1 2 3 4 5 6 7 8 9 */
    }
    
    {
        ft::vector<int> myvector;
        for (int i=0; i<10; i++) myvector.push_back(i);

        typedef ft::vector<int>::iterator iter_type;

        ft::reverse_iterator<iter_type> rev_end (myvector.begin());
        ft::reverse_iterator<iter_type> rev_begin (myvector.end());

        std::cout << "myvector:";
        for (iter_type it = rev_end.base(); it != rev_begin.base(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
    }
}