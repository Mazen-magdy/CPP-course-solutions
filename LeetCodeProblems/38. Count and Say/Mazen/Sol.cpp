/*
    ACCEPTED
    // *****************************
    // *   Runtime: 0 ms          *
    // *   Memory: 6.1 MB        *
    // *****************************
    Alogorithm:
    1. We uses Recursion to get the previous string
    2. We count the number of repeated characters and then add them to the buffer string as below
    3. Inside the loop there is an edge conditions handlers to handle the first and last characters of the string and the repitition
        i == 0     i == last number     s[i] == s[i-1]      Action
        1          x                    x                   counter++ and continue                                                  line 30
        0          0                    0                   counter++ and buffer += to_string(counter) + s[i-1] and counter = 1     line 46
        0          0                    1                   buffer += to_string(counter) + s[i-1] and counter = 1                   line 39
        0          1                    0                                                                                           line 49
        0          1                    1                   counter ++ and buffer += to_string(counter) + s[i-1] and counter = 1    line 48
*/
#include <iostream>
#include <string>
using namespace std;

string countAndSay(int n) {
    if(n==1)    
        return "1";
    int counter = 0;
    string buffer = "";
    string s = countAndSay(n-1);
    for(int i = 0;i<s.length();i++)
    {
        if(i == 0)
        {
            counter++;
            if(i == s.length() - 1 )
            {
                buffer += to_string(counter) + s[i];
            }
            continue;
        } 
        if(s[i] == s[i-1] && i != s.length()-1)
        {
            counter++;
            continue;
        }
        else if(s[i] != s[i-1])
        {
            buffer += to_string(counter) + s[i-1];
            counter = 1;
            if(i == s.length() -1)
            {
                buffer += to_string(counter) + s[i];
            }
        }
        else 
        {
            counter++;
            buffer += to_string(counter) + s[i-1];
            counter = 1;
        }
    }
    return buffer;
}

int main()
{
    int n;
    cin >> n;
    cout << countAndSay(n) << endl;
    return 0;
}