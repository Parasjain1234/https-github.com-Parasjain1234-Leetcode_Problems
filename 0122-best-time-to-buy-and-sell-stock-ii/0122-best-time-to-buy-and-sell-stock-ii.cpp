class Solution {
public:
    int solve(int ind, int buy, vector<int>&prices, int n, vector<vector<int>>&dp){
        if(ind==n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];

        int profit=0;
        if(buy){
            return dp[ind][buy]= max((-prices[ind]+ solve(ind+1, 0, prices, n, dp)), (0+ solve(ind+1, 1, prices, n, dp) ));
        }
        return dp[ind][buy]= max((prices[ind] + solve(ind+1, 1, prices, n, dp)), (0+ solve(ind+1, 0, prices, n, dp)));
    }
    int maxProfit(vector<int>& prices) {
       int n= prices.size();

       vector<vector<int>>dp(n, vector<int>(2,-1));

       return solve(0, 1, prices, n, dp);
    //    int mn= prices[0];
    //    int mx=0;
    //    int sum=0;
    //    for(int i=1; i<prices.size(); i++){
    //     mx= max(mx, prices[i]- mn);
    //     mn= min(mn, prices[i]);
    //     if(mx){
    //         sum+= mx;
    //         mx=0;
    //         mn= prices[i];
    //     }
    //    }
    //    return sum; 
    

    // vector<vector<int>>dp(n+1, vector<int>(2,0));
    
    //   for(int i=n-1; i>=0; i--){
    //     for(int j=0; j<2; j++){
    //         int profit=0;
    //         if(j){
    //             profit=  max((-prices[i]+ dp[i+1][0]),( 0 + dp[i+1][1]));

    //         }
    //         else {
    //             profit= max((prices[i]+ dp[i+1][1]),(0+ dp[i+1][0]));
    //         }

    //         dp[i][j]= profit;
    //     }
    //   }

    //   return dp[0][1];
    }

    
};