// 1697. Checking Existence of Edge Length Limited Paths
// An undirected graph of n nodes is defined by edgeList, where edgeList[i] = [ui, vi, disi] denotes an edge between nodes ui and vi with distance disi. Note that there may be multiple edges between two nodes.

// Given an array queries, where queries[j] = [pj, qj, limitj], your task is to determine for each queries[j] whether there is a path between pj and qj such that each edge on the path has a distance strictly less than limitj .

// Return a boolean array answer, where answer.length == queries.length and the jth value of answer is true if there is a path for queries[j] is true, and false otherwise.

 

// Example 1:


// Input: n = 3, edgeList = [[0,1,2],[1,2,4],[2,0,8],[1,0,16]], queries = [[0,1,2],[0,2,5]]
// Output: [false,true]
// Explanation: The above figure shows the given graph. Note that there are two overlapping edges between 0 and 1 with distances 2 and 16.
// For the first query, between 0 and 1 there is no path where each distance is less than 2, thus we return false for this query.
// For the second query, there is a path (0 -> 1 -> 2) of two edges with distances less than 5, thus we return true for this query.
// Example 2:


// Input: n = 5, edgeList = [[0,1,10],[1,2,5],[2,3,9],[3,4,13]], queries = [[0,4,14],[1,4,13]]
// Output: [true,false]
// Exaplanation: The above figure shows the given graph.
 

// Constraints:

// 2 <= n <= 105
// 1 <= edgeList.length, queries.length <= 105
// edgeList[i].length == 3
// queries[j].length == 3
// 0 <= ui, vi, pj, qj <= n - 1
// ui != vi
// pj != qj
// 1 <= disi, limitj <= 109
// There may be multiple edges between two nodes.


class UnionFind {
    public:
        vector<int> group;
        vector<int> rank;

        UnionFind(int size){
            group = vector<int>(size);
            rank = vector<int>(size);
            for(int i = 0; i < size; i++){
                group[i] = i;
            }
        }

        int find(int node){
            if(group[node] != node){
                group[node] = find(group[node]);
            }
            return group[node];
        }

        void join(int node1, int node2){
            int group1 = find(node1);
            int group2 = find(node2);
            if(group1 == group2){ return; }
            if(rank[group1] > rank[group2]) {
                group[group2] = group1;
            } else if(rank[group1] < rank[group2]){
                group[group1] = group2;
            } else {
                group[group1] = group2;
                rank[group2] += 1;
            }
        }

        bool areConnected(int node1, int node2){
            int group1 = find(node1);
            int group2 = find(node2);
            return group1 == group2;
        }
};

class Solution {
public:
    bool static compare(vector<int>& a, vector<int>& b){
        return a[2]<b[2];
    }
    vector<bool> distanceLimitedPathsExist(int n, 
        vector<vector<int>>& edgeList,
        vector<vector<int>>& queries) {
        
        UnionFind uf(n);
        int queriesCount = queries.size();
        vector<bool> answer(queriesCount);

        vector<vector<int>> queriesWithIndex(queriesCount);
        for(int i = 0; i < queriesCount; i++){
            queriesWithIndex[i] = queries[i];
            queriesWithIndex[i].push_back(i);
        }

        int edgesIndex = 0;

        sort(edgeList.begin(), edgeList.end(), compare);
        sort(queriesWithIndex.begin(), queriesWithIndex.end(), compare);

        for(auto& query : queriesWithIndex){
            int p = query[0];
            int q = query[1];
            int limit = query[2];
            int queryOriginalIndex = query[3];

            while(edgesIndex < edgeList.size() && edgeList[edgesIndex][2] < limit){
                int node1 = edgeList[edgesIndex][0];
                int node2 = edgeList[edgesIndex][1];
                uf.join(node1, node2);
                edgesIndex += 1;
            }

            answer[queryOriginalIndex] = uf.areConnected(p, q);
        }

        return answer;
    }

};
