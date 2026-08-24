class Solution {
public:
    int solve(int ind1, int ind2, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>&dp){
        if(ind1<0 || ind2<0) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(nums1[ind1]== nums2[ind2]) return dp[ind1][ind2]= 1+ solve(ind1-1, ind2-1, nums1, nums2, dp);
        return dp[ind1][ind2]=0;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size();
        int m= nums2.size();
        int ans=0;

        vector<vector<int>>dp(n, vector<int>(m,-1));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                ans = max(ans, solve(i, j, nums1, nums2, dp));

            }
        }

        return ans;
    }
};