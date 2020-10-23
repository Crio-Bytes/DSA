//Updating the array
function keyValue(key, value){
    this.Key = key;
    this.Value = value;
  };
var array = [];
  array.push(new keyValue("A","11"),new keyValue("B","22"),new keyValue("C","33"));

function Update(keyValue, newKey, newValue)
  {
    keyValue.Key = newKey;
    keyValue.Value = newValue; 
  }


//indexOf()

//This method looks for an item in an array and returns the index where it was found else it returns -1

let color = ['Orange', 'White', 'Blue', 7]
color.indexOf('orange'); // returns 1
color.indexOf(7); // returns 3
color.indexOf(null); // returns -1 (not found)

//lastIndexOf()

//This method works the same way indexOf() does except that it works from right to left. It returns the last index where the item was found

let colour = ['Orange', 'White', 'Blue', 'Gray','Yellow']
colour.lastIndexOf('Yellow'); // returns 4


