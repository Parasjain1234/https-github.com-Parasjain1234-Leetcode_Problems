// class Solution {
// public:
//     // void dfs(int node, vector<vector<int>>&adj, vector<int>&vis){
//     //     vis[node]=1;
//     //     for(auto it: adj[node]){
//     //         if(!vis[it]){
//     //             dfs(it, adj, vis);
//     //         }
//     //     }
//     // }
//     bool dfs(int node, int parent,
//          vector<vector<int>>& adj,
//          vector<int>& vis)
// {
//     vis[node] = 1;

//     for (auto it : adj[node])
//     {
//         if (!vis[it])
//         {
//             if (dfs(it, node, adj, vis))
//                 return true;
//         }
//         else if (it != parent)
//         {
//             return true;   // Cycle mili
//         }
//     }

//     return false;
// }
//     bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
//        vector<vector<int>>adj(n+1);
//        for(int i=0; i<dislikes.size(); i++){
//         int u= dislikes[i][0];
//         int v= dislikes[i][1];

//         adj[u].push_back(v);
//         adj[v].push_back(u);
//        }

//        vector<int>vis(n+1,0);
//     //    int c=0;
//     //    for(int i=1; i<=n; i++){
//     //     if(!vis[i]){
//     //         dfs(i, adj, vis);
//     //         c++;
//     //     }
//     //    }
//     //    if(c>1) return true;
//     //    return false;

//      for (int i = 1; i <= n; i++)
// {
//     if (!vis[i])
//     {
//         if (dfs(i, -1, adj, vis))
//             return false;   // Cycle hai
//     }
// }

// return true;    // Cycle nahi hai

//     }
// };
class Solution {
public:
    bool dfs(int node, int color,
             vector<vector<int>>& adj,
             vector<int>& col)
    {
        col[node] = color;

        for (auto it : adj[node])
        {
            if (col[it] == -1)
            {
                if (!dfs(it, 1 - color, adj, col))
                    return false;
            }
            else if (col[it] == color)
            {
                return false;
            }
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        vector<vector<int>> adj(n + 1);

        for (auto &e : dislikes)
        {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> col(n + 1, -1);

        for (int i = 1; i <= n; i++)
        {
            if (col[i] == -1)
            {
                if (!dfs(i, 0, adj, col))
                    return false;
            }
        }

        return true;
    }
};