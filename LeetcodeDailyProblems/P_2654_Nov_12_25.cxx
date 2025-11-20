#include <bits/stdc++.h>
using namespace std;
#define nl endl;

// https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/?envType=daily-question&envId=2025-11-12
int minOperations(vector<int> &nums)
{

    int n = nums.size();
    int temp = 0;

    int c1 = 0;
    int ans = INT_MAX;

    int count1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 1)
            ++count1;
    }

    for (int i = 0; i < n - 1; i++)
    {
        temp = nums[i];
        for (int j = i + 1; j < n; j++)
        {
            if (__gcd(nums[j], temp) == 1)
            {
                c1 = j - i;
                ans = min(ans, c1 + (n - (1 + count1)));
                c1 = 0;
                break;
            }
            else
            {
                temp = __gcd(nums[j], temp);
                continue;
            }
        }
    }

    if (ans == INT_MAX)
        return -1;

    return ans;
}

int main()
{
    vector<int> nums = {6, 10, 15};
    cout << "Ans is " << minOperations(nums);
    return 0;
}