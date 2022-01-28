

window.onload = function(){
  

  class RomanNumerals {

    static romanToNum = [
      {roman: "I", decimal : 1},
      {roman: "V", decimal : 5},
      {roman: "X", decimal : 10},
      {roman: "L", decimal : 50},
      {roman: "C", decimal : 100},
      {roman: "D", decimal : 500},
      {roman: "M", decimal : 1000},
    ];


    static toRoman(number){
      if(number == 0) return '';
      for(var i = this.romanToNum.length-1; i >= 0; i--){
        if(this.romanToNum[i].decimal >= number){
          console.log(this.romanToNum[i].decimal);
            return this.romanToNum[i].roman + this.toRoman(number - this.romanToNum[i].decimal);
          }
        // else if(i != -1 && this.romanToNum[i-1].decimal < number){
        //     if(number - this.romanToNum[i-1].decimal < this.romanToNum[i-1].decimal - number){
        //       return this.romanToNum[i-1].roman + this.toRoman(number - this.romanToNum[i].decimal);
        //     } else {
        //       return this.toRoman(number - this.romanToNum[i].decimal) - this.romanToNum[i-1].roman;
        //     }
        //   }
      }
      return -1;
    }

  }

  // file:///Y:/codewars/index.html
  function outRoman(number){
    // console.log(number);
    if(number == 0) return '';
    for(var i = RomanNumerals.romanToNum.length-1; i >= 0; i--){
      if(RomanNumerals.romanToNum[i].decimal == number){
            return RomanNumerals.romanToNum[i].roman + outRoman(number - RomanNumerals.romanToNum[i].decimal);
      }
      else if(i-1 != -1 && RomanNumerals.romanToNum[i-1].decimal < number && RomanNumerals.romanToNum[i].decimal > number){
        if(number - RomanNumerals.romanToNum[i-1].decimal > RomanNumerals.romanToNum[i].decimal - number){
          return outRoman(RomanNumerals.romanToNum[i].decimal - number) + RomanNumerals.romanToNum[i].roman;
        } else {
          return RomanNumerals.romanToNum[i-1].roman + outRoman(number - RomanNumerals.romanToNum[i-1].decimal);
        }
      }
    }
    return 'NA';    
  }

  function outNumber(roman){
    var n = 0;
    for(var i = 0; i < roman.length; i++){
      if(i != 0 && getNumberFromRoman(roman[i-1]) < getNumberFromRoman(roman[i])){
        n = getNumberFromRoman(roman[i]) - n;
      } else {
        n += getNumberFromRoman(roman[i]);
      }
      console.log(n);
    }
    return n;
  }

  function getNumberFromRoman(roman){
    for(var i = 0; i < RomanNumerals.romanToNum.length; i++){
      if(roman === RomanNumerals.romanToNum[i].roman){
        return RomanNumerals.romanToNum[i].decimal;
      }
    }
    return 0;
  }
  

  // for(var i = 0; i < 20; i++){
  //   console.log(outRoman(i));
  // }


  console.log(outNumber("XIV"));  
  

};
