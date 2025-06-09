#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isCompositeNumber(int num)
{

    if (num < 3)
        return false;

    vector<int> divisors;

    for (int i = 1; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            divisors.push_back(i);

            if (num / i != i)
            {
                divisors.push_back(i);
            }
        }
    }

    return divisors.size() > 2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    if (n % 2 == 0)
    {
        cout << 4 << " " << n - 4 << endl;
    }
    else
    {
        cout << 9 << " " << n - 9 << endl;
    }
    return 0;
}