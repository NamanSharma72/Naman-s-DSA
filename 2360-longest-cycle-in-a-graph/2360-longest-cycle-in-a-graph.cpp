class Solution {
public:
    int maxi = -1;
    bool doit(int node , vector<int> &edges , vector<int> &visited , 
    vector<int> &pathVis , int num){
        visited[node] = num;
        pathVis[node] = 1;
        if(edges[node] == -1) {
            pathVis[node] = 0;
            return false;
        }
        if(!visited[edges[node]]){
            if(doit(edges[node] , edges , visited , pathVis , num+1)) {
                pathVis[node] = 0;
                return true;
            }
        }
        else if(pathVis[edges[node]]){
            maxi = max(maxi , num - visited[edges[node]]+1);
            pathVis[node] = 0;
            return true;
        }
        pathVis[node] = 0;
        return false;
    }
    int longestCycle(vector<int>& edges) {
        vector<int> visited(edges.size() , 0);
        vector<int> pathVis(edges.size() , 0);
        for(int i = 0 ; i<edges.size() ; i++){
            if(!visited[i]){
                doit(i , edges , visited , pathVis , 1);
            }
        }
        return maxi;
    }
};