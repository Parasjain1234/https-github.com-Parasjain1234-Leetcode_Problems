class Solution {
public:
    bool check(vector<int>&nums, int n, int mn_idx){
        int i;
        for(i= mn_idx; i<mn_idx+n; i++){
            if((nums[(i+1)%n]-1)!=nums[i%n]){
                break;
            }
        }
        if((i+1)%n == mn_idx) return true;
        return false;  
    }
    int minOperations(vector<int>& nums) {
        int n= nums.size();

        int mn_idx=-1;
        for(int i=0; i<n; i++){
            if(nums[i]==0) {
                mn_idx=i;
                break;
            }
        }

        bool inc= check(nums, n, mn_idx); 
        bool dec= false;
        if(!inc){
            reverse(nums.begin(), nums.end());
            mn_idx=n-mn_idx-1;
            dec= check(nums,n, mn_idx);
        }
        if(!inc && !dec) return -1;
        int ans= INT_MAX;

        if(inc){
            ans=min(mn_idx, n-mn_idx+2);
            return ans;
        }

        return min(mn_idx+1, n-mn_idx+1);

         
    }
};