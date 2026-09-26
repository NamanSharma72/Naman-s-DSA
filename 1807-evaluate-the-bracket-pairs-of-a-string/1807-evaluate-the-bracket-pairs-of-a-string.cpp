class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string , string> mpp;
        for(int i = 0 ; i<knowledge.size() ; i++){
            mpp[knowledge[i][0]] = knowledge[i][1];
        }
        string ans = "";
        int flag = 0;
        string collect = "";
        int index = 0;
        while(index < s.size()){
            if(s[index] == '('){
                flag = 1;
            }
            else if(s[index] == ')'){
                flag = 0;
                if(mpp.find(collect) != mpp.end()) ans+=mpp[collect];
                else ans+="?";
                collect = "";
            }
            else{
                if(flag == 1) collect+=s[index];
                else ans+=s[index];
            }
            index++;
        }
        return ans;
    }
};