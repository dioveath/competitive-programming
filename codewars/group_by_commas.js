



function groupByCommas(n){
  var s = (n+'').split('');
  for(var i = s.length - 3; i > 0; i-=3)
      s.splice(i, 0, ',');
  return s.join('');
}

console.log(groupByCommas(1));
console.log(groupByCommas(10));
console.log(groupByCommas(100));
console.log(groupByCommas(1000));
console.log(groupByCommas(10000));
console.log(groupByCommas(100000));
console.log(groupByCommas(1000000));
console.log(groupByCommas(10000000));
console.log(groupByCommas(100000000));
