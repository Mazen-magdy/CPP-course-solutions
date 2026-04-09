#include <iostream>
#include <string.h>
using namespace std;





std::string convert(std::string s, int numRows)
{
    if ( s.size() <= numRows || numRows == 1 ) return s;
    int siz = s.size();
    int pattern = 2*(numRows-1);
    string ans = "";
    //add the first row;
    for ( int i = 0; i < siz; i+=pattern )
    {
        ans += s[i];
    }
    int j, avail_char_pos, m = 1; // now we start adding the middle and diagonal elements so we start from second row
    for ( int i = 0; i < numRows-2; ++i)
    {
        avail_char_pos = i + 1; // this just makes so that at the second our our s string (beggining of middle and diag charcter)
        // we start from the second available char which is s[1] then at next row its s[2] and so on
        j = avail_char_pos;
        while ( j < siz)
        {
            ans += s[j];
            j += (pattern - m -1);
            if (j >= siz)
                break;
            ans += s[j];
            j += m +1;
        }
        m += 2;
    }
    // add last row
  for ( int i = numRows-1; i < siz; i += pattern)
    {
        ans += s[i];
    }
    return ans;
}


int main()
{
    string s = "ab";
    cout<<convert(s,1);

}
