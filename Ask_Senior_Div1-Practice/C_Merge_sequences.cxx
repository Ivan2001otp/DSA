#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    vector<int> B(M);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < M; i++)
    {
        cin >> B[i];
    }

    vector<int> temp(N + M, 0);

    int i = 0, j = 0;
    int cn = min(N, M);
    int k = 0;
    while (i < N && j < M)
    {

        if (A[i] <= B[j])
        {
            temp[k] = A[i];
            k++;
            i++;
        }
        else if (A[i] > B[j])
        {
            temp[k] = B[j];
            k++, j++;
        }
    }

    while (i < N)
    {
        temp[k] = A[i];
        i++, k++;
    }

    while (j < M)
    {
        temp[k] = B[j];
        k++, j++;
    }

    
    unordered_map<int, int> mp;
    for (int i = 0; i < temp.size(); i++)
    {
        mp[temp[i]] = i + 1;
    }

    for (int i = 0; i < N; i++)
    {
        cout << mp[A[i]] << " ";
    }
    cout << endl;
    for (int j = 0; j < M; j++)
    {
        cout << mp[B[j]] << " ";
    }
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}