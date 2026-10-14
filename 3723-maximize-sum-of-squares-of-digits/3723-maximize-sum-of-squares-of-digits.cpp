class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > num*9) return "";
        string ans = "";
        for(int i = 0 ; i<num ; i++){
            if(sum-9 >=0){
                ans+='9';
                sum-=9;
            }
            else{
                ans+=(sum + '0');
                sum = 0;
            }
            if(sum == 0) break;
        }
        int left = num - ans.size();
        while(left > 0){
            ans+='0';
            left--;
        }
        return ans;
    }
};