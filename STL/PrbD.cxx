#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N;
    cin >> M;

    vector<int> arr(N);
    unordered_map<int, bool> mp;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        mp[arr[i]] = true;
    }

    bool flag = false;
    int number = 0;

    for (int i = -M; i <= M; i++)
    {
        if (!mp[i])
        {
            number = i;
            flag = true;
            break;
        }
    }

    if (flag)
    {
        cout << number << endl;
    }

    return 0;
}