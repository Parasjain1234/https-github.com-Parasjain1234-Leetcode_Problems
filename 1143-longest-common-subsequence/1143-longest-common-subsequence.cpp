class Solution {
public:
    int solve(int ind1, int ind2, string text1, string text2, vector<vector<int>>&dp){
        if(ind1<0 || ind2<0) return 0;
        
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(text1[ind1]== text2[ind2]) return dp[ind1][ind2]= 1+ solve(ind1-1, ind2-1, text1, text2, dp);
         return dp[ind1][ind2]= 0+ max(solve(ind1-1, ind2, text1, text2,dp), solve(ind1, ind2-1, text1, text2, dp));

    }
    int longestCommonSubsequence(string text1, string text2) {
        int l= text1.size();
        int l1= text2.size();
        
        vector<vector<int>>dp(l+1, vector<int>(l1+1, 0));
        for(int ind1=1; ind1<=l; ind1++){
            for(int ind2=1; ind2<=l1; ind2++){
                 if(text1[ind1-1]== text2[ind2-1])  dp[ind1][ind2]= 1+ dp[ind1-1][ind2-1];
                 else  dp[ind1][ind2]= 0+ max(dp[ind1-1][ind2] , dp[ind1][ind2-1]);

            }
        }
        return dp[l][l1];
    }
};