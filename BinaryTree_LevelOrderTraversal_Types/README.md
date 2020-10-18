# INTRODUCTION
Understand Level Order Traversal in Binary Trees and the different kinds of questions based on this concept.
<br/> 
<br/>

## BACKGROUND
#### WHAT IS A BINARY TREE? 
Unlike arrays and linked lists which are linear data structures, binary tree is a **hierarchical data structure**, that is, data in binary trees are stored in a hierarchical fashion. It is similar to how we draw a family tree or represent the different directories and files in the filesystem.<br/>
A binary tree  serves as a **collection of nodes**. A node is an object that has 3 attributes: 
* the data
* left child and 
* the right child.  

The data in a binary tree is stored in **different levels**.<br/>
Refer to [this](img/levels.png) to get an idea about the different levels in a binary tree.

We could access the data in the binary tree by traversing it.

#### WHAT ARE THE DIFFERENT TRAVERSALS OF A BINARY TREE?
Trees have several ways of traversing them.<br/><br/>
**Depth-First-Search Traversals**:
* Preorder traversal : Traverse the root, then the left subtree and then the right subtree.
* Inorder traversal  : Traverse the left subtree, then the root, and then the right subtree.
* Postorder traversal : Traverse the left subtree,  then the right subtree and then the root.


**Breadth-First-Search Traversal** or **Level-Order traversal**:  
* We visit each node level by level.

> Refer to [this](img/traversals.png) to get an idea about inorder,preorder,postorder and level-order traversal for binary tree.<br/>
> Refer to [this](src/dfs.cpp) for the code for depth first search traversal.

<br/>

# PRIMARY GOALS:
* Understand level order traversal in binary tree.
* Understand the different kind of questions that are based on this concept.
<br/>

# PREREQUISITES:
* A machine with g++ compiler installed.
* Knowledge of how queue and stack data structures work.
* Loads of enthusiasm and a zest for knowledge!


#### NOTE:
>To run the code,use the command: <br/>
  &nbsp;&nbsp;  g++ ProgramName.cpp -o ProgramName <br/>
  &nbsp;&nbsp; ./ProgramName </br>
where ProgramName is the name of the program.


# ACTIVITIES:
### ACTIVITY 1:
Now that we know what accessing nodes level-by-level means, how exactly do we go about coding it?

One of the simplest ways to go about this is by using a queue data structure.
The algorithm for this would be : <br/>

#### ALGORITHM-1:
**levelorder(root)**:
>  1. Create an empty queue 'q'.
>  2. Push the root into the queue.
>  3. While the queue does not become empty : <br/>
     a. Get the element 'temp' at the front of the queue 'q' and print it. <br/>
     b. Check if 'temp' has a left child, if yes, push it into the queue 'q'. <br/>
     c. Check if 'temp' has a right child, if yes,push it into the queue 'q'. <br/>
     d. Dequeue(pop) the element from the queue 'q'.

This is implemented in [level_order.cpp](src/level_order.cpp). 


Can you guess what the time and space complexity would be?

Think ! <br/>
Think !!

Well,you are right !
Time complexity is O(n) as we are visiting each node exactly once and the space complexity is also O(n) where n is the number of nodes.



<hr>

### ACTIVITY 2:
In the previous activity,we saw how we could print the level order traversal of the tree starting from the root going all the way down till the last level.<br/>
So,do you think we can instead start printing from the last level all the way to the first level(root)?<br/>
Well,we can definetely do that as well!<br/>
This is problem is called **'Reverse Level Order Traversal'** and is one of the variations of the normal level order traversal.

For an example of this,refer to [this image](img/reverse_level_order_traversal.png).

One way of implementing this would be by using a stack along with the queue by slightly modifying Algorithm-1. <br/>

#### ALGORTIHM-2
**reverse_Level_Order(root)**:
> 1. Create an empty queue 'q'.
> 2. Create an empty stack 'st'.
> 3. Push the root into the queue.
> 4. While the queue 'q' does not become empty : <br/>
    a. Get the element 'temp' at the front of the queue 'q' and push it into the stack 'st' . <br/>
    b. Check if 'temp' has a left child,if yes,push it into the queue 'q'. <br/>
    c. Check if 'temp' has a right child, if yes,push it into the queue 'q'. <br/>
    d. Dequeue(pop) the element from the queue 'q'. <br/>
