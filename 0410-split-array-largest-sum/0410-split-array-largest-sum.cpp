class Solution {
public:
    bool doit(long long maxi , vector<int>& nums , int totalStudents){
        int countStudents = 0;
        long long sum = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            if(sum+nums[i] > maxi){
                countStudents++;
                sum = nums[i];
            }
            else sum+=nums[i];
        }
        if(sum > 0) countStudents++;
        return countStudents <= totalStudents;
    }
    int splitArray(vector<int>& nums, int k) {
        long long low = *max_element(nums.begin() , nums.end());
        long long high = accumulate(nums.begin() , nums.end() , 1LL);
        long long ans = -1;
        while(low <= high){
            long long mid = high - ((high-low)/2);
            if(doit(mid , nums , k)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return (int)ans;
    }
};