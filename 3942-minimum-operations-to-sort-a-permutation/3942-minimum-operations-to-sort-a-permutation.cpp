class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        int pos0 = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i]==0) pos0 = i;
            int prev = nums[(i-1+n)%n] , next = nums[(i+1+n)%n];
            if((abs(nums[i]-prev) >= 2 || abs(nums[i]-next) >= 2) && nums[i] != 0 && nums[i] != n-1) return -1;
        }
        if(pos0 == 0){
            if(nums[1] == 1) return 0;
            else return 2;
        }
        else if(pos0 == nums.size()-1){
            if(nums[pos0-1] == 1) return 1;
            return min(pos0 , n-pos0+2);
        }
        if(nums[pos0+1] == 1) return min(pos0 , n-pos0+2);
        else return min(n-pos0 , pos0+2);
        return 0;
    }
};