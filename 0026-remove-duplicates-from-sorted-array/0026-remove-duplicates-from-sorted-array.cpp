class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>st;
        for(int i: nums){
            st.insert(i);
        }
        int k=nums.size();
        int p= st.size();
        nums.erase(nums.begin() , nums.end());
        for(int i: st){
            nums.push_back(i);

        }
        return st.size();
        
    }
};