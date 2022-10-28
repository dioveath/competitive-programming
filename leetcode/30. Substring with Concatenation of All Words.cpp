// 30. Substring with Concatenation of All Words

// You are given a string s and an array of strings words. All the strings of words are of the same length.
// A concatenated substring in s is a substring that contains all the strings of any permutation of words concatenated.

// For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated substring because it is not the concatenation of any permutation of words.
// Return the starting indices of all the concatenated substrings in s. You can return the answer in any order.

 

// Example 1:

// Input: s = "barfoothefoobarman", words = ["foo","bar"]
// Output: [0,9]
// Explanation: Since words.length == 2 and words[i].length == 3, the concatenated substring has to be of length 6.
// The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which is a permutation of words.
// The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which is a permutation of words.
// The output order does not matter. Returning [9,0] is fine too.
// Example 2:

// Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
// Output: []
// Explanation: Since words.length == 4 and words[i].length == 4, the concatenated substring has to be of length 16.
// There is no substring of length 16 is s that is equal to the concatenation of any permutation of words.
// We return an empty array.
// Example 3:

// Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
// Output: [6,9,12]
// Explanation: Since words.length == 3 and words[i].length == 3, the concatenated substring has to be of length 9.
// The substring starting at 6 is "foobarthe". It is the concatenation of ["foo","bar","the"] which is a permutation of words.
// The substring starting at 9 is "barthefoo". It is the concatenation of ["bar","the","foo"] which is a permutation of words.
// The substring starting at 12 is "thefoobar". It is the concatenation of ["the","foo","bar"] which is a permutation of words.
 

// Constraints:

// 1 <= s.length <= 104
// 1 <= words.length <= 5000
// 1 <= words[i].length <= 30
// s and words[i] consist of lowercase English letters.

class Solution {
public:
    unordered_map<string, int> map_w;    
    
    vector<int> findSubstring(string s, vector<string>& words) {
        int sub_len = words[0].size();
        for(int i = 0; i < words.size(); i++)
            map_w[words[i]]++;
        
        int full_len = sub_len * words.size();
        if(full_len > s.size()) return {};
        
        vector<int> ans;
        int i = 0;
        while(i <= s.length()-full_len) {
            if(check_substring(map_w, s.substr(i, full_len), sub_len)) {
                ans.push_back(i);
            }            
            i++;
        }
        
        return ans;
    }
    
    bool check_substring(unordered_map<string, int> umap, string word, int sub_len){
        for(int i = 0; i < word.size(); i += sub_len){
            string sub_word = word.substr(i, sub_len);
            if(umap.find(sub_word) == umap.end()) return false;
            umap[sub_word]--;
            if(umap[sub_word] == 0) umap.erase(sub_word);
        }
        return umap.empty();
    }
    
};



// NOTE: Not a solution
class Solution {
public:
    unordered_map<string, int> map_w;    
    
    vector<int> findSubstring(string s, vector<string>& words) {
        // given,
        // string s 
        // 1 <= s.length <= 10^4
        //
        // array<string> words
        // 1 <= words.length <= 5000
        // 1 <= words[i].length <= 30
        
        // return array<int> indices_of_s 
        // (where from indices_of_s[i] to perm.length is equal to perm(words))
        
        // solution 1, brute force:
        // every permutation of the words
        // ["foo", "bar"]
        // ["foobar", "barfoo"]
        
        // check every substring in s for permutations
        // "barfoothefoobarman" i,j
        // "b"
        // "ba"
        // "bar"
        // "bar...n"
        // "barfoo" -> ans.push_back(i)
        // "a"
        // "ar"
        // "arf"
        // "arf..n"
        // "foobar" -> ans.push_back(i)
        // ""           
        
        // solution 2, O(n^2) time complexity, O(n^2) space complexity
        // get every permutation
        // and put it in hash_map 
        
        // i = 0, j = words[i to n].length()
        // for j < s.length()
        //     if hash_map(s.substr(i, j))
        //         ans.push_back(i)
        //     i++; j++;
        
        set<int> idx_set;
        backtrack(words, idx_set, "");
    
        int sub_len = 0;
        if(map_w.size()){
            sub_len = map_w.begin()->first.length();
        }
        
        if(sub_len > s.length()) return {};
        
        vector<int> ans;
        int i = 0;
        while(i <= s.length()-sub_len) { 
            if(map_w[s.substr(i, sub_len)]) {
                ans.push_back(i);
            }
            i++;
        }
        
        
        return ans;
    }
    
    void backtrack(vector<string>& words, set<int>& vs, string curr){        
        if(vs.size() == words.size()) {
            map_w[curr]++;
            return;
        }
        
        for(int i = 0; i < words.size(); i++){
            if(vs.find(i) != vs.end()) continue;
            set<int> t_vs = vs;            
            t_vs.insert(i);
            string tmp = curr;        
            tmp += words[i];
            backtrack(words, t_vs, tmp);
        }
    }
    
};
