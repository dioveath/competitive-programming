window.onload = ()=> {


  var isPP = function(n){
    for(var i = 2; i <= n/2; i++){
      console.log();

    }
    return null;
  };


  function getPrimeFactors(n){
    var f = [];
    for(var i = 2; i <= n/2; i++){
      if(isPrime(i) && n % i == 0){
        if(f.includes(i)) continue;
        f.push(i);
        f.push(n/i);
      }
    }
    return f;
  }


  function isPrime(n){
    if(n < 2) return false;
    for(var i=2; i <= Math.floor(n/2); i++)
      if(n % i == 0) return false;
    return true;
  }

  // for(var i = 0; i < 100; i++){
  //   console.log(i + " is " + (isPrime(i) ? " prime." : " composite."));
  // }

  // for(var i = 0; i < 100; i++){
  //   console.log("Factors of " + i + ":  " + getPrimeFactors(i));
  // }

  for(var i = 0; i < 100; i++){
    console.log(`Math.log(${i}): ${Math.log(i)}`);
  }  


  



};
