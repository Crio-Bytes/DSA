const array = [2, 111, 5, 1, 9, 6, 7];
// Deleting from the beginning of the array.
array.shift();  
// array: [111,5, 1, 9, 6, 7]

const array = [0, 1, 2, 3, 4];
// Deleting from the middle
array.splice(2, 1); // delete 1 element at position 2.
// array: [0, 1, 3, 4]

// Deleting from the end
const array = [2, 5, 1, 9, 111];
array.pop(); 
// array: [2, 5, 1, 9]