class Solution {
public:
    void doit(int node1 , int dist , vector<int> &distNode , vector<int>& edges , vector<int> &visited){
        if(node1 == -1) return;
        visited[node1] = 1;
        dist++;
        if(edges[node1] != -1 && visited[edges[node1]] == 0) {
            distNode[edges[node1]] = dist;
            doit(edges[node1] , dist , distNode , edges , visited);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> distNode1(n , -1);
        distNode1[node1] = 0;
        vector<int> distNode2(n , -1);
        distNode2[node2] = 0;
        vector<int> visited1(n , 0);
        vector<int> visited2(n , 0);
        doit(node1 , 0 , distNode1 , edges , visited1);
        doit(node2 , 0 , distNode2 , edges , visited2);
        int mini = INT_MAX;
        int minIndex = -1;
        for(int i = 0 ; i<distNode1.size() ; i++){
            if(distNode1[i] != -1 && distNode2[i] != -1){
                int maxi = max(distNode1[i] , distNode2[i]);
                if(maxi < mini){
                    mini = maxi;
                    minIndex = i;
                }
            }
        }
        return minIndex;
    }
};