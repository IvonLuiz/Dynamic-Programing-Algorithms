# Crowded Elevator

In a building with N floors there is an elevator with capacity to carry at most C people. The floors are enumerated from 0 to N-1. There is a group of M people wanting to use the elevator, all on floor 0. Each one would like to go to a specific floor. You must decide the order that those people will use the elevator in such a way that the energy used is minimized.

Initially, you decide a group of at most C people to enter the elevator on floor 0. Then you must decide the order in which the floors will be visited. Logically, the floors of all people using the elevator must be visited. The energy cost is only when it moves, it is, each time you go up or down one floor you will spend one unit of energy. The process is repeated until there are no more people on floor 0. At the end the elevator must return to floor 0.

Given the building size, the elevator capacity and the people information, compute the best strategy that minimizes the energy used by the elevator. Output this energy value.

### Input

- The first line contains an integer \( T \) (\( T = 100 \)) indicating the number of test cases.

- For each test case:
  - The first line contains three integers: \( N \) (1 ≤ \( N \) ≤ 10,000), \( C \) (1 ≤ \( C \) ≤ \( M \)), and \( M \) (1 ≤ \( M \) ≤ 1,000 or 1 ≤ \( M \) ≤ 50,000).
  - The next line contains \( M \) integers representing the floors to be visited. Floor numbers are between 1 and \( N - 1 \), inclusive.

### Output

For each test case, output the minimum amount of energy needed.

### Example

#### Input
3
10 1 3
1 2 3
100 2 4
10 10 10 3
100 2 5
100 1 100 1 100

#### Output
12
40
402