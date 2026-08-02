class Solution {
public:
    int fun(int ind, vector<int>& piles, vector<int>&dp){
        if(ind==0) return piles[ind];
        if(ind<0) return 0;

        if(dp[ind]!= -1) return dp[ind];

        int pick= piles[ind]+ fun(ind-2, piles, dp);
        int not_pick= 0+ fun(ind-1, piles, dp);

        return dp[ind]= max(pick, not_pick);
    }
    bool stoneGame(vector<int>& piles) {
        int n= piles.size();
        // int alice=0;
        // int bob=0;
        // int i=0;
        // int j=n-1;
        // while(i<j){
        //     if(piles[i]>=piles[j]){
        //         alice+= piles[i];
        //         i++;
        //     }
        //     else {
        //         alice+= piles[j];
        //         j--;
        //     }

        //     if(piles[i]>= piles[j]){
        //         bob+= piles[i];
        //         i++;
        //     }
        //     else {
        //         bob+= piles[j];
        //         j--;
        //     }
        // }

        // if(alice> bob) return true;


        // i=0;
        // j=n-1;
        // alice=0;
        // bob=0;
        // reverse(piles.begin(), piles.end());
        // while(i<j){
        //     if(piles[i]>=piles[j]){
        //         alice+= piles[i];
        //         i++;
        //     }
        //     else {
        //         alice+= piles[j];
        //         j--;
        //     }

        //     if(piles[i]>= piles[j]){
        //         bob+= piles[i];
        //         i++;
        //     }
        //     else {
        //         bob+= piles[j];
        //         j--;
        //     }
        // }
        // if(alice> bob) return true;


        // return false;
        vector<int>dp(n,-1);

        int ans= fun(n-1, piles, dp);

        int sum= accumulate(piles.begin(), piles.end(), 0);
        int left= sum-ans;

        if(ans> left) return true;
        return false;




    }
};