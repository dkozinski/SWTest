#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

bool compfun (int i,int j) { return (i<j); }

bool IsOdd (int i) {
  return ((i%2)==1);
}

bool myfunction (int i, int j) {
  return (i==j);
}

int main(int argc, char **argv) {
    std::cout << "Hello, world!" << std::endl;
    int n1 = 3;
    int n2 = 5;

    ///////////////////////////////////////////////////////////////////////////
    /*
     * Find 
     */    
    int tab[] = {0, 1, 2, 3, 4};   
    std::cout<<sizeof(tab)<<std::endl;
    std::cout<<sizeof(tab)/sizeof(*tab)<<std::endl;
    int size = sizeof(tab)/sizeof(*tab);
    
    int myints[] = {5,20,5,30,30,20,10,10,20};
    std::vector<int> myvector (myints,myints+sizeof(myints)/sizeof(*myints));
    std::vector<int>::iterator it;
    for(it=myvector.begin();it!=myvector.end();++it)
    {
            
            std::cout<<" : " <<(*it)<<std::endl;
    }
    
    std::vector<int> v(tab,tab+size);
    
    std::vector<int>::iterator result1 = std::find(v.begin(), v.end(), n1);
    std::vector<int>::iterator result2 = std::find(v.begin(), v.end(), 5);
 
    if (result1 != v.end()) {
        std::cout << "v contains: " << n1 << '\n';
    } else {
        std::cout << "v does not contain: " << n1 << '\n';
    }
 
    if (result2 != v.end()) {
        std::cout << "v contains: " << n2 << '\n';
    } else {
        std::cout << "v does not contain: " << n2 << '\n';
    }
    
    ///////////////////////////////////////////////////////////////////////////
    /*
     * Find adjacent_find
     */    

    // using default comparison:
    it = std::adjacent_find (myvector.begin(), myvector.end());

    if (it!=myvector.end())
        std::cout << "the first pair of repeated elements are: " << *it << '\n';

    //using predicate comparison:
    it = std::adjacent_find (++it, myvector.end(), myfunction);

    if (it!=myvector.end())
        std::cout << "the second pair of repeated elements are: " << *it << '\n';

    ///////////////////////////////////////////////////////////////////////////
    /*
     * Find find_if
     */    

    std::vector<int>::iterator it2 = std::find_if (myvector.begin(), myvector.end(), IsOdd);
    std::cout << "The first odd value is " << *it2 << '\n';
    
    ///////////////////////////////////////////////////////////////////////////
    /*
     * binary_search
     */    
    
    // using default comparison:
    std::sort (v.begin(), v.end());

    std::cout << "looking for a 3... ";
    if (std::binary_search (v.begin(), v.end(), 3))
        std::cout << "found!\n"; else std::cout << "not found.\n";

    // using myfunction as comp:
    std::sort (v.begin(), v.end(), myfunction);

    std::cout << "looking for a 6... ";
    if (std::binary_search (v.begin(), v.end(), 6, compfun))
        std::cout << "found!\n"; else std::cout << "not found.\n";
  
    return 0;
}
