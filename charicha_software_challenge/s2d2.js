window.onload = () => {

  let zero = f => f === undefined ? 0 : Math.floor(f(0));
  let one = f => f === undefined ? 1 : Math.floor(f(1));
  let two = f => f === undefined ? 2 : Math.floor(f(2));
  let three = f => f === undefined ? 3 : Math.floor(f(3));
  let four = f => f === undefined ? 4 : Math.floor(f(4));
  let five = f => f === undefined ? 5 : Math.floor(f(5));
  let six = f => f === undefined ? 6 : Math.floor(f(6));
  let seven = f => f === undefined ? 7 : Math.floor(f(7));
  let eight = f => f === undefined ? 8 : Math.floor(f(8));
  let nine = f => f === undefined ? 9 : Math.floor(f(9));

  let plus = r => (v) => Math.floor(v+r);
  let minus = r => (v) => Math.floor(v-r);
  let times = r => (v) => Math.floor(v*r);
  let dividedBy = r => (v) => Math.floor(v/r);

  // function dividedBy(r) { return (v) => v / r; }

  var r = eight(dividedBy(three()));

  console.log(seven(times(five())));
  console.log(four(plus(nine())));
  console.log(eight(minus(three())));
  console.log(six(dividedBy(two())));

  console.log(r);


  // describe("Tests", () => {
  // 	it("test", () => {
  // 		Test.assertEquals(seven(times(five())), 35);
  // 		Test.assertEquals(four(plus(nine())), 13);
  // 		Test.assertEquals(eight(minus(three())), 5);
  // 		Test.assertEquals(six(dividedBy(two())), 3);
  // 	});
  // });

};
