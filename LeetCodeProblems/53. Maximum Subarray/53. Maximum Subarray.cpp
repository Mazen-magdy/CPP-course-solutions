#include <iostream>
#include <vector>



using namespace std;


int maxSubArray(vector<int>& nums)
{
    int local_sum = nums[0], max_sum = nums[0];
    int  s = nums.size();
    for ( int i = 1; i < s; ++i)
    {
        local_sum = max( nums[i], local_sum + nums[i] );
        // if our number is bigger on its own then we can start with it its own subarray, otherwise put it with
        // the previous subarray
        if ( local_sum > max_sum )
        {
            max_sum = local_sum;
        }
    }
    return max_sum;
}



int main()
{
    vector<int>nums = {1,2,3,4,5,-3 , -2 ,10};
    cout<<maxSubArray(nums);
}
