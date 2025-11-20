#include <bits/stdc++.h>
using namespace std;
#define nl endl;

int minOperations(vector<int> &nums)
{

    int ans = 0;

    stack<int> st;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {

        while (
            !st.empty() &&
            st.top() > nums[i])
        {
            ans++; // a dip in layer is detected that takes separate operation to reduce itself to zero.
            st.pop();
        }

        if ((st.empty() || st.top() != nums[i]) && nums[i] != 0)
        {
            st.push(nums[i]);
        }
    }

    return ans + st.size();
}

int main()
{
    // vector<int> v;
    // int ele;
    // for (int i = 0; i < 6; i++)
    // {
    //     cin >> ele;
    //     v.push_back(ele);
    // }

    // cout << minOperations(v) << endl;

    int n = 2;
    if (n == 1)
    {
        cout << "*" << endl;
        return 0;
    }
    else if (n == 2)
    {
        cout << " **" << endl;
        cout << "**" << endl;
        return 0;
    }
    int spaces = n - 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= spaces; j++)
        {
            cout << " ";
        }
        --spaces;
        for (int k = 0; k < n; k++)
        {
            if (i == 0 || i == n - 1)
            {
                // print full
                cout << "*";
            }
            else
            {
                if (k == 0 || k == n - 1)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
    return 0;
}