#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*

    int total = 0;
    multiset<int> st;
    vector<pair<int, int>> pb;
    vector<int> ans;

    for (int i = 0; i < N; i++)
    {
        st.insert(v[i]);
        pb.push_back({v[i], i});
        total += v[i];
    }

    sort(pb.begin(), pb.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.first < b.first; });

    for (int i = 0; i < N; i++)
    {
        int val = pb[i].first;
        int indx = pb[i].second;
        st.erase(st.find(val));

        int end_ele = *(--st.end());

        if (total - end_ele - val == end_ele)
        {
            ans.push_back(indx + 1);
        }

        st.insert(val);
    }
    if (ans.size() == 0)
        cout << 0 << endl
             << endl;

    else
    {
        cout << ans.size() << endl;

        for (auto a : ans)
        {
            cout << a << " ";
        }
    }

*/

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll N;
    cin >> N;

    vector<ll> v(N);
    unordered_map<ll, ll> mpp;
    vector<ll> res;

    ll total = 0;

    for (ll i = 0; i < N; i++)
    {
        cin >> v[i];
        total += v[i];
        mpp[v[i]]++;
    }

    for (ll i = 0; i < N; i++)
    {

        if ((total - v[i]) % 2 != 0)
            continue;

        ll target = (total - v[i]) / 2;

        mpp[v[i]]--;

        if (mpp[target] > 0)
        {
            res.push_back(i + 1);
        }

        mpp[v[i]]++;
    }

    cout << res.size() << endl;
    for (auto a : res)
        cout << a << " ";
    cout << endl;
    return 0;
}