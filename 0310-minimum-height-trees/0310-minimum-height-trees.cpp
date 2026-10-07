class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<int>indegree(n,0);
        vector<vector<int>>adj(n);

        for(auto ad: edges){
             int u= ad[0];
             int v= ad[1];

             adj[u].push_back(v);
             adj[v].push_back(u);

             indegree[u]++;
             indegree[v]++;

        }

        queue<int>q;
        for(int i=0; i<n; i++){
            if(indegree[i]==1) q.push(i);
        }

        vector<int>ans;
        while(!q.empty()){
            int s= q.size();
            ans.clear();
            for(int i=0; i<s; i++){
                int node= q.front();

                ans.push_back(node);
                q.pop();

                for(auto j: adj[node]){
                    indegree[j]--;
                    if(indegree[j]==1) q.push(j);
                }
            }

        }

        return ans; 

    }
};