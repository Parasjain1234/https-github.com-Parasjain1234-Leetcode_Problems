/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
    // int fun(TreeNode* root, int i){
    //     if(!root) return 0;
    //     if(i%2) int l1= 1+ fun(root->left, i+1);
    //     else int r1= 1+ fun(root->right, i+1);

    //     return max(l1, r1);
    // }
//     int fun(TreeNode* root, int i){
//     if(!root) return 0;

//     int l1 = 0;
//     int r1 = 0;

//     if(i % 2)
//         l1 = 1 + fun(root->left, i + 1);
//     else
//         r1 = 1 + fun(root->right, i + 1);

//     return max(l1, r1);
// }
//     int longestZigZag(TreeNode* root) {
//         int i=0;
//         return fun(root, i);
    
        
//     }
// };
class Solution {
public:
    int ans = 0;

    void fun(TreeNode* root, bool left, int len) {
        if (!root) return;

        ans = max(ans, len);

        if (left) {
            // Last move was left, ab right jana hoga
            fun(root->right, false, len + 1);

            // Naya ZigZag start karo
            fun(root->left, true, 1);
        } else {
            // Last move was right, ab left jana hoga
            fun(root->left, true, len + 1);

            // Naya ZigZag start karo
            fun(root->right, false, 1);
        }
    }

    int longestZigZag(TreeNode* root) {
        fun(root->left, true, 1);
        fun(root->right, false, 1);

        return ans;
    }
};
