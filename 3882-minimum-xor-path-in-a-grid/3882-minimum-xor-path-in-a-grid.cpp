// #include<bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     int m, n;
//     int ans = INT_MAX;
//     vector<vector<int>>res;

//     void fun(int i, int j, vector<vector<int>>& grid, vector<int>&part) {
        
//         if(i >= m || j >= n) return;


//         if(i == m-1 && j == n-1) {
//             part.push_back(grid[i][j]);
//             res.push_back(part);
//             part.pop_back();
//             return;
//         }

//         part.push_back(grid[i][j]);
//         fun(i, j+1, grid, part);
//         part.pop_back();

//         part.push_back(grid[i][j]);
//         fun(i+1, j,grid, part);
//         part.pop_back();
//     }

//     int minCost(vector<vector<int>>& grid) {
//         m = grid.size();
//         n = grid[0].size();
//         vector<int>part;
//         fun(0, 0, grid, part);

//         int mn= INT_MAX;
//         for(auto vec: res){
//             int size= vec.size();
           
//             int x= vec[0];
//             for(int i=1; i<size; i++){
//                 x= x^vec[i];
//             }
//             mn= min(mn, x);
//         }

        
//         return mn;



        
//     }
// };

class Solution {
private:
    int n, m;
    vector<vector<vector<int>>> dp;
    int dfs(int i, int j, int temp, vector<vector<int>>& nums){
        if(i >= n || j >= m){
            return INT_MAX;
        }
        temp ^= nums[i][j];
        if(i == n-1 && j == m-1){
            return temp;
        }
        if(dp[i][j][temp] != -1){
            return dp[i][j][temp];
        }
        int right = dfs(i+1, j, temp, nums);
        int down = dfs(i, j+1, temp, nums);
        return dp[i][j][temp] = min(right, down);
    }
public:
    int minCost(vector<vector<int>>& nums) {
        n = nums.size();
        m = nums[0].size();
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(1024, -1)));
        return dfs(0, 0, 0, nums);
    }
};