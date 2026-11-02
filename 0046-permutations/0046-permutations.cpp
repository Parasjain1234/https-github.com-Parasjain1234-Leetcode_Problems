class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>paras;
        sort(nums.begin() , nums.end());
        paras.push_back(nums);
        while(next_permutation(nums.begin() , nums.end())){
            paras.push_back(nums);
        }
        return paras;
        
    }
};
