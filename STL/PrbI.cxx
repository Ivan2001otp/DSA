#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, Q;
    cin >> N >> Q;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    while (Q--)
    {
        string s;
        cin >> s;

        ll l, r, num;

        if (s == "sort")
        {
            cin >> l >> r;
            if (l > r)
                swap(l, r);
            l--, r--;
            sort(v.begin() + l, v.begin() + r + 1);
        }
        else if (s == "reverse")
        {
            cin >> l >> r;
            if (l > r)
                swap(l, r);

            l--, r--;
            reverse(v.begin() + l, v.begin() + r + 1);
        }

        else if (s == "push_back")
        {
            cin >> num;
            v.push_back(num);
        }
        else if (s == "pop_back")
        {
            v.pop_back();
        }
        else if (s == "front")
        {
            cout << v.front() << endl;
        }
        else if (s == "back")
        {
            cout << v.back() << endl;
        }
        else
        {
            int index;
            cin >> index;
            index--;
            cout << v[index] << endl;
        }
    }

    return 0;
}