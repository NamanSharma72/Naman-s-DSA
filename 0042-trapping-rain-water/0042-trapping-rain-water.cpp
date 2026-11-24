class Solution {
public:
    int trap(vector<int>& nums) {
        vector<int> maxRight(nums.size());
        vector<int> maxLeft(nums.size());
        int maxR = -1;
        for(int i = nums.size()-1 ; i>=0 ; i--){
            maxRight[i] = maxR;
            maxR = max(maxR , nums[i]);
        }
        int maxL = -1;
        for(int i = 0  ; i<=nums.size()-1 ; i++){
            maxLeft[i] = maxL;
            maxL = max(maxL , nums[i]);
        }
        int ans = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            if(min(maxRight[i] , maxLeft[i]) > nums[i]) ans+=(min(maxRight[i] , maxLeft[i]) - nums[i]);
        }
        return ans;
    }
};