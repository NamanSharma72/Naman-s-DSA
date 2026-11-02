class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int ans = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            int curr = i , original = nums[i]-1;
            if(curr == original) continue;
            int start = curr < original ? curr : original;
            int end = curr > original ? curr : original;
            for(int j = start ; j<= end ; j++){
                if(locked[j] == 1){
                    if(k <= 0) return -1;
                    else{
                        k--;
                        locked[j] = 0;
                        ans++;
                    }
                }
            }
        }
        for(int i = 0 ; i<nums.size()-1 ; i++){
            for(int j = i+1 ; j<nums.size() ; j++){
                if(nums[i] > nums[j]) ans++;
            }
        }
        return ans;
    }
};