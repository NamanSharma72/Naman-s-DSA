class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin() , strs.end());
        string first = strs[0] , second = strs[strs.size()-1];
        string ans = "";
        int i1 = 0 , i2 = 0;
        while(i1 < first.size() && i2 < second.size()){
            if(first[i1] == second[i2]) ans+=first[i1];
            else break;
            i1++;
            i2++;
        }
        return ans;
    }
};