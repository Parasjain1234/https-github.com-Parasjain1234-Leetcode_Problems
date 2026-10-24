
class Solution {
public:
    int fun(vector<int>&prices, int buy, int ind, vector<vector<int>>&dp){
        if(ind>=prices.size()) return 0;

        if(dp[ind][buy]!=-1) return dp[ind][buy];

        int profit=0;
        if(buy){
           profit= max(-prices[ind]+ fun(prices, 0, ind+1, dp), 0+ fun(prices, 1, ind+1, dp));
        }
        else profit= max(prices[ind]+ fun(prices, 1, ind+2, dp), 0+ fun(prices, 0, ind+1, dp));

        return dp[ind][buy]=profit;


    }
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>>dp(n+2, vector<int>(2,-1));
        int ans= fun(prices, 1, 0, dp);

        return ans;
    }
};

