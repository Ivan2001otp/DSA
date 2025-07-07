#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int minimumEffortPath(vector<vector<int>> &heights)
{

    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>

        >
        q;

    int row = heights.size();
    int col = heights[0].size();

    vector<vector<int>> dist(row, vector<int>(col, 1e9));
    dist[0][0] = 0;
    q.push({dist[0][0], {0, 0}});
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    while (!q.empty())
    {
        auto item = q.top();
        q.pop();

        int curr_diff = item.first;
        int x = item.second.first;
        int y = item.second.second;

        if (x == row - 1 && y == col - 1)
        {
            return curr_diff;
        }

        for (auto dir : dirs)
        {
            int newX = x + dir[0];
            int newY = y + dir[1];

            if (newX >= 0 && newX < row && newY >= 0 && newY < col)
            {
                int newDiff = max(abs(heights[newX][newY] - heights[x][y]), curr_diff);

                if (newDiff < dist[newX][newY])
                {
                    dist[newX][newY] = newDiff;
                    q.push({newDiff, {newX, newY}});
                }
            }
        }
    }

    

    return 0;
}

int main()
{
    vector<vector<int>> grid = {{1, 2, 1, 1, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 1, 1, 2, 1}};
    cout << minimumEffortPath(grid) << endl;
    return 0;
}