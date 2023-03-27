// 2360. Longest Cycle in a Graph
// You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.

// The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from node i, then edges[i] == -1.

// Return the length of the longest cycle in the graph. If no cycle exists, return -1.

// A cycle is a path that starts and ends at the same node.
 

// Example 1:


// Input: edges = [3,3,4,2,3]
// Output: 3
// Explanation: The longest cycle in the graph is the cycle: 2 -> 4 -> 3 -> 2.
// The length of this cycle is 3, so 3 is returned.
// Example 2:


// Input: edges = [2,-1,3,1]
// Output: -1
// Explanation: There are no cycles in this graph.
 

// Constraints:

// n == edges.length
// 2 <= n <= 105
// -1 <= edges[i] < n
// edges[i] != i

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        // edges
        // 0-indexed array
        // indicates node i to node edges[i]
        // if there is no edge, edges[i] == -1

        int n = edges.size();
        vector<bool> visit(n);
        vector<int> indegree(n);

        for(int edge : edges){
            if(edge != -1) indegree[edge]++;   
        }

        queue<int> q;
        for(int i = 0; i < n; i++)
            if(indegree[i] == 0) q.push(i);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            visit[node] = true;
            int neighbor = edges[node];
            if(neighbor != -1) {
                indegree[neighbor]--;
                if(indegree[neighbor] == 0) q.push(neighbor);
            }
        }

        int ans = -1;
        for(int i = 0; i < n; i++){
            if(!visit[i]){
                int neighbor = edges[i];
                int count = 1;
                visit[i] = true;

                while(neighbor != i){
                    visit[neighbor] = true;
                    count++;
                    neighbor = edges[neighbor];
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};
