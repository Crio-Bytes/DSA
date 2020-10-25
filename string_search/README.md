## Table of Contents
* ##### Introduction
    * Overview
    * Rabin Karp string matching algorithm
    * KMP string matching algorithm
* ##### Activity 1 
    * Best case complexity comparision
* ##### Activity 2
    * Average case complexity comparision
* ##### Activity 3
    * Worst case complexity comparision
* ##### Activity 4
    * Custom input by user
* ##### References
## Introduction
#### Overview
In this micro-byte, we will be going through the working of the two most famous string matching algorithms: Rabin Karp and KMP string matching algorithm. The speciality of both these algorithms is that they achieve linear time complexity for average case, making them far more superior to naive string matching algorithm which completes string matching in quadratic time for all cases.
We start with understanding the working of each algorithm and then compare time taken by both algorithms in best/ average/ worst case scenarios. As an additional acitivity, readers can try out their own scenarios and compare time taken by both algorithms.
#### Rabin Karp algorithm
The Rabin Karp algorithm, named after Michael O. Rabin and Richard M. Karp, is unlike other string matching algorithms which makes use of string hashing, a technique which maps a unique number to that string. Hashing has many forms, Rabin Karp algorithm utilizes what is known as a Rolling-Hash function.
In order to achieve string matching in linear time on an average, Rabin Karp utilizes a preprocessing step which hashes the given text and pattern. Once the hashes are generated, we only compare the hash value of the pattern to the hash value of text of the same length. Only in the case of the hash values matching will we proceed with character by character comparision. If the hash values do not match, we generate the next rolling hash for the text. There can be cases where hash values of unlike strings match, we call this spurious hits. We can avoid spurious hits and the character by character comparision all together if we choose proper parameters for the hash generating function. An example for matching DNA samples using Rabin Karp Algorithm can be found in the Rabin Karp Visualizations link of [References](#References) below.
#### KMP Algorithm
The KMP algorithm, named after Donald Knuth, James H. Morris and Vaughan Pratt, is an algorithm that does not go through each character of the text string more than once, allowing the algorithm run in linear time on an average case. This is achieved by an preprocessing step where a table of size of the pattern is built. Each element of the table, ```table[i]``` points to the last known index of the character ```pattern[i]``` where ```i``` is the index of the character in question. In case the character had never occured before as in the case of first character of any given pattern, the value is set to zero. An example demonstrating how the table is filled can be found in KMP Table Filling link of [References](#References) below. 
Once the table is ready, the algorithm proceeds to simply character match the text and pattern, in case theres a mismatch, the pattern index sets of the value given by the table and proceeds. A visualization of the KMP algorithm in action can be found in the KMP Visualization link of [References](##References) below. 
**NOTE** Since pattern matching of strings is a simple task, execution time may vary at each run. To minimize this, we consider the default ```text_length``` to be 1000 and default ```pattern_length``` to be 100. Having longer input lengths can help reduce these variance and make comparison of the algorithms easier. Our demonstrations will only be showing the final time taken to execute each algorithm. For users interested in seeing the actual text and pattern and other data used in during development of this program, set ```DEBUG``` macro to ```1```
## Activity 1
For our first activity, we will be comparing the Rabin Karp algorithm and KMP algorithm in their best case time complexity. For users who are unfamiliar with the asymptotic time complexity notations, we recommend they first go through the asymptotic time complexities link in [References](#References) below. To summarize, Best case complexity of an algorithm can be defined as least time taken to complete its execution. This is achieved in most optimal conditions, which in our case is, the pattern occurs at the beginning of the text. Best Case time complexity is not generally used in the real world as it relies on the state of the data, or in our case, is the pattern present at the beginning of the text string? If yes, Best case is achieved, if not, Best Case time complexity gives us a lower bound - minimum time taken to execute a program.
To execute our demonstration:
```
gcc strings.c
./a.out
0
```
After entering ```0```, the program generates a pattern that occurs at the beginning of the string. Here's a sample screenshot attached below showing the output.

[](resources/Activity1.jpg)
## Activity 2
In this activity we will be demonstrating the average case time complexity of Rabin Karp and KMP algorithm. Average Case time complexity gives us an estimate for real/expected execution time. Rabin Karp and KMP algorithm achieve a linear time even in their average case time complexity.
To execute our demonstration:
```
gcc strings.c
./a.out
1
```
After entering ```1```, the program generates a pattern that occurs somewhere at the middle of the string. For simplicity, we take the pattern occuring in the middle of the string. Here's a sample screenshot attached below showing the output.

![](resources/Activity2.jpg?raw=true)
## Activity 3
For our third activity, we will be looking at the worst case time complexity of the Rabin Karp and KMP algorithm. Worst Case time complexity gives the developer an upper bound, or the maximum time a given program will execute. It is the most popular asymptotic notation among the rest as developers will be interested in minimizing the worst case complexity. Both Rabin Karp and KMP algorithms achieve a quadratic time in their worst case complexity. The goal for any algorithm would be to achieve linear time or lower in Best, Average and Worst case complexity.
To execute our demonstration:
```
gcc strings.c
./a.out
2
```
After entering ```2```, the program generates a pattern that occurs somewhere at the end of the string. Here's a sample screenshot attached below showing the sample output.

![](resources/Activity3.jpg?raw=true)
## Activity 4
Finally, in our last activity, we let users enter their own test cases and compare the running time of both algorithms. Feel free to enter any combination of characters.
To execute our demonstration:
```
gcc strings.c
./a.out
3
```
After entering ```3```, the program waits for the user text and pattern input. Here's a sample screenshot attached below showing the sample output.

![](resources/Activity4.jpg?raw=true)
## References
* [Rabin Karp Overview](https://en.wikipedia.org/wiki/Rabin%E2%80%93Karp_algorithm)
* [Rabin Karp Algorithm](https://www.programiz.com/dsa/rabin-karp-algorithm)
* [Rabin Karp Visualization](https://www-igm.univ-mlv.fr/~lecroq/string/node5.html)
* [String hashing](https://cp-algorithms.com/string/string-hashing.html)
* [KMP Overview](https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm)
* [KMP Table Filling](https://www.javatpoint.com/daa-knuth-morris-pratt-algorithm)
* [KMP Visualization](https://people.ok.ubc.ca/ylucet/DS/KnuthMorrisPratt.html)
* [Asymptotic complexities](https://www.cs.cornell.edu/courses/cs3110/2012sp/lectures/lec19-asymp/review.html)
