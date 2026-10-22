class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (is_sorted(nums.begin(), nums.end())) return 0;
        int pos0 = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            int first = 0 , second = 0;
            if(nums[i] == 0) pos0 = i;
            if(i == 0){
                first = (nums[i] - nums[i+1]);
                second = (nums[i] - nums[nums.size()-1]);
            }
            else if(i == nums.size()-1){
                first =(nums[i] - nums[0]);
                second =(nums[i] - nums[i-1]);
            }
            else{
                first = (nums[i] - nums[i-1]);
                second = (nums[i] - nums[i+1]);
            }
            if((first >= 2 || second >= 2) && nums[i] != 0 && nums[i] != nums.size()-1) return -1;
        }
        if(pos0 == 0){
            if(nums[1] == 1) return 0;
            return 2;
        }

        if(pos0 == nums.size()-1){
            if(nums[pos0-1] == 1) return 1;
            return min(pos0 , n-pos0+2);
        }

        if(nums[pos0+1] == 1){
            return min(pos0 , n-pos0+2);
        }
        else return min(n-pos0 , pos0+2);
        return 0;
    }
};