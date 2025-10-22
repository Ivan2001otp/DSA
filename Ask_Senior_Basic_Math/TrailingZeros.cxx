#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// trailing zeros concept.... occurence of 5 is smaller than 2....

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll N;
    cin >> N;

    int count = 0;
    int i = 5;

    while (N / i != 0)
    {
        count += N / i;
        i = i * 5;
    }

    cout << count << endl;
    return 0;
}