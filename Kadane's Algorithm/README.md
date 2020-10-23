# Maximum Sub-Array Sum

Given an array of n numbers, our task is to calculate the maximum subarray sum, i.e., the largest possible sum of a sequence of consecutive values in the
array.<br>
For example, in the array

![Maximum Subarray Sum](https://github.com/G1Joshi/DSA/blob/patch-2/Kadane's%20Algorithm/img/Maximum%20Subarray%20Sum.png)

---

## Algorithm 1

A straightforward way to solve the problem is to go through all possible subarrays, calculate the sum of values in each subarray and maintain the maximum sum.<br>
The following code implements this algorithm:

```C++
int best = 0;

for (int a = 0; a < n; a++) {
    for (int b = a; b < n; b++) {
        int sum = 0;
        for (int k = a; k <= b; k++) {
            sum += array[k];
        }
        best = max(best,sum);
    }
}

cout << best << "\n";
```

The variables a and b fix the first and last index of the subarray, and the sum of values is calculated to the variable sum. The variable best contains the maximum sum found during the search.<br>
The time complexity of the algorithm is O(n³), because it consists of three nested loops that go through the input.

---

## Algorithm 2

It is easy to make Algorithm 1 more efficient by removing one loop from it. This is possible by calculating the sum at the same time when the right end of the subarray moves.<br>
The result is the following code:

```C++
int best = 0;

for (int a = 0; a < n; a++) {
    int sum = 0;
    for (int b = a; b < n; b++) {
        sum += array[b];
        best = max(best,sum);
    }
}

cout << best << "\n";
```

After this change, the time complexity is O(n²).

---

## Algorithm 3
# Kadane's Algorithm

![Kadane Algorithm](https://github.com/G1Joshi/DSA/blob/patch-2/Kadane's%20Algorithm/img/Kadane%20Algorithm.jpeg)

**Kadane's algorithm** scans the given *array* **A[1...n]** from left to right.
In the ith step, it computes the *subarray* with the largest sum ending at i,
this sum is maintained in a variable **current_sum**.<br>
Moreover, it computes the *subarray* with the largest sum anywhere in **A[1...j]** maintained in variable **global_sum**,
and easily obtained as the maximum of all values of **current_sum** seen so far.

Surprisingly, it is possible to solve the problem in O(n) time, which means that just one loop is enough. The idea is to calculate, for each array position, the maximum sum of a subarray that ends at that position. After this, the answer for the problem is the maximum of those sums. Consider the subproblem of finding the maximum-sum subarray that ends at position k.

There are two possibilities:
1. The subarray only contains the element at position k.
2. The subarray consists of a subarray that ends at position k −1, followed by the element at position k.

In the latter case, since we want to find a subarray with maximum sum, the subarray that ends at position k −1 should also have the maximum sum. Thus, we can solve the problem efficiently by calculating the maximum subarray sum for each ending position from left to right.<br>
The following code implements the algorithm:

```C++
int best = 0, sum = 0;

for (int k = 0; k < n; k++) {
    sum = max(array[k],sum+array[k]);
    best = max(best,sum);
}

cout << best << "\n";
```

The algorithm only contains one loop that goes through the input, so the time complexity is O(n). This is also the best possible time complexity, because any algorithm for the problem has to examine all array elements at least once.

---

## Efficiency comparison

It is interesting to study how efficient algorithms are in practice. The following table shows the running times of the above algorithms for different values of n on a modern computer.<br>
In each test, the input was generated randomly. The time needed for reading the input was not measured.

| array size n | Algorithm 1 | Algorithm 2 | Algorithm 3 |
| :---: | :---: | :---:| :---: |
| 10² | 0.0 s | 0.0 s | 0.0 s |
| 10³ | 0.1 s | 0.0 s | 0.0 s |
| 10⁴ | >10.0 s | 0.1 s | 0.0 s |
| 10⁵ | >10.0 s | 5.3 s | 0.0 s |
| 10⁶ | >10.0 s | >10.0 s | 0.0 s |
| 10⁷ | >10.0 s | >10.0 s | 0.0 s |
