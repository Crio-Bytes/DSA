// (1) Add elements at the creation time:
const array = [2, 5, 1, 9, 6, 7];

// (2) initialize an empty array and add values later
const array2 = [];
array2[3] = 1;
array2[100] = 2;

// Inserting at the beginning of the array
const array = [2, 5, 1, 9, 6, 7];
array.unshift(0); // 
// array: [0, 2, 5, 1, 9, 6, 7]

// Inserting at the middle of the array
const array = [2, 5, 1, 9, 6, 7];
array.splice(1, 0, 111); 
// array: [2, 111, 5, 1, 9, 6, 7]


// Inserting at the end of the array
const array = [2, 5, 1, 9, 6, 7];
array.push(4); 
// array: [2, 5, 1, 9, 6, 7, 4]

