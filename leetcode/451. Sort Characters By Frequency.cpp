// 451. Sort Characters By Frequency
// Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.
// Return the sorted string. If there are multiple answers, return any of them.

// Example 1:

// Input: s = "tree"
// Output: "eert"
// Explanation: 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
// Example 2:

// Input: s = "cccaaa"
// Output: "aaaccc"
// Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
// Note that "cacaca" is incorrect, as the same characters must be together.
// Example 3:

// Input: s = "Aabb"
// Output: "bbAa"
// Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two different characters.
 

// Constraints:

// 1 <= s.length <= 5 * 105
// s consists of uppercase and lowercase English letters and digits.

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for(auto c : s) freq[c]++;
        sort(s.begin(), s.end(), [&] (char a, char b) {
            if(freq[a] > freq[b]) return true;
            if(freq[a] == freq[b] && a > b) return true;
            return false;
        });

        return s;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        map<int, string> bucket;
        string ans;

        for(auto c : s) freq[c]++;
        
        for(auto it : freq)
            bucket[it.second] += string(it.second, it.first);

        for(auto rb = bucket.rbegin(); rb != bucket.rend(); rb++)
            ans += rb->second;

        return ans;
    }
};
