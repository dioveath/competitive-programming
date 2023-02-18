// 783. Minimum Distance Between BST Nodes
// Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.

// Example 1:

// Input: root = [4,2,6,1,3]
// Output: 1
// Example 2:

// Input: root = [1,0,48,null,null,12,49]
// Output: 1

// Constraints:

// The number of nodes in the tree is in the range [2, 100].
// 0 <= Node.val <= 105

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
class Solution
{
public:
    int minDiffInBST(TreeNode *root)
    {
        vector<int> vec = getVectorFromNode(root);
        sort(vec.begin(), vec.end());

        int minDiff = INT_MAX;
        for (int i = 1; i < vec.size(); i++)
        {
            minDiff = min(minDiff, abs(vec[i - 1] - vec[i]));
        }
        return minDiff;
    }

    vector<int> getVectorFromNode(TreeNode *root)
    {
        vector<int> vec;
        stack<TreeNode *> st({root});
        while (!st.empty())
        {
            TreeNode *top = st.top();
            st.pop();
            vec.push_back(top->val);
            if (top->left)
                st.push(top->left);
            if (top->right)
                st.push(top->right);
        }
        return vec;
    }
};