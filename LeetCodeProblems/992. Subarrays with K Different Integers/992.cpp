#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
int nsubarrays ( vector<int>&nums, int k )
{
    int left = 0;
    unordered_map<int,int> map;
    int ans = 0, unique = 0;
    int s = nums.size();
    for ( int r = 0; r < s; ++r )
    {
        if ( map.find(nums[r]) == map.end() )
        {
            unique++;
            map[nums[r]] = 1;
        }
        else
        {
            map[nums[r]]++;
        }
        while ( unique > k)
        {

            map[nums[left]]--;
            if ( map[nums[left]] == 0 )
               {
                   map.erase(nums[left]);
                   unique--;
               }
            left++;

        }
        ans += r - left + 1;
    }


    return ans;
}

int subarraysWithKDistinct(vector<int>& nums, int k)
{
  return nsubarrays( nums, k) - nsubarrays(nums, k-1);
}






int main()
{
    vector<int>nums = {1,2,1,3,4};
    int k = 3;
    cout<<subarraysWithKDistinct( nums, k );
}
