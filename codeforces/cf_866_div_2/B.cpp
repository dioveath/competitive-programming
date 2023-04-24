#include<bits/stdc++.h>

using namespace std;


void solve(int t){
    string s;
    cin >> s;

    int n = s.length();
    int maxl = 0, maxr = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            int l = i;
            int r = i+1;
            while(r < n && s[r] == '1') r++;
            if(r-l > maxr-maxl) {
                maxl = l; maxr = r;
            }
            i = r-1;
        }
    }

    cout << "l: " << maxl << " r: " << maxr << endl;

    int size = maxr-maxl;

    if(size == 0) { 
        cout << 0 << endl;
        return;
    }



    // // check for outleft & outright
    // int l = 0, r = n-1;
    // while(l < n && s[l] == '1') l++;
    // while(r >= 0 && s[r] == '1') r--;

    // cout << "l: " << l << " r: " << r << endl;

    // if(l >= r) {
    //     cout << size * size << endl;
    //     return;
    // }
    // if(l < r) size = max(size, l+1+(n-r)+1);



    if(size % 2 == 0) cout << size-1 * min(1, size-2) << endl;
    else cout << min(1, size-1) * min(1, size-1) << endl;
}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}
