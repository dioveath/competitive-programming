#include <iostream>

using namespace std;


int main(){
  int t;
  cin >> t;
  while(t--) {
    int ck, nd = 0;
    int d[3];

    cin >> ck;
    for(int i = 0; i < 3; i++)
      cin >> d[i];
    
    while(ck){
      ck = d[ck-1];
      nd++;
    }

    if(nd == 3) cout << "YES" << endl;
    else cout << "NO" << endl;

  }
  return 0;
}
