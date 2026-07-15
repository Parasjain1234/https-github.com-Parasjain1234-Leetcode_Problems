class Solution {
public:
    int solve(int ind1, int ind2, string s, string st1, vector<vector<int>>&dp){
        if(ind1<0 || ind2<0) return 0;

        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];

        if(s[ind1]== st1[ind2]) return dp[ind1][ind2]= 1+ solve(ind1-1, ind2-1, s, st1,dp);
        return dp[ind1][ind2]= 0+ max(solve(ind1-1, ind2, s, st1, dp), solve(ind1, ind2-1, s, st1, dp));
    }
    int longestPalindromeSubseq(string s) {
        int n= s.size();
        string st1= "";
        for(auto i : s) st1+= i;
        reverse(st1.begin(), st1.end());

        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        
        for(int ind1=1; ind1<=n; ind1++){
            for(int ind2=1; ind2<=n; ind2++){
                if(s[ind1-1]== st1[ind2-1])  dp[ind1][ind2]= 1+ dp[ind1-1][ind2-1];
                else  dp[ind1][ind2]= 0+ max(dp[ind1-1][ind2], dp[ind1][ind2-1]);


            }
        }

        return dp[n][n];

    }
};