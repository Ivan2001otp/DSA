#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*

    while (m--)
    {
        int l, r;
        int n = s.size();
        cin >> l >> r;
        l--, r--;
        ll count = 0;

        for (int i = l; i < r; i++)
        {
            if (s[i] == s[i + 1])
                ++count;
        }

        cout <<  count << endl;
    }
*/

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    getline(cin, s);

    int m;
    cin >> m;

    int N = s.size();
    vector<int> pre(N);

    for (int i = 1; i < N; i++)
    {
        if (s[i] == s[i - 1])
        {
            pre[i] = 1;
        }
    }

    vector<int> preResult(pre.size());

    for (int i = 1; i < pre.size(); i++)
    {
        preResult[i] = pre[i] + preResult[i - 1];
    }

    while (m--)
    {
        int l, r;
        cin >> l >> r;

        l--, r--;

        if (l > r)
            swap(l, r);

        cout << preResult[r] - preResult[l] << endl;
    }

    return 0;
}