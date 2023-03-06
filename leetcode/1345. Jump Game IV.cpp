// 1345. Jump Game IV
// Given an array of integers arr, you are initially positioned at the first index of the array.
// In one step you can jump from index i to index:

// i + 1 where: i + 1 < arr.length.
// i - 1 where: i - 1 >= 0.
// j where: arr[i] == arr[j] and i != j.
// Return the minimum number of steps to reach the last index of the array.

// Notice that you can not jump outside of the array at any time.


// Example 1:
// Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
// Output: 3
// Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.
// Example 2:

// Input: arr = [7]
// Output: 0
// Explanation: Start index is the last index. You do not need to jump.
// Example 3:

// Input: arr = [7,6,9,6,9,6,9,7]
// Output: 1
// Explanation: You can jump directly from index 0 to index 7 which is last index of the array.
 

// Constraints:

// 1 <= arr.length <= 5 * 104
// -108 <= arr[i] <= 108



// Valid Solution
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n <= 1) return 0;

        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++){
            mp[arr[i]].push_back(i);
        }

        queue<int> q({0});
        vector<bool> vis(n, false);
        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int idx = q.front();
                q.pop();

                if(idx == n-1) return ans;
                if(idx+1 < n && !vis[idx+1]) {
                    q.push(idx+1);
                    vis[idx+1] = true;
                } 
                if(idx-1 >= 0 && !vis[idx-1]){
                    q.push(idx-1);
                    vis[idx-1] = true;
                }
                for(auto it : mp[arr[idx]]){
                    if(!vis[it]) {
                        q.push(it);
                        vis[it] = true;
                    }
                }
                mp[arr[idx]].clear();
            }
            ans++;             
        }        

        return ans;
    }
};



//NOTE: NOT VALID SOLUTION 
class Solution {
public:
    int minJumps(vector<int>& arr) {
        // array<int>
        // initially positioned at i = 0
        // you can jump to,
        // i. i+1
        // ii. i-1
        // iii. j where arr[i] == arr[j] and i != j
        // return min steps to reach the last index

        // 100 -23  -23  404  100   23   23   23   3   404
        // 0 -> 1 -> 2 -> 3 -> 1 -> 2 -> 3 -> 3 -> 4 -> 2

        // map[key, val] = key is arr[i], val is the step to reach there
        // dp[n+1]

        // i
        // 100
        // if we're in last then return dp[i] = dp[i-1]; map[arr[i]] = dp[i]

        // i
        // 100 -23
        // for arr[i] 
        // there can be mp[arr[i]] with small step
        // there can be mp[arr[i-1]]
        // dp[i] = min(map[arr[i-1]]+1, min(map[arr[i]]+1, dp[i-1]+1), map[arr[i+1]]+1));
        // if(map[arr[i]])
        //    map[arr[i]] = min(map[arr[i]], dp[i])
        // else
        //    map[arr[i]] = dp[i];

        int n = arr.size();
        unordered_map<int, int> mp; // keep lowest index for any arr[i]
        vector<int> dp(n+1, -1);

        dp[0] = 0;
        mp[arr[0]] = 0;
        for(int i = 1; i < n; i++){
            int min_j = dp[i-1]+1;
            // cout << min_j << " == " <<  mp[arr[i-1]]+1 << endl;
            if(mp.find(arr[i-1]) != mp.end()) min_j = min(min_j, mp[arr[i-1]]+2);
            if(mp.find(arr[i]) != mp.end()) {       
                int k = mp[arr[i]];         
                min_j = min(min_j, dp[k]+1);
                // if(k-1 >= 0 && mp.find(arr[k-1]) != mp.end()) min_j = min(min_j, dp[k-1]+2); 
                if(k+1 < n && mp.find(arr[k+1]) != mp.end()) min_j = min(min_j, dp[k+1]+2);
            }
            
            dp[i] = min_j;

            if(mp.find(arr[i]) != mp.end()) {
                int k = mp[arr[i]];
                if(dp[i] < dp[k]) mp[arr[i]] = i;
            } else mp[arr[i]] = i;
        }

        return dp[n-1];
    }
};


