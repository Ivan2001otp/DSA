#include <bits/stdc++.h>
using namespace std;

bool result(vector<int> &src, vector<int> &target)
{
    int i = 0, j = 0;

    while (i < src.size() && j < target.size())
    {
        if (src[i] == target[j])
        {
            j++;
        }
        i++;
    }

    return j == target.size();
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> A(N, 0);
    vector<int> B(M, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < M; i++)
    {
        cin >> B[i];
    }

    bool res = result(A, B);
    if (res)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}