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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root==NULL) return NULL;
        removeLeafNodes(root->left, target);
        removeLeafNodes(root->right, target);
        if(root->left && root->left->left==NULL && root->left->right==NULL){
            if(root->left->val==target){
                root->left=NULL;
            }
        }
        if(root->right && root->right->left==NULL && root->right->right==NULL){
            if(root->right->val==target){
                root->right=NULL;
            }
        }
        if(root&& root->left==NULL && root->right==NULL){
            if(root->val==target){
                root=NULL;
            }
        }
        return root;
    }
};