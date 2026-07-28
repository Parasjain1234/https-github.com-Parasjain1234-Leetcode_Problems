class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        for(auto i: nums) mp[i]++;

        vector<int>paras;
        for(auto i: mp){
            paras.push_back(i.second);
        }

        sort(paras.begin(), paras.end());
        reverse(paras.begin(), paras.end());

        vector<int>ans;

        for(int i=0; i<k; i++){
            int fre= paras[i];
            for(auto i: mp){
                if(i.second==fre){
                    ans.push_back(i.first);
                    mp[i.first]=0;
                    break;
                }
            }
        }
        return ans;
    
    }
};