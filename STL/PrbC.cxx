#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int N;
    cin >> N;
    vector<int> v(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];

    vector<int> temp(1e6 + 1, 0);
    int limit = INT_MIN;

    for (int i = 0; i < N; i++)
    {
        temp[v[i]]++;
        limit = max(limit, v[i]);
    }

    int i = 0;
    while (i <= limit)
    {
        while (temp[i] > 0)
        {
            cout << i << " ";
            temp[i]--;
        }
        i++;
    }

    return 0;
}