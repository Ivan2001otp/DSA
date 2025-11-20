#include <bits/stdc++.h>
using namespace std;
#define nl endl;

// https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/description/?envType=daily-question&envId=2025-11-13
int maxOperations(string s)
{
    // 1001101
    int n = s.size();

    int one_count = 0;

    int res = 0;
    // set<int> st;
    // for (int i = 0; i < n; i++) {
    //     if (s[i] == '1') {
    //         ++one_count;
    //     } else {
    //         // res += one_count;
    //         if (st.count(one_count) == 0) {
    //             st.insert(one_count);
    //         }
    //     }
    // }

    // while (!st.empty()) {
    //     int ele = *st.begin();
    //     res += *st.begin();
    //     st.erase(ele);
    // }
    one_count = (s[0] == '1');
    for (int i = 1; i < n; i++)
    {
        if (s[i] == '1')
        {
            ++one_count;
        }
        else if (s[i - 1] == '1')
        {
            // but curr ele is '0'.
            res += one_count;
        }
    }

    return res;
}

int main()
{
    string s = "00111";
    cout << "ans is " << maxOperations(s);
    return 0;
}