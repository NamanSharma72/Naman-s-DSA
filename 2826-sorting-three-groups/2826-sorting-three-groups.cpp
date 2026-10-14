class Solution {
public:
    // int dp[101][101];
    // int doit(int idx , vector<int>& nums , int prev){
    //     if(idx == nums.size()) return 0;
    //     if(dp[idx][prev] != -1) return dp[idx][prev];
    //     int skip = doit(idx+1 , nums , prev);
    //     int take = 0;
    //     if(prev == 0 || nums[idx] >= nums[prev-1]){
    //         take = 1 + doit(idx+1 , nums , idx+1);
    //     }
    //     return dp[idx][prev] = max(take , skip);
    // }
    int minimumOperations(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1 , vector<int>(nums.size()+1 , 0));
        for(int i = nums.size()-1 ; i>=0 ; i--){
            for(int prev = 0 ; prev <=nums.size() ; prev++){
                int skip = dp[i+1][prev];
                int take = 0;
                if(prev == 0 || nums[i] >= nums[prev-1]) take = 1 + dp[i+1][i+1];
                dp[i][prev] = max(skip , take);
            }
        }
        return nums.size() - dp[0][0];
    }
};