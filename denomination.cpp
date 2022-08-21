#include <stdlib>


using namespsace std;

vector<vector<int>> ans;
vector<vector<int>> denominate(vector<int> units, int target){
  vector<int> d;
  solve(d, units, target, 0);
  return ans;
}

void solve(vector<int> d, vector<int> units, int target, int curr){
  if(curr == target) { ans.push_back(d); return; }

  for(int i = 0; i < units.size(); i++){
    if(curr + units[i] <= target) {
      vector<int> temp = d;
      temp.push_back(units[i]);
      solve(temp, units, target, curr-units[i]);
    }
  }

}


