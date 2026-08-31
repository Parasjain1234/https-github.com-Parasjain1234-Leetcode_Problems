class Solution {
public:
      int fun(int ind, int prev, vector<int>& nums, vector<vector<int>>dp){
    if(ind < 0) return 0;
    if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];

    int not_pick = fun(ind - 1, prev, nums, dp);

    int pick = 0;

    if(prev == -1 || nums[ind] < nums[prev]){
        pick = 1 + fun(ind - 1, ind, nums, dp);
    }

    return dp[ind][prev+1]= max(pick, not_pick);
    }

    int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();

    //vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
         vector<vector<int>> dp(n, vector<int>(n + 1, 0));

  for(int i = 0; i < n; i++){
       for(int prev = -1; prev < n; prev++){

        int not_pick = 0;

        if(i > 0)
            not_pick = dp[i-1][prev+1];

        int pick = 0;

        if(prev == -1 || nums[i] < nums[prev]){
            if(i == 0)
                pick = 1;
            else
                pick = 1 + dp[i-1][i+1];
        }

        dp[i][prev+1] = max(pick, not_pick);
       }
    }

        return dp[n-1][0];  

    
    }
    
};