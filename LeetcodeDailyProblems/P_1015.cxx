#include <bits/stdc++.h>
#include <map>
#include <unordered_map>
using namespace std;

// https://leetcode.com/problems/smallest-integer-divisible-by-k/?envType=daily-question&envId=2025-11-25
int f(int k)
{
    if (k == 2 || k == 5)
        return -1;

    int rem = 0;
    unordered_map<int, int> mp;

    for (int i = 0; i < 100; i++)
    {
        rem = (rem * 10 + 1) % k;
        mp[rem]++;
    }

    for (int i = 0; i < mp.size(); i++)
    {
        cout << mp[i].first << "->" << mp[i].second << endl;
    }

    return 0;
}
int smallestRepunitDivByK(int k)
{
    if (k == 2 || k == 5)
        return -1;

    int rem = 0;
    unordered_map<int, int> mp;

    int c = 0;
    bool flag = false;

    for (int i = 0; i <= k; i++)
    {
        rem = (rem * 10 + 1) % k;
        ++c;
        if (rem == 0)
        {
            flag = true;
            break;
        }
        if (!mp[rem])
        {
            mp[rem] = 1;
        }
        else
        {
            break;
        }
    }

    for (auto a : mp)
    {
        cout << a.first << "->" << a.second << endl;
    }

    if (flag)
    {
        return c;
    }

    return -1;
}
int main()
{
    f(7);
    return 0;
}