class Solution {
public:
    int minSelection(vector<vector<int>>& availableIntervals, vector<vector<int>>& targetIntervals) {
        sort(availableIntervals.begin() , availableIntervals.end());
        sort(targetIntervals.begin() , targetIntervals.end());
        vector<vector<int>> mergedTargets;
        for(int i = 0 ; i<targetIntervals.size() ; i++){
            if(mergedTargets.empty()) mergedTargets.push_back(targetIntervals[i]);
            else if(targetIntervals[i][0] <= mergedTargets.back()[1]){
                mergedTargets.back()[1] = max(targetIntervals[i][1] , mergedTargets.back()[1]);
            }
            else mergedTargets.push_back(targetIntervals[i]);
        }
        vector<vector<int>> mergedAvailable;
        for(int i = 0 ; i<availableIntervals.size() ; i++){
            if(mergedAvailable.empty()) mergedAvailable.push_back(availableIntervals[i]);
            else if(mergedAvailable.back()[0] <= availableIntervals[i][0] && mergedAvailable.back()[1] >= availableIntervals[i][1]){
                continue;
            }
            else if(mergedAvailable.back()[0] >= availableIntervals[i][0] && mergedAvailable.back()[1] <= availableIntervals[i][1]){
                mergedAvailable.back() = availableIntervals[i];
            }
            else mergedAvailable.push_back(availableIntervals[i]);
        }
        int aval = 0 , tar = 0;
        int count = 0;
        int prev = -1;
        while(tar < mergedTargets.size() && aval < mergedAvailable.size()){
            if(mergedAvailable[aval][0] > mergedTargets[tar][0]) return -1;
            else if(aval+1 < mergedAvailable.size() && mergedAvailable[aval+1][0] <= mergedTargets[tar][0] && mergedAvailable[aval+1][1] >= mergedTargets[tar][1] && prev != aval){
                aval++;
            }
            else if(mergedTargets[tar][0] >= mergedAvailable[aval][0] && mergedTargets[tar][1] <= mergedAvailable[aval][1]){
                if(aval != prev) count++;
                prev = aval;
                tar++;
            }
            else if(prev == aval && mergedTargets[tar][0] < mergedAvailable[aval][1]){
                mergedTargets[tar][0] = mergedAvailable[aval][1];
            }
            else if(aval+1 < mergedAvailable.size() && mergedAvailable[aval+1][0] <= mergedTargets[tar][0]) {
                prev = aval;
                aval++;
            }
            else{
                mergedTargets[tar][0] = mergedAvailable[aval][1];
                if(aval != prev) count++;
                prev = aval;
                aval++;
            }
        }
        if(tar < mergedTargets.size()) return -1;
        return count;
    }
};