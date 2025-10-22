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
    vector<vector<int>> v(N, vector<int>(M));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> v[i][j];
        }
    }

    int X;
    cin >> X;

    bool flag = false;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (v[i][j] == X)
            {
                flag = true;
                break;
            }
        }
    }

    if (flag)
    {
        cout << "will not take number" << endl;
    }
    else
    {
        cout << "will take number" << endl;
    }

    return 0;
}