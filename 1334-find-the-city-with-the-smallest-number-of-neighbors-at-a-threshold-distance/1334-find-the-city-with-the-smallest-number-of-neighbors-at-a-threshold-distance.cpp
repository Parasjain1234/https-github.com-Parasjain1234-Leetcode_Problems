class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges,
                    int distanceThreshold) {

        vector<vector<pair<int, int>>>adj(n);

        int mn=n; int ans=-1;

        for(auto it: edges){
            int u= it[0];
            int v= it[1];
            int wt= it[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});

        }
        int INF= 1e9;
        int mx=0;
        for(int i=0; i<n; i++){
            int src=i;
            vector<int>dis(n,INF);
            dis[src]=0;
            queue<pair<int,int>>q;
            q.push({src,0});

            while(!q.empty()){
                int node= q.front().first;
                int wt= q.front().second;

                q.pop();

                for(auto it: adj[node]){
                    int adjNode= it.first;
                    int wt1= it.second;

                    if((wt+wt1<= distanceThreshold) && (wt+ wt1<dis[adjNode])){
                        dis[adjNode]= wt+wt1;
                        q.push({adjNode, dis[adjNode]});
                    }
                }

            }
            int c=0;
            // for(int i=0; i<n; i++) if(dis[i]!=INF) c++;
            // c--;
            // mx= max(mx,c);

             for(int j = 0; j < n; j++){
                if(j != src && dis[j] != INF) c++;
            }

            if(c <= mn){
                mn = c;
                ans = src;
            }

        }
        return ans;
    }
};