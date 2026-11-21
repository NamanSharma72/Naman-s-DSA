class Solution {
public:
    int r[4] = {0,1,0,-1};
    int c[4] = {1,0,-1,0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        queue<tuple<int,int,int>> qt;
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                // x , y , distance
                if(grid[i][j] == 0) qt.push({i,j,0});
            }
        }
        vector<vector<int>> visited(m , vector<int>(n , 0));
        while(!qt.empty()){
            auto [currx , curry , currDist] = qt.front();
            qt.pop();
            for(int i = 0 ; i<4 ; i++){
                int newx = currx + r[i] , newy = curry + c[i];
                if(newx >=0 && newx < m && newy >=0 && newy < n && grid[newx][newy] == 1 && visited[newx][newy] == 0){
                    visited[newx][newy] = 1;
                    grid[newx][newy] = currDist+1;
                    qt.push({newx , newy , currDist+1});
                }
            }
        }
        return grid;
    }
};