#include <bits/stdc++.h>
using namespace std;
#define nl endl;
typedef long long ll;

// https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i/?envType=daily-question&envId=2025-11-04

class Solution
{
public:
    vector<int> findXSum(vector<int> &nums, int k, int x)
    {
        
        int n = nums.size();
        vector<int> freq(51, 0);
        vector<int> ans(n - k + 1, 0);

        for (int i = 0; i < k; i++)
            freq[nums[i]]++;

        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < 51; i++)
        {
            if (freq[i] > 0)
                pq.push(pair<int, int>(freq[i], i));
        }

        pair<int, int> tmp;
        int sm = 0;
        for (int i = 0; i < x && pq.size(); i++)
        {
            tmp = pq.top();
            pq.pop();
            sm += tmp.first * tmp.second;
        }

        ans[0] = sm;
        // second subarray onwards
        for (int i = 1; i < n - k + 1; i++)
        {
            freq[nums[i - 1]]--;
            freq[nums[k + i - 1]]++;

            priority_queue<pair<int, int>> pqn;

            for (int j = 0; j < 51; j++)
            {
                if (freq[j] > 0)
                    pqn.push(pair<int, int>(freq[j], j));
            }

            pair<int, int> tmp;
            int sm = 0;
            for (int k = 0; k < x && pqn.size(); k++)
            {
                tmp = pqn.top();
                pqn.pop();
                sm += tmp.first * tmp.second;
            }

            ans[i] = sm;
        }

        return ans;
    }
};