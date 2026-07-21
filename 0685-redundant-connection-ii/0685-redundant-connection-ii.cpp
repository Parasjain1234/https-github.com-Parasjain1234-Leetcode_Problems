// // class Solution {
// // public:
// //     vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        




        
// //     }
// // };
// class DisjointSet {
// public:
//     vector<int> rank, parent;

//     DisjointSet(int n) {
//         rank.resize(n + 1, 0);
//         parent.resize(n + 1);

//         for (int i = 0; i <= n; i++)
//             parent[i] = i;
//     }

//     int findUPar(int node) {
//         if (node == parent[node])
//             return node;

//         return parent[node] = findUPar(parent[node]);
//     }

//     void unionByrank(int u, int v) {

//         int ulp_u = findUPar(u);
//         int ulp_v = findUPar(v);

//         if (ulp_u == ulp_v)
//             return;

//         if (rank[ulp_u] < rank[ulp_v]) {
//             parent[ulp_u] = ulp_v;
//         }
//         else if (rank[ulp_v] < rank[ulp_u]) {
//             parent[ulp_v] = ulp_u;
//         }
//         else {
//             parent[ulp_v] = ulp_u;
//             rank[ulp_u]++;
//         }
//     }
// };

// class Solution {
// public:
//     vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {

//         int n = edges.size();

//         DisjointSet ds(n);
//         sort(edges.begin(), edges.end());

//         for (int i = 0; i < n; i++) {

//             int u = edges[i][0];
//             int v = edges[i][1];

//             // Agar dono same component me hain, to ye redundant edge hai
//             if (ds.findUPar(u) == ds.findUPar(v)) {
//                 return {u, v};
//             }

//             ds.unionByrank(u, v);
//         }

//         return {};
//     }
// };
class DisjointSet {
public:
    vector<int> rank, parent;

    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByrank(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if (pu == pv) return;

        if (rank[pu] < rank[pv])
            parent[pu] = pv;
        else if (rank[pv] < rank[pu])
            parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        vector<int> par(n + 1, 0);

        vector<int> firstEdge, secondEdge;

        // Step 1 : Find node having two parents
        for (auto &e : edges) {

            int u = e[0];
            int v = e[1];

            if (par[v] == 0) {
                par[v] = u;
            }
            else {
                firstEdge = {par[v], v};
                secondEdge = {u, v};
                e[1] = 0;        // Ignore second edge temporarily
            }
        }

        // Step 2 : DSU
        DisjointSet ds(n);

        for (auto &e : edges) {

            if (e[1] == 0)
                continue;

            int u = e[0];
            int v = e[1];

            if (ds.findUPar(u) == ds.findUPar(v)) {

                if (firstEdge.empty())
                    return e;

                return firstEdge;
            }

            ds.unionByrank(u, v);
        }

        return secondEdge;
    }
};
