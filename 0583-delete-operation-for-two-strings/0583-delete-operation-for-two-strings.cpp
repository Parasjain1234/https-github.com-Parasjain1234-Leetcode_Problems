class Solution {
public:
    int solve(int i, int j, string &word1, string &word2, vector<vector<int>>&dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]== word2[j]) return dp[i][j]= 1+ solve(i-1, j-1, word1, word2, dp);
        return dp[i][j]= 0+ max(solve(i-1, j, word1, word2, dp), solve(i, j-1, word1, word2, dp));
    }
    int minDistance(string word1, string word2) {
        int n= word1.size();
        int m= word2.size();

        
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(word1[i-1]==word2[j-1]) dp[i][j]= 1+ dp[i-1][j-1];
                else dp[i][j]= 0+ max(dp[i-1][j], dp[i][j-1]);
            }
        }
        int len= dp[n][m];
        return n+m- 2*len;
    }
};