

// var a = ['aa', 'bb', 'cc'];
// a[100] = 'fsa';
// console.log(a.length);


// const foo = [1, 2, 3];
// const [n] = foo;
// console.log(n);

// class X {
//   get Y() { return 42; }
// }

// var x = new X();

// console.log(x.Y);

const des = { type: 'pie' };
des.type = 'pudding';

const seconds = des;
seconds.type = 'asdfsa';

console.log(des.type);
