function gap(g, m, n){
  var ng = null;
  var pbg = false;
  for(var i = m; i <= n-g; i++){
    if(isPrime(i) && isPrime(i+g)) {
      for(var j = i+1;j <= i+g-1 && j <= n; j++){
        if(isPrime(j)) {
          pbg = true;
          break;
        } else
          pbg = false;
      }

      if(pbg){
        continue;
      }
      ng=[i, i+g];
      break;
    }
  }
  return ng;
}

function isPrime(n){
  for(var i = 2; i <= n/2; i++)
    if(n % i == 0) return false;
  return true;
}

