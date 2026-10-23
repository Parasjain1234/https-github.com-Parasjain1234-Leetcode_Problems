class Solution {
public:
    int solve(vector<int>&coins, int idx, int t, vector<vector<int>>&dp){
        if(idx==0){
            if(t%coins[0]==0) return t/coins[0];
            else return INT_MAX;
        }

        if(dp[idx][t]!=-1) return dp[idx][t];

        int not_take= 0+solve(coins, idx-1, t, dp);
        int take= INT_MAX;
        if(t>= coins[idx]){
            int res= solve(coins, idx, t- coins[idx], dp);
            if(res!= INT_MAX) take= 1+ res;
        }

        return dp[idx][t]=min(take, not_take);
    }
   
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        sort(coins.begin(), coins.end());
        int ans= solve(coins, n-1, amount, dp);
        if(ans== INT_MAX) return -1;

        return ans;
        
    }
};