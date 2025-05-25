#include <bits/stdc++.h>
using namespace std;

int main()
{

    int N;
    cin >> N;

    int reverse = 0;
    int temp = N;

    while (temp != 0)
    {
        int rem = temp % 10;
        reverse = reverse * 10 + rem;
        temp = temp / 10;
    }

    cout<<reverse<<endl;
    if (reverse == N)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}