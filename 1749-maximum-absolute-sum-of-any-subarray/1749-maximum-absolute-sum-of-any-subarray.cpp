class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxi = 0;
        int posSum = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            if(posSum < 0) posSum = nums[i];
            else posSum+=nums[i];
            maxi = max(maxi , posSum);
        }
        int mini = 0;
        int negSum = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            if(negSum > 0) negSum = nums[i];
            else negSum+=nums[i];
            mini = min(mini , negSum);
        }
        return max(maxi , abs(mini));
    }
};