//Forward traversing
var string = ["Blue", "Red", "White", "Black"];

for(let i = 0; i < string.length; i++) 
{
  console.log(string[i]);
}
//Backwork traversing
for (let i = string.length - 1; i >= 0; i--) 
{
    console.log(string[i]);
}
//Another way for Backwork traversing
const array = [1,2,3,4,5];
for (const number of array.reverse()) {
    console.log(number);
}
