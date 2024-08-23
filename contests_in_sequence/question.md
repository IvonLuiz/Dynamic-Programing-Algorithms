# Contests in Sequence

Denis is a very fair competitive programming teacher. In a discipline, he makes \( N \) programming contests to evaluate his \( M \) students. The last Denis' idea is to reward the three students with the best results in the contests. For this, Denis had the idea to create the following rank function.

\[ f(T_1, T_2, \dots, T_N) = c_1T_1 + c_2T_2 + \dots + c_NT_N \]

In this function, the \( N \)-tuple \( (T_1, T_2, \dots, T_N) \) indicates the rank positions of a single student in the \( N \) contests. For example, if there are two contests, a student gets the third place in the first contest and first place in the second contest, his ordered pair is \( (3, 1) \).

As Denis wants to be as fair as possible, he doesn't want there to be a possibility of a tie. As he is also lazy for trying to prove that his function is free of ties, he asked you to write a program that, given the coefficients \( c_1, c_2, \dots, c_N \), determines whether the function can actually be used for ranking. In other words, if the function won't give equal scores to different students.

Note that the software used by Denis to rank his students in a contest is free of ties. In other words, it's not possible that two students get the first place in a same contest, or the second place, etc.

## Input

The input consists of several test cases and ends with end of file.

- The first line of a test case consists of two integers \( N \) and \( M \) which are respectively the number of contests made by Denis and the number of students that will compete in each contest, where \( 1 \leq N \leq 3 \) and \( 1 \leq M \leq 10 \).
- Following are given \( N \) integers \( c_1, c_2, \dots, c_N \), the coefficients of the Denis' function, where \( c_i \geq 1 \) for all \( i \).

In a test case, it is guaranteed that the values of Denis' function are at most \( 10^9 \).

## Output

For each test case, print the line "Lucky Denis!" if the function can be used by Denis, or "Try again later, Denis..." otherwise.

## Example

### Input
1 1
1
3 10
1 1 1
3 10
1 2 3
3 10
1000001 1000100 1010000

### Output
Lucky Denis!
Try again later, Denis...
Try again later, Denis...
Lucky Denis!
