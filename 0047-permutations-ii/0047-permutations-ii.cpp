class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<vector<int>>paras;
        paras.push_back(nums);

        while(next_permutation(nums.begin() , nums.end())){
            if(!count(paras.begin() , paras.end() , nums)){
                paras.push_back(nums);
           }
        }
        return paras;
        
    }
};

// class Solution {
// public:
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         vector<vector<int>> result;
//         sort(nums.begin(), nums.end()); // \U0001f511 Start from the lowest lexicographical permutation
//         do {
//             result.push_back(nums);
//         } while (next_permutation(nums.begin(), nums.end())); // STL skips duplicates by design
//         return result;
//     }
// };