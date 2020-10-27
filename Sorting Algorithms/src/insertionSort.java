import java.util.*;

class insertionSort{

    private static void solution(int[] arr, int n) {
        
        for (int i = 1; i < n; ++i) { 
            int key = arr[i]; 
            int j = i - 1; 
  
            /* Move elements of arr[0..i-1], that are 
               greater than key, to one position ahead 
               of their current position */
            while (j >= 0 && arr[j] > key) { 
                arr[j + 1] = arr[j]; 
                j = j - 1; 
            } 
            arr[j + 1] = key;
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