#include<bits/stdc++.h>

using namespace std;


int main(){
  int n, m;

  cin >> n;  
  cin >> m;

  long long a[n];
  long long s[m][2];

  for(int i = 0; i < n; i++)
    cin >> a[i];

  unsigned long long dp_inc[n] = {0};
  unsigned long long dp_dec[n] = {0};

  dp_dec[n-1] = 0;
  for(int i = 0, j = n-1; i < n; i++, j--) {
    if(i != 0)
      dp_inc[i] = a[i] < a[i-1] ? dp_inc[i-1] + (a[i-1] - a[i]) : dp_inc[i-1];
    if(j != n-1) {
      dp_dec[j] = a[j+1] > a[j] ? dp_dec[j+1] + (a[j+1] - a[j]) : dp_dec[j+1];
    } 
  }

  for(int i = 0; i < m; i++)
    cin >> s[i][0] >> s[i][1];  

  for(int i = 0; i < m; i++){
    unsigned long long d = 0;

    if(s[i][1] > s[i][0]){
      d = dp_inc[s[i][1]-1] - dp_inc[s[i][0]-1];
    } else {
      d = dp_dec[s[i][1]-1] - dp_dec[s[i][0]-1];
    }

    cout << d << endl;
  }



  return 0;
}
