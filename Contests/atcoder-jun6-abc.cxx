#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// difference array + prefix sum.
void solve3()
{
    int N, M;
    cin >> N >> M;

    vector<int> diff_arr(N + 1);
    int L, R;
    for (int i = 1; i <= M; i++)
    {
        cin >> L >> R;
        diff_arr[L]++;
        diff_arr[R + 1]--;
    }

    // prefix sum;
    int mx = 1e9;

    for (int i = 1; i <= N; i++)
    {
        diff_arr[i] = diff_arr[i] + diff_arr[i - 1];
        mx = min(mx, diff_arr[i]);
    }

    cout << mx << endl;
}

void solve2()
{
    int N;
    cin >> N;
    vector<int> v(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int count = 0;
    vector<int> ans;

    for (int i = 0; i < N; i++)
    {
        if (i == N - 1)
        {
            count++;
            ans.push_back(v[i]);
            continue;
        }

        if (v[i] != v[i + 1])
        {
            count++;
            ans.push_back(v[i]);
        }
    }

    cout << count << endl;

    for (auto a : ans)
    {
        cout << a << " ";
    }

    return;
}

void solve1()
{
    int N, S;
    cin >> N >> S;

    float threshold = S + 0.5;

    vector<int> T(N);

    for (int i = 0; i < N; i++)
    {
        cin >> T[i];
    }

    vector<int> res(N, 0);
    int flag = 1;

    if (T[0] > threshold)
    {
        flag &= 0;
    }

    for (int i = 1; i < N; i++)
    {
        int diff = abs(T[i] - T[i - 1]);
        if (diff > threshold)
        {
            flag &= 0;
            break;
        }
    }

    if (flag)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve3();
    return 0;
}