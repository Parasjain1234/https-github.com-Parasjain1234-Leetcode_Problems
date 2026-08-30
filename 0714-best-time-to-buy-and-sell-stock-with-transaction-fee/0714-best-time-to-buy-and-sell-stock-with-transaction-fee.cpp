class Solution {
public:
    int solve(int ind, int buy, vector<int>&prices, int n, int fee,  vector<vector<int>>dp){
        if(ind==n) return 0;

        if(dp[ind][buy]!= -1) return dp[ind][buy];

        if(buy) return dp[ind][buy]= max((-prices[ind]+ solve(ind+1, 0, prices, n, fee, dp)), ( 0+solve(ind+1, 1, prices, n, fee, dp) ));

        return dp[ind][buy]= max((prices[ind]- fee + solve(ind+1, 1, prices, n, fee, dp)), (0+ solve(ind+1, 0, prices, n, fee, dp)));
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n= prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2,0));
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<=1; j++){
                if(j) dp[i][j]= max( -prices[i]+ dp[i+1][0], 0+ dp[i+1][1]);
                else dp[i][j]= max(prices[i]- fee + dp[i+1][1],  0+ dp[i+1][0]);


            }
        }
        return dp[0][1];
    }
};