#include <iostream>
#include <vector>

using namespace std;
int helpa ( vector<int>& nums, int goal  )
{
    int arrs =0, sum = 0, left = 0;
    for ( int i = 0; i < nums.size(); ++i)
    {
        sum += nums[i];


        while ( sum > goal && left < nums.size())
        {
            sum -= nums[left];
            left++;

        }
        if ( left > i  )
            continue;

        arrs += i - left + 1;
    }
    return arrs;
}
int numSubarraysWithSum(vector<int>& nums, int goal)
{
   // if ( goal == 0) return helpa ( nums , goal);
  // cout<<helpa( nums,goal )<<" - "<<helpa( nums,goal -1 )<<endl;
    return (   helpa( nums,goal ) - helpa( nums,goal -1 ))  ;
}

int main ()

{
    vector<int>nums = { 1,1,1,1,1,1};
    int goal = 0;
    cout<<numSubarraysWithSum(nums,goal);
}
