// 28. Find the Index of the First Occurrence in a String
// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
// Example 1:

// Input: haystack = "sadbutsad", needle = "sad"
// Output: 0
// Explanation: "sad" occurs at index 0 and 6.
// The first occurrence is at index 0, so we return 0.
// Example 2:

// Input: haystack = "leetcode", needle = "leeto"
// Output: -1
// Explanation: "leeto" did not occur in "leetcode", so we return -1.
 

// Constraints:

// 1 <= haystack.length, needle.length <= 104
// haystack and needle consist of only lowercase English characters.

class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0, j = 0;
        int k = 0;
        while(k < haystack.length()){
            if(haystack[k] == needle[j]) { 
                k++; j++; 
                if(j == needle.length()) return i;
            } else {
                j = 0; k = ++i;             
            }
        }
        return -1;
    }
};

// Rabin-Karp algorithm (Double Hash)
class Solution {
public:
    const int RADIX_1 = 26;
    const int RADIX_2 = 27;
    const int MOD_1 = 1000000033;
    const int MOD_2 = 2147483647;

    pair<long, long> hashPair(string str, int m){
        long hash1 = 0, hash2 = 0;
        long factor1 = 1, factor2 = 1;

        for(int i = m - 1; i >= 0; i--){
            hash1 += ((int) (str[i] - 'a') * (factor1)) % MOD_1;
            factor1 = (factor1 * RADIX_1) % MOD_1;

            hash2 += ((int) (str[i] - 'a') * (factor2)) % MOD_2;
            factor2 = (factor2 * RADIX_2) % MOD_2;
        }

        return make_pair(hash1 % MOD_1, hash2 % MOD_2);
    }

    int strStr(string haystack, string needle) {
        int m = needle.length();
        int n = haystack.length();
        if(n < m) return -1;

        long MAX_WEIGHT_1 = 1;
        long MAX_WEIGHT_2 = 1;

        for(int i = 0; i < m; i++){
            MAX_WEIGHT_1 = (MAX_WEIGHT_1 * RADIX_1) % MOD_1;
            MAX_WEIGHT_2 = (MAX_WEIGHT_2 * RADIX_2) % MOD_2;
        }

        pair<long, long> hashNeedle = hashPair(needle, m);
        pair<long, long> hashHay = { 0, 0 };

        for(int i = 0; i <= n-m; i++){
            if(i == 0){
                hashHay = hashPair(haystack, m);
            } else {
                hashHay.first = ((hashHay.first * RADIX_1) % MOD_1 
                - ((int) (haystack[i-1]-'a') * MAX_WEIGHT_1) % MOD_1 
                + (int) (haystack[i+m-1]-'a') + MOD_1) % MOD_1;

                hashHay.second = ((hashHay.second * RADIX_2) % MOD_2
                - ((int) (haystack[i-1]-'a') * MAX_WEIGHT_2) % MOD_2
                + (int) (haystack[i+m-1]-'a') + MOD_2) % MOD_2;
            }

            if(hashNeedle.first == hashHay.first && hashNeedle.second == hashHay.second) return i;
        }

        return -1;
    }
};
