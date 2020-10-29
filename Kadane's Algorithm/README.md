# Maximum Sub-Array Sum

## Introduction
The maximum sum subarray problem is the task of finding a contiguous subarray with the largest sum, within a given one-dimensional array A[1...n] of numbers.

## History
The maximum subarray problem was proposed by Ulf Grenander in 1977 as a simplified model for maximum likelihood estimation of patterns in digitized images.

## Problem Statement
Given an array of n numbers, our task is to calculate the maximum subarray sum, i.e., the largest possible sum of a sequence of consecutive values in the
array.<br>
For example, in the array

![Maximum Subarray Sum](https://github.com/G1Joshi/DSA/blob/patch-2/Kadane's%20Algorithm/img/Maximum%20Subarray%20Sum.png)

### Some properties of this problem are:

1. If the array contains all non-negative numbers, then the problem is trivial; a maximum subarray is the entire array.
2. If the array contains all non-positive numbers, then a solution is any subarray of size 1 containing the maximal value of the array (or the empty subarray, if it is permitted).
3. Several different sub-arrays may have the same maximum sum.

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

The most optimal solution for obtaining the maximum sub-array is **Kadane’s algorithm**; it uses two variables:
1. _current_maximum_ to keep track of whether or not the value at the current index would increase the maximum sum.
2. _global_maximum_ to keep track of the overall maximum that is propagated along the array.

## Kadane's Algorithm

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

### Algorithm
- Set both of the above-mentioned variables to the value at the first index, i.e., arr[0].
- For the next index i, store the maximum of _current_maximum_ and _current_maximum_ + arr[i] in current_maximum itself.
- Store the maximum of _global_maximum_ and current_maximum in _global_maximum_.
- Repeat the above two steps for the remaining indices.
- Return the value of _global_maximum_.

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

---

## Applications

- Genomic sequence analysis employs maximum subarray algorithms to identify important biological segments of protein sequences.
- In computer vision, maximum-subarray algorithms are used on bitmap images to detect the brightest area in an image.

---

### References

- [Largest Sum Contiguous Subarray](https://www.google.com/amp/s/www.geeksforgeeks.org/largest-sum-contiguous-subarray/amp)<br>
- [Maximum subarray problem](https://en.m.wikipedia.org/wiki/Maximum_subarray_problem)
- [Kadane's Algorithm](https://codeforces.com/blog/entry/13713?mobile=false)
- [The maximum sub-array sum problem](https://www.educative.io/edpresso/the-maximum-sub-array-sum-problem)
