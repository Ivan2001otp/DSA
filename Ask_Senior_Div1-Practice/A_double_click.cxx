#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int N, D;
    cin >> N >> D;
    vector<int> T(N);

    for (int i = 0; i < N; i++)
    {
        cin >> T[i];
    }

    bool found = false;
    for (int i = 1; i < N; i++)
    {
        if (T[i] - T[i - 1] <= D)
        {
            cout << T[i] << endl;
            found = true;
            break;
        }
    }

    if (found)
        return;
    cout << -1 << endl;
}

void solve2()
{
    int N;
    cin >> N;
    int X, Y;
    cin >> X >> Y;
    vector<int> v(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    int max_ele = *(max_element(v.begin(), v.end()));
    int path1 = X * max_ele;
    int path2 = v.size() * Y;
    cout << "res : ";
    cout << min(path1, path2) << endl;
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve2();
    }
}