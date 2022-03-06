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
    int longestZigZag(TreeNode* root) {
        if(!root || (!root->left && !root->right)){return 0;}
        
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        
        int rez=-1;
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            TreeNode* node=p.first;
            int lr=p.second.first;
            int cost=p.second.second;
            rez=max(rez,cost);
            
            if(lr==0){
                if(node->left){
                    q.push({node->left,{-1,cost+1}});
                }
                if(node->right){
                    q.push({node->right,{1,cost+1}});
                }
            }
            
            if(lr==1){
                if(node->left){
                    q.push({node->left,{-1,cost+1}});
                }
                if(node->right){
                    q.push({node->right,{1,1}});
                }
            }
            
            if(lr==-1){
                if(node->right){
                    q.push({node->right,{1,cost+1}});
                }
                if(node->left){
                    q.push({node->left,{-1,1}});
                }
            }
        }
        
        
        return rez;
    }
};

/*
{node,{left/right,cost}}

-1 -> left, 1 -> right

*/