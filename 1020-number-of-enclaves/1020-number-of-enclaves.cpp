class Solution {
public:
    int r[4] = {0,1,0,-1};
    int c[4] = {1,0,-1,0};
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        queue<pair<int,int>> qt;
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if((i == 0 || j == 0 || i == m-1 || j == n-1) && (grid[i][j] == 1)) {
                    grid[i][j] = 2;
                    qt.push({i,j});
                }
            }
        }
        while(!qt.empty()){
            int currx = qt.front().first , curry = qt.front().second;
            qt.pop();
            for(int i = 0 ; i<4 ; i++){
                int newx = currx + r[i] , newy = curry + c[i];
                if(newx >=0 && newx < m && newy >=0 && newy < n && grid[newx][newy] == 1){
                    grid[newx][newy] = 2;
                    qt.push({newx,newy});
                }
            }
        }
        int count = 0;
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(grid[i][j] == 1) count++;
            }
        }
        return count;
    }
};