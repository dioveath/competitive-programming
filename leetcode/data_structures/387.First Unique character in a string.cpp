// Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
// Example 1:
// Input: s = "leetcode"
// Output: 0
// Example 2:
// Input: s = "loveleetcode"
// Output: 2
// Example 3:
// Input: s = "aabb"
// Output: -1
// Constraints:
// 1 <= s.length <= 105
// s consists of only lowercase English letters.

#include <queue>
#include <vector>
#include <iostream>
#include <map>

using namespace std;


// class Solution {
// public:
//     // int firstUniqChar(string s) {
//     //     map<char, int> map;
//     //     queue<int> q;
//     //     for(int i = 0; i < s.length(); i++){
//     //         if(map.find(s[i]) == map.end()) { 
//     //             map[s[i]] = i;
//     //             q.push(i);
//     //         } else { 
//     //             vector<int> temp;
//     //             bool found = false;
//     //             while(!q.empty()) { 
//     //                 if(!found && q.front() == map[s[i]]){
//     //                     found = true;
//     //                     q.pop();
//     //                 } else {
//     //                     temp.push_back(q.front());
//     //                     q.pop();
//     //                 }
//     //             }
//     // 		for(int i = 0; i < temp.size(); i++)
//     // 		  q.push(temp[i]);
//     //         }
//     //     }
//     //     if(q.empty()) return -1; 
//     //     return q.front();
//     // }

//   int firstUniqChar(string s){
//     map<char, int> charIndex, map;
//     for(int i = 0; i < string.length(); i++) {
//       map[s[i]]++;
//       charIndex[s[i]] = i;
//     }

//     for(auto i : map)
//       if(i.second == 1) return charIndex[i.first];
//     return -1;
//   }

  
// };

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        queue<pair<char, int>> q;
        for(int i = 0; i < s.length(); i++){
            m[s[i]]++;
            q.push({s[i], i});
        }
        
        while(!q.empty()){
            if(m[q.front().first] == 1) return q.front().second;
            q.pop();
        }
        
        return -1;
    }
};

// int main(){
//   Solution s;
//   s.firstUniqChar("leetcode");
//   return 0;
// }
