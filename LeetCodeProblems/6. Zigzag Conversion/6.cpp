#include <iostream>
#include <string.h>

using namespace std;

std::string convert(std::string s, int numRows)
{
    if (numRows == 1) return s;
    int cols = s.size() + 1;
    char** parse = new char*[numRows];
    for ( int  i = 0; i < numRows; ++i)
    {
        parse[i] = new char[cols];
        for ( int j = 0; j < cols; ++j)
        {
            parse[i][j] = '&';
        }
    }


    int i = 0, row =0 , col =0;
    int isDia =0;
    while( i < cols -1)
    {
      if (isDia == 0 )
      {
        parse[row][col] = s[i];             /* P   A   H   N
                                               A P L S I I G
                                               Y   I   R
                                               PAYPALISHIRING*/
        row++;
        i++;
        if (row == numRows)
            {isDia = 1;
            row --;}
      }
      else if ( isDia == 1)
      {
        row --;
        col++;
        parse[row][col] = s[i];
        i++;
        if( row == 0)
            {isDia = 0;
            row++;}

      }
   }
  /* for ( int i = 0; i < numRows; ++i)
    {
        for ( int j = 0; j < cols; ++j)
        {
            std::cout<<parse[i][j]<<" ";
        }
        std::cout<<std::endl;
    } */
   string ans = "";
   for ( int i = 0; i < numRows; ++i)
   {
       for ( int j = 0; j < cols; ++j)
       {
           if ( parse[i][j] != '&' )
            ans += parse[i][j];
       }
   }

return ans;
}


int main()
{
string s = "PAYPALISHIRING";
//cout<<s.size();

cout<<convert(s,5);

}
