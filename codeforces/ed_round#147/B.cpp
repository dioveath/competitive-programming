#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;

    vector<int> a(n), b(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        cin>>b[i];
    }
    
    int l = 0, r = n-1;
    while(a[l] == b[l]) l++;
    while(a[r] == b[r]) r--;

    while(l > 0 && b[l-1] <= b[l]) l--;
    while(r < n-1 && b[r] <= b[r+1]) r++;

    cout << l+1 << " " << r+1 << endl;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
}