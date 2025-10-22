#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    int count = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            if (count % 4 == 0)
            {
                cout << "PUM";
            }
            else
                cout << count << " ";

            count++;
        }

        cout << endl;
    }

    return 0;
}