#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int div = 1;
    while (div <= N)
    {
        if (N % div == 0)
        {
            cout << div << endl;
        }
        div++;
    }

    return 0;
}