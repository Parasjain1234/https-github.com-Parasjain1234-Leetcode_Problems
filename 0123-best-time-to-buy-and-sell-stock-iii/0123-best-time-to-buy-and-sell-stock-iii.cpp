class Solution {
public:
    int fun(vector<int>&prices, int buy, int ind, vector<vector<vector<int>>>&dp, int cap){
        if(ind==prices.size() || cap==0) return 0;

        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];

        int profit=0;
        if(buy){
           profit= max(-prices[ind]+ fun(prices, 0, ind+1, dp, cap), 0+ fun(prices, 1, ind+1, dp, cap));
        }
        else profit= max(prices[ind]+ fun(prices, 1, ind+1, dp, cap-1), 0+ fun(prices, 0, ind+1, dp, cap));

        return dp[ind][buy][cap]=profit;


    }
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2,vector<int>(3,-1)));
        int ans= fun(prices, 1, 0, dp, 2);

        return ans;
    }
};