// class Solution {
// public:
//     bool uniformArray(vector<int>& nums1) {
//         int o=0;
//         int e=0;
//         int n= nums1.size();
//         for(auto i: nums1){
//             if(i%2==0) e++;
//             else o++;
//         }
//         if(n==o || n==e) return true;
//         if(n==2){
//             if(o==n||n==e) return true;
//             else if(nums1[0]%2 && nums1[1]-nums1[0]>=1)return true;
//             else if(nums1[0]%2==0 && nums1[0]-nums1[1]>=1) return true;
//             return false;
//         }
//         int t=0;
//         int t1=0;
//         for(int i=0; i<n-1; i++){
//             if(nums1[i]%2==0 && nums1[i+1]%2==0)t++;
//             else if(nums1[i]%2!=0 && nums1[i+1]%2!=0) t1++;
//         }
//         if(t||t1) return false;
//         return true;
        
//     }
// };
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini=INT_MAX;
        bool odd=false;
        for(auto t:nums1){
            
            if(t%2){
                odd=true;
                mini=min(mini,t);
            }
        }
        if(!odd) return true;
        for(int t:nums1){
            if(t%2==0 && mini>t) return false;
        }
        return true;
    }
};