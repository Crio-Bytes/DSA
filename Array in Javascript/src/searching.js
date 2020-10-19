function searchByIndex(array, index) {
  return array[index];
}


function searchByValue(array, value) {
  for (let index = 0; index < array.length; index++) {
    const element = array[index];
    if (element === value) return index;
  }
  return -1;
}