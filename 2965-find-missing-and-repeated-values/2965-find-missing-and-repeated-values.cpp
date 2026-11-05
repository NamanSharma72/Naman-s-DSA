class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int num = n*n;
        long long givenSum = 0;
        long long givenSquareSum = 0;
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<n ; j++){
                givenSum+=grid[i][j];
                givenSquareSum = givenSquareSum + (1LL * grid[i][j] * grid[i][j]);
            }
        }
        long long expectedSum =(1LL * num * (num+1))/2;
        long long expectedSquareSum = (1LL * num * (num + 1) * (2*num +1))/6;
        long long z1 = givenSum - expectedSum;
        long long z2 = (givenSquareSum - expectedSquareSum)/z1;
        long long repeating = (z1 + z2)/2;
        long long missing = (z2 - z1)/2;
        return {(int)repeating , (int)missing};
    }
};