#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/binary-prefix-divisible-by-5/?envType=daily-question&envId=2025-11-24
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {

        int n = nums.size();  
        vector<bool> visited(n);
        int num = nums[0];

        visited[0] = (num==0) ? true : false;
        num = 2*num + nums[1];

        for(int i=1;i<n;i++) {

            if (num % 5 == 0) {
                visited[i]=true;
            } else {
                visited[i]= false;
            }
            num = 2*(num) + nums[i];
        }

        return visited; 
    }
};