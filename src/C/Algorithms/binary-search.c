#include <stdio.h> 

//Needs a sorted array (ascending/descending). Spilts the array into half. Checks if the number to find is in the left-half, right-half, or the middle.
//Keeps doing this recuresively till it finds the number in the middle-position, or is unable to find a match after a single numner is left.
  

int binarySearch(int arr[], int l, int r, int x) 
{ 
    if (r >= l) { 
        //Finding the middle element
        int mid = l + (r - l) / 2; 
        // If the element is present at the middle, we found the element
        if (arr[mid] == x){
            printf("Element %d is present at index %d\n",x,mid);
            return x;
            }
        // If element is smaller than mid, then we need to look in the left half, so we run the function with a new array
        if (arr[mid] > x){
            return binarySearch(arr, l, mid - 1, x);  
            }
        //The only condition left. 
        // If element is smaller than mid, then we need to look in the right half, so we run the function with a new array
        return binarySearch(arr, mid + 1, r, x); 
    } 
    //After exhausting the array and unable to find the number.
    printf("Element %d is not present in array\n",x);
    return -1; 
} 
  
int main(void) 
{ 
    int arr[] = {1,2,3,4,5,7,8,9,10}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int x = 4; 
    //True 
    binarySearch(arr, 0, n - 1, x); 
    //False
    int y = 6;
    binarySearch(arr, 0, n - 1, y); 
} 
