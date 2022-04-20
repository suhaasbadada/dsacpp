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
class BSTIterator {
private:
    int idx;
    vector<int> nodes;
public:
    BSTIterator(TreeNode* root) {
        inorder(root);
        idx=-1;
    }
    
    void inorder(TreeNode* root){
        if(root==0)
            return;
        inorder(root->left);
        nodes.push_back(root->val);
        inorder(root->right);
    }
    
    int next() {
        idx++;
        return nodes[idx];
    }
    
    bool hasNext() {
        return idx==(nodes.size()-1)?false:true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */