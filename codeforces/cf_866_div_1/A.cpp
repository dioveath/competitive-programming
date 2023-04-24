#include<bits/stdc++.h>

using namespace std;

void solve(int t){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int mex = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(a[j] == mex) { mex++; break; }
        }
    }

    mex++;
    int l = 0, r = n-1;
    while(l < n && a[l] != mex) l++;
    while(r >= 0 && a[r] != mex) r--;

    cout << "l: " << l << " r:" << r << endl;

    if(l >= r) 

    set<int> s;    
    for(int i = 0; i < l && i < n; i++) s.insert(a[i]);
    for(int i = r+1; i < n; i++) s.insert(a[i]);



    for(int i = 0; i < mex-1; i++) 
        if(s.find(i) == s.end()){
            cout << "NO" << endl;
            return;
        }

    cout << "YES" << endl;
}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}
