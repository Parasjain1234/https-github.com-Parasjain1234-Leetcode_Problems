// class Solution {
// public:
//     vector<int>rank, parent;
//       DisjointSet(int n){
//         rank.resize(n+1, 0);
//         parent.resize(n+1);
//         for(int i=0; i<=n; i++) parent[i]=i;

//     }

//     int finUPar(int node){
//         if(node== parent[node]) return node;
//         return parent[node]= findUPar(parent[node]);
//     }
//     void unionByrank(int u, int v){
//         int ulp_u= findUPar(u);
//         int ulp_v= findUPar(v);

//         if(ulp_u ==  ulp_v) return;

//         if(rank[ulp_u] < rank[ulp_v]) parent[ulp_u]=ulp_v;

//         else if(rank[ulp_v]< rank[ulp_u]) parent[ulp_v]= ulp_u;

//         else {
//             parent[ulp_v]= ulp_u;
//             rank[ulp_u]++;

//         } 


//     }
//     vector<int> findRedundantConnection(vector<vector<int>>& edges) {
//         int n= edges.size();
//         DisjointSet ds(n);

//         vector<pair<int,int>>ans;
//         for(int i=0; i<n; i++){
//             int u= edges[i][0];
//             int v= edges[i][1];
//             if(ds.findUPar(u)!= ds.findUpar(v)){
//                 ans.push_back({u,v});
//             }
//         }
//         return ans;
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

        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        DisjointSet ds(n);

        for (int i = 0; i < n; i++) {

            int u = edges[i][0];
            int v = edges[i][1];

            // Agar dono same component me hain, to ye redundant edge hai
            if (ds.findUPar(u) == ds.findUPar(v)) {
                return {u, v};
            }

            ds.unionByrank(u, v);
        }

        return {};
    }
};