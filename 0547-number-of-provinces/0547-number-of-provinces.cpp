class Solution {
public:
    void doit(int node , vector<vector<int>> &adj , vector<int> &visited){
        visited[node] = 1;
        for(auto &it : adj[node]){
            if(visited[it] == 0) doit(it , adj , visited);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        vector<vector<int>> adj(isConnected.size());
        for(int i = 0 ; i<isConnected.size() ; i++){
            for(int j = 0 ; j<isConnected[i].size() ; j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> visited(isConnected.size() , 0);
        for(int i = 0 ; i<isConnected.size() ; i++){
            if(!visited[i]){
                count++;
                doit(i , adj , visited);
            }
        }
        return count;
    }
};