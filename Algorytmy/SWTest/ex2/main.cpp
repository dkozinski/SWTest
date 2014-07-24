#include <iostream>
#include <cstdio>
#define MAX_N 501
using namespace std;

int N;
int Board[MAX_N][MAX_N];
int Answer1, Answer2, Answer3, Answer4;

int main(void)
{
        const int T = 10;
        int test_case;
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


        /*
           Your program should handle 10 test cases given.
         */
        for(test_case = 1; test_case <= T; ++test_case)
        {
                int i, j;

                /*
                   Read each test case from standard input.
                   Read N, and the matrix Board[1..N][1..N].
                 */
                cin>>N;
                for(i = 1; i <= N; ++i)
                        for(j = 1; j <= N; ++j)
                                cin >> Board[i][j];

                /////////////////////////////////////////////////////////////////////////////////////////////
                /*
                   Implement your algorithm here.
                   The answers to the case will be stored in variable Answer1, Answer2, Answer3, Answer4.
                 */
                Answer1 = 0;
                Answer2 = 0;
                Answer3 = 0;
                Answer3 = 0;
                
                for(i = 1; i <= N; ++i) 
                {
                    for(j = 1; j <= N; ++j)
                    {
                        if(test_case  == 1)  
                        {
                            cout<<"Board["<<i<<"]["<<j<<"]:"<<Board[i][j]<<endl;
                        }
                        
                        if(Board[i][j] == 1 && Board[i][j+1] == 0 && Board[i+1][j] == 1 && Board[i+1][j+1] == 1 && (i+1)<=N && (j+1)<=N)
                        {
                            //if(test_case  == 1)    
                            //    cout<<"AAAAAAAAAAAA"<<i<<j<<endl;
                            Answer1++;
                        }
                        if(Board[i][j] == 1 && Board[i][j+1] == 1 && Board[i+1][j] == 1 && Board[i+1][j+1] == 0 && (i+1)<=N && (j+1)<=N)
                        {
                            Answer2++;
                        }
                        if(Board[i][j] == 1 && Board[i][j+1] == 1 && Board[i+1][j] == 0 && Board[i+1][j+1] == 1 && (i+1)<=N && (j+1)<=N)
                        {
                            Answer3++;
                        }
                        if(Board[i][j] == 0 && Board[i][j+1] == 1 && Board[i+1][j] == 1 && Board[i+1][j+1] ==1 && (i+1)<=N && (j+1)<=N)
                        {
                            Answer4++;
                        }
 
                    }
                }
                /////////////////////////////////////////////////////////////////////////////////////////////
                // Answer1 = Answer2 = Answer3 = Answer4 = 0;


                // Print the answer to standard output(screen).
                cout << "#" << test_case << " " << Answer1 << " " << Answer2 << " " << Answer3 << " " << Answer4 << endl;
        }

        return 0;//Your program should return 0 on normal termination.
}
