class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size() , -1);
        queue<int> qt;
        for(int i = 0 ; i<graph.size() ; i++){
            if(color[i] == -1){
                qt.push(i);
                color[i] = 0;
                while(!qt.empty()){
                    int node = qt.front();
                    qt.pop();
                    int newColor = color[node] == 0 ? 1 : 0;
                    for(auto &it : graph[node]){
                        if(color[it] == -1){
                            color[it] = newColor;
                            qt.push(it);
                        }
                        else if(color[it] == color[node]) return false;
                    }
                }
            }
        }
        return true;
    }
};