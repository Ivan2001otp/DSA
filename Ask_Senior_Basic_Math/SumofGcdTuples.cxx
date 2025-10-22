#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }

    return gcd(b % a, a);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int K;
    cin >> K;

    vector<vector<int>> arr;

    for (int i = 1; i <= K; i++)
    {
        for (int j = 1; j <= K; j++)
        {

            for (int k = 1; k <= K; k++)
            {
                vector<int> v;
                v.push_back(i);
                v.push_back(j);
                v.push_back(k);
                arr.push_back(v);
            }
        }
    }

    long long sum = 0, ans = 0;
    for (auto l1 : arr)
    {
        int a = l1[0], b = l1[1], c = l1[2];

        if (a < b)
            swap(a, b);

        ans = gcd(gcd(a, b), c);

        sum += ans;
    }

    cout << sum << endl;

    return 0;
}