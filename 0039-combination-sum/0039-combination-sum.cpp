class Solution {
public:
    void doit(int idx , int sum , vector<int>& candidates , int target , vector<int> &use , vector<vector<int>> &ans){
        if(sum > target || idx >= candidates.size()) return;
        if(sum == target) {
            ans.push_back(use);
            return;
        }
        sum+=candidates[idx];
        use.push_back(candidates[idx]);
        doit(idx , sum , candidates , target , use , ans);
        sum-=candidates[idx];
        use.pop_back();
        doit(idx+1 , sum , candidates , target , use , ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());
        vector<int> use;
        vector<vector<int>> ans;
        doit(0 , 0 , candidates , target , use , ans);
        return ans;
    }
};