#include <iostream>
#include <unordered_map>
#include <vector>


using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
    vector<int>two_indices;
    unordered_map<int,int>hash;
    int s = nums.size();
    for ( int i = 0; i < s; ++i)
    {
        if ( hash.find( target - nums[i] ) != hash.end() )
        {
            // 9 - 7 = 2 which we found
            two_indices.push_back(hash[target - nums[i]]);
            two_indices.push_back(i);
            break;
        }
        else
        {
            hash[nums[i]] = i;
            // [2] = 0;
        }
    }
    return two_indices;
}



int main()
{

vector<int>nums = {-1 , 10, 2, 4};
int target = 9;
vector<int>ans = twoSum( nums, target );
cout<<ans.size()<<endl<<endl;
cout<<ans[0]<<" "<<ans[1]<<endl;
unordered_map<int,int> test;

}
