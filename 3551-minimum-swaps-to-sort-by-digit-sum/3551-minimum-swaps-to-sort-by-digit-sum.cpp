class Solution {
public:
    static bool cmp(const pair<int,int> &a , const pair<int,int> &b){
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    }
    int minSwaps(vector<int>& nums) {
        vector<pair<int , int>>  use;
        for(int i = 0 ; i<nums.size() ; i++){
            int sum = 0 , num = nums[i];
            while(num != 0){
                int a = num%10;
                sum+=a;
                num = num/10;
            }
            use.push_back({sum , nums[i]});
        }
        vector<pair<int , int>> helper = use;
        sort(helper.begin() , helper.end() ,  cmp);
        // for(int i = 0 ; i<helper.size() ; i++) cout << helper[i].first << " " << helper[i].second << endl;
        unordered_map<int , int> mpp;
        for(int i = 0 ; i<use.size() ; i++) mpp[use[i].second] = i;
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