class Solution {
public:
    // directions are 0 , 1 , 2 , 3
    vector<pair<int , int>> dir = {{-1 , 1} , {1 , 1} , {1 , -1} , {-1 , -1}};
    int dp[500][500][4][2];
    int doit(int currx , int curry , int direction , int turn , vector<vector<int>>& grid){
        if(dp[currx][curry][direction][turn] != -1) return dp[currx][curry][direction][turn];
        int nextValue = grid[currx][curry] == 2 ? 0 : 2;
        int goForward = 0;
        // only when the sequence is maintained
        int newx = currx + dir[direction].first , newy = curry + dir[direction].second;
        if(newx >= 0 && newx < grid.size() && newy >=0 && newy < grid[0].size() && grid[newx][newy] == nextValue){
            goForward = 1 + doit(newx , newy , direction , turn , grid);
        }

        int turnLelo = 0;
        // only if it can be done
        if(turn == 1){
            int nextx = currx + dir[(direction+1)%4].first , nexty = curry + dir[(direction+1)%4].second;
            if(nextx >= 0 && nextx < grid.size() && nexty >=0 && nexty < grid[0].size() && grid[nextx][nexty] == nextValue){
                turnLelo = 1 + doit(nextx , nexty , (direction+1)%4 , 0 , grid);
            }
        }

        return dp[currx][curry][direction][turn] = max(turnLelo , goForward);

    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        int maxi = 0;
        memset(dp , -1 , sizeof(dp));
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(grid[i][j] == 1){
                    maxi = max(maxi , 1);
                    for(int k = 0 ; k<4 ; k++){
                        int newx = i+dir[k].first;
                        int newy = j+dir[k].second;
                        if(newx < 0 || newx >= m || newy < 0  || newy >= n) continue;
                        if(grid[newx][newy] == 2){
                            int get = 2 + doit(newx , newy , k , 1 , grid);
                            // x , y , curr direction , turn left
                            maxi = max(maxi , get);
                        }
                    }
                }
            }
        }
        return maxi;
    }
};