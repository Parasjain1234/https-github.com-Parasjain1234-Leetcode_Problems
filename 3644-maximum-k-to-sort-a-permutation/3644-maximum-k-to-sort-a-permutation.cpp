class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n= nums.size();
        int c=-1;
        for(int i=0; i<n; i++){
            if(nums[i]!=i){
                c= c&nums[i];
            }
        }
         return (c==-1) ? 0: c;
        
    }
};