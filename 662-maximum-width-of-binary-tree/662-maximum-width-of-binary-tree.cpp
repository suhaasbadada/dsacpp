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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int maxwidth=1; // root condition
        
        while(!q.empty()){            
            int size=q.size();
            int r=q.back().second;
            int l=q.front().second;
            maxwidth=max(maxwidth,r-l+1);
            
            for(int i=0;i<size;i++){
                TreeNode* node=q.front().first;
                int idx=q.front().second-l;
                q.pop();
                if(node->left){
                    q.push({node->left,(long long)2*idx+1});
                }
                
                if(node->right){
                    q.push({node->right,(long long)2*idx+2});
                }
            }
        }
        
        return maxwidth;
    }
};