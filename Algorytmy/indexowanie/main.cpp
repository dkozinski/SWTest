#include <iostream>
#include <string.h>

int main(int argc, char **argv) {
    std::cout << "Hello, world!" << std::endl;
    
    int __tab[5][5] = {{1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}};
    int* _tab[] = {__tab[0] -1 , __tab[1] - 1, __tab[2] - 1,__tab[3] - 1,__tab[4] - 1};
    int** tab = _tab - 1;
    
    for(int i=1;i<=5;i++)
    {
        
        for(int j=1;j<=5;j++)
        {
               std::cout<<"tab["<<i<<"]["<<j<<"] "<<tab[i][j]<<std::endl;
        }
    }
    
    int __tab1[5] = {1,2,3,4,5};
    int *tab1 = __tab1-1;
    for(int i=1;i<=5;i++)
    {
            std::cout<<"tab1["<<i<<"]"<<tab1[i]<<std::endl;
    }
    
    ///////////////////////////////////////////////////////////////////////////
    // INDEKSUJEMY OD 1 do N
    //
    int m = 5;
    int n = 6;
    int** __tab2 = new int* [m];
    int** _tab2 = new int* [m]; //{__tab[0] -1 , __tab[1] - 1, __tab[2] - 1,__tab[3] - 1,__tab[4] - 1};
    
    for(int i=0; i<m;i++)
    {
        __tab2[i] = new int[n];
        memset(__tab2[i],0,sizeof(int)*n);
        _tab2[i] = __tab2[i] - 1; 
    }
    
     for(int i=0; i<m;i++)
    {
        for(int j=0; j<n;j++)
        {            
            __tab2[i][j] = j+1;
        }
    }

    int** tab2 = _tab2 - 1;
    
    for(int i=1;i<=m;i++)
    {
        
        for(int j=1;j<=n;j++)
        {
               std::cout<<"tab2["<<i<<"]["<<j<<"] "<<tab2[i][j]<<std::endl;
        }
    }
    
    ///////////////////////////////////////////////////////////////////////////
    int *__tab3 = new int[m];
    int *tab3 = __tab3-1;
    for(int i=1;i<=m;i++)
    {
            tab1[i] = i;
    }
    
    for(int i=1;i<=m;i++)
    {
            std::cout<<"tab1["<<i<<"]"<<tab1[i]<<std::endl;
    }

    return 0;
}
