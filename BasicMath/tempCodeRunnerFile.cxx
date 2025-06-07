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
    int A, B;
    cin >> A >> B;

    int ans = 0;
    int c1 = N / (A + B);

    int rem = N % (A + B);
    int c2 = 0;

    if (rem != 0)
    {
        c2 = min(A, rem);
    }

    ans = c1 + c2;
    cout << "result : " << ans << endl;

    return 0;
}