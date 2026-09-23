class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int , int> suffix;
        int sum = 0;
        for(int i = nums.size()-1 ; i>=0 ; i--){
            sum+=nums[i];
            suffix[sum] = i;
        }
        int preSum = 0;
        int mini = INT_MAX;
        for(int i = 0 ; i<nums.size() ; i++){
            preSum+=nums[i];
            if(preSum == x) mini = min(mini , i+1);
            int left = x - preSum;
            if(suffix.find(left) != suffix.end() && suffix[left] > i){
                int size =  i+1 + (nums.size() - suffix[left]);
                mini = min(mini , size);
            }
        }
        if(suffix.find(x) != suffix.end()){
            int last = nums.size() - suffix[x];
            mini = min(mini , last);
        }
        if(mini == INT_MAX) return -1;
        return mini;
    }
};