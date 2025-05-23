#include <bits/stdc++.h>
using namespace std;

int main()
{
    double A, B;
    char S;
    cin >> A >> S >> B;

    int ans;

    switch (S)
    {
    case '+':
        ans = A + B;
        break;

    case '-':
        ans = A - B;
        break;

    case '*':
        ans = A * B;
        break;

    case '/':
        ans = (double)(A / B);
        break;
    }
    cout << ans << endl;

    return 0;
}