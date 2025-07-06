#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int minimumCostPath(vector<vector<int>> &grid)
{
   /*
        [0,1,1,1,1,1,1,1]
        [0,1,1,0,0,0,0,0]
        [0,1,0,1,1,1,1,0]
        [0,1,0,1,1,1,1,0]
        [0,1,1,0,0,1,1,0]
        [0,1,1,1,1,0,1,0]
        [0,0,0,0,0,1,1,0]
        [1,1,1,1,1,1,1,0]
   */

   int N = grid.size();

   vector<vector<int>>dirs = {{0,1}, {0,-1},{1,0},{-1,0}};
   vector<vector<int>>dist(N, vector<int>(N,1e9));

   priority_queue<pair<int,pair<int,int>>, 
                                vector<pair<int,pair<int,int>>>,
                                greater<pair<int,pair<int,int>>>
                                >pq;

   dist[0][0] = grid[0][0];
   pq.push({dist[0][0], {0,0}});// {dist , {x,y}}
   
   
   while(!pq.empty()) {
        auto item = pq.top();
        pq.pop();
        int currDist = item.first;
        int x = item.second.first;
        int y = item.second.second;
        
        if (x==N-1 && y==N-1) {
            return currDist;
        }
        if (dist[x][y] < currDist)continue;

        for(auto a: dirs) {
            int newX = x + a[0];
            int newY = y + a[1];

            if (newX >= 0 && newX<N && newY>=0 && newY<N) {

                if (currDist + grid[newX][newY] < dist[newX][newY]) {
                    dist[newX][newY] = currDist + grid[newX][newY];
                    pq.push({dist[newX][newY], {newX, newY}});
                }

            }
        }
   }

   return dist[N-1][N-1];
}

int main()
{
    vector<vector<int>> grid = {{4,4},{3,7}};
    cout << minimumCostPath(grid) << endl;
    return 0;
}