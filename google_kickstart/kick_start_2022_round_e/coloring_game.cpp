#include<iostream>

using namespace std;

void solve(int T){
    int N;
    cin >> N;

    int bot = 0;
    while(N > 0){
        bot++;
        N -= 5;
    }
    
    cout << "Case #" << T << ": " << bot << endl;
}

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++)
        solve(i+1);
}
