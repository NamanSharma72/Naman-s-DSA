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
            else if(sum > 0){
                ans+=(sum + '0');
                sum = 0;
            }
            else{
                ans+='0';
            }
        }
        // int left = num - ans.size();
        // while(left > 0){
        //     ans+='0';
        //     left--;
        // }
        return ans;
    }
};