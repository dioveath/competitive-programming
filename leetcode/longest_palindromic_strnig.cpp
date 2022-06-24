// 0 1 2 3 4 5 6 7 8 9 10 11 12 13
//                 s   i     e

// // if middle has one char only 
// currentLen = 8 - 12 - 1 = 3
// start = 10 - (3 - 1)/2 = 9;
// end = 10 + 3/2 = 11;

// return s(9, 11 + 1);


// 0 1 2 3 4 5 6 7 8 9 10 11 12 13
//                 s   i        e
// // if middle has two char
// current = 8 - 13 - 1 = 4;
// start = 10 - ((4-1)/2) = 9;
// end = 10 + 4/2 = 12;

// return s(9, 12 + 1);

class Solution {
public:


  string longestPalindrome(string s){
    if(s.length() < 1) return "";
    int start = 0, maxLen = 0;
    for(int i = 0; i < s.length(); i++){
      int len1 = expandAroundCenter(s, i, i);
      int len2 = expandAroundCenter(s, i, i+1);
      int currentLen = max(len1, len2);
      if(currentLen > maxLen) {
	    start = i - (currentLen - 1)/2;
	    maxLen = currentLen;
      }
    }

    return s.substr(start, maxLen);
  }

  int expandAroundCenter(string s, int left, int right){
    int L = left, R = right;
    while(L >= 0 && R < s.length() && s[L] == s[R]) {
        
      L--;
      R++;
    }
    return R - L - 1;
  }


};



