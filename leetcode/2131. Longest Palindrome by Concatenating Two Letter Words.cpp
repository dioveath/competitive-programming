// 2131. Longest Palindrome by Concatenating Two Letter Words
// You are given an array of strings words. Each element of words consists of two lowercase English letters.
// Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.
// Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.
// A palindrome is a string that reads the same forward and backward.

// Example 1:

// Input: words = ["lc","cl","gg"]
// Output: 6
// Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
// Note that "clgglc" is another longest palindrome that can be created.
// Example 2:

// Input: words = ["ab","ty","yt","lc","cl","ab"]
// Output: 8
// Explanation: One longest palindrome is "ty" + "lc" + "cl" + "yt" = "tylcclyt", of length 8.
// Note that "lcyttycl" is another longest palindrome that can be created.
// Example 3:

// Input: words = ["cc","ll","xx"]
// Output: 2
// Explanation: One longest palindrome is "cc", of length 2.
// Note that "ll" is another longest palindrome that can be created, and so is "xx".
 

// Constraints:
// 1 <= words.length <= 105
// words[i].length == 2
// words[i] consists of lowercase English letters.


class Solution {
public:
    int longestPalindrome(vector<string>& words) {  
        unordered_map<string, int> umap;
        for(auto word : words) umap[word]++;
        
        int max_palin = 0;                
        bool central = false;
        for(const auto& [word, wcount] : umap){
            if(word[0] == word[1]){
                if(wcount % 2 == 0){
                    max_palin += wcount;
                } else {
                    max_palin += wcount - 1;
                    central = true;
                }
            } else if(word[0] < word[1] && umap.count({word[1], word[0]})){
                max_palin += 2 * min(wcount, umap[{word[1], word[0]}]);
            }
        }
        
        if(central) max_palin++;
        return 2 * max_palin;        
    }
};



class Solution {
public:
    int longestPalindrome(vector<string>& words) {  
        unordered_map<string, int> umap;
        int max_palin = 0;

        for(int i = 0; i < words.size(); i++){
            if(umap[words[i]]) {
                max_palin += 4;
                umap[words[i]] = 0;
                continue;
            }
            string to_palin = "";
            to_palin += words[i][1];
            to_palin += words[i][0];
            umap[to_palin]++;
        }

        for(auto it : umap){
            if((it.first[0] != it.first[1])) continue;
            max_palin += 2;
            break;
        }
        return max_palin;
    }
};
