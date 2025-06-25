#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int N;
    cin >> N;
    int cnt = 0;
    for (int i = 1; i <= N; i = i * 10 + 1)
    {
        for (int j = 1; j <= 9; j++)
        {
            if (i * j <= N)
                cnt++;
        }
    }

    cout << cnt << endl;
}

void solve2() {
    string s;
    cin >> s;
    
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve2();
    }
}