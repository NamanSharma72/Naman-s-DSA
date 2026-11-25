class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        int m = num1.size() , n = num2.size();
        vector<int> ans(m+n,0);
        for(int i = m-1 ; i>=0 ; i--){
            for(int j = n-1 ; j>=0 ; j--){
                int f = num1[i]-'0' , s = num2[j]-'0';
                int sum = f * s + ans[i+j+1];
                ans[i+j+1] = sum%10;
                ans[i+j]+=(sum/10);
            }
        }
        string finalAns = "";
        for(int i = 0 ; i<ans.size() ; i++){
            if(finalAns.empty() && ans[i] == 0) continue;
            finalAns+=(ans[i]+'0');
        }
        return finalAns;
    }
};