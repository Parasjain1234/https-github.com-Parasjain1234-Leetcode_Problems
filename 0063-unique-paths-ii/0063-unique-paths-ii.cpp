class Solution {
public:
    // int f(int i, int j, vector<vector<int>>&dp,vector<vector<int>>& Grid ){

    //     if(i>=0 && j>=0 && Grid[i][j]==1 ) return 0;
    //     if(i==0 && j==0 ) return 1;
    //     if(i<0 || j<0) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int up=0, left=0;
    //      if(i>0)  up= f(i-1,j, dp, Grid);
    //     if(j>0) left= f(i, j-1, dp, Grid);
    //     return up+left;
        

    // }
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        int m= Grid.size();
        int n= Grid[0].size();

        vector<vector<int>>dp(m, vector<int>(n,0));
        // int ans=f(m-1, n-1, dp,Grid);
        // return ans;
        // dp[0][0]=1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(Grid[i][j]==1) dp[i][j]=0;
                else if(i==0 && j==0) dp[i][j]=1;
                else{
                    int up=0, left=0;
                    if(i>0) up= dp[i-1][j];
                    if(j>0) left= dp[i][j-1];
                    dp[i][j]=up+left;
                }
            }

        }
        return dp[m-1][n-1];
    }
};