class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin() , nums.end());
        int i = 0;
        while(i < nums.size()){
            int left = i+1 , right = nums.size()-1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == 0){
                    ans.push_back({nums[i] , nums[left] , nums[right]});
                    left++;
                    right--;
                    while(left < right && nums[left] == nums[left-1]) left++;
                    while(right > left && nums[right] == nums[right+1]) right--;
                }
                else if(sum < 0) left++;
                else right--;
            }
            i++;
            while(i < nums.size() && nums[i] == nums[i-1]) i++;
        }
        return ans;
    }
};