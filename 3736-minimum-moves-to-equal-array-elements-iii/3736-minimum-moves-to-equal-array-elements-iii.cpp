class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n= nums.size();
        int mx= *max_element(nums.begin(), nums.end());

        int ans=0;
        for(auto i: nums) ans+= abs(i-mx);

        return ans;
    }
};