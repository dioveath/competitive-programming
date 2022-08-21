// 589. N-ary Tree Preorder Traversal
// Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
// Output: [1,2,3,6,7,11,14,4,8,12,5,9,13,10]
 

// Constraints:

// The number of nodes in the tree is in the range [0, 104].
// 0 <= Node.val <= 104
// The height of the n-ary tree is less than or equal to 1000.
 

// Follow up: Recursive solution is trivial, could you do it iteratively?


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        if(!root) return {};
        vector<int> ans;
        stack<Node*> st({root});
        
        while(!st.empty()){
            Node* top = st.top();
            st.pop();
            ans.push_back(top->val);
            for(int i = (top->children).size() - 1; i >= 0; i--){
                if((top->children)[i] != nullptr) 
                    st.push((top->children)[i]);
            }
        }
        
        return ans;
    }
    
};


class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        traverse(root, ans);
        return ans;
    }
    
    void traverse(Node* root, vector<int>& ans){
        if(!root) return;
        ans.push_back(root->val);        
        for(int i = 0; i < (root->children).size(); i++){
            traverse((root->children)[i], ans);
        }
    }
};
