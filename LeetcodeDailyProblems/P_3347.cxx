#include <bits/stdc++.h>
using namespace std;
#define nl endl;

int maxFrequency2(vector<int> &nums, int k, int ops)
{
    int maxVal = *max_element(nums.begin(), nums.end()) + k;
    vector<int> diff(maxVal + 2, 0);
    unordered_map<int, int> freq;
    int l, r;
    for (auto a : nums)
    {
        freq[a]++;

        l = max(a - k, 0);
        r = min(a + k, maxVal);
        diff[l]++;
        diff[r + 1]--;
    }

    int res = 1;
    for (int target = 0; target <= maxVal; target++)
    {
        diff[target] += (target > 0 ? diff[target - 1] : 0);
        int targetFreq = freq[target];
        int requiredFreq = diff[target] - targetFreq;
        int maxPossibleFreq = min(ops, requiredFreq);

        res = max(res, targetFreq + maxPossibleFreq);
    }

    return res;
}


// https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-ii/description/?envType=daily-question&envId=2025-10-22
int maxFrequency(vector<int> &nums, int k, int numOperations)
{
    int n = nums.size();
    int l, r;

    unordered_map<int, int> freq;
    map<int, int> diff;
    for (int i = 0; i < n; i++)
    {
        freq[nums[i]]++;

        l = nums[i] - k;
        r = nums[i] + k;

        diff[nums[i]] += 0;
        diff[l]++;
        diff[r + 1] -= 1;
    }

    int cummalative = 0;
    int result = 1;

    int targetFreq;
    for (auto it = diff.begin(); it != diff.end(); it++)
    {
        int target = it->first;
        it->second += cummalative;

        targetFreq = freq[target];
        int needConversion = it->second - targetFreq;
        int maxPossibleFreq = min(needConversion, numOperations);
        result = max(result, targetFreq + maxPossibleFreq);

        cummalative = it->second;
    }

    return result;
}

int main()
{
    vector<int> v = {5, 11, 20, 20};
    int k = 5;
    int o = 1;
    maxFrequency(v, k, 0);
    return 0;
}