// class Solution {
// public:
    
//     int fun(int i, int j, vector<vector<int>>& grid){
//         if(i==0 && j==0) return grid[i][j];
//         if(i<0 ||  j<0) return 0;

//         int up= grid[i][j]+ fun(i-1, j, grid);
//         int right= grid[i][j]+ fun(i, j-1, grid);

//         return max(up, right);
//     }
//     long long gridGame(vector<vector<int>>& grid) {
//         int n= grid[0].size();
        

//         vector<vector<int>>dp(2,vector<int>(n,0));

//         for(int i=0; i<2; i++){
//             for(int j=0; j<n; j++){
//                 if(i==0 && j==0) dp[i][j]= grid[i][j];

//                 int up= grid[i][j];
//                 if(i-1>=0) up+= dp[i-1][j];
//                 int right= grid[i][j];
//                 if(j-1>=0) right+= dp[i][j-1];

//                 dp[i][j]= max(up, right);


//             }
//         }
//         int i = 1;
//         int j = n - 1;

//         while(true){

//             grid[i][j] = 0;

//                if(i == 0 && j == 0)
//                   break;

//             if(i == 0){
//                 j--;
//             }
//             else if(j == 0){
//                  i--;
//             }
//             else{
//         // jis direction se maximum aaya tha udhar jao
//               if(dp[i-1][j] > dp[i][j-1])
//                    i--;
//               else
//                     j--;
//             }
//         }

//         vector<vector<int>>dp1(2,vector<int>(n,0));

//         for(int i=0; i<2; i++){
//             for(int j=0; j<n; j++){
//                 if(i==0 && j==0) dp1[i][j]= grid[i][j];

//                 int up= grid[i][j];
//                 if(i-1>=0) up+= dp1[i-1][j];
//                 int right= grid[i][j];
//                 if(j-1>=0) right+= dp1[i][j-1];

//                 dp1[i][j]= max(up, right);


//             }
//         }
//         return dp1[1][n-1];
        
//     }
// };

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {

        int n = grid[0].size();

        long long top = 0;
        for(int x : grid[0]) top += x;

        long long bottom = 0;
        long long ans = LLONG_MAX;

        for(int i = 0; i < n; i++) {

            top -= grid[0][i];

            ans = min(ans, max(top, bottom));

            bottom += grid[1][i];
        }

        return ans;
    }
};