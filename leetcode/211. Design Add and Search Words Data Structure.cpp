// 211. Design Add and Search Words Data Structure
// Design a data structure that supports adding new words and finding if a string matches any previously added string.
// Implement the WordDictionary class:
// WordDictionary() Initializes the object.
// void addWord(word) Adds word to the data structure, it can be matched later.
// bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 

// Example:

// Input
// ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
// [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
// Output
// [null,null,null,null,false,true,true,true]

// Explanation
// WordDictionary wordDictionary = new WordDictionary();
// wordDictionary.addWord("bad");
// wordDictionary.addWord("dad");
// wordDictionary.addWord("mad");
// wordDictionary.search("pad"); // return False
// wordDictionary.search("bad"); // return True
// wordDictionary.search(".ad"); // return True
// wordDictionary.search("b.."); // return True
 

// Constraints:

// 1 <= word.length <= 25
// word in addWord consists of lowercase English letters.
// word in search consist of '.' or lowercase English letters.
// There will be at most 3 dots in word for search queries.
// At most 104 calls will be made to addWord and search.



class WordDictionary {
public:
    struct Trie {
        Trie* children[26];
        bool isEnd = false;
        Trie() {
            for(int i = 0; i < 26; i++)
                children[i] = nullptr;                
        }
    };

    Trie* root;
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        Trie* current = root;
        for(auto c : word){
            int index = c - 'a';
            if(!current->children[index])
                current->children[index] = new Trie();
            current = current->children[index];
        }
        current->isEnd = true;
    }
    
    bool search(string word) {
        return searchHelper(word, root, 0);
    }

    bool searchHelper(string& word, Trie* curr, int idx){
        if(idx == word.length()) return curr->isEnd;
        if(word[idx] == '.'){
            for(int i = 0; i < 26; i++)
                if(curr->children[i] && searchHelper(word, curr->children[i], idx+1)) return true;
            return false;
        } else {
            int charIdx = word[idx] - 'a';
            if(!curr->children[charIdx]) return false;
            return searchHelper(word, curr->children[charIdx], idx+1);
        }

        return false;
    }
};
