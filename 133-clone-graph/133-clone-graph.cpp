/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
const int MAX=101;
class Solution {
    void dfs(Node* node,Node* newnode,vector<Node*>& viz){
        viz[newnode->val]=newnode;
        
        for(auto x:(node->neighbors)){
            if(!viz[x->val]){
                Node* nn=new Node(x->val);
                (newnode->neighbors).push_back(nn);
                dfs(x,nn,viz);
            }else{
                (newnode->neighbors).push_back(viz[x->val]);
            }
        }
    }
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return NULL;
        }
        
        vector<Node*> viz(MAX,NULL);
        Node* clone=new Node(node->val);
        viz[node->val]=clone;
        
        for(auto x:(node->neighbors)){
            if(!viz[x->val]){       
                Node* nn=new Node(x->val);
                (clone->neighbors).push_back(nn);
                dfs(x,nn,viz);
            }else{
                (clone->neighbors).push_back(viz[x->val]);
            }
        }
        
        return clone;
    }
};