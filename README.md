# dlsh
DLSH (Dave's Linear Search Hullaballoo) contest - Spring 2023

It is well-known that the fastest sorting algorithms have time complexity O(*n log n*). This contest seeks a O(*n*) algorithm that does a "pretty good job" of sorting (in non-decreasing order). We will measure "pretty good job" by counting the number of "inversions" in the pretty good sorted list. An inversion is a pair of entries in the list that are not correctly sorted. For example, if the input data is 3 4 2 2 1 4 and your algorithm outputs 2 1 3 2 4 4 then your inversion score would be 2 (because 2 is larger than 1 and 3 is larger than 2). The second criterion on which your algorithm will be judged is running time; the winner of the contest will be an algorithm with a low inversion score and a low running time. 

I have written starter code that is shared in this repository, so that you can easily jump right into the fray. I can explain what makes an algorithm run in O(*n*) time for those who have yet to study that subject; it's not hard to understand. See the Discord server at https://discord.gg/3gC4VNKHZx for questions and answers on this and all other topics.

I wrote a quick answer to my own contest that works like this: find the minimum and maximum entries in the given sequence, average those, and then iterate through the sequence, pushing those entries that are lower than that average into one vector, and those higher than that average into another vector; finally, concatenate those two vectors. When I run my algorithm on a random list of 100 integers, the number of inversions dropped from 2664 to 1250, and it took 23 milliseconds. 

This code is in `main.cpp` and you can run it as follows:

```
g++ -std=c++17 -o main main.cpp

./main input01
```

The file input01 can be named anything you want, but it must be a .txt file that is inside a folder called inputs and the contents must look something like this:

```
3
5
11
8
5
```

I haven't found any evidence that an algorithm like this has been considered by the CS community; if that holds up, then perhaps the outcome of this contest could lead to a conference talk or a publication.
