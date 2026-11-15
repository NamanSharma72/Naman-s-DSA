class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int , int> mpp;
        int count = 0;
        int sum = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            sum+=nums[i];
            int rem;
            if(sum >=0) rem = sum%k;
            else rem = ((sum%k)+k)%k;
            count+=mpp[rem];
            if(rem == 0) count++;
            mpp[rem]++;
        }
        return count;
    }
};