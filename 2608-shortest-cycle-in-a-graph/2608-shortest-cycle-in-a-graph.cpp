// class Solution {
// public:
//     int findShortestCycle(int n, vector<vector<int>>& edges) {
 
//         int V= n;
//         vector<vector<int>>adj(V);
       
//         for(int i=0; i<edges.size(); i++){
//             int u= edges[i][0];
//             int v= edges[i][1];

           
            
//             adj[u].push_back(v);
//             adj[v].push_back(u);
            
//         }
//         int mn= INT_MAX;;
//         for(int i=0; i<n; i++){
//             int src= i;
//         queue<pair<int,int>>q;
//         q.push({src,0});
        
        
//         vector<int>vis(V,0);
//         vis[src]=1;
//         vector<int>dis(V,INT_MIN);
//         dis[src]=0;
        
//         while(!q.empty()){
//             int node= q.front().first;
//             int len= q.front().second;
            
//             q.pop();
     
//             for(auto adjNode: adj[node]){
//                 if(!vis[adjNode]){
//                     dis[adjNode]= dis[node]+1;
//                     q.push({adjNode, dis[adjNode]});
//                     vis[adjNode]=1;
//                 }
//                 else if(adjNode== src){
//                     mn= min(mn, len+1);
//                    // break;
//                 }
//             }
            
            
            
//         }
        
//         }
//         //if(mn==INT_MAX) return -1;
//         return mn;
//     }
// };


class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
       
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int min_cycle = INT_MAX;

        
        for (int i = 0; i < n; ++i) {
            vector<int> dist(n, -1);
            vector<int> parent(n, -1);
            queue<int> q;

            dist[i] = 0;
            q.push(i);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (dist[v] == -1) {
                        // Unvisited node
                        dist[v] = dist[u] + 1;
                        parent[v] = u;
                        q.push(v);
                    } else if (parent[u] != v) {
                        // Already visited node and not direct parent -> Cycle found!
                        min_cycle = min(min_cycle, dist[u] + dist[v] + 1);
                    }
                }
            }
        }

        return (min_cycle == INT_MAX) ? -1 : min_cycle;
    }
};