// class Solution {
// public:
//     int maxSubarrayLength(vector<int>& nums, int k) {
//         int n= nums.size();

//         int left=0;
//         int mx=0;
//         unordered_map<int,int>mp;
//         for(int i=0; i<n; i++){
//             int ele= nums[i];
//             mp[ele]++;
//             if(mp[ele]>k){
                
//                 mp[ele]--;
//                 left=i-k+1;
//             }
//             else {
//                 mx= max(mx, i-left+1);
//             }
//         }

//         return mx;


//     }
// };
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int left = 0, mx = 0;

        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;

            while(mp[nums[i]] > k) {
                mp[nums[left]]--;
                left++;
            }

            mx = max(mx, i - left + 1);
        }

        return mx;
    }
};