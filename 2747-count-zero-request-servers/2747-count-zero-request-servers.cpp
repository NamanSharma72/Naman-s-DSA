class Solution {
public:
    static bool cmp(const vector<int> &a , const vector<int> &b){
        return a[1] < b[1];
    }
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin() , logs.end() , cmp);
        vector<int> ans(queries.size());
        vector<pair<int , int>> transQuery;
        for(int i = 0 ; i<queries.size() ; i++) transQuery.push_back({queries[i] , i});
        sort(transQuery.begin() , transQuery.end());
        int l = 0 , r = 0;
        vector<int> freq(n+1 , 0);
        int activeServers = 0;
        for(int i = 0 ; i<queries.size() ; i++){
            int start = transQuery[i].first-x , end = transQuery[i].first;
            while(l < logs.size() && logs[l][1] < start){
                if(l < r){
                    freq[logs[l][0]]--;
                    if(freq[logs[l][0]] == 0) activeServers--;
                }
                l++;
            }
            r = max(r , l);
            while(r < logs.size() && logs[r][1] <= end){
                freq[logs[r][0]]++;
                if(freq[logs[r][0]] == 1) activeServers++;
                r++;
            }
            ans[transQuery[i].second] = n-activeServers;
        }
        return ans;
    }
};