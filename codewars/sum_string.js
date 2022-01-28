
function sumStrings(a, b){
  if(a.length > b.length){
    var t = a;
    a = b;
    b = t;
  }
  
  a = a.split("").reverse();
  b = b.split("").reverse();
  var rs = [], c = 0;
  for(var i = 0; i < b.length; i++){
    var da = 0, db = 0, s = 0;
    if(i >= a.length) {
      db = parseInt(b[i]);
      s = db + c;
    } else {
      da = parseInt(a[i]);
      db = parseInt(b[i]);
      s = da + db + c;
    }

    if(s > 9) {
      c = 1;
      var d = s % 10;
      rs.push(d);
    } else {
      c = 0;
      rs.push(s);
    }
  }
  if(c) rs.push(c);
  for(var i = rs.length-1; rs[i] == 0; i--) rs.splice(rs.length-1, 1);
  return rs.reverse().join("");
}

console.log(sumStrings("00103", "08567"));

// function sumStrings(a, b){
//   return String(Number(a) + Number(b));
// }


