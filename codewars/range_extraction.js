

function solution(arr){
  var s = "";
  for(var i = 0; i < arr.length; i++){
    if(arr[i+2] == arr[i] + 2) {
      var k = 0;
      for(k = 2; (i+k) < arr.length; k++){
        if(arr[i+k] != arr[i] + k) break;
        console.log(arr[i+k]);
      }
      s += `${arr[i]}-${arr[i+k-1]}${(i+k)<arr.length ? ',':''}`;
      i += k-1;
    } else {
      s += `${arr[i]}${i<arr.length-1 ? ',':''}`;
    }
  }
  return s;
}

console.log(solution([-6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8, 9, 10, 11, 14, 15, 17, 18, 19, 20]));
