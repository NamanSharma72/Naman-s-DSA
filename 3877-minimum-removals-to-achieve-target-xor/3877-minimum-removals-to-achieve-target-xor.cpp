class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        vector<int> next(16384 , 0);
        vector<int> curr(16384 , 0);
        for(int i = 0 ; i<16384 ; i++){
            if(i == target) next[i] = 0;
            else next[i] = -50;
        }
        for(int i = nums.size()-1 ; i>=0 ; i--){
            for(int xo = 0 ; xo<16384 ; xo++){
                int notTake = next[xo];
                int take = 1 + next[xo ^ nums[i]];
                curr[xo] = max(take , notTake);
            }
            swap(curr , next);
        }
        if(next[0] < 0) return -1;
        return nums.size()-next[0];
    }
};