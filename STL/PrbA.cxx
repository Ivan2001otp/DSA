#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, Q;
    cin >> N >> Q;

    unordered_map<int, int> mp;

    while (Q--)
    {
        int z, x;
        cin >> z >> x;

        if (z == 1)
        {
            mp[x]++;
        }
        else
        {
            
            if (!mp[x])
            {

                cout << "0" << endl;
            }
            else
            {
                cout << mp[x] << endl;
            }
        }
    }

    return 0;
}