#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// subsequence addition - g2
void f()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    if (arr[0] != 1)
    {
        cout << "NO" << endl;
        return;
    }

    vector<int> prefixsum(n, 0);
    prefixsum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefixsum[i] = prefixsum[i - 1] + arr[i];
    }

    bool flag = false;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > prefixsum[i - 1])
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
    {
        f();
    }
    return 0;
}