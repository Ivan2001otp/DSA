#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isOdd(int num)
{
    return num & 1;
}

bool isEven(int num)
{
    return num % 2 == 0;
}

void solve()
{

    ll N;
    cin >> N;
    vector<ll> v(N);

    for (ll i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    stack<ll> st;
    st.push(v[0]);

    int c = 0;
    ll i = 1;
    while (!st.empty() && i < N)
    {
        ll ele = st.top();

        if ((isOdd(ele) && isOdd(v[i])) || (isEven(ele) && isEven(v[i])))
        {
            // both are of same parity.
            c++;
            ll ans = ele * v[i];
            st.pop();
            st.push(ans);
        }
        else
        {
            st.push(v[i]);
        }
        i++;
    }

    cout << c << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}