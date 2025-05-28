#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, Q;
    cin >> N >> Q;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    sort(v.begin(), v.end());


    while (Q--)
    {
        string s;
        cin >> s;
        int num;
        cin >> num;
        if (s == "lower_bound")
        {

            auto it = lower_bound(v.begin(), v.end(), num);
            if (it != v.end())
                cout << *it << endl;
            else
                cout << "-1" << endl;
            ;
        }
        else if (s == "upper_bound")
        {

            auto it = upper_bound(v.begin(), v.end(), num);
            if (it != v.end())
            {
                cout << *it << endl;
            }
            else
                cout << "-1" << endl;
        }
        else
        {

            if (binary_search(v.begin(), v.end(), num))
            {
                cout << "found" << endl;
            }
            else
            {
                cout << "not found" << endl;
            }
        }
    }

    return 0;
}