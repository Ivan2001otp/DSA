#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long N, Q;
    cin >> N >> Q;

    vector<long long> v(N + 1);
    vector<long long> temp(N + 2);

    for (long long i = 1; i <= N; i++)
        cin >> v[i];

    // solved using difference array concept
    while (Q--)
    {

        long long L, R, val;
        cin >> L >> R >> val;

        temp[L] += val;
        temp[R + 1] -= val;
    }

    // prefix sum
    for (long long i = 1; i <= N; i++)
    {
        temp[i] += temp[i - 1];
    }

    for (long long i = 1; i <= N; i++)
    {
        v[i] += temp[i];
    }

    for (long long i = 1; i <= N; i++)
    {
        cout << v[i] << " ";
    }
    cout<<endl;

    return 0;
}