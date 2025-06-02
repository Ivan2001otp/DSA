#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

// template <typename T>
using pbds = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

int solve()
{
    int n;
    cin >> n;

    vector<pair<int, int>> v = {{-4, 9}, {-2, 5}, {3, 4}, {6, 7}, {8, 10}};
    sort(v.begin(), v.end());
    pbds ends;

    for(auto a  : v) {
        ends.insert(a.second);
    }

    int ans = 0;

    for (auto x : v) {
        int endPoint = x.second;
        // order_of_key - gives number of elements less than
        int B = ends.order_of_key(x.second);
        int A = ends.order_of_key(x.first);
        
        ends.erase(endPoint);
        ans += (B-A);
    }
    return ans;
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
