# INTRODUCTION 
Arrays are one of the most used data structures. You probably have used it a lot, but are you aware of the runtimes many array operations? In this microbyte, we are going deeper into the most common operations and their runtimes.

# PREREQUISITES:
* A machine with any JS compiler installed. Or any online compiler will work too
* Knowledge of Javascript syntex.
* Loads of enthusiasm!

## Array Basics
An array is a collection of things (strings, characters, numbers, objects, etc.).

### Fixed vs. Dynamic Size Arrays
Some programming languages have fixed-size arrays like Java and C++. Fixed-size arrays might be a hassle when your collection gets full, and you have to create a new one with a bigger size. Those programming languages also have built-in dynamic arrays: we have vector in C++ and ArrayList in Java. Dynamic programming languages like JavaScript, Ruby, and Python use dynamic arrays by default.

Arrays look like this

![this](img/array.png)

Figure 1. Array representation: each value is accessed through an index. index starts from 0

#### What are the diffrent operations on an array ?
* **Insertion**

* **Deletion**

* **Searching**


# ACTIVITIES:

### ACTIVITY 1:
## Insertion
Arrays are built-in in most languages. Inserting an element is simple; you can either add them at creation time or after initialization. Below you can find an example for both cases:

```
Inserting elements into an array
// (1) Add elements at the creation time:
const array = [2, 5, 1, 9, 6, 7];

// (2) initialize an empty array and add values later
const array2 = [];
array2[3] = 1;
array2[100] = 2;
```
The runtime for inserting elements using an index is always is constant: O(1).

### Insertion can be done in 3 ways

### Inserting at the beginning of the array

```
const array = [2, 5, 1, 9, 6, 7];
array.unshift(0); // 
// array: [0, 2, 5, 1, 9, 6, 7]
```
As you can see, 2 was at index 0, now was pushed to index 1, and everything else is on a different index. unshift takes O(n) since it affects all the elements in the array.

### Inserting at the middle of the array

```
const array = [2, 5, 1, 9, 6, 7];
array.splice(1, 0, 111); 
// array: [2, 111, 5, 1, 9, 6, 7]
```
At position 1, delete 0 elements and insert 111.
The Big O for this operation would be O(n) since, in the worst case, it would move most of the elements to the right.

### Inserting at the end of the array

```
const array = [2, 5, 1, 9, 6, 7];
array.push(4); 
// array: [2, 5, 1, 9, 6, 7, 4]
```
The 4 element would be pushed to the end of the array. Notice that push returns the new length of the array. Adding to the tail of the array doesn’t change other indexes. E.g., element 2 is still at index 0. So, this is a constant time operation O(1).
Full code can be found at [here](src/insertion.js)
### Micro-Challenge
Can you find A way to clone an array. Create a PR and add it here as Micro-Challenge Solution
Solution:
An array can be cloned by returning the element in our map call like this-

```
let arr1 = [2, 3, 6, 1];
let arr2 = arr1.map((x) => x);
// arr2: [2, 3, 6, 1];
```
(x) => x is called identity. It returns whatever parameter it's been given.
### ACTIVITY 2:
## Deletion
There are three possible deletion scenarios (similar to insertion): removing at the beginning, middle, or end.

### Deleting from the beginning of the array.

```
const array = [2, 111, 5, 1, 9, 6, 7];
// Deleting from the beginning of the array.
array.shift();  
// array: [111,5, 1, 9, 6, 7]
```
As expected, this will change every index, so this takes O(n).
### Deleting element from the middle
```
const array = [0, 1, 2, 3, 4];
// Deleting from the middle
array.splice(2, 1); // delete 1 element at position 2.
// array: [0, 1, 3, 4]
```
Deleting from the middle might cause most of the array elements to move up one position to fill in for the eliminated item. Thus, runtime: O(n).
### Deleting element from the end
```
const array = [2, 5, 1, 9, 111];
array.pop(); 
// array: [2, 5, 1, 9]
```
No other element has been shifted, so it’s an O(1) runtime.
Full code can be found at [here](src/deletion.js)
### Micro-Challenge
How to remove multiple elements from array in JavaScript ? Give it a try create a PR and add it here as Micro-Challenge Solution
Solution:
If we want to remove consecutive elements from an array(from a particular index) then we can use the "splice" method.
```
const arr = [1, 2, 3, 4, 5, 6, 7];
// we want to remove 3 elements starting from index 2
arr.splice(2, 3);
// arr: [1, 2, 6, 7]
```
If we want to remove multiple elements from an array which aren't necessarily consecutive then we can follow the method given below:
```
const arr = [1, 2, 3, 4, 5, 6, 7];
// we want to remove 3 elements: elements at indices 1, 3 and 4
const removeElementAtIndex = [1, 3, 4];
for (let i = removeElementAtIndex.length - 1; i >= 0; i--) {
    arr.splice(removeElementAtIndex[i], 1);
}
// arr: [1, 3, 6, 7]
// We are traversing the "removeElementAtIndex" array in reverse order so that the indices of the elements yet to be removed are not messed up
```
### ACTIVITY 3:
## Searching 
There are two possible searching.
* Searching by index
* Searching by value 


```
function searchByIndex(array, index) {
  return array[index];
}
```
Searching by index takes constant time - O(1) - to retrieve values out of the array.

```
function searchByValue(array, value) {
  for (let index = 0; index < array.length; index++) {
    const element = array[index];
    if (element === value) return index;
  }
  return -1;
}
```

We would have to loop through the whole array (worst case) or until we find it: O(n).
Full code can be found at [here](src/searching.js)
### Micro-Challenge
Can you find more efficient solution ? Create a PR and add it here as Micro-Challenge solution

# Summary
We just learned most common operations of array and their runtimes. Amazing right? now we can go ahead, do further excercise.
Congo on completing this MicroByte!  Don't forget to add your solutions.

# References

- [MDN Web Docs: Array](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array)
- [MDN Web Docs: Splice](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/splice)
- [MDN Web Docs: Unshift](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/unshift)
- [MDN Web Docs: Shift](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/shift)
- https://stackoverflow.com/questions/9425009/remove-multiple-elements-from-array-in-javascript-jquery
