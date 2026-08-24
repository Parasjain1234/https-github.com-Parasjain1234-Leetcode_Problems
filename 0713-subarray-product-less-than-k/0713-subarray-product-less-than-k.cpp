class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n= nums.size();
        int left=0;
        int right=0;
        int p=1;
        int ans=0;
        while(right<n){
             p*= nums[right];
            //  if(p>k){
            //     p= p/nums[left];
            //     left++;
            //  }
            while (left <= right && p >= k) {
                p /= nums[left];
                left++;
            }
             ans+= (right-left+1);
             right++;
        }
        return ans;
    }
};