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
    void inorder(TreeNode* root,vector<int>& io){
        if(root!=NULL){
            inorder(root->left,io);
            io.push_back(root->val);
            inorder(root->right,io);
        }        
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> io;
        inorder(root,io);
        
        sort(io.begin(),io.end());
        
        
        return io[k-1];
    }
};