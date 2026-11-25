class Solution {
public:
    void doit(int num , int k , int target , vector<int> &use , vector<vector<int>> &ans , int sum){
        if(use.size() == k){
            if(sum == target) ans.push_back(use);
        }
        for(int i = num ; i<=9 ; i++){
            sum+=i;
            use.push_back(i);
            doit(i+1 , k , target , use , ans , sum);
            sum-=i;
            use.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> use;
        vector<vector<int>> ans;
        doit(1 , k , n , use , ans , 0);
        return ans;
    }
};