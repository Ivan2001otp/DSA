#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--)
    {

        int n;
        cin >> n;
        int result = 0;

        while (n != 1)
        {
            int nw = 1;
            int x = 1;

            for (int i = 2; i * i <= n; i++)
            {
                if (n % i == 0)
                {
                    n = n / i;
                    nw *= i;

                    while (n % i == 0)
                    {
                        n = n / i;
                        x = x * i;
                    }
                }
            }

            nw = nw * n;
            n = x;
            result += nw;
        }

        cout << result << endl;
    }

    return 0;
}