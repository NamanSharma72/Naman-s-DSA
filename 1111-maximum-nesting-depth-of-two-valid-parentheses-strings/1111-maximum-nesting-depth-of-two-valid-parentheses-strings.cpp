class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int openingG1 = 0 , openingG2 = 0 , closingG1 = 0 , closingG2 = 0;
        vector<int> ans;
        for(int i = 0 ; i<seq.size() ; i++){
            if(seq[i] == '('){
                if(openingG1 == openingG2){
                    ans.push_back(0);
                    openingG1++;
                }
                else if(openingG1 > openingG2){
                    ans.push_back(1);
                    openingG2++;
                }
            }
            if(seq[i] == ')'){
                if(closingG1 == closingG2){
                    ans.push_back(0);
                    closingG1++;
                }
                else if(closingG1 > closingG2){
                    ans.push_back(1);
                    closingG2++;
                }
            }
        }
        return ans;
    }
};