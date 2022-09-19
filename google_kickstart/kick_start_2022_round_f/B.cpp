#include<bits/stdc++.h>

using namespace std;


void dfs(int from, int to, vector<vector<int>>& adj, vector<int>& levels) {
  if(to >= adj.size()) return;
  levels[to]++;
  for(int i = 0; i < adj[to].size(); i++){
    if(from == adj[to][i]) continue;
    dfs(to, adj[to][i], adj, levels);
  }
}


void solve(int t){
  int N, Q;

  vector<vector<int>> adj;
  for(int i = 0; i < N-1; i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for(int i = 0; i < Q; i++) {
    int _; cin >> _;
  }

  for(int i = 0; i < adj.size(); i++){
    for(int j = 0; j < adj[i].size(); j++) {
      cout << adj[i][j] << " ";
    }
    cout << endl;
  }

  vector<int> levels;
  dfs(-1, 0, adj, levels);

  for(int i = 0; i < levels.size(); i++){
    cout << levels[i] << endl;
  }

  cout << "Case #" << t << ": " << 0 << endl;
}


int main(){
  int T;
  cin >> T;

  for(int i = 0; i < T; i++)
    solve(i+1);
}



// struct Node {
//   int val = 0;
//   set<Node*> children;
//   Node() : val(0) {}
//   Node(int x) : val(x) {}
// };


// void solve(int t){
//   int N, Q;
//   cin >> N >> Q;

//   unordered_map<int, Node*> um;
//   Node* root = nullptr;
//   for(int i = 0; i < N-1; i++){
//     int a, b;
//     cin >> a >> b;
//     if(b < a) swap(a, b);

//     if(um.find(a) != um.end() && um.find(b) != um.end()) {
//       um[a]->children.insert(um[b]);
//     } else if(um.find(b) != um.end()) {
//       Node* tmp = new Node(a);
//       um[a] = tmp;
//       tmp->children.insert(um[b]);
//     } else if(um.find(a) != um.end()){
//       Node* tmp = new Node(b);
//       um[b] = tmp;
//       um[a]->children.insert(tmp);
//     } else {
//       Node* tmp = new Node(a);
//       Node* tmp2 = new Node(b);
//       tmp->children.insert(tmp2);
//       um[a] = tmp;
//       um[b] = tmp2;      
//     }

//     if(!root && a == 1) root = um[a];
//   }

//   for(int j = 0; j < Q; j++) {
//     int b;
//     cin >> b;
//   }

//   if(!root) {
//     cout << "Case #" << t << ": " << (Q >= 1 ? 1 : 0) << endl;
//     return;    
//   }   

//   int cnt = 0;
//   queue<Node*> q({root});
//   while(!q.empty()){
//     int sz = q.size();

//     if(cnt + sz > Q) {
//       cout << "Case #" << t << ": " << cnt << endl;
//       return;
//     } else {
//       cnt += sz;
//     }

//     set<Node*> next;
//     while(sz--){
//       Node* nd = q.front();
//       q.pop();
//       for(auto it : nd->children) next.insert(it);
//     }

//     for(auto it : next) q.push(it);
//   }

//   cout << "Case #" << t << ": " << cnt << endl;
// }


// int main(){
//   int T;
//   cin >> T;

//   for(int i = 0; i < T; i++)
//     solve(i+1);
// }



