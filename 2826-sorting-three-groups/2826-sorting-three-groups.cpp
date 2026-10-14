class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int> next(nums.size()+1 , 0);
        vector<int> curr(nums.size()+1);
        for(int i = nums.size()-1 ; i>=0 ; i--){
            for(int prev = 0 ; prev <=nums.size() ; prev++){
                int skip = next[prev];
                int take = 0;
                if(prev == 0 || nums[i] >= nums[prev-1]) take = 1 + next[i+1];
                curr[prev] = max(skip , take);
            }
            swap(curr , next);
        }
        return nums.size() - next[0];
    }
};