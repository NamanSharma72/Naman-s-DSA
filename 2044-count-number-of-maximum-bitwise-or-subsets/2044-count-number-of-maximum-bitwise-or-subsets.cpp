class Solution {
public:
    int doit(int idx , vector<int>& nums , int maxi , int xo , vector<vector<int>> &dp){
        if(idx == nums.size()){
            if(xo == maxi) return 1;
            return 0;
        }
        if(dp[idx][xo] != -1) return dp[idx][xo];
        int take = 0;
        take+=doit(idx+1 , nums , maxi , xo | nums[idx] , dp);
        int skip = 0;
        skip+=doit(idx+1 ,  nums , maxi , xo , dp);
        return dp[idx][xo] = take + skip;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi = 0;
        for(int i = 0 ; i<nums.size() ; i++) maxi |= nums[i];
        vector<vector<int>> dp(nums.size() , vector<int>(maxi+1 , -1));
        int count = doit(0 , nums , maxi , 0 , dp);
        return count;
    }
};