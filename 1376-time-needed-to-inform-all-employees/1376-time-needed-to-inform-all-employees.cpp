class Solution {
public:
    int doit(int idx , vector<vector<int>> &adj , vector<int>& informTime){
        int maxi = 0;
        for(auto &it : adj[idx]){
            maxi = max(maxi , doit(it , adj , informTime));
        }
        return maxi + informTime[idx];
    }
    int numOfMinutes(int n, int headID, vector<int>& nums, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        int boss = -1;
        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i] != -1){
                adj[nums[i]].push_back(i);
            }
            else boss = i;
        }
        return doit(boss , adj , informTime);
    }
};