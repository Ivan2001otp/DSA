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
    for (long long i = 1; i <= N; i++)
    {
        cin >> v[i];
    }

    vector<long long> prefix(N + 1);

    for (long long i = 1; i <= N; i++)
    {
        prefix[i] = prefix[i - 1] + v[i];
    }



    while (Q--)
    {
        long long L,R;
        cin>>L>>R;

        cout<<"Result : "<<prefix[R] - prefix[L-1]<<endl;
    }

    return 0;
}