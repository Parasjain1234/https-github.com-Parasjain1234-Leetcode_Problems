class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n= nums.size();
        
      

int mx = 0;
int p = 0;

int left = 0;

for(int right = 0; right < n; right++) {

    if(nums[right] == 0) {
        p++;
    }

   
    while(p > k) {
        if(nums[left] == 0) {
            p--;
        }
        left++;
    }

    mx = max(mx, right - left + 1);
}

return mx;
    }
};