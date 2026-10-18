class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sum = INT_MAX;
        int maxi = INT_MAX;
        sort(nums.begin() , nums.end());
        for(int i = 0 ; i<nums.size()-2 ; i++){
            int left = i+1 , right = nums.size()-1;
            while(left < right){
                int use = nums[i] + nums[left] + nums[right];
                int diff = abs(target - use);
                if(diff <= maxi){
                    sum = use;
                    maxi = diff;
                }
                if(use < target) left++;
                else right--;
            }
        }
        return sum;
    }
};