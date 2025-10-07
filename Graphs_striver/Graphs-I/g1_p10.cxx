#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void f(vector<vector<char>>grid, vector<vector<int>>& vis, int x, int y, int row, int col) {

    vector<vector<int>> dirs  = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    queue<pair<int,int>>q;

    q.push({x, y});
    vis[x][y] = 1;

    int oldX, oldY;
    while(! q.empty()) {
        auto curr = q.front();
        q.pop();
        oldX = curr.first;
        oldY = curr.second;

        for(auto a : dirs) {
            int newX = a[0] + oldX;
            int newY = a[1] + oldY;

            if (newX>=0 && newX < row && newY>=0 && newY<col && !vis[newX][newY] && grid[newX][newY]==1) {
                q.push({newX, newY});
                vis[newX][newY] = 1;
            }
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    int count = 0;
    
    int row = grid.size();
    int col = grid[0].size();

    vector<vector<int>>vis(row, vector<int>(col, 0));

    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            if (grid[i][j]=='1' && (!vis[i][j])) {
                ++count;
                f(grid, vis, i, j, row, col);
            }
        }
    }

    return count;
}