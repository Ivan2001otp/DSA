#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// trailing zeros concept.... occurence of 5 is smaller than 2....
// biweekly 156 - revisit all easy-medium probs
int minOperations(vector<int> &nums)
{
    /*
    You are given an array nums of size n, consisting of non-negative integers. Your task is to apply some (possibly zero) operations on the array so that all elements become 0.

In one operation, you can select a subarray [i, j] (where 0 <= i <= j < n) and set all occurrences of the minimum non-negative integer in that subarray to 0.

Return the minimum number of operations required to make all elements in the array 0.
    */
    stack<int> st;
    int ans = 0;

    for (int a : nums)
    {
        while (!st.empty() && st.top() > a)
        {
            st.pop();
        }

        if (st.empty() || st.top() < a)
        {
            // incoming element should be greater
            if (a > 0)
                ans++;
            st.push(a);
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout << "testing" << endl;
    vector<int> v = {3, 1, 2, 1};
    minOperations(v);
    return 0;
}