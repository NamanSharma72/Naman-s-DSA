class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<pair<int , int>>  use(nums.size());
        unordered_map<int , int> mpp;
        mpp.reserve(nums.size());
        for(int i = 0 ; i<nums.size() ; i++){
            int sum = 0 , num = nums[i];
            while(num != 0){
                int a = num%10;
                sum+=a;
                num = num/10;
            }
            use[i] = {sum , nums[i]};
            mpp[use[i].second] = i;
        }
        vector<pair<int , int>> helper = use;
        sort(helper.begin() , helper.end());
        int count = 0;
        for(int i = 0 ; i<use.size() ; i++){
            if(use[i].second != helper[i].second){
                count++;
                int original = mpp[helper[i].second];
                mpp[use[i].second] = original;
                mpp[use[original].second] = i;
                swap(use[i] , use[original]);
            }
        }
        return count;
    }
};