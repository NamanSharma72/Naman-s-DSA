class Solution {
public:
    vector<string> ans;
    void doit(int idx , int size , int opened , int closed , string &use){
        if(idx == size){
            ans.push_back(use);
            return;
        }
        // choosing open only if it is less than half
        if(opened < (size/2)){
            use+="(";
            doit(idx+1 , size , opened+1 , closed , use);
            use.pop_back();
        }
        // closing close but only if there is an open 
        if(closed < opened){
            use+=")";
            doit(idx+1 , size , opened , closed+1 , use);
            use.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        string use = "";
        doit(0 , 2*n , 0 , 0 , use);
        return ans;
    }
};