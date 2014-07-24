#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

long long A, B, Answer;

int main(int argc, char **argv) {
int test_case;

    /* 
    The freopen function below opens input.txt in read only mode and 
    sets your standard input to work with the opened file. 
    When you test your code with the sample data, you can use the function
    below to read in from the sample data file instead of the standard input.
    So. you can uncomment the following line for your local test. But you
    have to comment the following line when you submit for your scores.
    */

    freopen("/home/dawid/SW Test/Algorytmy/SWTEST_2/sample_input.txt", "r", stdin);

    for(test_case = 1; test_case <= 10; test_case++)
    {
    /*
        Read each test case from standard input.
    */
            cin >> A; cin >> B;
            Answer = 0;
            
            vector<unsigned long long> vectorPowFirst;
            vector<unsigned long long> vectorPowSecond;
            vector<unsigned long long> vectorPowFirstMultPowSecond;
            
            // create vectors of powers
            for(int i=0;i<10;i++)
            {
                int m1 = pow(A, i+1);
                int m2 = pow(B, i+1);
                //cout<<m1<<endl;
                //cout<<m2<<endl;
                
                vectorPowFirst.push_back(pow(A, i+1));
                vectorPowSecond.push_back(pow(B, i+1));
            }
             
            // create vector that contains cobination of power mult    
            for(int i=0;i<10;i++)
            {
                for(int j=0;j<10;j++)
                {
                    vectorPowFirstMultPowSecond.push_back(vectorPowFirst[i]*vectorPowSecond[j]);
                }
            }

            set<unsigned long long> setFirstSecond;
            setFirstSecond.insert(vectorPowFirst.begin(),vectorPowFirst.end());
            setFirstSecond.insert(vectorPowSecond.begin(),vectorPowSecond.end());
            setFirstSecond.insert(vectorPowFirstMultPowSecond.begin(),vectorPowFirstMultPowSecond.end());
            
            vector<unsigned long long> vectorResults(setFirstSecond.begin(),setFirstSecond.end());
            sort(vectorResults.begin(),vectorResults.end());
                
            Answer = vectorResults[9];

            //cout<<A<<endl;
            //cout<<B<<endl;    
            /////////////////////////////////////////////////////////////////////////////////////////////
            /*
                    Please, implement your algorithm from this section.
            */
            /////////////////////////////////////////////////////////////////////////////////////////////
    // Answer = 0;
    


            // Print the answer to standard output(screen).
            cout << "#" << test_case << " " << Answer << endl;
    }

    return 0;//Your program should return 0 on normal termination.
}
