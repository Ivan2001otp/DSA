#include <bits/stdc++.h>
using namespace std;
    typedef long long ll;

int alternatingSum(vector<int> &nums)
{
    ll oddsum = 0;
    ll evensum = 0;

    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            evensum += nums[i];
        }
        else
        {
            oddsum += nums[i];
        }
    }

    return oddsum + evensum;
}


int longestSubsequence(vector<int>& nums) {
        bool isAllZero = true;
        int xorSum = 0;

        for(auto a : nums) {
            xorSum = xorSum xor a;

            if (a != 0) isAllZero = false;
        }

        if (isAllZero) return 0;

        return xorSum != 0 ? nums.size() : nums.size()-1;
    }©leetcode
int main()
{
    vector<int> v = {1, 3, 5, 7};
    cout << alternatingSum(v) << endl;
    return 0;
}