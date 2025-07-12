#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
    void solve()
    {
        int N;
        cin >> N;
        int S;
        cin >> S;

        vector<int> v(N);

        for (int i = 0; i < N; i++)
        {
            cin >> v[i];
        }

        int st = v[0];
        int end = v[N - 1];
        int pos = S;
        int res = 0;

        if (pos >= st && pos <= end)
        {

            // check is it in middle
            int leftDiff = pos - st;
            int rightDiff = end - pos;
            if (leftDiff == rightDiff)
            {
                res = res + 2 * (leftDiff) + rightDiff;
            }
            else
            {
                if (leftDiff < rightDiff)
                {
                    res = res + 2 * (leftDiff) + rightDiff;
                }
                else
                {
                    res = res + (2 * rightDiff) + leftDiff;
                }
            }
        }
        else
        {

            res += max(pos - st, end - pos);
        }
        cout << res << endl;
    }
*/

void solve()
{
    int N;
    cin >> N;
    string s;
    cin >> s;

    unordered_map<char, int> mp;
    int len = s.size();
    int N1 = s.size();
    for (int i = N1 - 1; i >= 0; i--)
    {
        if (mp.count(s[i]) == 0)
        {
            mp[s[i]]++;

            --len;
        }
        else
        {
            --len;
            break;
        }
    }

    mp.clear();

    if (len > 0)
    {
        cout << "YES" << endl;
        return;
    }
    else
    {

        len = N1;
        for (int i = 0; i < N1; i++)
        {
            if (!mp[s[i]])
            {
                mp[s[i]]++;
                --len;
            }
            else
            {
                --len;
                break;
            }
        }

        if (len > 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}