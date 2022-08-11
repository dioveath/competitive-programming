using namespace std;

// O(n2) time | space(2)??
bool isValidSubsequence(vector<int> array, vector<int> sequence) {
  if(sequence.size() > array.size()) return false;
  int prev_idx = -1, k = 0;
  for(int i = 0; i < sequence.size(); i++){
    bool found = false;
    for(int j = k; j < array.size(); j++){
      if(array[j] == sequence[i]) { 
        if(prev_idx > j) return false;
        prev_idx = j;
        k = j+1;
        found = true;
        break;
      }
    }
    if(!found) return false;
  }
  return true;
}


using namespace std;

// O(n) time | space(1)
bool isValidSubsequence(vector<int> array, vector<int> sequence) {
  if(sequence.size() > array.size()) return false;
  int k = 0;
  for(int i = 0; i < array.size(); i++)
    if(array[i] == sequence[k]) k++;
  return (k) == sequence.size();
}
