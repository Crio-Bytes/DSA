import java.util.*;

class bubbleSort{

    private static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    private static void solution(int[] arr, int n) {
        
        //swapping 2 adjacent elements to get the maximum element

        for(int i = 0; i < n; i++) {
            for(int j = 1; j < n - i; j++) {
                if(arr[j - 1] > arr[j]) {
                    //if number in left is smaller than the number in right, swap them.
                    swap(arr, j - 1, j);
                }
            }
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