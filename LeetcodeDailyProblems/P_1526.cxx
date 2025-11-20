// https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/submissions/1815799365/?envType=daily-question&envId=2025-10-30
#include <bits/stdc++.h>
using namespace std;
#define nl endl;
typedef long long ll;

int minNumberOperations(vector<int> &target)
{
    int n = target.size();

    int count = 0;
    int prev = 0;
    for (int i = 0; i < n; i++)
    {

        // check sign;
        if ((prev < 0 && target[i] > 0) || (prev > 0 && target[i] < 0))
        {
            count += target[i];
            continue;
        }

        if (abs(target[i]) > abs(prev))
        {
            count += (target[i] - prev);
        }
        else if (abs(target[i]) <= abs(prev))
        {
            count += 0;
        }

        prev = target[i];
    }

    return count;
}