class Solution {
public:
     
    int solve(int i, int n, vector<int>&costs){
        if(i==n) return 0;

        int j= i+1;
         int cost = INT_MAX;

        if(j<=n){cost= costs[j-1]+ (j-i)*(j-i)+ solve(j, n, costs);}

        j= i+2;
        if(j<=n){cost= min(cost, costs[j-1]+ (j-i)*(j-i)+ solve(j, n, costs));}

        j= i+3;
        if(j<=n){cost= min(cost, costs[j-1]+ (j-i)*(j-i) + solve(j, n, costs));}


        return cost;

    }
    int climbStairs(int n, vector<int>& costs) {

        vector<int>dp(n+1, 0);
        for(int i= n-1; i>=0; i--){
            int cost= INT_MAX;
             int j= i+1;
        

        if(j<=n)cost= costs[j-1]+ (j-i)*(j-i)+ dp[j];

        j= i+2;
        if(j<=n)cost = min(cost, costs[j-1]+ (j-i)*(j-i)+ dp[j]);

        j= i+3;
        if(j<=n)cost= min(cost, costs[j-1]+ (j-i)*(j-i) + dp[j]);

        dp[i]= cost;

        }
       
        return dp[0];
    }
};