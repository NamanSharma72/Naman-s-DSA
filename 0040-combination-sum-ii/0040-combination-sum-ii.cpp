class Solution {
public:
    void doit(int idx , vector<int>& candidates , int target , vector<int> &use ,vector<vector<int>> &ans , int sum){
        if(sum == target){
            ans.push_back(use);
            return;
        }
        if(sum > target) return;
        if(idx >= candidates.size()) return;
        for(int i = idx ; i<candidates.size() ; i++){
            if(i > idx && candidates[i] == candidates[i-1]) continue;
            if(sum+candidates[i] > target) break;
            use.push_back(candidates[i]);
            sum+=candidates[i];
            doit(i+1 , candidates , target , use , ans , sum);
            sum-=candidates[i];
            use.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());
        vector<int> use;
        vector<vector<int>> ans;
        doit(0 , candidates , target , use , ans , 0);
        return ans;
    }
};