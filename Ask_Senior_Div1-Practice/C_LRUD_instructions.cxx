#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct hash_cmp {
    size_t operator()(const pair<int,int>&p) const {
        return hash<ll>()(((ll)p.first) ^ (((ll)p.second) << 32));
    }
};

void solve()
{
    int N;
    string S;
    cin >> N >> S;

    unordered_map<pair<int,int>,int, hash_cmp> mp;// {x, {y, count}}

    int x = 0, y = 0;
    mp[{0,0}]=1;

    for (auto ch : S)
    {
        switch (ch)
        {
        case 'R':
            x++;
            break;

        case 'L':
            x--;
            break;

        case 'U':
            y++;
            break;

        case 'D':
            y--;
            break;
        }
        mp[{x,y}]++;

        if (mp[{x,y}]>1) {
            cout<<"Yes"<<endl;
            return; 
        }
    }

   


    cout << "No" << endl;
    return;
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}