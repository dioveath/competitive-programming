#include <vector>
#include <queue>
using namespace std;

int dir_x[4] = {1, -1, 0, 0};
int dir_y[4] = {0, 0, 1, -1};

vector<int> riverSizes(vector<vector<int>> matrix) {
  vector<int> res;
  for(int i = 0; i < matrix.size(); i++){
    for(int j = 0; j < matrix[i].size(); j++){
      if(matrix[i][j] == 0) continue;

      queue<pair<int, int>> q({{i, j}});

      int rs = 0;
      
      while(!q.empty()){
        int sz = q.size();
        while(sz--){
          pair<int, int> pos = q.front();
          q.pop();
          for(int k = 0; k < 4; k++){
            int dx = pos.second  + dir_x[k];
            int dy = pos.first + dir_y[k];
            if(dx < 0 || dx >= matrix[i].size() || dy < 0 || dy >= matrix.size()) continue;
            if(matrix[dy][dx] == 0) continue;
            matrix[dy][dx] = 0;
            q.push({dy, dx});
          }
          matrix[pos.first][pos.second] = 0;
          rs++;          
        }
      }

      res.push_back(rs);
      
    }
  }
  return res;
}
