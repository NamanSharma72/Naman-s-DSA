class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2){
        long long sum = 0;
        long long difference = 0;
        int total = k1+k2;
        long long totalDifference = 0;
        map<int , int> mpp;
        for(int i = 0 ; i<nums1.size() ; i++){
            sum = sum + 1LL * abs(nums1[i] - nums2[i]) * abs(nums1[i] - nums2[i]);
            difference = abs(nums1[i] - nums2[i]);
            totalDifference+=abs(nums1[i] - nums2[i]);
            mpp[difference]++;
        }
        if(sum == 0 || total > totalDifference) return 0;
    
        while(!mpp.empty() && total > 0){
            auto it = prev(mpp.end());
            int key = it->first;
            int value = it->second;
            if(value > total){
                mpp[key] = value - total;
                if(key-1 > 0) mpp[key-1]+=total;
                sum = sum - 1LL * total * key * key;
                if(key-1 >= 0) sum = sum + 1LL * total * (key-1) * (key-1);
                total = 0;
            }
            else{
                mpp.erase(key);
                if(key-1 > 0) mpp[key-1]+=value;
                sum = sum - 1LL * value * key * key;
                if(key-1 >= 0) sum = sum + 1LL * value * (key-1) * (key-1);
                total = total - value;
            }
        }

        return sum;
    }
};