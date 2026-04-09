#include <iostream>
#include <vector>

using namespace std;


vector<int> findClosestElements(vector<int>& arr, int k, int x)
{
    int s = arr.size();
    vector<int>diff(s);
    vector<int>elements;
    for ( int i = 0; i < s; ++i)
    {
        diff[i] = abs( arr[i] - x );
        //cout<<diff[i]<<endl;
    }
    //cout<<endl;
    int sum = 0;
    for ( int i = 0; i < s; ++i)
    {
        if ( elements.size() == k)
        {
            //cout<<"if statmenet "<<i<<endl;
            if ( sum - diff[i - k ] + diff[i] < sum  )
            {
                sum -= diff[ i - k ];
                sum += diff[ i ];
                elements.erase(elements.begin());
                elements.push_back(arr[i]);
            }

        }
        else
           {
               //cout<<"else statmenet "<<i<<endl;
              elements.push_back(arr[i]);
              sum += diff[i];
           }
    }
    return elements;

}






int main()
{
vector<int>m = {1,1,2,3,4,};
int k = 4, x = -1;
vector<int>sol = findClosestElements(m,k,x);
for ( int i = 0; i < sol.size(); ++i)
{
    cout<<sol[i]<<endl;
}
}
