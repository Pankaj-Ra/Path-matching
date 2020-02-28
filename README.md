# Path-matching

Consider an undirected, connected graph with nodes and edges. Each node is numbered from to . You are given a string of length such that the first node of the graph is assigned the first character of string

, the second node is assigned the second character, and so on.

You are also given a pattern
along with queries. A query is described by an ordered pair of nodes . For each query, consider the new string formed by the letters on the nodes on the simple path from to . To answer a query, you must find the number of occurrences of as a substring of

.

The graph below illustrates a small example with 4 nodes and string
. If we take , the string formed by the simple path between and is

image

Input Format

The first line contains two space-separated integers describing the respective values of
and .
The second line contains a single string, denoting .
The third line contains a single string, denoting .
Each of the subsequent lines contains two space-separated integers, and , describing an edge between nodes and .
Each of the subsequent lines contains two space-separated integers, and

, describing a query.

Constraints

String consists of
lowercase English letters.
String
is nonempty and consists of at most

    lowercase English letters.
    Time limit is 2x for this problem.

Output Format

For each query, print on a new line a single integer denoting how many times the pattern occurs as a substring on the path from
to

.

Sample Input 0

5 5
abbaa
ab
1 2
2 4
2 5
1 3
4 5
5 4
4 3
3 4
2 4

Sample Output 0

1
1
2
1
0

Explanation 0

The image below depicts the graph for the sample test case, as well as the string formed by each query.

image

Submissions: 871

Max Score:

90

Difficulty:

Expert

Rate This Challenge:
More
