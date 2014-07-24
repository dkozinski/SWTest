#include<stdio.h>
#include<iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int P1, P2;
int A[100];
int Answer;

int main(int argc, char** argv)
{
        int i;
        /*
           freopen function below opens input.txt file in read only mode, and afterward,
           the program will read from input.txt file instead of standard(keyboard) input.
           To test your program, you may save input data in input.txt file,
           and use freopen function to read from the file when using cin function.
           You may remove the comment symbols(//) in the below statement and use it.
           Use #include<cstdio> or #include<stdio.h> to use the function in your program.
           But before submission, you must remove the freopen function or rewrite comment symbols(//).
         */
        freopen("input.txt", "r", stdin);

        // Read two positive integers specifying two positions.
        // And read 100 positive integers and store them in A[0..99].

        cin >> P1 >> P2;
        for(i = 0; i < 100; i++)
        {       cin >> A[i];
                cout<<A[i]<<endl;
        }


        /////////////////////////////////////////////////////////////////////////////////////////////
        /*
           Implement your algorithm here.
           The answer to the case will be stored in variable Answer.
         */
        /////////////////////////////////////////////////////////////////////////////////////////////
        cout<<"P1: "<<P1<<"/ P2: "<<P2<<endl;
        Answer = 0;
        if(P1>0 && P1<=100 && P2 >0 && P2<=100)
            Answer = fabs(A[P1-1]-A[P2-1]);


        // Print the answer to standard output(screen).
        cout << Answer << endl;

        return 0;//Your program should return 0 on normal termination.
}
