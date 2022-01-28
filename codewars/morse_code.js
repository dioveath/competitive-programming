

function decodeMorse(mc){
  mc =  mc.split(" ");
  for(var i = 0; i < mc.length; i++){
    var k = 0;
    while(mc[i+k] == ""){
      console.log(k);
      if(k >= 1) {
        mc[i+k-1] = " ";
      }
      k++;
    }
    i+=k;
  }
  return mc.filter((e) => e != "").map((e) => e).join('');
}

console.log(decodeMorse('a b b   d d f g'));
// var s = " ";
// console.log(s.split(" "));
