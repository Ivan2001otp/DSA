#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/1-bit-and-2-bit-characters/description/?envType=daily-question&envId=2025-11-18
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();

        int i = 0;
        for(;i<n-1;) {
            if (bits[i]==0) {
                i+=1;
            } else {    
                i+=2;
            }
        }

        return i==n-1 ;
    }
};