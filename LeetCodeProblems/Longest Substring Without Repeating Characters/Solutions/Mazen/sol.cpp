/* 
 ACCEPTED
*/
#include <iostream>
#include <string>
using namespace std;
int lengthOfLongestSubstring(string s) {
    string buffer =  "";
    string biggest = "";
    for(int i= 0;i<s.length();i++){
        char ch = s[i];
        int initial = i;
        for(int j=0;j<buffer.length();j++)
            if(buffer[j] == ch)
            {
                //problem
                // if(buffer.length()> biggest.length())
                //     biggest = buffer;
                i =i - buffer.length();
                buffer = "";
                break;

            }
        if (initial == i)
            buffer += ch;
        if(buffer.length()> biggest.length())
                    biggest = buffer;
    }
    int length =  biggest.length() ;
    return length;
}

int main()
{
    string s = "dvdf";
    string test = "b";
    cout<< test.length() << endl;
    cout<<lengthOfLongestSubstring(s);
    return 0;
}