#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int N;
    cin >> N;
    vector<int> v(N);
    vector<pair<int, int>> res;

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
        res.push_back({v[i], i + 1});
    }

    sort(res.begin(), res.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.first < b.first; });

    int ans = 0;
    for (int i = 0; i < N - 1; i++)
    {
        int first_val = res[i].first;
        int first_indx = res[i].second;

        for (int j = i + 1; j < N; j++)
        {
            int second_val = res[j].first;
            int second_indx = res[j].second;

            if (first_val * second_val == first_indx + second_indx)
            {
                ans++;
            }
            else
            {
                if (first_val * second_val > 2 * N)
                {
                    break;
                }
            }
        }
    }
    cout << ans << endl;
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