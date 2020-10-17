# Kadane's Algorithm

**Kadane's algorithm** scans the given *array* **A[1...n]** from left to right. <br>
In the ith step, it computes the *subarray* with the largest sum ending at i,
this sum is maintained in a variable **current_sum**. <br>
Moreover, it computes the *subarray* with the largest sum anywhere in **A[1...j]** maintained in variable **global_sum**,
and easily obtained as the maximum of all values of **current_sum** seen so far.
