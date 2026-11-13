
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<int> ans;

        for(int i = 0; i < n; i++) {
            int ele = nums1[i];
            int idx = -1;

            auto it = find(nums2.begin(), nums2.end(), ele);

            if(it != nums2.end()) {
                idx = it - nums2.begin();
            }

            int nge = -1;

            for(int j = idx + 1; j < m; j++) {
                if(nums2[j] > ele) {
                    nge = nums2[j];
                    break;
                }
            }

            ans.push_back(nge);
        }

        return ans;
    }
};
