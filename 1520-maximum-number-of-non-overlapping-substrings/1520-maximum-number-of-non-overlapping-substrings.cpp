class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> firstOccu(26 , -1);
        vector<int> lastOccu(26 , -1);
        for(int i = 0 ; i<s.size() ; i++){
            if(firstOccu[s[i]-'a'] == -1) firstOccu[s[i]-'a'] = i;
            lastOccu[s[i]-'a'] = i;
        }
        vector<pair<int , int>> pt;
        for(int i = 0 ; i<s.size() ; i++){
            if(i == firstOccu[s[i]-'a']){
                int start = firstOccu[s[i]-'a'] , end = lastOccu[s[i]-'a'];
                int maxLast = end;
                int minFirst = start;
                for(int j = start+1 ; j<= end ; j++){
                    maxLast = max(maxLast , lastOccu[s[j]-'a']);
                    end = max(end , lastOccu[s[j]-'a']);
                    minFirst = min(minFirst , firstOccu[s[j]-'a']);
                }
                firstOccu[s[i]-'a'] = minFirst;
                lastOccu[s[i]-'a'] = maxLast;
            }
        }
        for(int i = 0 ; i<s.size() ; i++){
            if(i == firstOccu[s[i]-'a']){
                int start = firstOccu[s[i]-'a'] , end = lastOccu[s[i]-'a'];
                    int maxLast = end;
                    int minFirst = start;
                    for(int j = start+1 ; j<= end-1 ; j++){
                        maxLast = max(maxLast , lastOccu[s[j]-'a']);
                        minFirst = min(minFirst , firstOccu[s[j]-'a']);
                    }
                pt.push_back({minFirst , maxLast});
            }
        }
        vector<pair<int , int>> finalPt;
        for(int i = 0 ; i<pt.size() ; i++){
            if(finalPt.empty()) finalPt.push_back(pt[i]);
            else{
                while(!finalPt.empty() && pt[i].second <= finalPt.back().second){
                    finalPt.pop_back();
                }
                if(finalPt.empty()) finalPt.push_back(pt[i]);
                if(pt[i].first > finalPt.back().second) finalPt.push_back(pt[i]);
            }
        }
        vector<string> ans;
        for(int i = 0 ; i<finalPt.size() ; i++){
            string st = s.substr(finalPt[i].first , finalPt[i].second - finalPt[i].first + 1);
            ans.push_back(st);
        }
        return ans;
    }
};