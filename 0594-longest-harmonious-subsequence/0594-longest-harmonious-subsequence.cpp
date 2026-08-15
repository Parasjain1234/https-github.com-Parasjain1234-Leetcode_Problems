class Solution {
public:
    // int solve(int i, int j, vector<int>&nums){
    //     if(i==nums.size() || j<0 || i>j) return 0;
    //     if((nums[j]- nums[i])==1 ) return (j-i+1);
    //     return max(solve(i+1,j, nums), solve(i, j-1, nums));
    // }
    int findLHS(vector<int>& nums) {
        int n= nums.size();
       
        //return solve(0,n-1, nums);
        unordered_map<int, int> mp;

        for(int x : nums)
            mp[x]++;

        int ans = 0;

        for(auto &[x, freq] : mp) {
            if(mp.count(x + 1)) {
                ans = max(ans, freq + mp[x + 1]);
            }
        }

        return ans;
        
    }
};