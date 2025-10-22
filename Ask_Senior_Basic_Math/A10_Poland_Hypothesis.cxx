#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<bool> constructPrimeArr()
{
    const int N = 1e5 + 1;
    vector<bool> prime(N, true);

    for (int i = 2; i * i <= N; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                prime[j] = false;
            }
        }
    }

    return prime;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m = 1, n;
    vector<bool> prime = constructPrimeArr();

    cin >> n;
    int ans = 0;
    while (true)
    {
        ans = (n * m) + 1;
        // cout << "ans is " << ans << endl;
        if (!prime[ans])
        {
            cout << m << endl;
            break;
        }
        m++;
    }

    return 0;
}