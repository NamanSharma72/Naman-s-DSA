class Solution {
public:
    int x[4] = {0 , 1 , 0 , -1};
    int y[4] = {1 , 0 , -1 , 0};
    long long doit(int currx , int curry , int endx , int endy , vector<vector<int>>& grid){
        long long sum = grid[currx][curry];
        grid[currx][curry] = 0;
        for(int k = 0 ; k<4 ; k++){
            int newx = currx + x[k] , newy = curry + y[k];
            if(newx >= 0 && newx < endx && newy >= 0 && newy < endy && grid[newx][newy] > 0){
                sum=sum + doit(newx , newy , endx , endy , grid);
            }
        }
        
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size() , n = grid[0].size();
        int count = 0;
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(grid[i][j] > 0){
                    long long use = doit(i , j , m , n , grid);
                    if(use%k == 0) count++;
                }
            }
        }
        return count;
    }
};