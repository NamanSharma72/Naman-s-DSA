class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if(n == 1) return "";
        int index = -1;
        for(int i = 0 ; i<n ; i++){
            if(n%2 != 0){
                if(i != n/2){
                    if(palindrome[i] != 'a'){
                        index = i;
                        break;
                    }
                }
            }
            else{
                if(palindrome[i] != 'a'){
                    index = i;
                    break;
                }
            }
        }
        if(index != -1){
            palindrome[index] = 'a';
            return palindrome;
        }
        palindrome[n-1] = 'b';
        return palindrome;
    }
};