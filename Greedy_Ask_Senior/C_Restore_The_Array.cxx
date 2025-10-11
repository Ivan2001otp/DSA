#include <bits/stdc++.h>
using namespace std;

void f()
{
    int n;
    cin >> n;
    vector<int> v(n - 1);
    int s_n = n - 1;
    
    for (int i = 0; i < s_n; i++)
    {
        cin >> v[i];
    }

    vector<int> temp(n);
    temp[0] = v[0];
    temp[n - 1] = v[s_n - 1];

    for (int i = 1; i < s_n; i++)
    {
        temp[i] = min(v[i], v[i - 1]);
    }

    for (auto a : temp)
    {
        cout << a << " ";
    }
    cout << endl;

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    t = 1;
    cin >> t;

    while (t--)
    {
        f();
    }

    return 0;
}