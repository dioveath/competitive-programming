

window.onload = ()=> {


  Array.prototype.sameStructureAs = function (other) {
    if(!isArray(other)) return false;
    return checkArray(this, other);

    // Note: You are given a function isArray(o) that returns
    // whether its argument is an array.
  };

  function checkArray(a, b){
    if(a.length != b.length) return false;
    for(var i = 0; i < a.length; i++){
      if(isArray(a[i])) {
        if(!isArray(b[i])) return false;
      }
      if(isArray(b[i])) {
        if(!isArray(a[i])) return false;
      }
      if(isArray(a[i]) && isArray(b[i])) {
        console.log(a[i], b[i]);
        if(!checkArray(a[i], b[i])) {
          return false;
        } else continue;
      }

    }
    return true;
  }

  function isArray(a){
    return Array.isArray(a);
  }

  console.log(checkArray([1,[1,1]], [2,[2]]));


};
