#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll N, Q;
    cin >> N >> Q;

    set<int> st;
    for (int i = 0; i < N; i++)
    {
        int ele;
        cin >> ele;
        st.insert(ele);
    }

    vector<int> v;
    for (auto a : st)
    {
        v.push_back(a);
    }

    while (Q--)
    {

        int x;
        cin >> x;

        int pos1 = lower_bound(v.begin(), v.end(), x) - v.begin();
        int pos2 = upper_bound(v.begin(), v.end(), x) - v.begin();

        cout << pos1 << " " << v.size() - pos2 << endl;
    }

    return 0;
}