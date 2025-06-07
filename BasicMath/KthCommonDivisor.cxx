#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int A, B, K;
    cin >> A >> B;
    cin >> K;

    int l = min(A, B);

    int c = 0;
    for (int i = l; i >= 0; i--)
    {
        if (A % i == 0 && B % i == 0)
        {
            if (++c == K)
            {
                cout <<  i << endl;
                break;
            }
        }
    }

    return 0;
}