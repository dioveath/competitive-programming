
window.onload = ()=> {
  
  function zeros(n){
    var z=0;
    while(n >= 5){
      z += n = Math.floor(n/5);
    }
    return z;
  }

  function fact(n){
    if(n <= 0) return 1n;
    var a = n;
    while(--n) a *= n;
    return a;
  }

  var d = document.getElementById("debug");


  var nz = 0;
  for(var i = 0; i <= 125; i++){
    if(i % 5 == 0 && i != 0) {
      if(i % 25 == 0)
        nz++;
      nz++;
      console.log("------ " + nz);
    }
    console.log(fact(BigInt(i)));
  }



  

  zeros(0);
  zeros(5);
  zeros(6);
  zeros(30);
  
};
