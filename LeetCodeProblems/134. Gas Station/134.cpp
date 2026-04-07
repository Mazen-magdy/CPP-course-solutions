#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
    int s = gas.size();
    vector<int>diff;
    int gSum = 0;
    int cSum = 0;
    for ( int i = 0 ; i < s ; ++i)
    {

            diff.push_back( gas[i] - cost[i] );
            gSum += gas[i];
           cSum += cost[i];




    }
    if ( cSum > gSum ) return -1;
    // if we dont return -1 then there must exist a solution
    int total = 0, index = 0;
    for ( int i = 0 ; i < s ; ++i)
    {
        total += diff[i];
        if( total < 0)
        {
            total = 0;
            index = i + 1;
        }
    }
    return index; }


int main()
{

    vector<int>gas = {1,2,3,4};
    vector<int>cost = {1,2,3,4};
    cout<<canCompleteCircuit(gas, cost);
}
