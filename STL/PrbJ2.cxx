#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, Q;
    cin >> N;
    vector<int> v(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    stack<int> st;

    int n = v.size();

    cin >> Q;
    vector<int> nge(v.size(), -1);

    for (int i = n - 1; i >= 0; i--)
    {

        if (st.empty())
        {
            st.push(i);
            continue;
        }

        while (!st.empty() && v[i] >= v[st.top()])
        {
            st.pop();
        }

        if (!st.empty())
        {
            nge[i] = st.top();
        }

        st.push(i);
    }

    while (Q--)
    {
        int i;
        cin >> i;
        i--;
        if (nge[i] == -1)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << nge[i] + 1 << endl;
        }
    }

    return 0;
}