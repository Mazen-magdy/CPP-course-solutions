/*
    Solution fails at 33 / 110
    ********** ALGORITHM **********
    1. We start at the first index and we check how far we can jump from there.
    2. We then check all the indices we can jump to and we find the one that can jump the farthest.
    3. We then jump to that index and repeat the process until we reach the end of the array.
    4. But we check if we can jump to the end of the array from the current index, if we can then we jump to the end of the array and we are done.
*/

#include <iostream>
#include <vector>
using namespace std;

int jump(vector<int>& nums) {
    int jumps = 0;
    int i = 0;
    int n = nums.size();
    if(n == 1)
        return 0;
    while(i != n)
    {
        int max_jump = nums[i];
        if (max_jump + i >= n-1)
        {
            jumps ++;
            return jumps;
        }
        int max = nums[i+ max_jump];
        int max_index = i + nums[i];
        for(int j = i+1; j<i+nums[i]+1; j++)
        {
            if(max < nums[j])
            {
                max = nums[j];
                max_index = j;
            }
        }
        if(i + max_index > n -1 )
            i = n-1;
        else 
            i = max_index;
        jumps++;
    }
    return jumps;
}

int main()
{
    vector<int> nums = {5,9,3,2,1,0,2,3,3,1,0,0};
    cout << jump(nums) << endl;
    return 0;
}