#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> prime(N + 1, true);

    for (int p = 2; p * p <= N; p++)
    {
        if (prime[p])
        {
            for (int i = p * p; i <= N; i = i + p)
            {
                prime[i] = false;
            }
        }
    }

    for (int p = 2; p <= N; p++)
    {
        if (prime[p])
        {
            cout << p << " ";
        }
    }

    return 0;
}