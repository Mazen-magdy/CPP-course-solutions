
#include <iostream>
#include <iterator>
#include <vector>


using namespace std;


int maxProduct(vector<int>& nums)
{
    int neg = 1;
    int curr = 1;
    int ans = nums[0];
   // bool flag = 1; // 1 means we are at a pos element
    int s = nums.size();
    bool onlyOne = 0;
    int lol = 0;
    int beforeNeg = 1;
    for ( int i = 0; i < s; ++i)
    {
        // -3, -2,0,1
        //cout<<"index "<<i<<" curr "<<curr<<endl;
        curr *= nums[i];
        
        if ( curr < 0 && neg == 1 )
        { 
            neg = nums[i];
            onlyOne = 1;
            lol = i;
            
        }
        
        
        else if (  curr  < 0 && neg != 1)
        {
            ans = max( curr/(neg*beforeNeg), ans);
            
        }
        if ( curr == 0)
        {
            ans = max ( curr, ans);
            curr = 1;
            neg = 1;
            beforeNeg = 1;
            
            continue;
        }
        if ( nums[i] < 0 && i != lol )
            onlyOne = 0;


        if ( neg == 1)
            beforeNeg *= nums[i];

        ans = max ( ans, curr);
    }
    
    if ( onlyOne )
    {
        curr = 1;
        int ans2 = nums[0];
        for ( int i = 0; i < s; ++i)
        {
            curr *= nums[i];
            if ( curr <=  0 )
            {
                ans2 = max ( ans2, curr);
                curr = 1;
                continue;
            } 
            
            ans2 = max ( ans2, curr );
        }
        
        ans = max(ans2,ans);
    }
    return ans;

}

int main ()
{  
    vector<int>nums = { 0,-1,4,-4,5,-2,-1,-1,-2,-3,0,-3,0,1,-1,-4,4,6,2,3,0,-5,2,1,-4,-2,-1,3,-4,-6,0,2,2,-1,-5,1,1,5,-6,2,1,-3,-6,-6,-3,4,0,-2,0,2};
    cout<<maxProduct(nums)<<endl;
}

        



