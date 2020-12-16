class State:
    greedy_evaluation = None
    AStar_evaluation = None
    heuristic = None
    total_queens = 1
    max_queens = 8 #8x8
    
    def __init__(self, state, parent, depth, cost):
        self.state = state
        self.parent = parent
        self.depth = depth

        if parent:
            self.cost = parent.cost + cost

        else:
            self.cost = cost
         
    def test(self): #check if the given state is goal
        if self.total_queens == self.max_queens:
            return True
        return False

    def put_queen(self):
        self.total_queens += 1
        pass
        
    #heuristic function based on Manhattan distance
    def Manhattan_Distance(self ,n): 
        self.heuristic = 0
        for i in range(1 , n*n):
            distance = abs(self.state.index(i) - self.goal.index(i))
            
            #manhattan distance between the current state and goal state
            self.heuristic = self.heuristic + distance/n + distance%n

        self.greedy_evaluation = self.heuristic    
        self.AStar_evaluation = self.heuristic + self.cost
        
        return(self.greedy_evaluation, self.AStar_evaluation)

    def isAtaccked(self, board, n):
        queen_list = []

        for i in range(n):
            for j in range(n):
                if (board[i][j] == 1):
                    for queen in queen_list:
                        if queen[0] == i or queen[1] == j:
                            return True
                        else:
                            queen_list.append((i, j))

        for ci in range(len(queen_list)):
            for cj in range(ci + 1, len(queen_list)):
                distance_pre = abs(queen_list[ci][0] - queen_list[cj][0])
                distance_next = abs(queen_list[ci][1] - queen_list[cj][1])
                if distance_pre == distance_next:
                    return True

        return False

    #put the one queen for next step
    def available_next_step(self, n):
        x_list = []
        y_list = []
        x_avail_list = []
        y_avail_list = []
        queen_list = []
        available_position = []
        
        for i in range(n):
            for j in range(n):
                if(self.state[i][j] == 1):
                    x_list.append(i)
                    y_list.append(j)
                    queen_list.append((i,j))

        for count in range(n):
            if count not in x_list:
                x_avail_list.append(count)
            if count not in y_list:
                y_avail_list.append(count)

        print(x_avail_list)
        print(y_avail_list)

        for 
        # for ci in range(len(queen_list)):
        #     for cj in range(ci + 1, len(queen_list)):
        #         distance_pre = abs(queen_list[ci][0] - queen_list[cj][0])
        #         distance_next = abs(queen_list[ci][1] - queen_list[cj][1])
        #         if distance_pre == distance_next:
        #             return True
                    
        return available_position

    #produces children of a given state
    def expand(self, n): 
        moves = self.available_next_step(self.state, n)
        
        children = []
        # for direction in moves:
        #     temp = self.state.copy()
        #     if direction == 'Left':
        #         temp[x], temp[x - 1] = temp[x - 1], temp[x]
        #     elif direction == 'Right':
        #         temp[x], temp[x + 1] = temp[x + 1], temp[x]
        #     elif direction == 'Up':
        #         temp[x], temp[x - n] = temp[x - n], temp[x]
        #     elif direction == 'Down':
        #         temp[x], temp[x + n] = temp[x + n], temp[x]
        
        
        #     children.append(State(temp, self, self.depth + 1, 1)) #depth should be changed as children are produced
        return children

    #gets the given state and returns it's direction + it's parent's direction till there is no parent
    def solution(self):
        solution = []
        solution.append(self.direction)
        path = self
        while path.parent != None:
            path = path.parent
            solution.append(path.direction)
        solution = solution[:-1]
        solution.reverse()
        return solution