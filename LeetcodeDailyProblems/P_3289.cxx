#include <bits/stdc++.h>
using namespace std;
#define nl endl;
typedef long long ll;

// https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/description
class Solution
{
public:
    vector<int> getSneakyNumbers(vector<int> &nums)
    {
        int x = 0;
        for (auto a : nums)
        {
            x = x ^ a;
        }

        int n = nums.size();
        for (int i = 0; i < n - 2; i++)
        {
            x = x ^ i;
        }

        int diff_bit = x & -x;

        int xor1 = 0, xor2 = 0;
        for (auto a : nums)
        {
            if (a & diff_bit)
            {
                xor1 ^= a;
            }
            else
            {
                xor2 ^= a;
            }
        }

        for (int i = 0; i < n - 2; i++)
        {
            if (i & diff_bit)
            {
                xor1 ^= i;
            }
            else
            {
                xor2 ^= i;
            }
        }

        return {xor1, xor2};
    }
};