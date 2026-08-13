class Solution {
public:
    map<int,int> mp;

    int depth(int node, vector<int>& parent) {
        if(node == 0)
            return 1;

        if(mp.find(node) != mp.end())
            return mp[node];

        return mp[node] = depth(parent[node], parent) + 1;
    }

    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();

        mp[0] = 1;

        int height = 0;

        for(int i = 0; i < n; i++) {
            mp[i] = depth(i, parent);
            height = max(height, mp[i]);
        }

        long long wt = 0;

        for(int i = 0; i < n; i++) {
            int d = mp[i];
            wt += 1LL * nums[i] * (height - d + 1);
        }

        return wt;
    }
};