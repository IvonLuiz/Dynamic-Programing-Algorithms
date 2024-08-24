# Motoboy 

Joseph is a delivery person for a pizzeria, and his salary is based on the number of pizzas he delivers. As the pizzeria grows, Joseph has asked his friend Roberto to help with the deliveries. Roberto, who is currently not working, agreed to assist by taking on the most time-consuming orders.

Before each delivery run, Joseph determines how many pizzas Roberto should deliver, ensuring that Roberto handles the orders that will take the most time. The goal is to maximize the time Roberto spends delivering, but without exceeding the maximum number of pizzas Joseph allocates to him.

For example, if there are 22 pizzas to be delivered and Joseph decides Roberto can deliver at most 10 pizzas, these should be the orders that take the most time to deliver. The problem is to determine the total time Roberto will spend on his deliveries.

## Input

The input consists of multiple test cases. Each test case includes:

1. An integer `N` (1 ≤ N ≤ 20) representing the number of orders.
2. An integer `P` (1 ≤ P ≤ 30) representing the maximum number of pizzas Roberto can deliver.
3. The next `N` lines each contain two integers: the time required to deliver the order and the number of pizzas in that order.

The input ends when `N = 0`, which should not be processed.

## Output

For each test case, the output should be a single line containing the total time Roberto will spend delivering the selected orders, followed by the text `"min."`.

### Sample Input

6
10
15 5
23 4
21 2
16 4
19 5
18 2
7
8
10 4
12 4
20 3
22 3
21 2
15 5
38 2
0

### Sample Output
62 min.
81 min.