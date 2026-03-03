#include <iostream>
#include <vector>

    //          ACCEPTED
    // *****************************
    // *   Runtime: 23 ms         *
    // *   Memory: 20.52 MB       *
    // *****************************
    //Alogorithm:
    //1-start from the end
    //2-get the farest index can make u jump to the end
    //3-jump++
    //4-let this index is the end
    //5-repeat again

using namespace std;

int jump(vector<int>& nums)
{
    int n=nums.size()-1;
    int x=0,test,jumpp=0;
    while(n>0)
    {
        for(int i=n-1;i>=0;i--)
        {
            test=n-i;
            if(nums[i]>=test)x=i;
        }
        n=x;
        jumpp++;
    }
    return jumpp;
}

    int main(){
        //test case
    vector <int> nums={2,3,1,1,4};
    int jumpp=jump(nums);
    cout<<jumpp;

    return 0;
    }