> 5. While the stack 'st' does not become empty : <br/>
     a. Print the top of stack 'st'. <br/>
     b. Pop the element from the stack 'st'. <br/>

This algorithm is implemented in [this file](src/reverse_level_order.cpp).<br/>

<hr>

### ACTIVITY 3:
So, in this activity, we will be looking at a famous variation of the basic level-order traversal : <br/>
**Level Order Traversal in Spiral Form** also called **Zig-Zag level-order traversal** <br/>
That is, starting from the root,we print the a level from left-to-right and then the next level from right-to-left and so on till the last level.

Refer to [this picture](img/zigzag.png) to get an idea of it. 

Can you try to write the algorithm for this? 

Don't give up! <br/>
You've got this!! <br/>

If you are done writing your algorithm, Congratulations! <br/>
Even if you were unable to get an idea about this,there is nothing to worry, just don't give up and you will ultimately reach there! <br/>

You can get the algorithm [here](src/zigzag.txt). <br/>
This algorithm is implemented in [this file](src/zigzag.cpp).

**Further exploration:**
* How would you go about implementing this using 2 stacks ?

<hr>

### ACTIVITY 4:
Here,let us look at **'Reverse level order traversal in spiral form'** or **Reverse zig-zag level order traversal** .</br>
Refer to [this image](img/reverse_zigzag.png) to get an idea.
<br/><br/>
Can you try doing it on your own?
<br/><br/>
**Hints**:
* What data structure could we use to reverse elements?
* How do we reverse elements at alternate levels?
* How could you modify Algorithm-2 to achieve this?

<br/>
<br/>

Well,this is again very similar to the prevoius problems,we just need to have a  **boolean variable**  to keep track of alternative levels.<br/>
Here, we use a queue and a stack to solve this problem.

#### ALGORITHM 3:
**reverse_LevelOrderTraversal_Spiral(root)**:
> 1. Create an empty queue 'q'.
> 2. Initialize a boolean variable 'reverse' to true.
> 3. Push the root to the queue.
> 4. While the queue 'q' is not empty: <br/>
    a. Get the current size 'size' of the queue 'q'. <br/>
    b. Initialize a stack 'st'. <br/>
    c. While size != 0:   
    &nbsp;&nbsp;  - Get element 'temp' from front of the queue 'q' and pop it from the queue.<br/>
    &nbsp;&nbsp;  - If temp has a left child,push it to the queue 'q'. <br/> 
    &nbsp;&nbsp;  - If temp has a right child,push it to the queue 'q'. <br/>
    &nbsp;&nbsp;  - If reverse == true, print temp. <br/>
    &nbsp;&nbsp;  - Else,push temp to stack 'st'. <br/>
    &nbsp;&nbsp;  - Decrement 'size' by 1. <br/>
    d. If reverse == false: <br/>
    &nbsp;&nbsp; i. while stack 'st' is not empty: <br/>
    &nbsp;&nbsp;&nbsp;&nbsp; - print top of stack. <br/>
    &nbsp;&nbsp;&nbsp;&nbsp; - pop top of stack. <br/>
   e. 'reverse' = !'reverse'. <br/>

    


Don't get intimidated by this algorithm,its not that hard :)
This algorithm is implemented [here](src/reverse_spiral.cpp).

<hr>

### ACTIVITY 5:
By the time you've reached here, this activity would be child's play for you ;) <br/>
So here ,we want to print **level order traversal line by line**. Can you try doing this?

**Hints**:
* How would you leverage algorithm 1 to achieve this?
* Can you figure out where to place newline?



Code for this is available [here](src/levelOrder_lineByLine.cpp).

<hr>

### Further exploration:
There are loads of problems based on this concept. Some of them are :
1. Printing binary tree in vertical order
2. Connecting nodes at same level
3. Clockwise spiral traversal of binary tree 
4. Finding maximum node at a given level <br/>
and many many more !

<hr>

## REFERENCES:
http://en.wikipedia.org/wiki/Breadth-first_traversal <br/>
https://www.geeksforgeeks.org/level-order-tree-traversal/ <br/>
## SUMMARY:
I believe that you are now relatively comfortable with the idea of Level Order Traversal (BFS) of a binary tree . <br/>
I hope that you would be able to identify problems which could be easily solved by applying this concept. The trick here is to observe the patterns and identify places where you could implement algorithms already seen before.<br/>
Practice is the key for this, so keep practicing ! Happy coding !! :)


