# N-Queens-solver-program-assignment-2

## NOTICE
本次作業**未按照**要求的五項演算法實作，原因如下:
* 我把 GOAL 當作是只要放滿 N Queens 即完成，所以邊放的時候邊檢查是否 Queen 互相攻擊，搜尋深度至多到 N 而已。  

* 如果用 Graph Search 解 N-Queens 的問題我認為會把問題複雜化，畢竟此問題是要放滿 N Queens 並且不會相互衝突，不是要找最短路徑解。  

* 運用 C++ 高速的性能加上 Hash Table 作為 Queen 的暫存，整題提升遍歷的速度，加上編譯器的優化功能，**用最短的時間找出答案**。

故採用 **Backtracking (回溯法)** 作為解法，近似 DFS；這方向無解就換另一個方向尋找的思維。

## Input
```
Usage: [ARGS]
  -random ${n}          n = >4 number
  -init_state ${state}  $state example: '0,0,0,0,0,0,3,0'
``` 

### EXAMPLE
* If you want the 32 of queens puzzle with randomize initial
```
{$EXECUTABLE} -random 32
```

* Customize initial board

##### '0' is no queen in this column
```
{$EXECUTABLE} -init_state 0,0,0,3,0,0,0,0
```

## Output
 
```
========== INITIAL STATE ==========
 | | | | | | | |
 | | | | | | | |
 | | | | | | | |
 | | | | | |Q| |
 | | | | | | | |
 | | | | | | | |
 | | | | | | | |
 | | | | | | | |

===================================
============ GOAL STATE ===========
 |Q| | | | | | |
 | | | | |Q| | |
Q| | | | | | | |
 | | | | | |Q| |
 | | |Q| | | | |
 | | | | | | |Q|
 | |Q| | | | | |
 | | | |Q| | | |

===================================
```

## Requirement
* (a) Iterative-Deepening Search (IDS)
* (b) Uniform-Cost Search
* (c) Greedy Best-First Search
* (d) A* search
* (e) Recursive Best-First Search (RBFS)

## Output for each algorithm
* (a) The number of movements (state changes) from the initial state to the goal state.
* (b) The maximum number of states ever saved in the memory during the process

## Build C++ Program

#### Cygwin & Linux:
```
g++ -O3 main.cpp -o main
./main
```

#### MacOS:
```
clang++ -O3 main.cpp -o main
./main
```

## Performance
* 8 Queens: less 0.002 seconds
* 15 Queens: less 0.003 seconds
* 24 Queens: less 4 seconds
* 30 Queens: less 15 seconds
