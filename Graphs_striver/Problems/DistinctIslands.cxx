#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void bfs(vector<vector<int>>grid, int x,int y, vector<vector<int>>&vis, vector<pair<int,int>>&t) {
    queue<pair<int,int>>q;
    vis[x][y]= 1;
    int row =grid.size();
    int col = grid[0].size();

    q.push({x, y});
    vector<vector<int>>dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};


    while(! q.empty()) {
        auto curr = q.front();
        q.pop();

        int ox = curr.first;
        int oy = curr.second;

        for(auto dir : dirs) {

            int newX = dir[0] + ox;
            int newY = dir[1] + oy;

            if (newX>=0 && newX<row && newY>=0 && newY<col && !vis[newX][newY] && grid[newX][newY]) {
                q.push({newX, newY});
                t.push_back({newX-x, newY-y});
                vis[newX][newY]=1;
            }
        }
    }
}

int countDistinctIslands(vector<vector<int>>& grid) {

    int row = grid.size();
    int col = grid[0].size();

    vector<vector<int>>vis(row ,vector<int>(col, 0));
    set<vector<pair<int,int>>>st;

    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            if (grid[i][j]==1 && !vis[i][j]) {
                vector<pair<int,int>>t;
                bfs(grid, i, j, vis, t);
                st.insert(t);
            }
        }
    }

    return st.size();

}