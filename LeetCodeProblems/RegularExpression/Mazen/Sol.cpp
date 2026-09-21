#include <iostream>
#include <string>
using namespace std;

bool isMatch(string s, string p) {
    // if(p[p.length()-1] == '*') {  
    //     int pi = 0;
    //     for(int i =0;i<s.length();i++)
    //     {
    //         if(s[i] == p[pi] || p[pi] == '.')
    //             {pi++;continue;}
    //         else if(p[pi] == '*')
    //         {pi = 0;i--;}
    //         else
    //             return false;
    //     }
    // }
    // else if(p[p.length()-1] != '*') {
        int pi = 0;
        int stucker = -1;
        for(int i = 0; i<s.length();i++)
        {
            if(pi >= p.length()) return false;
            if((s[i] == p[pi] || p[pi] == '.'))
                {
                    if(i == s.length()-1)
                    {
                    if(pi != p.length()-1)
                    {
                        if(p[pi+1] == '*')
                        {
                            if(pi+1 == p.length()-1)
                                return true;
                            else if(p[pi+2] == p[pi] )
                            {
                                pi += 1;
                                i--;
                            }
                            else
                                return false;
                        }
                        else 
                            return false;
                    }
                    }
                    pi++;
                    continue;
                }
            else if(p[pi] == '*')
            {

                stucker = pi;
                pi = pi-1;
                i--;
            }
            else
            {
            
                if(p[pi+1] == '*')
                {
                    pi += 2;
                    stucker = pi-1;
                    i--;
                }
                else if(stucker == pi-1)
                {
                    if(p[pi+1] == '*')
                    {
                        pi += 2;
                        stucker = pi-1;
                        i--;
                    }
                    else 
                        return false;
                }
            }
        }
    if(pi != p.length())
        return false;
    // }
    return true;
}

int main() {
    string s, p;
    cin >> s >> p;
    cout << isMatch(s, p) << endl;
    return 0;
}