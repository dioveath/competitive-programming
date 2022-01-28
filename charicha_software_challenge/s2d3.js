window.onload = () => {

  function fib(n){
    if(n <= 1) return n;
    var a = "0";
    var b = "1";

    // var a = 0;
    // var b = 1;

    var t;

    for(var i = 2; i <= n; i++){
      // if(Number.isSafeInteger(a + b)){ 
      // 	t = Number(b);
      // 	b = a + b;
      //   a = t;
      // } else {
      // 	a = String(a);
      // 	b = String(b);
      // 	t = b;
      // 	b = add(a, b);
      // 	a = t;
      // }

      t = b;
      b = add(a, b);
      a = t;

      // t = b;
      // b = a + b;
      // a = t;
    }

    return b;
  }

  function reverse(s) {
    var r="";
    for(var i = s.length-1; i >= 0; i--)
      r += s[i];
    return r;
  }


  function add(a, b){
    var r = "";
    var c = 0;
    var s = 0;

    a = reverse(a).split("");
    b = reverse(b).split("");

    var l = a.length > b.length ? a.length : b.length;

    for(var i = 0; i < l; i++){
      var da = parseInt(a[i]) || 0;
      var db = parseInt(b[i]) || 0;

      var ws = da + db + c;
      if(ws > 9){
	s = ws % 10;
	c = 1;
      } else {
	c = 0;
	s = ws;
      }
      r += s;
    }

    if(c > 0) r+= c;

    return reverse(r);
  }

  // console.log(add("112312301278", "120947132"));
  // console.log(112312301278 + 120947132);

  function aroundFib(n){
    var start = Date.now();

    var fn = fib(n);
    var s = String(fn);

    var nc = Array(10).fill(0);
    var cnt = 0;
    var ld = 0;
    var ck = "";
    for(var i = 0; i < s.length; i++) {
      ck.length == 25 ? ck = s[i] : ck+=s[i];
      var d = parseInt(s[i]);
      nc[d]++;
      if(nc[d] > cnt) {
	cnt = nc[d];
	ld = d;
      }
      else if(nc[d] == cnt)
	if(d < ld) ld = d;

    }

    console.log((Date.now() - start)/1000 + " seconds");

    return `Last chunk ${ck}; Max is ${cnt} for digit ${ld}`;
  }

  // console.log(fib(180));

  document.body.innerHTML = `${aroundFib(18000)}`;

};
