class Solution {
public:
    // int dp[40][16384];
    // int doit(int idx , vector<int>& nums , int target , int xo){
    //     if(idx == nums.size()){
    //         if(xo == target) return 0;
    //         return -50;
    //     }
    //     if(dp[idx][xo] != -1) return dp[idx][xo];
    //     int notTake = doit(idx+1 , nums , target , xo);
    //     int take = 1 + doit(idx+1 , nums , target , xo ^ nums[idx]);
    //     return dp[idx][xo] = max(take , notTake);
    // }
    int minRemovals(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size()+1 , vector<int>(16384 , 0));
        for(int i = 0 ; i<16384 ; i++){
            if(i == target) dp[nums.size()][i] = 0;
            else dp[nums.size()][i] = -50;
        }
        for(int i = nums.size()-1 ; i>=0 ; i--){
            for(int xo = 0 ; xo<16384 ; xo++){
                int notTake = dp[i+1][xo];
                int take = 1 + dp[i+1][xo ^ nums[i]];
                dp[i][xo] = max(take , notTake);
            }
        }
        if(dp[0][0] < 0) return -1;
        return nums.size()-dp[0][0];
    }
};