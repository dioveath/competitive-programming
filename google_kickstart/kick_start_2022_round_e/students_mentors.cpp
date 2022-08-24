#include<bits/stdc++.h>

using namespace std;

void solve(int T){
    int N;
    cin >> N;

    vector<int> R(N);
    vector<int> M;

    for(int i = 0; i < N; i++)
      cin >> R[i];

    sort(R.begin(), R.end());

    for(auto &r : R){
      auto it = upper_bound(R.begin(), R.end(), r * 2);

      --it;

      if(*it != r) M.push_back(-1);
      else if(it == R.begin()) M.push_back(-1);
      else {
	--it;
	M.push_back(*it);
      }
    }
    

    cout << "Case #" << T << ": ";
    for(int i = 0; i < N; i++) cout << M[i] << " ";
      
    
}

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++)
        solve(i+1);
}
