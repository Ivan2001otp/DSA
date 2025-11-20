#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool kLengthApart(vector<int> &nums, int k)
    {

        int n = nums.size();
        int prev = -1;
        bool flag = true;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
            {

                if (prev == -1)
                {
                    prev = i;
                }
                else
                {
                    flag = ((i - prev - 1) >= k);
                    if (!flag)
                        break;
                    else
                    {
                        prev = i;
                    }
                }
            }
        }

        return flag;
    }
};