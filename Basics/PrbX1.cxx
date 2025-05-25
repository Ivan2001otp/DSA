#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    bool allX = true;

    cin >> N >> M;

    vector<vector<char>> v(N, vector<char>(M, 'x'));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> v[i][j];
        }
    }

    int X, Y;
    cin >> X >> Y;

    int dx[] = {-1, -1, 0, 1, 1, -1, 0, 1};
    int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};

    for (int i = 0; i < 8; i++)
    {
        int newX = (X - 1) + dx[i];
        int newY = (Y - 1) + dy[i];

        if (newX >= 0 && newX < N && newY >= 0 && newY < M)
        {
            if (v[newX][newY] != 'x')
            {
                allX = false;
                break;
            }
        }
    }

    cout << (allX ? "yes" : "no") << endl;
    return 0;
}