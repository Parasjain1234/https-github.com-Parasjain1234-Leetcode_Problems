class Solution {
public:
    vector<int> parent, rank;

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return;

        if (rank[a] < rank[b]) {
            parent[a] = b;
        }
        else if (rank[a] > rank[b]) {
            parent[b] = a;
        }
        else {
            parent[b] = a;
            rank[a]++;
        }
    }

    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();

        parent.resize(n);
        rank.assign(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            for (int p = 2; p * p <= x; p++) {
                if (x % p == 0) {

                    if (mp.count(p))
                        unite(i, mp[p]);
                    else
                        mp[p] = i;

                    while (x % p == 0)
                        x /= p;
                }
            }

            if (x > 1) {
                if (mp.count(x))
                    unite(i, mp[x]);
                else
                    mp[x] = i;
            }
        }

        unordered_map<int, int> count;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            count[find(i)]++;
            ans = max(ans, count[find(i)]);
        }

        return ans;
    }
};