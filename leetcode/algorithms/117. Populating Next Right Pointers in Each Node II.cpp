// 117. Populating Next Right Pointers in Each Node II


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q({root});
        
        while(!q.empty()){
            int sz = q.size();
            
            Node* prev = nullptr;
            while(sz--){
                Node* nd = q.front();
                q.pop();
                
                if(nd->left && nd->right) nd->left->next = nd->right;
                
                if(prev && nd->left) prev->next = nd->left;
                else if(prev && nd->right) prev->next = nd->right;

                if(nd->right) prev = nd->right;
                else if(nd->left) prev = nd->left;
                 
                if(nd->left) q.push(nd->left);
                if(nd->right) q.push(nd->right);
            }
        }
        return root;
    }
};
