#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int N;
    cin >> N;
    string S;
    cin >> S;

    stack<char> st;
    string ans = "";
    for (int i = 0; i < N; i++)
    {

        if (S[i] == '"')
        {
            if (st.empty())
            {
                st.push('"');
                ans.push_back('"');
            }
            else
            {
                st.pop();
                ans.push_back(
                    '"');
            }
        }
        else if (S[i] == ',')
        {
            if (!st.empty())
            {
                ans.push_back(',');
            }
            else
            {
                ans.push_back('.');
            }
        }
        else
        {
            ans.push_back(S[i]);
        }
    }
    cout << ans << endl;
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}