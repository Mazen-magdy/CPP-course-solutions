#include <iostream>

using namespace std;

// This function returns an array where each element is the product of all
// numbers in the original array except the number at that index.
//
// Idea:
// 1) Build a prefix product array (leftProd) where each index stores
//    the product of all elements from the start up to that index.
// 2) Build a suffix product array (rightProd) where each index stores
//    the product of all elements from that index to the end.
// 3) For each position i, multiply the product of everything on the left
//    (leftProd[i-1]) with everything on the right (rightProd[i+1]).
//
// Example:
// nums = [1,2,3,4]
// leftProd  = [1,2,6,24]
// rightProd = [24,24,12,4]
//
// result[0] = rightProd[1]
// result[n-1] = leftProd[n-2]
// result[i] = leftProd[i-1] * rightProd[i+1]
//
// This avoids using division and computes the result in O(n) time.

vector<int> productExceptSelf(vector<int> &nums)
{

    if (nums.size() == 2)
    {
        int temp = nums[0];
        nums[0] = nums[1];
        nums[1] = temp;
        return nums;
    }

    int prod = 1;

    int *leftProd = new int[nums.size()];
    for (int i = 0; i < nums.size(); i++)
    {
        prod = prod * nums[i];
        leftProd[i] = prod;
    }

    prod = 1;

    int *rightProd = new int[nums.size()];
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        prod = prod * nums[i];
        rightProd[i] = prod;
    }

    nums[0] = rightProd[1];
    nums[nums.size() - 1] = leftProd[nums.size() - 2];

    for (int i = 1; i < nums.size() - 1; i++)
    {
        nums[i] = leftProd[i - 1] * rightProd[i + 1];
    }

    return nums;
}

int main()
{

    vector<int> nums = {1, 0};
    productExceptSelf(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << ", ";
    }
    cout << endl;
}