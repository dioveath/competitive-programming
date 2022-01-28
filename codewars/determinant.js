


function determinant(m){
  if(m[0].length == 1) {
    return m[0][0];
  } else if(m[0].length == 2){
    return (m[0][0] * m[1][1]) - (m[0][1] * m[1][0]);
  } else {
    var sign = 1;
    var det = 0;
    for(var i = 0; i < m.length; i++){
      var nm = [];
      for(var j = 1; j < m.length; j++) {
        var tm = m[j].filter((_e, index) => index != i);
        nm.push(tm);
      }
      det += (m[0][i] * determinant(nm) * sign);
      sign *= -1;
    }
    return det;
  }
}

var m1 = [ [1, 3], [2,5]];
var m2 = [
  [2,5,3],
  [1,-2,-1],
  [1, 3, 4]
];

// console.log(determinant([[1]]), 1);
// console.log(determinant(m1),-1);
console.log(determinant(m2),-20);
