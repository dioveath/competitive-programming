// 967. Numbers With Same Consecutive Differences
// Return all non-negative integers of length n such that the absolute difference between every two consecutive digits is k.
// Note that every number in the answer must not have leading zeros. For example, 01 has one leading zero and is invalid.
// You may return the answer in any order.
// Example 1:

// Input: n = 3, k = 7
// Output: [181,292,707,818,929]
// Explanation: Note that 070 is not a valid number, because it has leading zeroes.
// Example 2:

// Input: n = 2, k = 1
// Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
 

// Constraints:

// 2 <= n <= 9
// 0 <= k <= 9



class Solution {
public:
    vector<int> res;
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i = 1; i <= 9; i++)
            permute(n-1, k, i, i); 
        return res;
    }
    
    void permute(int n, int k, int prev, int curr){
        if(n == 0) { res.push_back(curr); return; }
        int dig1 = prev+k;
        int dig2 = prev-k;
                
        if(dig1 < 10) permute(n-1, k, dig1, curr * 10 + dig1);
        if(k == 0) return;
        if(dig2 >= 0) permute(n-1, k, dig2, curr * 10 + dig2);
    }
};
