
function removeZeros(array) {
  // Sort "array" so that all elements with the value of zero are moved to the
  // end of the array, while the other elements maintain order.
  // [0, 1, 2, 0, 3] --> [1, 2, 3, 0, 0]
  // Zero elements also maintain order in which they occurred.
  // [0, "0", 1, 2, 3] --> [1, 2, 3, 0, "0"]
  
  // Do not use any temporary arrays or objects. Additionally, you're not able
  // to use any Array or Object prototype methods such as .shift(), .push(), etc
  
  // the correctly sorted array should be returned.
  return array;
}

function removeZeros(arr){
  var c = 0;
  arr = arr.filter((e) => {
    if(e != 0) {
      return true;
    }
    c++;
    return false;
  });
  var l = arr.length;
  for(var i = 0; i < c; i++){
    arr[l+i] = 0;
  }
  return arr;
}


function removeZeros(arr){
  var zc = 0;
  for(var i = arr.length-1; i >= 0; i--){
    if(arr[i] === 0 || arr[i] === "0"){
      for(var j = i; j < arr.length-1-zc; j++) {
        var t = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = t;
      }
      zc++;
    }
  }
  return arr;
}


console.log(removeZeros([7, 2, 3, 0, 4, 6, 0, 0, 13, 0, 78, 0, 0, 19, 14]));
