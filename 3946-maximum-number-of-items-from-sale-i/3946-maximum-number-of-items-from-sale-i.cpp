class Solution {
public:
    int doit(int index , vector<int> &itemscost , vector<int> &copies , int budget , int &mincost , vector<vector<int>> &dp)
    {
        if(index == itemscost.size())
        {
            if(budget >= mincost) return budget/mincost;
            return 0;
        }
        if(dp[index][budget] != -1) return dp[index][budget];
        int notTake = doit(index+1 , itemscost , copies , budget , mincost , dp);
        int take = INT_MIN;
        if(budget - itemscost[index] >= 0)
        {
            take = copies[index] + doit(index+1 , itemscost , copies , budget-itemscost[index] , mincost , dp);
        }
        return dp[index][budget] = max(take , notTake);
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        vector<int> copies(items.size());
        int mincost = INT_MAX;
        for(int i = 0 ; i<items.size() ; i++)
            {
                int count = 0;
                if(items[i][1] < mincost)
                {
                    mincost = items[i][1];
                }
                for(int j = 0 ; j<items.size() ; j++)
                    {
                        if(i == j) continue;
                        if(items[j][0]%items[i][0] == 0) count++;
                    }
                copies[i] = count+1;
            }
        vector<int> itemscost(items.size());
        for(int i = 0 ; i<items.size() ; i++)
            {
                itemscost[i] = items[i][1];
            }
        vector<vector<int>> dp(itemscost.size() , vector<int>(budget+1 , -1));
        return doit(0 , itemscost , copies , budget , mincost , dp);
    }
};