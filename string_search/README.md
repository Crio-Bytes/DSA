# Table of Contents
* #### Introduction
    * Overview
    * Rabin Karp string matching algorithm
    * KMP string matching algorithm
* #### Activity 1
    * Best case complexity comparision
* #### Activity 2
    * Average case complexity comparision
* #### Activity 3
    * Worst case complexity comparision
* #### Activity 4
    * Custom input by user
* #### References
# Introduction
#### Overview
In this micro-byte, we will be going through the working of the two most famous string matching algorithms: Rabin Karp and KMP string matching algorithm. The speciality of both these algorithms is that they achieve linear time complexity for average case, making them far more superior to naive string matching algorithm which completes string matching in quadratic time for all cases.
We start with understanding the working of each algorithm and then compare time taken by both algorithms in best/ average/ worst case scenarios. As an additional acitivity, readers can try out their own scenarios and compare time taken by both algorithms.

#### Rabin Karp algorithm
* Rabin Karp Algorithm utilizes string hashing, more precisely, it genrates rolling string hashes during its preprocessing step.
* The algorithm tries to match the hash value of the pattern to the rolling hash value of text.
* Rabin Karp algorithm can be a victim to spurious hits - matching hash values of dissimilar text.
* We can avoid spurious hits and the character by character comparison in Rabin Karp if we choose proper parameters for the hash generating function.
* An example demonstrating Rabin Karp algorithm to match DNA samples can be found in the Rabin Karp Visualizations link of References.  

![RB GIF](https://d18l82el6cdm1i.cloudfront.net/uploads/uIPjisbiCM-bruteforce.gif)
#### KMP Algorithm
* Unlike other string matching algorithms, each character in the text is checked only once - hence linear average time.
* KMP algorithm builds a Longest Common Suffix table during its preprocessing step.
* The table stores the last known position of the current character in the pattern.
* Examples demonstrating the building of LCS table and real time visualization of KMP algorithm can be found in KMP Table Filling link and KMP Visualization link respectively in references.  

![KMP GIF](https://coderscat.com/wp-content/uploads/kmp-s2.gif)

**NOTE** Since character comparison is a quick task, execution time may vary at each run. To minimize this, we consider the default ```TEXT_LENGTH``` to be ```1000``` and default ```PATTERN_LENGTH``` to be ```100```. Having longer input lengths can help reduce these variance and make comparison of the algorithms easier. Our demonstrations will only be showing the final time taken to execute each algorithm. **For users interested in seeing the actual text and pattern and other data used in during development of this program, set ```DEBUG``` macro to ```1```.**    
# Activity 1
For our first activity, we will be comparing the Rabin Karp algorithm and KMP algorithm in their best case time complexity. For users who are unfamiliar with the asymptotic time complexity notations, we recommend they first go through the asymptotic time complexities link in References below. To summarize, Best case complexity of an algorithm can be defined as least time taken to complete its execution. This is achieved in most optimal conditions.  
**FACTS**
* The Best Case running time of Rabin Karp algorithm is _O(n+m)_ where _n_ is the length of the text and _m_ is length of pattern.
* The Best Case running time of KMP algorithm is _O(n+m)_ where _n_ is the length of the text and _m_ is length of pattern.  

**QUESTION** What do you think is the most optimal condition for a string matching algorithm ?  
To execute our demonstration:
```
gcc strings.c
./a.out
0
```
After entering ```0```, the program generates a pattern demonstrating the best case time complexity. Here's a sample screenshot attached below showing the output.

![](images/Activity1.jpg?raw=true)

# Activity 2
In this activity we will be demonstrating the average case time complexity of Rabin Karp and KMP algorithm. Average Case time complexity gives us an estimate for real/expected execution time. Rabin Karp and KMP algorithm achieve a linear time even in their average case time complexity.  
**FACTS**
* The Average Case running time of Rabin Karp algorithm is _O(n+m)_ where _n_ is the length of the text and _m_ is length of pattern.
* The Average Case running time of KMP algorithm is _O(n+m)_ where _n_ is the length of the text and _m_ is length of pattern.
To execute our demonstration:
```
gcc strings.c
./a.out
1
```
After entering ```1```, the program generates a pattern that occurs somewhere at the middle of the string. For simplicity, we take the pattern occuring in the middle of the string. Here's a sample screenshot attached below showing the output.

![](images/Activity2.jpg?raw=true)
# Activity 3
For our third activity, we will be looking at the worst case time complexity of the Rabin Karp and KMP algorithm. Worst Case time complexity gives the developer an upper bound, or the maximum time a given program will execute. It is the most popular asymptotic notation among the rest as developers will be interested in minimizing the worst case complexity. The goal for any algorithm would be to achieve linear time or lower in Best, Average and Worst case complexity.   
**FACTS**
* Worst Case complexity of Rabin Karp algorithm is _O(n*m)_ where _n_ is the length of the text and _m_ is length of pattern.  
* The Worst Case complexity of KMP algorithm is _O(n+m)_ where _n_ is the length of the text and _m_ is length of pattern.  

**QUESTION** What is the least optimal condition/scenario which generates a worst case time complexity ?  
To execute our demonstration:
```
gcc strings.c
./a.out
2
```
After entering ```2```, the program generates a pattern demonstrating worst case time complexity. Here's a sample screenshot attached below showing the sample output.

![](images/Activity3.jpg?raw=true)
# Activity 4
Finally, in our last activity, we let users enter their own test cases and compare the running time of both algorithms. Feel free to enter any combination of characters.
To execute our demonstration:
```
gcc strings.c
./a.out
3
```
After entering ```3```, the program waits for the user text and pattern input. Here's a sample screenshot attached below showing the sample output.

![](images/Activity4.jpg?raw=true)
# References
* [Rabin Karp Overview](https://en.wikipedia.org/wiki/Rabin%E2%80%93Karp_algorithm)
* [Rabin Karp Algorithm](https://www.programiz.com/dsa/rabin-karp-algorithm)
* [Rabin Karp Visualization](https://www-igm.univ-mlv.fr/~lecroq/string/node5.html)
* [String hashing](https://cp-algorithms.com/string/string-hashing.html)
* [KMP Overview](https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm)
* [KMP Table Filling](https://www.javatpoint.com/daa-knuth-morris-pratt-algorithm)
* [KMP Visualization](https://people.ok.ubc.ca/ylucet/DS/KnuthMorrisPratt.html)
* [Asymptotic complexities](https://www.cs.cornell.edu/courses/cs3110/2012sp/lectures/lec19-asymp/review.html)
