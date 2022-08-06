// 617. Merge Two Binary Trees
// You are given two binary trees root1 and root2.
// Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not. You need to merge the two trees into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of the new tree.
// Return the merged tree.
// Note: The merging process must start from the root nodes of both trees.
// Example 1:

// Input: root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
// Output: [3,4,5,5,4,null,7]
// Example 2:

// Input: root1 = [1], root2 = [1,2]
// Output: [2,2]

// Constraints:

// The number of nodes in both trees is in the range [0, 2000].
// -104 <= Node.val <= 104


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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
      if(!root1) return root2;
      if(!root2) return root1;
      root1->val += root1->val;
      root1->left = mergeTrees(root1->left, root2->left);
      root1->right = mergeTrees(root1->right, root2->right);
      return root1;
    }
};


// Iterative 
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
      if(!root1) return root2;
      if(!root2) return root1;
        
        stack<TreeNode*> st1({root1});
        stack<TreeNode*> st2({root2});
        
        while(!st1.empty() || !st2.empty()){
            TreeNode* temp1 = st1.top();
            TreeNode* temp2 = st2.top();
            st1.pop(); 
            st2.pop();
            
            temp1->val += temp2->val;
                        
            if(temp1->left || temp2->left){
                if(!temp1->left) temp1->left = new TreeNode(0);
                else if(!temp2->left) temp2->left = new TreeNode(0);
                st1.push(temp1->left);
                st2.push(temp2->left);
            }
            
            if(temp1->right || temp2->right){
                if(!temp1->right) temp1->right = new TreeNode(0);
                else if(!temp2->right) temp2->right = new TreeNode(0);
                st1.push(temp1->right);
                st2.push(temp2->right);
            }
                        
        }
        
        
        return root1;
    }
};
