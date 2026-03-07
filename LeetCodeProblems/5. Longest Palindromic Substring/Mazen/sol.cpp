/**
 * *************************
 * Accepted 
 * run time: 2215ms
 * memory usage: 553.06MB
 * *************************
 * Algorithm: Brute Force
 * Description:
 * 1. Iterate though the string and consider each character as a center of a palindrome.
 * 2. Iteration is done in 0.5 steps to consider both odd and even length palindromes.
 * 3. For each center, expand outwards and check if the characters on both sides are the same. If they are, add them to the buffer string.
 * 4. If the buffer string is longer than the longest palindrome found so far, update the longest palindrome.
 * 5. Return the longest palindrome found.
 */


#include <iostream>
#include <string>
#include <math.h>

using namespace std;

string longestPalindrome(string s) {
    string longest = "";
    if(s.length() == 1)
        return s;
    for(float c = 0; c < s.length() - 1 ; c+=0.5)
    {
        string buffer = (c - floor(c) == 0.5) ? "" : string(1, s[(int)floor(c)]);
        int offset = c - s.length()/2;
        int center_offset = 0;
        for(int i = 1; i < floor((s.length()/2 - abs(offset) +1)); i++)
        {
            // if(c-i < 0 || c+i >= s.length())
            //     break;
            if(s[(int)ceil(c-i)] == s[(int)floor(c+i)]) // this is the case for odd length palindromes - flow in both directions
                buffer = s[(int)ceil(c-i)] + buffer + s[(int)floor(c+i)];
            // else if(s[c-i] == s[c+i - 1] ) // this is the case for even length palindromes - flow in left direction
            //     {
            //         buffer = s[c-i] + buffer ;
            //         center_offset--;
            //     }
            // else if(s[c-i + 1] == s[c+i])   // this is the case for even length palindromes - flow in right direction
            //     {
            //         buffer =  buffer + s[c+i];
            //         center_offset++;
            //     }
            else 
                break; 
        }
        if(buffer.length() > longest.length())
            longest = buffer;
    }
    return longest;
}

int main()
{
    string s = "bccb";
    cout<< "start..." << endl;
    cout << longestPalindrome(s) << endl;
    return 0;
}