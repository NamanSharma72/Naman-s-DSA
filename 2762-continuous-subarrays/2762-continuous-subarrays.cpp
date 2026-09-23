class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        deque<int> maxi , mini;
        long long count = 0;
        int l = 0 , r = 0;
        while(r < nums.size()){
            while(!maxi.empty() && nums[r] > maxi.back()){
                maxi.pop_back();
            }
            maxi.push_back(nums[r]);
            while(!mini.empty() && nums[r] < mini.back()){
                mini.pop_back();
            }
            mini.push_back(nums[r]);
            while(abs(maxi.front() - nums[r]) > 2 || abs(mini.front() - nums[r]) > 2){
                if(!maxi.empty() && nums[l] == maxi.front()) maxi.pop_front();
                if(!mini.empty() && nums[l] == mini.front()) mini.pop_front();
                l++;
            }
            count+=(r-l+1);
            r++;
        }
        return count;
    }
};