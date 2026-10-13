class Solution {
public:
    static bool cmp(const int &a , const int &b){
        return abs(a) < abs(b);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin() , nums.end() , cmp);
        // for(int i = 0 ; i<nums.size() ; i++) cout << nums[i] << " ";
        int count = nums.size()/2;
        long long sum = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            if(i < count) sum = sum - (nums[i] * nums[i]);
            else sum = sum + (nums[i] * nums[i]);
        }
        return sum;
    }
};