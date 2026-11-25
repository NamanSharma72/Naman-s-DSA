class Solution {
public:
    void doit(int idx , vector<int>& candidates , int target , vector<int> &use ,vector<vector<int>> &ans , int sum){
        if(sum == target){
            ans.push_back(use);
            return;
        }
        if(sum > target) return;
        if(idx >= candidates.size()) return;
        use.push_back(candidates[idx]);
        sum+=candidates[idx];
        doit(idx , candidates , target , use , ans , sum);
        sum-=candidates[idx];
        use.pop_back();
        doit(idx+1 , candidates , target , use , ans , sum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> use;
        vector<vector<int>> ans;
        doit(0 , candidates , target , use , ans , 0);
        return ans;
    }
};