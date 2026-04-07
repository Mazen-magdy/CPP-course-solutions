#include <iostream>
#include <cstdlib>
#include <string.h>
#include <stack>

using namespace std;

string removeKdigits(string num, int k) {
    if( k == num.size())
    {
        string temp = "0";
        return temp;
    }
    stack<char> ans;
    ans.push(num[0]);
    for( int i = 1; i < num.size(); ++i)
    {
        if( !ans.empty() && num[i] < ans.top() )
        {
            while( k > 0 && !ans.empty() )
            {
                if ( num[i] < ans.top())
                {
                    //cout<<ans.top();
                    ans.pop();
                    k--;
                }
                else
                    break;

            }

        }

        if(ans.empty())
        {
            if(num[i] == '0')
                continue;
        }
        ans.push(num[i]);


    }

    string temp ="";
    while( !ans.empty() )
    {
        temp += ans.top();
        ans.pop();
    }
    for ( int i = 0 ; i < temp.size()/2 ; ++i)
    {
        char x = temp[i];
        temp[i] = temp[temp.size()-1-i];
        temp[temp.size()-1-i] = x;
    }

    if (k > temp.size()) return "0"; // that means we will remove the whole number

    if(k > 0 )
    {
        temp.erase(temp.size()-k,k);
    }
    return temp.size() == 0? "0" : temp; //to not return an empty string

}

int main()
{
string num = "1432219"; int k = 3;
cout<<removeKdigits(num, k);

}
