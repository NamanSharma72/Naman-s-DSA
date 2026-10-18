class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size() , n = grid[0].size();
        // vector<vector<int>> visited(m , vector<int>(n , 0));
        int row = 0 , col = 0;
        while(true){
            int newRow = row , newCol = col;
            if(grid[row][col] == 'L') newCol--;
            else if(grid[row][col] == 'R') newCol++;
            else if(grid[row][col] == 'U') newRow--;
            else newRow++;
            if(newRow < 0 || newCol < 0 || newRow >= m || newCol >= n || grid[newRow][newCol] == '?') break;
            grid[row][col] = '?';
            row = newRow;
            col = newCol;
        }
        return {row , col};
    }
};