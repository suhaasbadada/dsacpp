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
    vector<string> bins;
    void myfn(TreeNode* root, string s)
    {
        s += (root->val+'0');
        if(root->left)
        myfn(root->left, s);
        if(root->right)
        myfn(root->right, s);
        if(!root->right && !root->left)
        {
            bins.push_back(s);
            return;
        }
    }
    int dec(string s){
        int cs=0;
        int k=s.size();
        k--;
        for(int i=0;i<s.size();i++){
            cs+=(s[i]-'0')*pow(2,k);
            k--;
        }
        return cs;
    }
    
    int sumRootToLeaf(TreeNode* root) {
        int s=0;
        myfn(root,"");
        for(auto x:bins){
            s+=dec(x);
        }
        
       return s;
    }
};