#include <iostream>
#include <string>

using namespace std;

int solution(string S) {
  int cnt = 0;
  if(S[0] == 'b') cnt += 1;
  if(S[0] == 'c') cnt += 2;

  for(int i = 0; i < S.length()-1; i++){
    int diff = S[i+1] - S[i];
    if(diff == 0) cnt += 2;
    else if(diff < 0 && !(S[i] == 'c' && S[i+1] == 'a')) cnt += 1;
    else if(diff > 0 && (S[i] == 'a' && S[i+1] == 'c')) cnt += 1;
  }

  return cnt;
}

int main(){
  solution("ab");
  solution("ca");
}
