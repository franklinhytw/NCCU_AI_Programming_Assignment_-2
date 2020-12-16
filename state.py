import copy
class State:
    greedy_evaluation = None
    AStar_evaluation = None
    heuristic = None
    total_queens = 1
    max_queens = 8 #8x8
    
    def __init__(self, state, parent, put_queen, depth, cost):
        self.state = state
        self.parent = parent
        self.depth = depth
        self.put_queen = put_queen

        if parent:
            self.cost = parent.cost + cost

        else:
            self.cost = cost
         
    def test(self): #check if the given state is goal
        if self.depth == 7:
            return True
        return False

    # def put_queen(self):
    #     self.total_queens += 1
    #     pass
        
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
        combination_list = []
        
        if self.isAtaccked(self.state, n):
            return combination_list
        x_list = []
        y_list = []
        x_avail_list = []
        y_avail_list = []
        queen_list = []
        
        # Find all of quuen position
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
                
        for xx in x_avail_list:
            for yy in y_avail_list:
                combination_list.append((xx,yy))
                
        for queen in queen_list:
            for comb in combination_list:
                distance_pre = abs(queen[0] - comb[0])
                distance_next = abs(queen[1] - comb[1])
                
                # print(queen[0], queen[1], comb[0], comb[1], distance_pre, distance_next)
                if distance_pre == distance_next:
                    combination_list.remove(comb)

        return combination_list

    def expand(self, n): 
        pos_list = self.available_next_step(n)

        children = []
               
        for pos in pos_list:
            # copy list to another memory address
            # such as C++: 'memcpy'
            temp = copy.deepcopy(self.state) # Oh! Deeper and Harder~~

            x = pos[0]
            y = pos[1]
            temp[x][y] = 1
            
            children.append(State(temp, self, pos, self.depth + 1, 1)) #depth should be changed as children are produced

        return children

    
    def solution(self):
        solution = []
        solution.append(self.put_queen)
        path = self
        while path.parent != None:
            path = path.parent
            solution.append(path.put_queen)
        solution = solution[:-1]
        solution.reverse()
        return solution