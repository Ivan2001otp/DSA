#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/greatest-sum-divisible-by-three/?envType=daily-question&envId=2025-11-23

int solve(int index, int remain, vector<int>& nums, vector<vector<int> > &t) {
    if (index >= nums.size()) {

        if (remain == 0) {
            return 0;
        }

        return INT_MIN;
    }


    if (t[index][remain] != -1) {
        return t[index][remain];
    }

    int take = nums[index] + solve(index+1, (remain + nums[index])%3, nums, t);
    int notTake = solve(index+1, remain, nums, t);

    return t[index][remain] = max(take, notTake);
}


int maxSumDivThree(vector<int> &nums)
{
    int sum = 0;
    int n = nums.size();

    int computedSum = 0;
    for (int i = 0; i < n; i++)
    {
        computedSum += nums[i];
    }

    vector<vector<int> > dp(n + 1, vector<int>(computedSum + 1, -1));
    for (int i = 0; i < n; i++)
        f(i, nums, dp, sum);

    int result = INT_MIN;
    for (int i = 0; i <= computedSum; i++)
    {
        if (dp[n - 1][i] == 1)
        {
            if (i % 3 == 0)
            {
                result = max(result, i);
            }
        }
    }
    if (result == INT_MIN)
        return 0;
    return result;
}

int f2(vector<int> &nums)
{
    int n = nums.size();
    int currSum = 0;
    vector<int> remain1;
    vector<int> remain2;

    for (int i = 0; i < n; i++)
    {
        currSum += nums[i];

        if (currSum % 3 == 1)
        {
            cout << nums[i] << " element going to remainder1 vector" << endl;
            remain1.push_back(nums[i]);
        }
        if (currSum % 3 == 2)
        {
            {
                cout << nums[i] << " element going to remainder2 vector" << endl;
                remain2.push_back(nums[i]);
            }
        }

        if (currSum % 3 == 0)
        {
            return currSum;
        }

        for (auto &a : remain1)
        {
            cout << a << " ";
        }
        cout << endl;

        for (auto &a : remain2)
        {
            cout << a << " ";
        }
        cout << endl;
        sort(remain1.begin(), remain1.end());
        sort(remain2.begin(), remain2.end());

        int result = 0;
        int remainder = currSum % 3;

        if (remainder == 1)
        {
            int remove1 = (remain1.size() >= 1) ? remain1[0] : INT_MAX;
            int remove2 = remain2.size() >= 2 ? (remain2[0] + remain2[1]) : INT_MAX;
            cout << "for remainder - 1 case :" << endl;
            cout << "value of remove1 is " << remove1 << endl;
            cout << "value of remove2 is " << remove2 << endl;

            result = max(result, currSum - min(remove1, remove2));
        }
        else
        {
            int remove1 = remain2.size() >= 1 ? remain2[0] : INT_MAX;
            int remove2 = remain1.size() >= 2 ? (remain1[0] + remain1[1]) : INT_MAX;
            cout << "for remainder - 1 case :" << endl;
            cout << "value of remove1 is " << remove1 << endl;
            cout << "value of remove2 is " << remove2 << endl;

            result = max(result, currSum - min(remove1, remove2));
        }

        return result;
    }
}
/*
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {

        int n = nums.size();
        int currSum  = 0;
        vector<int>remain1;
        vector<int>remain2;

        for(int i=0;i<n;i++) {
            currSum += nums[i];

            if (nums[i] % 3 == 1) {
                remain1.push_back(nums[i]);
            } else if (nums[i] % 3 == 2) {
                remain2.push_back(nums[i]);
            }
        }

        if (currSum % 3 ==0) {
            return currSum;
        }

        sort(remain1.begin(), remain1.end());
        sort(remain2.begin(), remain2.end());

        int result = 0;
        int remainder = currSum % 3;

        if (remainder==1) {
            int remove1 = (remain1.size()>=1) ? remain1[0] : INT_MAX;
            int remove2 = remain2.size()>=2 ? (remain2[0] + remain2[1]) : INT_MAX;
            result = max(result, currSum - min(remove1, remove2));
        } else {
            int remove1 = remain2.size() >=1 ? remain2[0] : INT_MAX;
            int remove2 = remain1.size() >=2 ? (remain1[0]+remain1[1]) : INT_MAX;
            result = max(result, currSum - min(remove1, remove2));
        }


        return result;

    }
};
*/
int main()
{
    vector<int> v = {1, 2, 3, 4, 4};
    // cout << maxSumDivThree(v) << endl;
    cout << f2(v) << endl;
    return 0;
}