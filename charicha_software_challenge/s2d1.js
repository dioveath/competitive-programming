window.onload = () => {

  // describe('description example', function() {
  //   var recipe, available;

  //   it('pass example tests', function() {
  //     recipe = { flour: 500, sugar: 200, eggs: 1 };
  //     available = { flour: 1200, sugar: 1200, eggs: 5, milk: 200 };
  //     Test.assertEquals(cakes(recipe, available), 2, 'Wrong result for example #1');

  //     recipe = { apples: 3, flour: 300, sugar: 150, milk: 100, oil: 100 };
  //     available = { sugar: 500, flour: 2000, milk: 2000 };
  //     Test.assertEquals(cakes(recipe, available), 0, 'Wrong result for example #2');
  //   });
  // });

  // var recipe = { flour: 500, sugar: 200, eggs: 1 };
  // var available = { flour: 1200, sugar: 1200, eggs: 5, milk: 200 };
      var recipe = { apples: 3, flour: 300, sugar: 150, milk: 100, oil: 100 };
      var available = { sugar: 500, flour: 2000, milk: 2000 };  

  console.log(cakes(recipe, available));

  function cakes(recipe, available) {
    var cakes = 9999999999;
    Object.keys(recipe).map((val) => {
      if(available[val] === undefined) cakes = 0;
      var n = Math.floor(available[val] / recipe[val]);
      if(n < cakes)
        cakes = n;
    });
    return cakes;
  }

  //best sol
  function bCakes(r, a){
    return Math.min(...Object.keys(r).map((v) => Math.floor(a[v] / r[v] || 0)));
  }

  var sol = document.getElementById("solution");
  sol.innerHTML = cakes.toString();

  var bSol = document.getElementById("bSolution");
  bSol.innerHTML = bCakes.toString();
  hljs.highlightAll();


};
