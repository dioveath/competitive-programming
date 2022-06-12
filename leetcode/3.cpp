// Longest Substring without repeating characters

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s){
    vector<char> prev;
    for(int i = 0; i < s.length(); i++){
      if(prev.exists(s[i])) {
	prev.empty();
      } else {
	prev.push(s[i]);
      }
    }
    return prev.size();
  }
};


int main() {
  return 0;
}
