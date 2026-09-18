class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<pair<int,int> , int> mpp;
        for(int i = 0 ; i<intervals.size() ; i++) {
            mpp[{intervals[i][0] , intervals[i][1]}] = i;
        }
        sort(intervals.begin() , intervals.end());
        vector<int> ans(intervals.size());
        for(int i = 0 ; i<intervals.size() ; i++){
            int use = intervals.size() , low = i , high = intervals.size()-1;
            while(low <= high){
                int mid = low + ((high-low))/2;
                if(intervals[mid][0] >= intervals[i][1]){
                    use = mid;
                    high = mid-1;
                }
                else low = mid+1;
            }
            int originalIdx = mpp[{intervals[i][0] , intervals[i][1]}];
            if(use == intervals.size()) ans[originalIdx] = -1;
            else{
                int originalAnsIdx = mpp[{intervals[use][0] , intervals[use][1]}];
                ans[originalIdx] = originalAnsIdx;
            }
        }
        return ans;
    }
};