import java.util.*;
import java.lang.*;
import java.io.*;

class Solution
{

    private static int[] merge(int[] A, int[] B) {
        int[] ans = new int[A.length + B.length];

        int i = 0, j = 0, k = 0;
        while(i < A.length && j < B.length) {
            if(A[i] <= B[j]){
                //if A[i] is smaller then it should be included first
                ans[k] = A[i];
                i++;
            } else {
                //if B[j] id smaller then it should be included first
                ans[k] = B[j];
                j++;
            }
            k++;
        }

        while(i < A.length) {
            //if any element in array A is left after comparing with array B the it gets merged here.
            ans[k] = A[i];
            i++;
            k++;
        } 

        while(j < B.length) {
            //if any element in array B is left after comparing with array A the it gets merged here.
            ans[k] = B[j];
            j++;
            k++;
        }
        return ans;
    }

    private static int[] mergeSort(int[] arr, int start, int end){
        //base case (if only one element if present then it is a sorted array)
        if(start == end) {
            int[] ans = new int[1];
            ans[0] = arr[start];
            return ans;
        }

        int mid = (start + end) / 2;

        return merge(mergeSort(arr, start, mid) , mergeSort(arr, mid + 1, end));
    }


	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner scn = new Scanner(System.in);
		System.out.println("Enter array size: ");
		int n = scn.nextInt();
		int[] arr = new int[n];
        System.out.println("Enter array elements: ");
        
        //input
		for(int i = 0; i < n; i++) {
		    arr[i] = scn.nextInt();
		}

		arr = mergeSort(arr, 0, n - 1);

		//display
		System.out.println("Array after sorting: ");
		for(int i = 0; i < n; i++) {
		    System.out.print(arr[i] + " ");
		}

	}
}