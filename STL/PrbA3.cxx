#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int Q;
    cin >> Q;

    set<int> st;

    while (Q--)
    {
        string s;
        cin >> s;

        if (s == "insert")
        {
            int num;
            cin >> num;
            st.insert(num);
        }
        else if (s == "lower_bound")
        {
            int num;
            cin >> num;
            auto it = st.lower_bound(num);

            if (it != st.end())
            {
                cout << *it << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
        else if (s == "upper_bound")
        {
            int num;
            cin >> num;
            auto it = st.upper_bound(num);

            if (it != st.end())
            {
                cout << *it << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
        else
        {
            // find
            int num;
            cin >> num;
            auto it = st.find(num);
            if (it != st.end())
            {
                cout << "found" << endl;
            }
            else
            {
                cout << "not found" << endl;
            }
        }
    }
    return 0;
}