class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int n= drones.size();
        int tu= target[0];
        int tv=target[1];
        vector<int>ans(n,INT_MAX);
        for(int i=0; i<n; i++){
            int u= drones[i][0];
            int v= drones[i][1];
            int range= drones[i][2];

            if((abs(u-tu) + abs(v-tv)) <= range){
                ans[i]= (abs(u-tu) + abs(v-tv));
            }

        }

        int mn= *min_element(ans.begin(), ans.end());
        int c=0;
        for(int i=0; i<n; i++){
            if(ans[i]== INT_MAX) c++;
            
        }
        if(c==n) return -1;
        for(int i=0; i<n; i++){
            if(ans[i]== mn) return i;
        }

        return -1;

        


    }
};