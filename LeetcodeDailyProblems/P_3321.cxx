#include <bits/stdc++.h>
using namespace std;
#define nl endl;
typedef long long ll;
// https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-ii/description/?envType=daily-question&envId=2025-11-05
class Solution {
    long long sum =0;
    set<pair<int,int>> mainSet;
    set<pair<int,int>> secSet;

public:

    void removeFromSet(const pair<int,int>&p, int x) {
            if (mainSet.find(p) != mainSet.end()) {
                sum -= (1LL*p.first*p.second);
                mainSet.erase(p);

                if (secSet.size() >0) {
                    // pick the largest
                    auto largest = *secSet.rbegin();
                    secSet.erase(largest);
                    mainSet.insert(largest);
                    sum += 1LL * largest.first * largest.second;
                }
            } else {
                secSet.erase(p);
            }
    }

    void addToSet(const pair<int,int>&p, int x) {

        if ((mainSet.size() < x ) || (p > *mainSet.begin())) {
            sum += 1LL * p.first * p.second;
            mainSet.insert(p);

            if (mainSet.size() > x) {
                auto smallest = *mainSet.begin();
                sum -= 1LL * smallest.first * smallest.second;
                mainSet.erase(smallest);
                secSet.insert(smallest);
            }
        } else {
            secSet.insert(p);
        }
    }


    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        
        sum = 0;
        vector<long long >result;
        unordered_map<int,int>mp;
       

        int i=0,j=0;
        int n = nums.size();

        while(j < n) {

            if (mp[nums[j]] > 0) {
                removeFromSet({mp[nums[j]], nums[j]}, x);
            }

            mp[nums[j]]++;
            addToSet({mp[nums[j]], nums[j]},x);

            if (j-i + 1 == k) {
                
                result.push_back(sum);
                removeFromSet({mp[nums[i]], nums[i]}, x);
                mp[nums[i]]--;

                if (mp[nums[i]]==0){
                    mp.erase(nums[i]);
                } else {
                    addToSet({mp[nums[i]], nums[i]}, x);
                }

                i++;
            }
            j++;
        }

        return result;
    }
};