#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

// template <typename T>
using pbds = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{

    int n;

    cin >> n;
    vector<vector<int>> ranges(n);
    int l, r;
    for (int i = 0; i < n; i++)
    {
        cin >> l >> r;
        ranges[i] = {l, r, i};
    }

    sort(ranges.begin(), ranges.end(), [](vector<int> &a, vector<int> &b)
         {
        if (a[0]==b[0]) {
            return a[1] > b[1];
        }
        return a[0] < b[0]; });

    pbds st;

    vector<int> ans1(n);

    for (int i = 0; i < n; i++)
    {
        int R = ranges[i][1], ind = ranges[i][2];

        int val = st.size() - st.order_of_key({R, -i});
        st.insert({R, -i});
        ans1[ind] = val;
    }

    vector<int> ans2(n);
st.clear();
    for (int i = n - 1; i >= n; i--)
    {
        int R = ranges[i][1], ind = ranges[i][2];

        st.insert({R, -i});
        int val = st.order_of_key({R, -i});
        ans2[ind] = val;
    }

    for (auto a : ans2)
        cout << a << " ";
    cout << endl;

    for (auto a : ans1)
        cout << a << " ";

    return 0;
}
