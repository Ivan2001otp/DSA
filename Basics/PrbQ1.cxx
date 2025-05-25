#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;
        int count = 0;

        int arr[N] = {0};

        for (int i = 0; i < N; i++)
            cin >> arr[i];

        for (int i = 0; i < N; i++)
        {
            for (int j = i; j < N; j++)
            {
                bool flag = true;
                for (int k = i; k < j; k++)
                {
                    if (arr[k] < arr[k + 1])
                    {
                    }
                    else
                    {
                        flag = false;
                        break;
                    }
                }

                if (flag)
                {
                    count++;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}