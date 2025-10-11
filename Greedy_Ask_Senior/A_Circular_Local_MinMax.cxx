#include <bits/stdc++.h>
using namespace std;

void f()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    if (n % 2)
    {
        cout << "NO" << endl;
        return;
    }

    sort(v.begin(), v.end());
    int l = 0, mid = v.size() / 2;

    vector<int> temp(n);

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            temp[i] = v[l];
            l++;
        }
        else
        {
            temp[i] = v[mid];
            ++mid;
        }
    }

    for (int i = 1; i < n - 1; i++)
    {
        if (temp[i] > temp[i + 1] && temp[i] > temp[i - 1])
            continue;
        else if (temp[i] < temp[i + 1] && temp[i] < temp[i - 1])
            continue;
        else
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
    for (auto a : temp)
    {
        cout << a << " ";
    }
    cout << endl;
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

// int main()
// {
//     int t;
//     t = 1;
//     cin >> t;

//     while (t--)
//     {
//         int n;
//         cin >> n;
//         int v[n];
//         for (int i = 0; i < n; i++)
//             cin >> v[i];
//         sort(v, v + n);

//         if (n % 2 || v[n / 2] == v[n / 2 - 1] && count(v, v + n, v[n / 2]) >= n / 2)
//             cout << "NO" << endl;
//         else
//         {
//             cout << "YES" << endl;
//             for (int i = 0; i < n / 2; i++)
//                 cout << v[i] << " " << v[i + n / 2] << " ";
//             cout << endl;
//         }
//     }
// }