// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     void fun(TreeNode* root, vector<int>&ans){
//         if(!root) return;

//         fun(root->left, ans);
//         if(!root->left && !root->right) ans.push_back(root->val);
//         fun(root->right, ans);
//     }
//     int countDominantNodes(TreeNode* root) {
//         vector<int>ans;
//         fun(root, ans);
//         return ans.size();
//     }
// };
class Solution {
public:
    int cnt=0;
    int dfs(TreeNode* r){
        if(!r)return 0;
        int l=dfs(r->left);
        int rr=dfs(r->right);
        if(r->val>=max(l,rr))cnt++; // current node is maximum in its subtree
        return max({r->val,l,rr}); // return subtree maximum
    }
    int countDominantNodes(TreeNode* root) {
        dfs(root);
        return cnt;
    }
};