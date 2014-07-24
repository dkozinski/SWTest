#include <iostream>
#include <cstdio>

int A[100], Answer;

int main(int argc, char **argv) {
    std::cout << "Hello, world!" << std::endl;
    
    std::freopen("sample_input.txt", "r", stdin);
    /*
        Read each test case from standard input.
        */
    //for(int i = 0; i < 100; i++)
    //{
    //        std::cin >> A[i];
    //}
        
    Answer = 0;    
    for(int i=1;i<99;i++)
    {
        if(A[i]==A[i-1]+A[i+1])
        {
            Answer = A[j];
            break;
        }
    }
    return 0;
}
