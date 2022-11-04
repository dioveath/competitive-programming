// 345. Reverse Vowels of a String
// Given a string s, reverse only all the vowels in the string and return it.
// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

// Example 1:
// Input: s = "hello"
// Output: "holle"
// Example 2:

// Input: s = "leetcode"
// Output: "leotcede"

// Constraints:

// 1 <= s.length <= 3 * 105
// s consist of printable ASCII characters.

// # Intuition
// <!-- Describe your first thoughts on how to solve this problem. -->
// Reversing anything would be fairly easy if we can have two pointers from left & right.

// # Approach
// <!-- Describe your approach to solving the problem. -->
// We're using two pointer to keep track of the vowels, from left & another one from right. First, we'll keep checking for vowel from left and after that, we'll check vowel from right to find another vowel. We'll swap the character reversing our first vowel letters. And continue this until our left & right pointer meets.

// # Complexity
// - Time complexity: O(n)
// <!-- Add your time complexity here, e.g. $$O(n)$$ -->

// - Space complexity: O(1)
// <!-- Add your space complexity here, e.g. $$O(n)$$ -->

// # Code

class Solution {
public:
    string reverseVowels(string s) {
        unordered_map<char, int> vowel({{'a',1}, {'e',1}, {'i', 1}, {'o', 1}, {'u', 1}});
        int i = 0, j = s.length()-1;
        while(i < j){
            while(i < j && !vowel[tolower(s[i])]) i++;
            while(i < j && !vowel[tolower(s[j])]) j--;
            swap(s[i++], s[j--]);
        }
        return s;
    }
};
