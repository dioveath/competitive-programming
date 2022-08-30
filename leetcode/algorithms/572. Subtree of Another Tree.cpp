// 572. Subtree of Another Tree

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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;
        
        if(root->val == subRoot->val) {
            stack<TreeNode*> st1({root}), st2({subRoot});
            bool eq = true;
            while((!st1.empty() || !st2.empty()) && st1.size() == st2.size()){
                TreeNode *t1 = st1.top();
                TreeNode *t2 = st2.top();
                st1.pop(); st2.pop();
                
                if(t1->val != t2->val) { eq = false; break; }
                
                if(t1->left) st1.push(t1->left);
                if(t1->right) st1.push(t1->right);
                if(t2->left) st2.push(t2->left);
                if(t2->right) st2.push(t2->right);
            }
            
            if(st1.size() != st2.size()) eq = false;
            if(eq) return true;
        }
        
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};




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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root || !subRoot) return false;
        if(check(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
    
    bool check(TreeNode* root, TreeNode* subRoot){
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;
        if(root->val != subRoot->val) return false;
        return check(root->left, subRoot->left) && 
            check(root->right, subRoot->right);        
    }
};
