// 2246. Longest Path With Different Adjacent Characters
// You are given a tree (i.e. a connected, undirected graph that has no cycles) rooted at node 0 consisting of n nodes numbered from 0 to n - 1. The tree is represented by a 0-indexed array parent of size n, where parent[i] is the parent of node i. Since node 0 is the root, parent[0] == -1.
// You are also given a string s of length n, where s[i] is the character assigned to node i.
// Return the length of the longest path in the tree such that no pair of adjacent nodes on the path have the same character assigned to them.
 

// Example 1:

// Input: parent = [-1,0,0,1,1,2], s = "abacbe"
// Output: 3
// Explanation: The longest path where each two adjacent nodes have different characters in the tree is the path: 0 -> 1 -> 3. The length of this path is 3, so 3 is returned.
// It can be proven that there is no longer path that satisfies the conditions. 
// Example 2:


// Input: parent = [-1,0,0,0], s = "aabc"
// Output: 3
// Explanation: The longest path where each two adjacent nodes have different characters is the path: 2 -> 0 -> 3. The length of this path is 3, so 3 is returned.
 

// Constraints:

// n == parent.length == s.length
// 1 <= n <= 105
// 0 <= parent[i] <= n - 1 for all i >= 1
// parent[0] == -1
// parent represents a valid tree.
// s consists of only lowercase English letters.

class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<int> child_count(n);
        for(int i = 1; i < n; i++)
          child_count[parent[i]]++;

        vector<vector<int>> max_chains(n);
        queue<int> q;
        int max_chain = 1;

        for(int node = 0; node < n; node++){
          max_chains[node] = vector<int>(2);
          if(child_count[node] == 0 && node != 0){
              q.push(node);
              max_chains[node][0] = 1;
          }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            int par = parent[node];

            if(s[node] != s[par]){
                int cur_max_chain = max_chains[node][0];
                if(cur_max_chain > max_chains[par][0]){
                    max_chains[par][1] = max_chains[par][0];
                    max_chains[par][0] = cur_max_chain;
                } else if (cur_max_chain > max_chains[par][1]){
                    max_chains[par][1] = cur_max_chain;
                }
            }

            max_chain = max(max_chain, max_chains[par][0] + max_chains[par][1] + 1);

            child_count[par]--;
            if(child_count[par] == 0 && par != 0) {
                max_chains[par][0]++;
                q.push(par);
            }
        }

        return max_chain;
    }
};
