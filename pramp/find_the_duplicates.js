function findDuplicates(arr1, arr2) {
  // your code goes here
  // arr1[int] arr2[int] 1 <= arr1.length <= 100 
  
  // return arr_result[int] containing all the arr1[int] == arr2[int] 
  
  // first solution, O(N) Space, O(N) Time
  // second solution,
  // i, j 
  // while(i < arr1.length() && j < arr.length()){
// if(arr1[i] == arr2[j]) {
  //    i++; j++;
  //    ans.push_back(arr[i]);
 // } else if arr1[i] < arr1[j] { 
  //     i++;
  // } else {
  //     j++;
  // }
  // 
  // }
   // M ≫ N - arr2 is much bigger than arr1.
  // O(M+N) == O(M), how can you improve this time complexity for case when M is much bigger
  /*
  
  arr1 = [5, 12];
  arr2 = [1, 3, 4, 5, 6, 7, 9, 11, 13, 17, 21]; O(M + N) = O(M)
  
  Theres a solution that is O(N*log(M)) which is better than O(N + M) in case where M is much much bigger than N
  
  https://www.linkedin.com/in/arjun-krishna-2001/
  */
    
  // Internet's not good 
  // 
  let result = [];
  let i = 0, j = 0;
  while(i < arr1.length && j < arr2.length){
    if(arr1[i] == arr2[j]) { 
      result.push(arr1[i]);
      i++; j++;
    } else if(arr1[i] < arr2[j]){
      i++;
    } else {
      j++;
    }
  }
  
  return result;
}


// console.log(findDuplicates( [1, 2, 2, 5, 6, 7], [2, 3, 3, 20]));
