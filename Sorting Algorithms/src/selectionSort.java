import java.util.*;

class selectionSort{

    private static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    private static void solution(int[] arr, int n) {
        
        // One by one move boundary of unsorted subarray 
        for (int i = 0; i < n - 1; i++) { 
            // Find the minimum element in unsorted array 
            int min_idx = i; 
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[min_idx]) min_idx = j;
            } 
  
            // Swap the found minimum element with the first 
            // element 
            swap(arr, min_idx, i); 
        } 

    }

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        
        System.out.println("Enter size of array: ");
        int n = scn.nextInt();

        int[] arr = new int[n];
        System.out.println("Enter the array elements: ");
        
        //input
        for(int i = 0; i < n; i++) {
            arr[i] = scn.nextInt();
        }

        solution(arr, n);

        //display
        System.out.println("Array after sorting: ");
        for(int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }


    }

}