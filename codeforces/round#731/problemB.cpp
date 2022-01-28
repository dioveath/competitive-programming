
#include<iostream>
#include<string>

using namespace std;

char la[26] = {'a','b','c','d','e','f','g','h','i','k','l','m','n','o','p','q','r','s','t','v','x'};

void solve() {
  string s;
  cin >> s;
  for(int i =0; i< s.length; s++){
    for(int j = 0; j < i; j++)
      if(la[i] != s[i] || la[j] != s[i]) continue;
	cout << "no";
  }
  cout << "yes";
}

int main(){

  int t = 0;
  cin >> t;
  for(int i = 0;i < t; i++){
    solve();
  }

  return 0;
}
