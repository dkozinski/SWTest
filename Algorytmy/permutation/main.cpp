// next_permutation example
#include <iostream>     // std::cout
#include <algorithm>    // std::next_permutation, std::sort, std::reverse
#include <vector>

int main () {
    int myints[] = {1,2,3,4};

    std::sort (myints,myints+4);
    std::reverse (myints,myints+4);

    std::cout << "The 3! possible permutations with 3 elements:\n";
    do {
        std::cout << myints[0] << ' ' << myints[1] << ' ' << myints[2] << ' ' << myints[3] <<'\n';
    } while ( std::prev_permutation(myints,myints+4) );

    std::cout << "After loop: " << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';

    ///////////////////////////////////////////////////////////////////////////
    // is_permutation
    int tabfoo[] = {1,2,3,4,5};
    int tabbar[] = {3,1,4,5,2};
    
    std::vector<int> foo(tabfoo,tabfoo+5);
    std::vector<int> bar(tabbar,tabbar+5);

    
//     if ( std::is_permutation (foo.begin(), foo.end(), bar.begin()) )
//         std::cout << "foo and bar contain the same elements.\n";
    
//     do {
//         // try a new permutation:
//         std::prev_permutation(foo.begin(),foo.end());
// 
//         // print range:
//         std::cout << "foo:";
//         for (int& x:foo) std::cout << ' ' << x;
//         std::cout << '\n';
// 
//     } while (!std::is_sorted(foo.begin(),foo.end()));
// 
//     std::cout << "the range is sorted!\n";

    return 0;
}
