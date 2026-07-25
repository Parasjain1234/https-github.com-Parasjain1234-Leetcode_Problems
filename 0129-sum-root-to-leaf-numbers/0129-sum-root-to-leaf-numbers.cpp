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
    int sumNumbers(TreeNode* root) {
        queue<pair<TreeNode* ,int>>q;
        q.push({root, 0});
        int sum=0;
        while(!q.empty()){
            auto [node, curr]= q.front();
            q.pop();

            curr= curr*10 + node->val;
            if(node->left) q.push({node->left, curr});
            if(node->right) q.push({node->right, curr});
            if(!node->left && !node->right) sum+= curr;
            
        }
        return sum;
    }
};