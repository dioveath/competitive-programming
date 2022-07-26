// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]
// Example 2:
// Input: root = [1]
// Output: [[1]]
// Example 3:
// Input: root = []
// Output: []
// Constraints:
// The number of nodes in the tree is in the range [0, 2000].
// -1000 <= Node.val <= 1000


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


/* More space complexity solution */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res({});
        stack<vector<TreeNode*>> st({{root}});
        while(!st.empty()){
            vector<TreeNode*> list = st.top();
            st.pop();

            vector<TreeNode*> new_list;
            vector<int> level_values;
            for(int i = 0; i < list.size(); i++){
                TreeNode* temp = list[i];
            
                level_values.push_back(temp->val);
                
                if(temp->left)
                    new_list.push_back(temp->left);                
                if(temp->right)
                    new_list.push_back(temp->right);
            }
            
            res.push_back(level_values);
            if(new_list.size()) st.push(new_list);
        }
        return res;
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
/* Great use of queue solution - Less space complexity*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q({root});
        while(!q.empty()){
            vector<int> row;
            int s = q.size();
            for(int i = 0; i < s; i++){
                TreeNode* temp = q.front();
                q.pop();
                row.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            res.push_back(row);
        }
        return res;
    }
};
