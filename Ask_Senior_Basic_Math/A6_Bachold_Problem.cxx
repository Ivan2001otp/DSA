#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    if (N & 1)
    {
        int num1 = ((N / 2) - 1);
        int curr = num1 * 2;
        int rem = N - curr;

        vector<int> v(num1, 2);
        v.push_back(rem);

        cout << v.size() << endl;
        for (auto a : v)
        {
            cout << a << " ";
        }
    }
    else
    {
        int num1 = N / 2;
        vector<int> v(num1, 2);
        cout << v.size() << endl;
        for (auto a : v)
            cout << a << " ";
    }

    return 0;
}