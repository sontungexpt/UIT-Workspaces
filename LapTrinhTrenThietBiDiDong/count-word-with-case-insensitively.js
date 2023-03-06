let string = "Hello world hello hello earth earth"

function countWord(string) {
  let stringArray = string.split(" ");
  let wordCount = {};
  for (let i = 0; i < stringArray.length; i++) {
    if (stringArray[i].toLowerCase() in wordCount) {
      wordCount[stringArray[i].toLowerCase()] += 1;
    } else {
      wordCount[stringArray[i].toLowerCase()] = 1;
    }
  }
  return wordCount;
}

for (let key in countWord(string)) {
  console.log(key + ": " + countWord(string)[key]);
}
