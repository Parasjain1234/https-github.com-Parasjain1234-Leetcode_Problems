class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n= nums.size();
        map<int,int>mp;
        for(int i: nums) mp[i]++;

        set<int>st;
        for(auto i: nums) st.insert(i);

        vector<int>ans;
        while(ans.size()!=n){
            for(auto i: st){
                if(mp[i]){
                    ans.push_back(i);
                    mp[i]--;
                }
            }
        }
        return ans;
    }
};