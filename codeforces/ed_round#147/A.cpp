#include<bits/stdc++.h>

using namespace std;

int fact(int n){
    if(n <= 1) return 1;
    return n * fact(n-1);
}

void solve(){
    string s;
    cin >> s;        

    int ans = 1;

    for(int i = 0; i < s.length(); i++){
        if(i == 0 && s[i] == '0') ans = 0;
        if(s[i] == '?') {
            if(i == 0) ans *= 9;
            else ans *= 10;
        }
    }

    cout << ans << endl;
}


int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
}