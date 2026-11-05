class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n= nums.size();
        unordered_map<int,int>mp, mp1;

       

        for(auto i: nums) mp[i]++;

        
        set<int>st;
        for(auto i: mp){
            mp1[i.second]++;
        }
        

        for(auto i: nums){
            if(mp1[mp[i]]==1) return i;
        }

        return -1;
    }
};