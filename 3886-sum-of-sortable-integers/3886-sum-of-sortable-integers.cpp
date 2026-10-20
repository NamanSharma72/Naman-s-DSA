class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        vector<int> original = nums;
        sort(original.begin() , original.end());
        if(original == nums) ans++;
        for(int i = 2 ; i<=nums.size() ; i++){
            if(n%i == 0){
                long long originalSum = 0;
                long long sum = 0;
                int count = 0;
                int flag = 0;
                int start = 0;
                for(int j = 0 ; j<nums.size() ; j++){
                    originalSum+=original[j];
                    sum+=nums[j];
                    if((j+1)%i == 0){
                        if(nums[j] > nums[start]) count++;
                        if(j > start && nums[j-1] > nums[j]) count++;
                        if(count > 1 || originalSum != sum){
                            flag = 1;
                            break;
                        }
                        start = j+1;
                        flag = 0;
                        count = 0;
                    }
                    else{
                        if(j > start && nums[j-1] > nums[j]) count++;
                        if(count > 1){
                            flag = 1;
                            break;
                        }
                    }
                }
                if(flag == 0) ans+=i;
            }

        }
        return ans;
    }
};