class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int negs1 = 0;
        int maxLen1 = 0;
        int start1 = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i] == 0){
                negs1 = 0;
                start1 = i+1;
            }
            else if(nums[i] < 0) {
                negs1++;
            }
            if(negs1%2 == 0){
                maxLen1 = max(maxLen1 , i-start1+1);
            }
        }

        int negs2 = 0;
        int maxLen2 = 0;
        int start2 = nums.size()-1;
        for(int i = nums.size()-1 ; i>=0 ; i--){
            if(nums[i] == 0){
                negs2 = 0;
                start2 = i-1;
            }
            else if(nums[i] < 0) {
                negs2++;
            }

            if(negs2%2 == 0){
                maxLen2 = max(maxLen2 , start2-i+1);
            }
        }

        return max(maxLen1 , maxLen2);
    }
};