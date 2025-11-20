#include <bits/stdc++.h>
using namespace std;
#define nl endl;
typedef long long ll;

// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/description/?envType=daily-question&envId=2025-11-03

int minCost(string colors, vector<int> &neededTime)
{
    int n = time.size();
    int cnt = 0;

    for (int i = 1; i < n; i++)
    {
        if (colors[i] == colors[i - 1])
        {
            cnt += min(time[i], time[i - 1]);
            time[i] = max(time[i], time[i - 1]);
        }
    }
    return cnt;
}

int main()
{
    string colors = "aaaaaaaaaaaaaa";
    vector<int> neededTime = {1, 3, 6, 5, 4, 5, 4, 4, 2, 8, 3, 10, 6, 6};
    cout << minCost(colors, neededTime) << endl;
    return 0;
}