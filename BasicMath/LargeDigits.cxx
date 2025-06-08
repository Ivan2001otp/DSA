#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int sumOfDigits(int n)
{
    int c = 0;
    while (n != 0)
    {
        int unit = n % 10;
        n = n / 10;
        c += unit;
    }
    return c;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int A, B;
    cin >> A >> B;

    cout << max(sumOfDigits(A), sumOfDigits(B)) << endl;
    return 0;
}