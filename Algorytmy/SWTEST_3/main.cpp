#include <iostream>
#include <cstdio>

#include<iostream>
#include <set>
#include <string>
#include <algorithm>


using namespace std;
#if 1
int main(int argc, char** argv)
{
        int test_case;
        int T;
        /* 
        The freopen function below opens input.txt in read only mode and 
        sets your standard input to work with the opened file. 
        When you test your code with the sample data, you can use the function
        below to read in from the sample data file instead of the standard input.
        So. you can uncomment the following line for your local test. But you
        have to comment the following line when you submit for your scores.
        */

        freopen("/home/dawid/SW Test/Algorytmy/SWTEST_3/sample_input.txt", "r", stdin);
        
        cin>>T;
        
        //cout<<T<<endl;
        /*
           Read each test case from standard input.
        */
      
        for(test_case = 1; test_case <= T; ++test_case)
        {

                /////////////////////////////////////////////////////////////////////////////////////////////
                /*
                        Please, implement your algorithm from this section.
                */
                /////////////////////////////////////////////////////////////////////////////////////////////
                int K = 0;
                string inputString;
                
                cin >> K;
                cin >> inputString;
                

                
                set<string> setSubStrings;
                //heap<string> h = make_heap<string>();
                
                for(int i = 0; i<inputString.length();i++)
                {
                    //string firstLetterOfSubstring;
                    string subString;
                    
                    //firstLetterOfSubstring.push_back(inputString[i]);
                    //setSubStrings.insert(firstLetterOfSubstring);
                    
                    
                    subString.push_back(inputString[i]);
                    setSubStrings.insert(subString);
                    
                    for(int j=i+1;j<inputString.length();j++)
                    {
                        subString.push_back(inputString[j]);
                        setSubStrings.insert(subString);
                        push_heap<string>(subString);
                    }
                    
                }
                
                string Answer;
                
                set<string>::iterator iter = setSubStrings.begin();
                
                
                advance(iter, K-1);
                //iter++;
                Answer = *(iter);
                
                // Print the answer to standard output(screen).
                cout << "#" << test_case << " " <<Answer.c_str()<< endl;
        }
        return 0;//Your program should return 0 on normal termination.
}
#endif
#if 0
#include <strstream>

set<string> setSubstrings;

void print(string str, int start, int end)
{
    int i;
    string substring("");
    char *pc = new char;
    
    for(i=start;i<=end;i++)
    {
        printf("%c",str[i]);
        //pc = str[i];
        //pc = &arr[i];
        substring.append(str,start,end+1);
    }
    //substring.append(&arr[start],end+1-start);
    cout<<">>>>>>>>"<<substring<<" --- "<< start<<"  === "<<end<<endl;
    setSubstrings.insert(substring);
    printf("\n");
}

void substrings(string str, int n)
{
    int pass, j, start, end;
    int no_of_strings = n-1;
    
    for(pass=0;pass<n;pass++)
    {   
        start = 0;
        end = start+pass;
        for(int j=no_of_strings;j>=0;j--)
        {
            print(str,start,end);
            start++;
            end = start + pass;
        }
    }
    no_of_strings--;
    
}

int main()
{
    string str = "love";
    substrings(str,4);
    
    set<string>::iterator it;
    int i = 0;
    for(it=setSubstrings.begin();it!=setSubstrings.end();it++)
    {   
        
        cout<< i <<" -- "<< (*it)<<endl;
        i++;
    }
    return 0;
}
#endif