class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int first = nums[nums.size()-1] - nums[2];
        int second = nums[nums.size()-3] - nums[0];
        int third = nums[nums.size()-2] - nums[1];
        return min(first , min(second , third));
    }
};