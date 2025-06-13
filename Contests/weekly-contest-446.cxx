#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// study this
/*
https://leetcode.com/problems/find-x-value-of-array-i/solutions/6668779/java-c-python-dp-o-k-space/
*/
int maximumPossibleSize(vector<int> &nums)
{
    stack<int> st;
    int n = nums.size();

    int i = n - 1;

    while (i >= 0)
    {
        if (st.empty())
        {
            st.push(nums[i]);
        }
        else
        {
            while (!st.empty() && st.top() < nums[i])
            {

                st.pop();
            }

            st.push(nums[i]);
        }
        i--;
    }

    return st.size();
}

long long calculateScore(vector<string> &instructions, vector<int> &values)
{
    ll score = 0;
    int N = instructions.size();
    unordered_map<int, bool> mp;
    int i = 0;

    while (i < N && i >= 0 && !mp[i])
    {
        mp[i] = true;
        cout << "index : " << i << " -> " << instructions[i] << endl;
        if (instructions[i] == "jump")
        {
            i = i + values[i];
        }
        else
        {
            score += values[i];
            i++;
        }
    }

    return score;
}

void solve()
{
    vector<int> v = {1, 2, 3};
    cout << maximumPossibleSize(v) << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}