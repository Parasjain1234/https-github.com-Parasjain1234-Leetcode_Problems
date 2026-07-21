// class Solution {
// public:
//     int dfs(int node, int c, vector<int>&dis, int threshold, vector<pair<int,pair<int,int>>>&adj){
//         for(auto it: adj[node]){
//             int u= it.first;
//             int w= it.second;

//             if((dis[node] + w < dis[u] ) && (dis[node] + w <= threshold) ){
//                 dis[u]= dis[node]+w;
//                 dfs(u, c+1 , dis, threshold, adj);
//             }
//         }
//         return c;
//     }
//     int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
//         vector<pair<int,pair<int,int>>>adj[n];
//         for(int i=0; i<edges.size(); i++){
//             int u= edges[i][0];
//             int v= edges[i][1];
//             int w= edges[i][2];
//             adj[u].push_back({v,w});
//             adj[v].push_back({u,w});
//         }
//         vector<int>dis(n,1e9);
//         vector<int>city(n);
//         for(int i=0; i<n; i++){
//             int node=i;
//             int c=0;
//             city[i]= dfs(node, c,dis , distanceThreshold, adj);
//         }
//         int mn= *min_element(city.begin(), city.end());
//         int idx=0;
//         for(int i=0; i<n; i++){
//             if(city[i]== mn){
//                 idx= i;
//             }
//         }
//           return idx;



//     }
// };

// class Solution {
// public:
//     void dfs(int node, vector<int>& dis, int threshold,
//             vector<pair<int,int>> adj[]) {

//         //int c = 0;

//         for(auto it : adj[node]) {
//             int u = it.first;
//             int w = it.second;

//             if((dis[node] + w < dis[u]) &&
//                (dis[node] + w <= threshold)) {

//                 dis[u] = dis[node] + w;
//                  dfs(u, dis, threshold, adj);
//             }
//         }

//        // return c;
//     }

//     int findTheCity(int n, vector<vector<int>>& edges,
//                     int distanceThreshold) {

//         vector<pair<int,int>> adj[n];

//         for(int i = 0; i < edges.size(); i++) {
//             int u = edges[i][0];
//             int v = edges[i][1];
//             int w = edges[i][2];

//             adj[u].push_back({v, w});
//             adj[v].push_back({u, w});
//         }

//         vector<int> city(n);

//         for(int i = 0; i < n; i++) {

//             vector<int> dis(n, 1e9);
//             dis[i] = 0;

//             dfs(i, dis, distanceThreshold, adj);

//             int cnt = 0;
//             for(int j = 0; j < n; j++) {
//                 if(i != j && dis[j] <= distanceThreshold)
//                     cnt++;
//             }

//             city[i] = cnt;
//         }

//         int mn = *min_element(city.begin(), city.end());

//         int idx = 0;
//         for(int i = 0; i < n; i++) {
//             if(city[i] == mn)
//                 idx = i;   // largest index in case of tie
//         }

//         return idx;
//     }
// };
// class Solution {
// public:
    

//     int findTheCity(int n, vector<vector<int>>& edges,
//                     int distanceThreshold) {

//         vector<pair<int,int>> adj[n];

        
//         int mn=INT_MAX;
//         int idx=n;
//         for(int i=0; i<n; i++){
//             int src= i;
//             vector<int>dis(n,1e8);
//             dis[src]=0;
//             for(int j=0; j<n-1; j++){
//                 for(int k = 0; k < edges.size(); k++) {
//                         int u = edges[k][0];
//                         int v = edges[k][1];
//                         int w = edges[k][2];

//                         if(dis[u]!= 1e8 && dis[u]+w < dis[v]){
//                             dis[v]= w+ dis[u];
//                         }

              
//                  }
//             }
//             int c=0;
//             for(int i=0; i<n; i++){
//                 if(dis[i]<= distanceThreshold){
//                     c++;
//                 }
//             }
//             c--;
//             mn= min(mn, c);
//             if(mn<=idx) idx=i;

//         }
//         return idx;



       
//     }
// };
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges,
                    int distanceThreshold) {

        int mn = INT_MAX;
        int idx = -1;

        for (int i = 0; i < n; i++) {

            int src = i;
            vector<int> dis(n, 1e8);
            dis[src] = 0;

            // Bellman-Ford
            for (int j = 0; j < n - 1; j++) {

                for (int k = 0; k < edges.size(); k++) {

                    int u = edges[k][0];
                    int v = edges[k][1];
                    int w = edges[k][2];

                    // u -> v
                    if (dis[u] != 1e8 && dis[u] + w < dis[v]) {
                        dis[v] = dis[u] + w;
                    }

                    // v -> u (graph is undirected)
                    if (dis[v] != 1e8 && dis[v] + w < dis[u]) {
                        dis[u] = dis[v] + w;
                    }
                }
            }

            int c = 0;
            for (int j = 0; j < n; j++) {
                if (dis[j] <= distanceThreshold)
                    c++;
            }

            c--; // remove itself

            if (c < mn) {
                mn = c;
                idx = i;
            }
            else if (c == mn) {
                idx = i;   // larger index
            }
        }

        return idx;
    }
};