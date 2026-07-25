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
class Solution {
public:
    int mx=INT_MAX;
    int c=0;
    void solve(TreeNode* root, int &mx){
        if(!root) return;

        solve(root->left, mx);
        mx= min(mx, root->val);
        solve(root->right, mx);
       
    }
    void fun(TreeNode* root, long long &mx1){
        if(!root) return;
        fun(root->left, mx1);
        if(root->val!=mx) {
            mx1= min(mx1, (long long)root->val);
            c++;}
        fun(root->right, mx1);
    }
    int findSecondMinimumValue(TreeNode* root) {
        
        solve(root, mx );
        long long mx1=LLONG_MAX;
        fun(root, mx1);
        if(mx1== LLONG_MAX) return -1;
        return mx1;
    }
};