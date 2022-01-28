var Sudoku = function(data) 
{
  //   Private methods
  // -------------------------


  //   Public methods
  // -------------------------
  return {
    board: data,
    isValid: function() {
      // YOUR SOLUTION
      var N = this.board.length;
      const t = N*(N+1)/2;
      var tsm = 0;
      for(var i = 0; i < N; i++){
        var trw = 0, tcl = 0;
        for(var j = 0; j < N; j++){
          if(typeof this.board[i][j] != "number") return false;
          trw += this.board[i][j];
          tcl += this.board[j][i];
        }
        if(trw != t || tcl != t) return false;
        var sm = this.board[i%~~Math.sqrt(N)][Math.floor(i/~~Math.sqrt(N))];
        if(typeof sm != "number") return false;
        tsm += sm;
      }
      if(tsm != t) return false;
      return true;
    }
  };
};


var goodSudoku1 = new Sudoku([
  [7,8,4, 1,5,9, 3,2,6],
  [5,3,9, 6,7,2, 8,4,1],
  [6,1,2, 4,3,8, 7,5,9],

  [9,2,8, 7,1,5, 4,6,3],
  [3,5,7, 8,4,6, 1,9,2],
  [4,6,1, 9,2,3, 5,8,7],
  
  [8,7,6, 3,9,4, 2,1,5],
  [2,4,3, 5,6,1, 9,7,8],
  [1,9,5, 2,8,7, 6,3,4]
]);

var goodSudoku2 = new Sudoku([
  [1,4, 2,3],
  [3,2, 4,1],

  [4,1, 3,2],
  [2,3, 1,4]
]);

var badSudoku1 = new Sudoku([
  [1,2,3, 4,5,6, 7,8,9],
  [1,2,3, 4,5,6, 7,8,9],
  [1,2,3, 4,5,6, 7,8,9],
  
  [1,2,3, 4,5,6, 7,8,9],
  [1,2,3, 4,5,6, 7,8,9],
  [1,2,3, 4,5,6, 7,8,9],
  
  [1,2,3, 4,5,6, 7,8,9],
  [1,2,3, 4,5,6, 7,8,9],
  [1,2,3, 4,5,6, 7,8,9]
]);




// console.log(badSudoku2.isValid());
console.log(goodSudoku1.isValid());
console.log(goodSudoku2.isValid());
console.log(badSudoku1.isValid());
