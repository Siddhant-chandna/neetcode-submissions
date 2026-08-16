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
    void trav(TreeNode* root, int maxm, int &ans){
        if(!root) return;
        if(root->val>=maxm){
            maxm=root->val;
            ans++;
        }
        trav(root->left, maxm, ans);
        trav(root->right, maxm, ans);
    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int maxm=INT_MIN;
        int ans=0;
        trav(root, maxm, ans);
        return ans;
    }
};
