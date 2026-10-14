class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    //     int n= grid.size();
    //     int m= grid[0].size();
    //     vector<vector<int>>vis(n, vector<int>(m,0));

    //     if(grid[0][0] ==1 || grid[n-1][m-1]==1) return -1;

    // priority_queue<pair<int, pair<int,int>>,vector<pair<int, pair<int,int>>>,greater<pair<int, pair<int,int>>>> pq;

    // pq.push({0,{0,0}});

    // while(!pq.empty()){
    //     int wt= pq.top().first;

    //     int r= pq.top().second.first;
    //     int c= pq.top().second.second;

    //     pq.pop();

    //     if(r==n-1 && c== m-1) return wt+1;

        

    //     int row=r-1, col= c-1;
    //     if(row>=0 && row<n && col>=0 && col<n && !vis[row][col] && grid[row][col]==0){
    //         pq.push({wt+1, { row, col}});
    //         vis[row][col]=1;
    //     }
        
    //     row= r-1, col= c;
    //     if(row>=0 && row<n && col>=0 && col<n && !vis[row][col] && grid[row][col]==0){
    //         pq.push({wt+1, { row, col}});
    //         vis[row][col]=1;
    //     }
    //     row= r-1, col= c+1;
    //     if(row>=0 && row<n && col>=0 && col<n && !vis[row][col] && grid[row][col]==0){
    //          pq.push({wt+1, { row, col}});
    //         vis[row][col]=1;
    //     }
    //     row= r, col= c-1;
    //     if(row>=0 && row<n && col>=0 && col<n && !vis[row][col] && grid[row][col]==0){
    //          pq.push({wt+1, { row, col}});
    //         vis[row][col]=1;
    //     }
    //     row= r, col= c+1;
    //     if(row>=0 && row<n && col>=0 && col<n && !vis[row][col] && grid[row][col]==0){
    //          pq.push({wt+1, { row, col}});
    //         vis[row][col]=1;
    //     }
        
    //     row= r+1, col= c-1;
    //     if(row>=0 && row<n && col>=0 && col<n && !vis[row][col] && grid[row][col]==0){
    //         pq.push({wt+1, { row, col}});
    //         vis[row][col]=1;
    //     }
        
    //     row= r+1, col= c;
    //     if(row>=0 && row<n && col>=0 && col<n && !vis[row][col] && grid[row][col]==0){
    //          pq.push({wt+1, { row, col}});
    //         vis[row][col]=1;
    //     }
        
    //     row= r+1, col= c+1;
    //     if(row>=0 && row<n && col>=0 && col<n && !vis[row][col] && grid[row][col]==0){
    //          pq.push({wt+1, { row, col}});
    //         vis[row][col]=1;
    //     }


        

    // }

    // return -1;
        int n= grid.size();

        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
       priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;

       pq.push({1, 0, 0});
       vector<vector<int>>vis(n, vector<int>(n,0));
       vis[0][0]=1;

       while(!pq.empty()){
        int len= get<0>(pq.top());
        int r= get<1>(pq.top());
        int c= get<2>(pq.top());

        if(r== n-1 && c== n-1) return len;

        pq.pop();

        // int dr[]= {-1,0,1,0};
        // int dc[]= {0,1,0,-1};
        int dr[] = {-1,-1,-1,0,0,1,1,1};
        int dc[] = {-1,0,1,-1,1,-1,0,1};

        for(int i=0; i<8; i++){
            int newr= r+ dr[i];
            int newc= c+ dc[i];
            if(newr>=0 && newr<n && newc>=0 && newc<n && grid[newr][newc]==0 && !vis[newr][newc]){
                vis[newr][newc]=1;
                pq.push({len+1, newr, newc});
            }
        }
       }

       return -1;


    
    
   


    }
};