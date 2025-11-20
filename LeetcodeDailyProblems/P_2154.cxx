#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/keep-multiplying-found-values-by-two/?envType=daily-question&envId=2025-11-19
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        /*
        int n = nums.size();
        unordered_map<int,int>mp;
        for(auto a : nums) {
            mp[a]=1;
        }
        
        while(mp[original]) {

            original *=2;
        }

        return original;
        */
        int i = 0;
        int n = nums.size();
        while(i<n) {

            if (original == nums[i]) {
                original*=2;
                i=0;
            } else {
                ++i;
            }
        }

        return original;
    }
};