// 212. Word Search II

// Given an m x n board of characters and a list of strings words, return all words on the board.
// Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

// Example 1:

// Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
// Output: ["eat","oath"]
// Example 2:


// Input: board = [["a","b"],["c","d"]], words = ["abcb"]
// Output: []
 

// Constraints:

// m == board.length
// n == board[i].length
// 1 <= m, n <= 12
// board[i][j] is a lowercase English letter.
// 1 <= words.length <= 3 * 104
// 1 <= words[i].length <= 10
// words[i] consists of lowercase English letters.
// All the strings of words are unique.


// ================================================================================
// Intuition

// First solution, brute-force
// Create set from words for o(1) access.
// Backtrack the board from every cell to 4 direction up to length 10

//     if current_word is in set
//        ans.push_back(current_word)
// Improvements ??
// Can we check if the curr_word is equaling to some words present in the words_set
// i.e. if the current word ith character is matching any ith character of words.

// vector<set<char>> words_char_set;

// 0 1 2 3 4 5 
// e a t
// c a r
// f o o b a r

// set<char> ({e, c, f}) ---- 0
// set<char> ({a, a, p}) ---- 1
// set<char> ({t, r, o}) ---- 2
// set<char> ({b})       ---- 3
// set<char> ({a})       ---- 4
// set<char> ({r})       ---- 5
// Improvements v2.0 ??
// Let's check if I can just keep the first starting letter, atleast it gives me better starting point.
// Nah It still doesn't work

// Approach
// Improvements v3.0 ??
// After seeing all this complexity, we better off see the problem with new angle from all of our findings. Considering the different paths a letter from words can take, and so many possibilities with words. We can view this as a trie like structure, where the letter of a word is a node and its descendents are its following character and we can do this for every word in words creating a trie.

// trienode { 
//     word            // this nodes char value
//     child_nodes[26]  // this is a linkage to next char in a word
// }
// We will build the trie with the all the words. Then, we'll start to backtrack every cell to find a matching word through grid.

// Complexity
// Time complexity: O(2^n)
// Space complexity: O(2^n)

// ================================================================================
// Code

class Solution {
public:
    struct Node {
        Node* children[26];
        string word;

        Node(): word(""){
            for(int i = 0; i < 26; i++) 
                children[i] = nullptr;
        }
    };

    Node* buildTrie(vector<string>& words){
        Node* root = new Node();
        for(string word : words){
            Node* curr = root;
            for(int i = 0; i < word.size(); i++){
                if(curr->children[word[i] - 'a'] == nullptr)
                    curr->children[word[i]-'a'] = new Node();
                curr = curr->children[word[i]-'a'];
            }
            curr->word = word;
        }
        return root;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size(), n = board[0].size();
        vector<string> ans;

        Node* root = buildTrie(words);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                backtrack(board, i, j, root, ans);
            }
        }

        return ans;
    }

    void backtrack(vector<vector<char>>& board, int y, int x, Node* curr_node, vector<string>& ans){
        int m = board.size(), n = board[0].size();
        if(y < 0 || y >= m || x < 0 || x >= n) return;
        
        char ch = board[y][x];
        if(ch == '*' || curr_node->children[ch-'a'] == nullptr) return;        

        curr_node = curr_node->children[ch-'a'];
        if(curr_node->word != "") {
            ans.push_back(curr_node->word);
            curr_node->word = "";
        }

        board[y][x] = '*';
        backtrack(board, y-1, x, curr_node, ans);
        backtrack(board, y+1, x, curr_node, ans);
        backtrack(board, y, x-1, curr_node, ans);
        backtrack(board, y, x+1, curr_node, ans);  
        board[y][x] = ch;
    }
};
