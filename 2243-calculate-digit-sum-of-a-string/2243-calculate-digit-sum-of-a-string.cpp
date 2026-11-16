class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size() > k){
            int idx = 0;
            string store = "";
            while(idx < s.size()){
                string use = idx+k-1 < s.size() ? s.substr(idx , k) : s.substr(idx , s.size()-idx);
                int count = 0;
                for(int i = 0 ; i<use.size() ; i++) count+=(use[i]-'0');
                store+=to_string(count);
                idx = idx+k-1 < s.size() ? idx+k : s.size();
            }
            s = store;
            cout << s << endl;
        }
        return s;
    }
};