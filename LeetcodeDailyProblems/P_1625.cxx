#include <bits/stdc++.h>
using namespace std;
#define nl endl;
typedef long long ll;

// https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/description/?envType=daily-question&envId=2025-10-19
string rotate(string s, int b)
{
    reverse(s.begin(), s.end());
    reverse(s.begin(), s.begin() + b);
    reverse(s.begin() + b, s.end());
    return s;
}

string findLexSmallestString(string s, int a, int b)
{
    queue<string> q;
    q.push(s);

    string small = s;
    map<string, int> vis;
    vis[s] = 1;

    while (!q.empty())
    {
        string curr = q.front();
        q.pop();

        if (curr < small)
        {
            small = curr;
        }

        // add
        string temp = curr;
        for (int i = 1; i < temp.size(); i += 2)
        {
            temp[i] = ((curr[i] - '0' + a) % 10) + '0';
        }

        if (!vis[temp])
        {
            vis[temp] = 1;
            q.push(temp);
        }

        // rotate;
        temp = rotate(curr, b);
        if (!vis[temp])
        {
            vis[temp] = 1;
            q.push(temp);
        }
    }

    return small;
}

int main()
{
    string s = "0011";
    int a = 4, b = 2;

    cout << findLexSmallestString(s, a, b);
    return 0;
}