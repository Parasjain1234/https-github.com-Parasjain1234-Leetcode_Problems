class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n= nums.size();
        int c=1;
        int mx=1;
        for(int i=1; i<n; i++){
            if(nums[i-1]< nums[i]) c++;
            else{
                mx= max(mx, c);
                c=1;
            }
        }
        mx= max(mx,c);
        return mx;
    }
};