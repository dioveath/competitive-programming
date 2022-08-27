#include<bits/stdc++.h>


using namespace std;


void solve(int t){
  string str1, str2;
  cin >> str1 >> str2;

  unordered_map<char, int> umap;

  for(int i = 0; i < 2; i++)
    umap['z'-str1[i]]++;
  for(int i = 0; i < 2; i++)
    umap['z'-str2[i]]++;  

  cout << umap.size() - 1 << endl;
}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}
