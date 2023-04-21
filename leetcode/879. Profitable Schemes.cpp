// 879. Profitable Schemes
// There is a group of n members, and a list of various crimes they could commit. The ith crime generates a profit[i] and requires group[i] members to participate in it. If a member participates in one crime, that member can't participate in another crime.
// Let's call a profitable scheme any subset of these crimes that generates at least minProfit profit, and the total number of members participating in that subset of crimes is at most n.
// Return the number of schemes that can be chosen. Since the answer may be very large, return it modulo 109 + 7.

// Example 1:
// Input: n = 5, minProfit = 3, group = [2,2], profit = [2,3]
// Output: 2
// Explanation: To make a profit of at least 3, the group could either commit crimes 0 and 1, or just crime 1.
// In total, there are 2 schemes.

// Example 2:
// Input: n = 10, minProfit = 5, group = [2,3,5], profit = [6,7,8]
// Output: 7
// Explanation: To make a profit of at least 5, the group could commit any crimes, as long as they commit one.
// There are 7 possible schemes: (0), (1), (2), (0,1), (0,2), (1,2), and (0,1,2).
 
// Constraints:
// 1 <= n <= 100
// 0 <= minProfit <= 100
// 1 <= group.length <= 100
// 1 <= group[i] <= 100
// profit.length == group.length
// 0 <= profit[i] <= 100

// top down dynamic programming
class Solution {
public:
    const int mod = 1e9+7;
    int memo[101][101][101];
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(memo, -1, sizeof(memo));
        return find(0, 0, 0, n, minProfit, group, profit);
    }

    int find(int index, int count, int profit, int n, int minProfit, vector<int>& group, vector<int>& profits){
        if(index >= group.size()) return profit >= minProfit;
        if(memo[index][count][profit] != -1) return memo[index][count][profit];
        
        int ways = find(index+1, count, profit, n, minProfit, group, profits);
        if(count + group[index] <= n) 
            ways += find(index+1, count+group[index], min(minProfit, profit+profits[index]), n, minProfit, group, profits);
        return memo[index][count][profit] = ways % mod;
    }
};



// bottom up dynamic programming approach
class Solution {
public:
    const int mod = 1e9+7;
    int dp[101][101][101];
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profits) {
        for(int i = 0; i <= n; i++){
            dp[group.size()][i][minProfit] = 1;
        }

        for(int index = group.size()-1; index >= 0; index--){
            for(int count = 0; count <= n; count++){
                for(int profit = 0; profit <= minProfit; profit++){
                    dp[index][count][profit] = dp[index+1][count][profit];
                    if(count + group[index] <= n){
                        // adding ways to get profitable schemes, including this crime
                        int take = dp[index+1][count+group[index]][min(minProfit, profit+profits[index])];
                        dp[index][count][profit] = (dp[index][count][profit] + take) % mod;
                    }
                }
            }
        }

        return dp[0][0][0];
    }

};
