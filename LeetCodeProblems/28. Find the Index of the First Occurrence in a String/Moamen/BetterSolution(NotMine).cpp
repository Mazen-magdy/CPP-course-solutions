

#include <iostream>

using namespace std;

int strStr(std::string haystack, std::string needle)
{
    for (int i = 0; i <= haystack.length() - needle.length(); ++i)
    {
        if (haystack.substr(i, needle.length()) == needle)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    string haystack = "aaa";
    string needle = "aaa";
    cout << strStr(haystack, needle) << endl;
    return 0;
}