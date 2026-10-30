class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int , int>>> adj(n);
        for(int i = 0 ; i<edges.size() ; i++){
            adj[edges[i][0]].push_back({edges[i][1] , edges[i][2]});
        }
        vector<vector<int>> minTotal(n , vector<int>(k+1 , INT_MAX));
        priority_queue<tuple<int,int,int,char> , vector<tuple<int,int,int,char>> , greater<tuple<int,int,int,char>>> pq;
        pq.push({0 , 1 , 0 , labels[0]});
        minTotal[0][1] = 0;
        while(!pq.empty()){
            auto [currCost , currK , currNode , currChar] = pq.top();
            pq.pop();
            if(currCost > minTotal[currNode][currK]) continue;
            if(currNode == n-1) return currCost;
            for(auto &it : adj[currNode]){
                int newNode = it.first , newCost = it.second;
                if(labels[newNode] != currChar){
                    if(currCost + newCost < minTotal[newNode][1]){
                        minTotal[newNode][1] = currCost + newCost;
                        pq.push({currCost + newCost , 1 , newNode , labels[newNode]});
                    }
                }
                else if(currK+1 <= k){
                        int newK = currK+1;
                        if(currCost + newCost < minTotal[newNode][newK]){
                            minTotal[newNode][newK] = currCost + newCost;
                            pq.push({currCost + newCost , newK , newNode , labels[newNode]});
                        }
                    }
            }
        }
        return -1;
    }
};