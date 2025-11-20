#include <bits/stdc++.h>
using namespace std;
#define nl endl;

// https://leetcode.com/problems/increment-submatrices-by-one/?envType=daily-question&envId=2025-11-14
vector<vector<int> > rangeAddQueries(int n, vector<vector<int> > &queries)
{
    vector<vector<int> > diff(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < q.size(); i++)
    {
        int r1 = q[i][0];
        int c1 = q[i][1];
        int r2 = q[i][2];
        int c2 = q[i][3];

        diff[r1][c1] += 1;
        diff[r2 + 1][c2 + 1] += 1;
        diff[r2 + 1][c1] -= 1;
        diff[r1][c2 + 1] -= 1;
    }

    vector<vector<int> > mat(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int left = 0;
            if (j > 0)
            {
                left = mat[i][j - 1];
            }

            int up = 0;
            if (i > 0)
            {
                up = mat[i - 1][j];
            }

            int c = 0;
            if (i > 0 && j > 0)
            {
                c = mat[i - 1][j - 1];
            }

            mat[i][j] = diff[i][j] + up + left - c;
        }
    }

    return mat;
}

int main()
{
    int n = 3;
    vector<vector<int> > q = {{1, 1, 2, 2}, {0, 0, 1, 1}};
    cout << "ans is " << rangeAddQueries(n, q);
    return 0;
}