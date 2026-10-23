// class Solution {
// public:
//     void dfs(int node, vector<int>&adj, int destination){
//         if(node == destination) return true;
//         vis[node]= 1;
//         for(auto it : adj[node]){
//             if(!vis[it]){
//                 dfs(it, adj, destination);
//             }
//         }
//     } 
//     bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
//         vector<int>adj[n];
//         for(auto it: edges){
//             int u= it[0];
//             int v= it[1];
//             adj[u].push_back(v);
//             adj[v].push_back(u);

//         }
//         vector<int>vis(n,0);
//         for(int i=0; i<n; i++){
//             if(!vis[i]){
//                 if(dfs(i, adj, destination)== true) return true;
//                 return true;
//             }
//         }
        
//     }
// };
class Solution {
public:

    bool validPath(int n, vector<vector<int>>& edges,
                   int source, int destination) {
        
        //int n= edges.size();
        vector<vector<int>>adj(n);
        for(int i=0; i<edges.size(); i++){
            int u= edges[i][0];
            int v= edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);

        }

        queue<int>q;
        q.push(source);
        vector<int>vis(n,0);
        vis[source]=1;

        while(!q.empty()){
            int node= q.front();
            q.pop();

            if(node== destination) return true;

            for(auto it: adj[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }

        return false;


       
    }
};