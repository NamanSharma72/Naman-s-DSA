class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = 0;
        int curr = 0;
        int maxElement = *max_element(nums.begin() , nums.end());
        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i] == maxElement) curr++;
            else curr = 0;
            maxi = max(maxi , curr);
        }
        return maxi;
    }
};