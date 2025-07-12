#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int N;
    cin >> N;
    vector<int> v(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    if (v.size() < 2)
    {
        cout << "No" << endl;
        return;
    }
    vector<int> temp(N);
    for (int i = 0; i < N; i++)
    {
        temp[i] = v[i];
    }

    sort(temp.begin(), temp.end());

    vector<int> t;
    for (int i = 0; i < N; i++)
    {
        if (temp[i] != v[i])
        {
            t.push_back(v[i]);
        }
    }

    if (t.size() >= 2)
    {
        cout << "Yes" << endl;
        cout << t.size() << endl;
        for (auto a : t)
            cout << a << " ";
        cout << endl;
        return;
    }
    cout << "No" << endl;
}

void solve2()
{
    int N;
    cin >> N;
    vector<int> v(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    if (v.size() <= 1)
    {
        cout << v[0] << endl;
        return;
    }
    cout << min(2 * v[0], v[0] + v[1]) << endl;
}

// code for lcm+hcf crack question.
long long gcd(int a, int b)
{

    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcm(int a, int b)
{

    if (a == 0 || b == 0)
        return 0;

    return (a * b) / gcd(a, b);
}

void solve3()
{
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    ll ans = v[0];
    for (int i = 1; i < N; i++)
    {
        ans = lcm(ans, v[i]);
    }
    cout << "res : " << ans << endl;
}

signed int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve3();
    }
    return 0;
}