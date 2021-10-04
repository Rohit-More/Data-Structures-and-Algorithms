### Problem Statement:

White Falcon just solved the data structure problem below using heavy-light decomposition. Can you help her find a new solution that doesn't require implementing any fancy techniques?

There are 2 types of query operations that can be performed on a tree:

1 u x: Assign x as the value of node u.
2 u v: Print the sum of the node values in the unique path from node u to node v.

Given a tree with N nodes where each node's value is initially 0, execute Q queries.

Input Format:

The first line contains 2 space-separated integers, N and Q, respectively.
The N-1 subsequent lines each contain 2 space-separated integers describing an undirected edge in the tree.
Each of the Q subsequent lines contains a query you must execute.
