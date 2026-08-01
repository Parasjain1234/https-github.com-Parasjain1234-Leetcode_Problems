// class Solution {
// public:
//     bool predictTheWinner(vector<int>& nums) {
//         int odd=0, even=0;
//         int n= nums.size();
//         if(n<=2) return true;
//         for(int i=0; i<n; i++){
//             if(i%2==0) even+= nums[i];
//             else odd+= nums[i];
//         }

//         if(even>=odd) return true;
//         reverse(nums.begin(), nums.end());

//         odd=0;
//         even=0;

//         for(int i=0; i<n; i++){
//             if(i%2==0) even+= nums[i];
//             else odd+= nums[i];
//         }
//         if(even>=odd) return true;

//         return false;
//     }
// };

class Solution {
public:
    int solve(int i, int j, vector<int>& nums) {
        if (i == j)
            return nums[i];

        int takeLeft = nums[i] - solve(i + 1, j, nums);
        int takeRight = nums[j] - solve(i, j - 1, nums);

        return max(takeLeft, takeRight);
    }

    bool predictTheWinner(vector<int>& nums) {
        return solve(0, nums.size() - 1, nums) >= 0;
    }
};