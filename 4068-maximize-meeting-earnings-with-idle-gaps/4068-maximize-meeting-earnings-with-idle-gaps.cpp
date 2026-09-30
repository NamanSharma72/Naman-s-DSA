class Solution {
public:
    long long dp[100000][2];
    long long doit(int idx , vector<vector<int>>& meetings , int flag){
        if(idx >= meetings.size()) return 0;
        if(dp[idx][flag] != -1) return dp[idx][flag];
        long long skip = doit(idx+1 , meetings , flag);
        long long take = meetings[idx][2];
        int l = idx+1 , r = meetings.size()-1 ,  index = meetings.size();
        while(l <= r){
            int mid = l + ((r-l)/2);
            if(meetings[mid][0] >= meetings[idx][1]){
                index = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        if(flag == 0) {
            take-=(meetings[idx][1]);
        }
        else if(flag == 1){
            if(index == meetings.size()){
                take+=meetings[idx][0];
            }
            else{
                take+=meetings[idx][0];
                take-=(meetings[idx][1]);
            }
        }
        take+=doit(index , meetings , 1);
        return dp[idx][flag] = max(take , skip);
    }
    long long maxEarnings(vector<vector<int>>& meetings) {
        sort(meetings.begin() , meetings.end());
        memset(dp , -1 , sizeof(dp));
        long long maxi = doit(0 , meetings , 0);
        for(int i = 0 ; i<meetings.size() ; i++){
            maxi = max(maxi , (long long)meetings[i][2]);
        }
        return maxi;
    }
};