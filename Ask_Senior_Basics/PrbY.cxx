#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, Q;
    cin >> N >> Q;
    int v[N + 1] = {0};

    for (int i = 1; i <= N; i++)
    {
        cin >> v[i];
    }

    int prefix[N + 1] = {0};
    for (int i = 1; i <= N; i++)
    {
        prefix[i] = prefix[i - 1] + v[i];
    }

    while (Q--)
    {
        int l, r;
        cin >> l >> r;
        int sum = 0;
        sum = prefix[r] - prefix[l - 1];
        cout << sum << endl;
    }

    return 0;
}