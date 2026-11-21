class Solution {
public:
    vector<string> assignUmbrella(vector<int>& rain) {
        int alice = 0 , bob = 0;
        vector<string> ans;
        for(int i = 0 ; i<rain.size() ; i++){
            if(i == rain.size()-1){
                if(rain[i] == 1) {
                    ans.push_back("Bob");
                    bob++;
                }
                else ans.push_back("None");
            }
            else{
                if(rain[i] == 1){
                    if(rain[i+1] == 1){
                        if(alice <= bob) {
                            ans.push_back("Alice");
                            alice++;
                        }
                        else {
                            ans.push_back("Bob");
                            bob++;
                        }
                    }
                    else{
                        ans.push_back("Bob");
                        bob++;
                    }
                }
                else ans.push_back("None");
            }
        }
        return ans;
    }
};