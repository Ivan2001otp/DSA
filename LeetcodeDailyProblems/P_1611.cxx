#include <bits/stdc++.h>
using namespace std;
#define nl endl;

int minimumOneBitOperations(int n)
{
    vector<long long> F(32, 0);

    // F[i] = 2*F[i-1] + 1;
    F[0] = 1;
    for (int i = 1; i <= 31; i++)
    {
        F[i] = (2 * F[i - 1]) + 1;
    }

    int sign = 0;
    int res = 0;

    int ith_bit_set = 0;
    for (int i = 31; i >= 0; i--)
    {
        ith_bit_set = (1 << i) & n;
        if (ith_bit_set == 0)
            continue;

        if (sign)
        {
            res += F[i];
        }
        else
        {
            res -= F[i];
        }

        sign = !sign;
    }

    return res * (-1);
}

int main()
{
    int n = 3;

    return 0;
}