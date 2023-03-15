// 958. Check Completeness of a Binary Tree
// Given the root of a binary tree, determine if it is a complete binary tree.

// In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

 

// Example 1:


// Input: root = [1,2,3,4,5,6]
// Output: true
// Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.
// Example 2:


// Input: root = [1,2,3,4,5,null,7]
// Output: false
// Explanation: The node with value 7 isn't as far left as possible.
 

// Constraints:

// The number of nodes in the tree is in the range [1, 100].
// 1 <= Node.val <= 1000

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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q({root});
        bool isLast = false;
        while(!q.empty()){
            int sz = q.size();
            bool foundNull = false;

            while(sz--){
                TreeNode* front = q.front();
                q.pop();

                if(foundNull || isLast) {
                    if(front) return false;
                } else {
                    if(!front) { 
                        foundNull = true;
                        isLast = true;                        
                    }
                }


                if(front) {
                    q.push(front->left);
                    q.push(front->right);
                }
            }
        }
        return true;
    }
};
