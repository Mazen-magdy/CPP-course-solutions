#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int x[] = {13,2,5,4,9,6,21,10};
    int target = 19 , left =0 , right=7, i = 0;
    std::sort(x[0],x[7]);
    
    while( i<8)
    {
        if(x[left]+x[right]>target)
        right--;
        else if(x[left]+x[right]<target)
        left++;
        else{
        cout<<x[left]<<" and "<<x[right]<<endl;
        break;}
        i++;
    }
    return 0;
}