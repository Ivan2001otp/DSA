// https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k/description/?envType=daily-question&envId=2025-11-27
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    // time complexity : O(k * n/k) => O(n)
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long>prefixSum(n,0);

        prefixSum[0] = nums[0];

        for(int i=1;i<n;i++) {
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }

        long long result = LLONG_MIN;

        for(long long d =0;d<k;d++) {

            long long currSum = 0;
            long long start = d;
            while(start<n && start + k -1 <n) {
                int end = start+k-1;
                long long subArrSum = prefixSum[end]-(start>0 ? prefixSum[start-1] : 0);
                currSum = max(subArrSum, currSum+subArrSum);
                result = max(result, currSum);
                start+=k;
            }
        }

        return result;
    }
};