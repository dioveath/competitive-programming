#include<bits/stdc++.h>

using namespace std;

void solve(int t){
    int n, k;
    cin >> n >> k;

    for(int i = 2; i <= 100; i++){
        int j = n-i;
        int temp = (i*(i-1))/2 + (j*(j+1)/2;
        if(temp == k){
            cout << "YES" << endl;
            i++;
            while(i--) cout << "1 ";
            j++;
            while(j--) cout << "-1 ";
            cout << endl;
            return;
        }
    }
    cout << "NO" << endl;
}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}
