#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int Q;
    cin >> Q;
    stack<int> st;

    while (Q--)
    {
        string s;
        cin >> s;

        if (s == "push")
        {
            int ele;
            cin >> ele;
            st.push(ele);
        }
        else if (s == "top")
        {
            cout << st.top() << endl;
        }
        else
        {
            st.pop();
        }
    }

    return 0;
}