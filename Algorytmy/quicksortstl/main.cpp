// stable_sort example
#include <iostream>     // std::cout
#include <algorithm>    // std::stable_sort
#include <vector>       // std::vector

bool myfunction (int i,int j) { return (i<j); }

struct myclass {
  bool operator() (int i,int j) { return (i<j);}
} myobject;

bool compare_as_ints (double i,double j)
{
    return (int(i)<int(j));
}

int main () {
    double mydoubles[] = {3.14, 1.41, 2.72, 4.67, 1.73, 1.32, 1.62, 2.58};

    std::vector<double> myvector;

    myvector.assign(mydoubles,mydoubles+8);

    std::cout << "using default comparison:";
    std::stable_sort (myvector.begin(), myvector.end());
    for (std::vector<double>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    myvector.assign(mydoubles,mydoubles+8);

    std::cout << "using 'compare_as_ints' :";
    std::stable_sort (myvector.begin(), myvector.end(), compare_as_ints);
    for (std::vector<double>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    
    ///////////////////////////////////////////////////////////////////////////
    //
    int myints[] = {32,71,12,45,26,80,53,33};
    std::vector<int> myvector2 (myints, myints+8);               // 32 71 12 45 26 80 53 33

    // using default comparison (operator <):
    std::sort (myvector2.begin(), myvector2.begin()+4);           //(12 32 45 71)26 80 53 33

    // using function as comp
    std::sort (myvector2.begin()+4, myvector2.end(), myfunction); // 12 32 45 71(26 33 53 80)

    // using object as comp
    std::sort (myvector2.begin(), myvector2.end(), myobject);     //(12 26 32 33 45 53 71 80)

    // print out content:
    std::cout << "myvector contains:";
    for (std::vector<int>::iterator it=myvector2.begin(); it!=myvector2.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    return 0;
}
