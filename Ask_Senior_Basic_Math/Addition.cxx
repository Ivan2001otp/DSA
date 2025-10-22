#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll N;
    cin >> N;
    ll element;
    ll even_count = 0, odd_count = 0;

    for (ll i = 0; i < N; i++)
    {
        cin >>element;

        if (element & 1)
        {
            odd_count++;
        }
        else
        {
            even_count++;
        }
    }

    if (odd_count & 1)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }

    return 0;
}