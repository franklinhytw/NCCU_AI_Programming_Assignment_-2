from searchAlgorithms import *
from state import State
from time import time
from random import *

def print_board(board):
    n = len(board)
    for i in range(n):
        for j in range(n):
            if board[i][j] == 1:
                print('Q',end="|")
            else:
                print(' ',end="|")
        print()


if __name__ == '__main__':
    # initial state
    # n = int(input("Enter n\n"))
    # print("Enter your" ,n,"*",n, "puzzle")
    # root = []
    # for i in range(0,n*n):
    #     p = int(input())
    #     root.append(p)

    n = 8
    init_state = [
        [0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0],
        [1, 0, 0, 0, 0, 0, 0, 0]
    ]
    # TEST
    # init_state = [
    #     [1, 0, 0, 0, 0, 0, 0, 0],
    #     [0, 0, 0, 0, 0, 0, 0, 1],
    #     [0, 1, 0, 0, 0, 0, 0, 0],
    #     [0, 0, 0, 0, 1, 0, 0, 0],
    #     [0, 0, 0, 0, 0, 0, 0, 0],
    #     [0, 0, 0, 0, 0, 0, 0, 0],
    #     [0, 0, 0, 1, 0, 0, 0, 0],
    #     [0, 0, 0, 0, 0, 0, 0, 0]
    # ]

    print("Initial State:")
    print_board(init_state)
    print()
    
    # root = State(init_state, None, None, 0, 0)
    # q_list = root.expand(n)
    # for q_state in q_list:
    #     print_board(q_state.state)
    #     print("\n\n", end="")

    # root = []
    
    # root = State(init_state, None, 0, 0)
    

    # random initial state generator
    # while len(root) < 16:
    #     rn = randint(0, 15)
    #     if rn not in root:
    #         root.append(rn)
            
    # print(gen_root)

    # print("Initial state is:")
    # print_puzzle(root)
    # print("Goal state is:")
    #
    # print_puzzle(State.goal)
    
    # print("Please wait..... \n")
    
    # root.expand(n)
    #
    start_time = time()
    IDS_solution = solve(init_state, n)
    IDS_time = time() - start_time
    print('IDS Solution is ', IDS_solution[0])
    print('STEP:', len(IDS_solution[0]))
    print('Number of explored nodes is ', IDS_solution[1])
    print('IDS Time:%.4fms' % (IDS_time*1000), "\n")
    # start_time = time()
    # IDS_solution = IDS(init_state, n)
    # IDS_time = time() - start_time
    # print('IDS Solution is ', IDS_solution[0])
    # print('STEP:', len(IDS_solution[0]))
    # print('Number of explored nodes is ', IDS_solution[1])
    # print('IDS Time:%.4fms' % (IDS_time*1000), "\n")
    #
    # start_time = time()
    # UCS_solution = UniformCostSearch(root, n)
    # UCS_time = time() - start_time
    # print('UCS is ', UCS_solution[0])
    # print('STEP:', len(UCS_solution[0]))
    # print('Number of explored nodes is ', UCS_solution[1])
    # print('UCS Time:%.4fms' % (UCS_time*1000), "\n")
    #
    # start_time = time()
    # Greedy_solution = Greedy(root, n)
    # Greedy_time = time() - start_time
    # print('Greedy with Manhattan Distance Solution is ', Greedy_solution[0])
    # print('STEP:', len(Greedy_solution[0]))
    # print('Number of explored nodes is ', Greedy_solution[1])
    # print('Greedy Time:%.4fms' % (Greedy_time*1000) , "\n")
    #
    # start_time = time()
    # AStar_solution = AStar_search(root, n)
    # AStar_time = time() - start_time
    # print('A* with Manhattan Distance Solution is ', AStar_solution[0])
    # print('STEP:', len(AStar_solution[0]))
    # print('Number of explored nodes is ', AStar_solution[1])
    # print('A* Time:%.4fms' % (AStar_time*1000), "\n")
    #
    # start_time = time()
    # RBFS_solution = RBFS(root, n)
    # RBFS_time = time() - start_time
    # print('RBFS is ', RBFS_solution[0])
    # print('STEP:', len(RBFS_solution[0]))
    # print('Number of successors is ', RBFS_solution[1])
    # print('RBFS Time:%.4fms' % (RBFS_time*1000), "\n")