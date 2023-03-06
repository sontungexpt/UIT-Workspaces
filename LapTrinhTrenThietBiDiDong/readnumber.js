// write a script to read the number
// and print the number in words
// for example: 1234 => one thousand two hundred thirty four
// 1000 => one thousand
// 100 => one hundred
// 10 => ten
// 1 => one
// 0 => zero
// 1001 => one thousand one
// 1010 => one thousand ten
let number = 123.34;

let numtoword = {
  0: "zero",
  1: "one",
  2: "two",
  3: "three",
  4: "four",
  5: "five",
  6: "six",
  7: "seven",
  8: "eight",
  9: "nine",
}

let specialchartoword = {
  ".": "dot",
  "-": "minus",
  ",": "comma",
  " ": "space",
}

function readNumber(number) {
  let numberString = number.toString();
  let numberArray = numberString.split("");
  let numberWord = "";
  for (let i = 0; i < numberArray.length; i++) {
    if (numberArray[i] in specialchartoword) {
      numberWord += specialchartoword[numberArray[i]] + " ";
    } else {
      numberWord += numtoword[numberArray[i]] + " ";
    }
  }
  return numberWord;
}

console.log(readNumber(number))

