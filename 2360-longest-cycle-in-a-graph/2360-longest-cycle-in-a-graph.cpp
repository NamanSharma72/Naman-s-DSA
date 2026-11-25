class Solution {
public:
    int doit(int node , vector<int>& edges , vector<int> &visited , vector<int> &pathVis){
        visited[node] = 1;
        pathVis[node] = 1;
        int next = edges[node];
        if(next == -1){
            pathVis[node] = 0;
            return -1;
        }
        if(!visited[next]){
            int got = doit(next , edges , visited , pathVis);
            pathVis[node] = 0;
            return got;
        }
        else if(pathVis[next]){
            int count = 0;
            int temp = next;
            do{
                count++;
                temp = edges[temp];
            }while(temp != next);
            pathVis[node] = 0;
            return count;
        }
        pathVis[node] = 0;
        return -1;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> visited(n,0);
        vector<int> pathVis(n,0);
        int maxi = -1;
        for(int i = 0 ; i<n ; i++){
            if(!visited[i]){
                int ans = doit(i , edges , visited , pathVis);
                maxi = max(maxi , ans);
            }
        }
        return maxi;
    }
};