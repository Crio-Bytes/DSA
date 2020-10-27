import java.util.*;
public class merge{

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

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
		System.out.println("Enter first array size: ");
		int n = scn.nextInt();
		int[] A = new int[n];
        System.out.println("Enter first array elements: ");
        
        //input
		for(int i = 0; i < n; i++) {
		    A[i] = scn.nextInt();
        }
        
        System.out.println("Enter second array size: ");
		int m = scn.nextInt();
		int[] B = new int[m];
        System.out.println("Enter second array elements: ");
        
        //input
		for(int i = 0; i < m; i++) {
		    B[i] = scn.nextInt();
        }

		int[] arr = merge(A, B);

		//display
		System.out.println("Array after merging: ");
		for(int i = 0; i < n; i++) {
		    System.out.print(arr[i] + " ");
		}
    }



}