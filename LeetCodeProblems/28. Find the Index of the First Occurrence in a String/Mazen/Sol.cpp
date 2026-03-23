/**
 * ACCEPTED 
 * RUNTIME : 3ms
 * MEMORY : 9.22MB
 */


#include <iostream>
#include <string>

using namespace std;

int strStr(string haystack, string needle) {
        if(needle.length() > haystack.length())
            return -1;
        for(int i = 0; i< haystack.length() - needle.length() + 1;i++)
        {
            for(int j = 0; j < needle.length();j++)
            {
                if(haystack[i+j] != needle[j])
                    break;
                else if(j == needle.length() - 1)
                    return i;
            }
        }
        return -1;
    }

int main(){
    string s1 = "ABCD";
    string s2 = "ABD";
    int result = strStr(s1,s2);
    cout <<result;
    return 0;
}