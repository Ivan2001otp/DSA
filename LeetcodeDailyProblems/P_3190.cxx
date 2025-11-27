
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        int n = nums.size();
        int c = 0;
        int ele1 = 0, ele2 = 0, ele3 = 0;

        for (int i = 0; i < n; i++)
        {
            ele1 = nums[i] % 3;
            ele2 = ele1 + ele1;
            ele3 = 3 - ele1;

            // c += (min({ele1, ele2, ele3}));
            c += min(ele1, ele3);
        }

        return c;
    }
};