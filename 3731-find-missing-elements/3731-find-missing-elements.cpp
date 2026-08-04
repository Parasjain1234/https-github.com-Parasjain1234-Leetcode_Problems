class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n= nums.size();
        int mn= *min_element(nums.begin(), nums.end());
        int mx= *max_element(nums.begin(), nums.end());

        set<int>st;
        for(auto it: nums) st.insert(it);

        vector<int>ans;
        for(int i= mn; i<= mx;  i++){
            if(!st.count(i)) ans.push_back(i);
        }

        return ans;
    }
};