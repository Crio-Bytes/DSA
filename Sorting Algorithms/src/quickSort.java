import java.util.*;

class quickSort{

    private static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    private static int partition(int[] arr, int start, int end){
        int i = start, j = start;
        int val = arr[end];

        while(j <= end){
            if(arr[j] <= val){
                swap(arr, i, j);
                i++;
            }
            j++;
        }
        return i - 1;
    }

    private static void quicksort(int[] arr, int lo, int hi){
        if(lo >= hi){
            return;
        }

        int a = partition(arr, lo, hi);
        
        quicksort(arr, lo, a - 1);
        quicksort(arr, a + 1, hi);
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

        quicksort(arr, 0, n - 1);

        //display
        System.out.println("Array after sorting: ");
        for(int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }


    }

}