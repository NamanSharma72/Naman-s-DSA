class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> minSet , maxSet;
        vector<double> ans;
        auto balance = [&](){
            while(maxSet.size() > minSet.size() + 1){
                minSet.insert(*(prev(maxSet.end())));
                maxSet.erase(prev(maxSet.end()));
            }
            while(minSet.size() > maxSet.size()){
                maxSet.insert(*(minSet.begin()));
                minSet.erase(minSet.begin());
            }
        };
        for(int i = 0 ; i<nums.size() ; i++){
            if(maxSet.empty() || nums[i] <= *(prev(maxSet.end()))){
                maxSet.insert(nums[i]);
            }
            else minSet.insert(nums[i]);
            balance();
            if(i >= k){
                int toRemove = nums[i-k];
                auto it = maxSet.find(toRemove);
                if(it != maxSet.end()) maxSet.erase(it);
                else{
                    auto it2 = minSet.find(toRemove);
                    minSet.erase(it2);
                }
                balance();
            }
            if(i >= k-1){
                double median;
                if(maxSet.size() > minSet.size()){
                    median = (double)(*(prev(maxSet.end())));
                }
                else{
                    median = ((double)*minSet.begin() + *(prev(maxSet.end())))/2.0;
                }
                ans.push_back(median);
            }
        }
        return ans;
    }
};