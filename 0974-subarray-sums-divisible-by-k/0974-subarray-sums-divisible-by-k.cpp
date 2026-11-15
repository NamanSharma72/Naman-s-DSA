class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> mpp(10001 , 0);
        int count = 0;
        int sum = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            sum+=nums[i];
            int rem = ((sum%k)+k)%k;
            count+=mpp[rem];
            if(rem == 0) count++;
            mpp[rem]++;
        }
        return count;
    }
};