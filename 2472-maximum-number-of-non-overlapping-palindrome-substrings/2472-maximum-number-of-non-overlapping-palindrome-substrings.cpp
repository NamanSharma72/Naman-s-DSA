class Solution {
public:
    int maxPalindromes(string s, int k) {
        if(k == 1) return s.size();
        int start = 0;
        int answer = 0;
        int prevEnd = -1;
        while(start < s.size()){
            int i = start-1 , j = start+1;
                int count = 1;
                int finalEnd1 = start;
                int flag1 = 0;
                while(i > prevEnd && j < s.size()){
                    if(s[i] == s[j]){
                        count+=2;
                        finalEnd1 = j;
                        if(count >= k) {
                            flag1 = 1;
                            break;
                        }
                        i--;
                        j++;
                    }
                    else break;
                }

            int flag2 = 0;
            int finalEnd2 = start+1;
            if(start+1 < s.size() && s[start+1] == s[start]){
                int count = 2;
                if(count >= k){
                    flag2 = 1;
                }
                else{
                    int ni = start-1 , nj = start+2;
                    while(ni > prevEnd && nj < s.size()){
                        if(s[ni] == s[nj]){
                            count+=2;
                            finalEnd2 = nj;
                            if(count >= k) {
                                flag2 = 1;
                                break;
                            }
                            ni--;
                            nj++;
                        }
                        else break;
                    }
                }
            }

            
            if(flag1 == 1 && flag2 == 1){
                prevEnd = min(finalEnd1 , finalEnd2);
                start = prevEnd+1;
                answer++;
            }
            else if(flag1 == 1){
                prevEnd = finalEnd1;
                start = prevEnd+1;
                answer++;
            }
            else if(flag2 == 1){
                prevEnd = finalEnd2;
                start = prevEnd+1;
                answer++;
            }
            else start++;
        }
        return answer;
    }
};