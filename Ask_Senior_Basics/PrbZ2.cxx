#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, Q;
    cin >> N >> Q;

    int arr[N] = {0};

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    while (Q--)
    {
        int ele;
        bool flag = false;
        cin >> ele;

        int low = 0;
        int high = N - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] == ele)
            {
                flag = true;
                break;
            }
            else if (arr[mid] < ele)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        if (flag)
        {
            cout << "found" << endl;
        }
        else
        {
            cout << "not found" << endl;
        }
    }

    return 0;
}