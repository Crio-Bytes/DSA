# Introduction
0-1 Knapsack is a classic Dynamic Programming problem. If haven't yet studied DP do give this a read: [Dynamic Programming](https://www.geeksforgeeks.org/dynamic-programming/) 
In this Mirco-Byte we will focus on how this concept can be extended to solve other DP problems having similar patterns.

## Prerequisites 
Basic programming, arrays, recursion, basic knowledge of algorithms including time and space complexity

**Problem Statement:** 
Given weights and values of `n` items, put these items in a knapsack of capacity `w` to get the maximum total value in the knapsack. Note that we are allowed to have only one quantity of each item.

**Explanation:** 
Given two integer arrays `val` and `wt` which represent values and weights associated with `n` items respectively. Also given an integer `w` which represents knapsack capacity, find out the maximum subset sum of `val` such that sum of the weights of this subset is smaller than or equal to `w`. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).

For example - 

![alt text](https://www.geeksforgeeks.org/wp-content/uploads/knapsack-problem-660x285.png)

**Solution:**
Generally there are two approaches to solving a DP problem: top-down and bottom-up. For this problem the top-down approach would be via recursion followed by memoization to optimize it. To read more about both the approaches refer this link: [Top Down and Bottom Up approaches](https://www.geeksforgeeks.org/tabulation-vs-memoization/)

**Todo:** Find out the pros and cons of both the approaches. 

**Top-Down Method**

Approach: Consider all subsets of items and calculate the total weight and value of all subsets. Consider the only subsets whose total weight is smaller than W. From all such subsets, pick the maximum value subset. To consider all subsets of items, there can be two cases for every item.

Case 1: The item is included in the optimal subset.

Case 2: The item is not included in the optimal set.

Therefore, the maximum value that can be obtained from ‘n’ items is the max of the following two values: 1. Maximum value obtained by n-1 items and w weight (excluding nth item). 2. Value of nth item plus maximum value obtained by n-1 items and w minus the weight of the nth item (including nth item).

Let’s visualize for for the following data:
```
val  wt
6    15 
6    5 
5    6 
6    4 
6    6 
3    5 
7    2 

w = 15
```

![alt text](https://qphs.fs.quoracdn.net/main-qimg-a0276875d1a3e898d54a3927a82b1ccb)

Try it youself and if you get stuck you can check the code given below

<details>
<summary>CLICK TO SEE SOLUTION</summary>

```
int knapsack(wt[], int val[], int w, int n) {
  // base case
  if(n == 0 || w == 0) {
      return 0;
  }
  
  // If weight of the nth item is more 
  // than Knapsack capacity w, then reject the item
  if(wt[n-1] > w) {
      return knapsack(wt, val, w, n-1);
  }
  
  //now there are 2 options: include the item or reject and move towards the next item
  // the max of the two should be taken
  return max(val[n-1] + knapsack(wt, val, w - wt[n-1], n-1), knapsack(wt, val, w, n-1));
}
```

</details>

**Todo:** Calculate the time and space complexity for the above the method.(Hint: Try drawing the recursion tree. We are actually checking all possible subsequences of the array. Now what do you think should the time complexity be?)

### Micro-Challenge:
Write down the memoized version of the above program.

**Bottom-Up Method**

Like other typical Dynamic Programming(DP) problems, recomputations of same subproblems can be avoided by constructing a temporary array in bottom-up manner.

Approach: Take a 2D array of dimension n+1 by w+1(Why include 'n' and 'w'? Hint: Observe values of which parameters get modified in each function call in the Top-Down approach).
 The rows correspond to the items (elements from 0th index to (n-1)th index in the original array and also includes the possibility of zero items) and the columns correspond to the value of w (from 0 to w). Now why 0 to w? Try to figure out how to build the solution from its subproblems. So in this approach you are asked to figure what would have been the answer if value of 'w' was 0 and then 1 and so on. The key is to understand how we are storing the solutions to subproblems in the cells of the matrix so that we can compute the solution to the entire problem. In this case each cell in the matrix, say (x,y), gives us the maximum subset sum of `val` if `val` consisted of the first x elements of the original array and the total maximum weight allowed was y.
 
Try it youself and if you get stuck you can check the code given below

<details>
<summary>CLICK TO SEE SOLUTION</summary>
 
 ```
 int knapsack(int wt[], int val[], int w, int n) {
    int dp[n+1][w+1];
    
    for(int i = 0;i <= n;i++) {
      for(int j = 0; j <= w;j++) {
        // in case there are zero elements or maximum allowed weight is zero
        if(i == 0 || j == 0) {
            dp[i][j] = 0;
        }
        // including the (i-1)th element
        else if(wt[i-1] <= j) {
            dp[i][j] = max(val[i-1] + dp[i-1][j - wt[i-1]], dp[i-1][j]);
        }
        // rejecting the (i-1)th element
        else {
            dp[i][j] = dp[i-1][j];
        }
      }
    }
    return dp[n][w];
}
 ```
 
 </details>
 
 If want to visualize the bottom-up approach you can follow this link: [Knapsack Problem Visualization](https://algorithm-visualizer.org/dynamic-programming/knapsack-problem)
 
 **Todo:** Calculate the time and space complexity for the above the method. (Hint: We are traversing a 2D array of dimensions already mentioned before. Now what do you think should be the time complexity? Have we used any extra space?)
 
 Now we will see how the above given concepts can be utilised to solve other DP problems having similar patterns.(Note that we won't discuss the top down approach)
 
 # Activity 1: Subset Sum Problem
 
 Problem: Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. For example
 
 1. input: arr[] = {2, 3, 7, 8, 10}, 
             sum = 11, 
      output: true     
 2. input: arr[] = {3, 34, 4, 12, 5, 2}, 
           sum = 30, 
    output: false
    
Now how is this problem similar to the 0-1 knapsack problem? Note that in knapsack problem the cumulative weight had to be less than a given weight. Here we have to find out whether any subset sums up to a given sum. Also here we have two options while traversing the array: include the element or reject it. 

By now it is clear that in the bottom-up approach we need to use a similar 2D array. Now how do we actually solve the problem? Consider the following points: 

- What would happen if 'sum' is zero?
- What would happen if 'sum' is greater than zero and the input array is empty?
- What happens when the current element is greater than the 'sum' of the subproblem?
- The output is a bool variable

Keeping the following points in mind, can you come up with the solution for this problem?

### Micro-Challenge: 
Write the solution for the above problem in your preferred programming language(bottom-up approach). Also find out its time and space complexity.

# Activity 2: Equal Sum Partition Problem

Problem: Determine whether a given set can be partitioned into two subsets such that the sum of elements in both subsets is the same. For example-

1. input: arr[] = {1, 5, 11, 5}, 
   output: true, 
2. input: arr[] = {1, 5, 3}, 
   output: false
   
A very important point with regard to this problem is: "equal partition". What does this indicate? It means that if the array is to be partitioned into 2 subsets of equal sum then the sum of all elements of array must be even. Consider the first example- 

The sum of all elements of the array is = 1 + 5 + 11 + 5 = 22 which is even. That means we have to find out whether there exists a subset sum in the array whose value is 22/2 = 11. Beacuse if there actually exists such a subset then the sum of the rest of the elements will also be 11 and thus we can say that the array can be partitioned into two equal sum subsets. 

Now, if you have already understood the concepts taught in the previous sections and take into consideration certain additional factors introduced in this section, this problem would be a cakewalk.

### Micro-Challenge: 
Write the solution for the above problem in your preferred programming language(bottom-up approach). Also find out its time and space complexity.

# Activity 3: Count of subsets with a given sum

Problem: Given an array arr[] of length n and an integer x, the task is to find the number of subsets with sum equal to x. For example- 

1. input: arr[] = {1, 2, 3, 3}, sum = 6, 
   output: 3
   
   subsets - {1, 2, 3}, {1, 2, 3}, {3, 3}

Note that if you are able to solve the subset sum problem, you should ideally be able to solve this one too. The only difference is that here you have to find out the total number of subsets each of whose sum equal to x, instead of just finding whether such a sum exists or not.

### Micro-Challenge: 
Write the solution for the above problem in your preferred programming language(bottom-up approach). Also find out its time and space complexity.

# Activity 4: Minimum subset sum difference

Problem: Given a set of integers, the task is to divide it into two sets s1 and s2 such that the absolute difference between their sums is minimum. For example- 

1. input: arr[] = {1, 6, 11, 5}, 
   output: 1
   
   [ s1 = {1, 5, 6} => sum = 12, s2 = {11} => sum = 11 so diff = 1] 

This is a slightly complex one. But don't get intimidated. What I want you to realise is that you need to find out the possible subset sums (here there is no given "sum" - think about what should be taken as the value of "sum"; hint- it's hidden in this explanation itself). You don't really need to think about subset sum pairs as long as the subset sum 
is less than or equal to the sum of all elements in the array as the sum of the remaining elements would form other the other half of the pair (partitioning the total sum into a pair of subset sums). After this all you need to do is find the pair which has minimum difference of sums (if you unable to comprehend refer the example given above). 

Now that you got the idea of how to approach the problem what's stopping you from giving it a try.

### Micro-Challenge: 
Write the solution for the above problem in your preferred programming language(bottom-up approach). Also find out its time and space complexity.

### Bonus Challenges: 
1. [Target Sum](https://leetcode.com/problems/target-sum/)
2. [Equal Average Partition](https://www.geeksforgeeks.org/partition-an-array-of-non-negative-integers-into-two-subsets-such-that-average-of-both-the-subsets-is-equal/)
3. [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

Now that you have got a hang of how to solve problems related to the 0-1 Knapsack problem, try finding other problems having similar patterns and start solving because as far as 
dynamic programming is concerned, finding patterns and identifying how to build a solution from subproblems is the key.

### References:
- [GFG - Dynamic Programming](https://www.geeksforgeeks.org/dynamic-programming/)
- [GFG - 0-1 Knapsack](https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/)
- [Aditya Verma - Youtube Channel - DP Playlist](https://www.youtube.com/watch?v=nqowUJzG-iM&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go)
- [Knapsack Problem Visualization](https://algorithm-visualizer.org/dynamic-programming/knapsack-problem)
