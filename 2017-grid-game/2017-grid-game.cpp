class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> firstHalf(n);
        vector<long long> secondHalf(n);
        long long firstSum = 0;
        for(int i = n-1 ; i>=0 ; i--){
            firstHalf[i] = firstSum;
            firstSum+=grid[0][i];
        }
        long long secondSum = 0;
        for(int i = 0 ; i<n ; i++){
            secondHalf[i] = secondSum;
            secondSum+=grid[1][i];
        }
        long long mini = LLONG_MAX;
        for(int i = 0 ; i<n ; i++){
            mini = min(mini , max(firstHalf[i] , secondHalf[i]));
        }
        return mini;
    }
};