# Stack

## Definition of Stack
### LIFO last in first out
1. top : top of stack
2. push : insert data at the top
3. pop : delete data at the top

## ADT
1. create : create stack
2. destroy : delete stack
3. push : insert data
4. pop : delete data
5. get_top : get the data of the top
6. is_empty : check the stack is empty
7. is_full : check the stack is full
8. get_size : get the size of stack(number of elements)

## Stack Application
1. keyboard input
2. Post-Fix Expression
3. decimal to binary(example)
4. make a string reverse
5. matching brace

## DFS
### Depth First Search
일반적으로 재귀호출을 구현하는 방법 -> Stack
즉 Stack으로 DFS문제를 풀 수 있다.(Back Tracking)
1. 어떤 도시에 방문할 때마다 도시에 마킹을 하고 stack에 push한다.
2. 가능한 도시들에 대해 진행하다 더이상 이동할 수 없으면 이동가능한 도시가 나타날때까지 pop한다.
3. 만약 원하는 도시에 도착한다면 경로가 존재하는 것이고 도착하기 전에 stack이 비어진다면 경로가 존재하지 않는 것이다.

깊이우선 탐색의 기본 원리
- 해당 지점에서의 모든 경우의 수를 다 해본다는 것.(marking이 필요)
- 목적지를 찾지 못하거나 더 이상 나아갈 수 없다면 이전 상태로 되돌아간다는 것(Back Tracking)

__따라서 DFS를 구현하기 위해서는 marking과 stack에 준하는 구조가 필요하다.__

```c++
DepthFirstSearch(Origin, Destination) {
    s.create();
    Mark all nodes as unvisited;
    s.push(origin);
    Mark Origin as visited;
    While (!s.is_empty() && Destination != s.get_top) {
        if (All adjacent cities are visited)
            s.pop();
        else {
            Select a new city C;
            s.push(c);
            Mark C as visited;
        }
    }
    if (s.is_emtpy())
        return "No";
    else
        return "Yes";
}
```

## Remove Recursion
1. if tail recursion -> iteration will work
2. else -> use stack
