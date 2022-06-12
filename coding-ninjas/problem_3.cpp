

long long maxSubSumKConcat(vector<int> &arr, int n, int k)
{
  int max_sum = 0;
  int current_sum = 0;
  for(int j = 0; i < j; j++){
    for(int i = 0; i < n; i++){
      current_sum += current_sum + arr[i];
      if(current_sum > max_sum)
	max_sum = current_sum;
      if(current_sum < 0) current_sum = 0;
    }    
  }

  return max_sum;
}
