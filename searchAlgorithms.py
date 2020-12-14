from state import State
from queue import PriorityQueue
from queue import Queue
from queue import LifoQueue
from sys import maxsize


def DLS(given_state, n, depth):
    root = State(given_state, None, None, 0, 0)
    if root.test():
        return root.solution()
    frontier = Queue()
    frontier.put(root)
    explored = []
    
    while not(frontier.empty()):
        current_node = frontier.get()

        max_depth = current_node.depth #current depth
        explored.append(current_node.state)
        
        if max_depth >= depth:
            continue #go to the next branch
        
        children = current_node.expand(n)
        for child in children:
            if child.state not in explored:
                if child.test():
                    return child.solution(), len(explored)
                frontier.put(child)
    return (False, len(explored))
    
def IDS(given_state , n):
    for depth in range(100): # 0 ~ 100
        (result,length) = DLS(given_state, n ,depth)
        if result != False:
            return result, length
        

def RBFS(given_state , n):
    rtn = RBFS_impl(State(given_state, None, None, 0, 0), n, f_limit=maxsize)
    node = rtn[0]
    
    return node.solution(), rtn[1]
    
    
def RBFS_impl(node, n, f_limit):
    successors=[]
    
    if node.test():
        return node, None
    
    children=node.expand(n)
    if not len(children):
        return None, maxsize
    
    count=-1
    for child in children:
        count+=1
        successors.append((child.Manhattan_Distance(n)[1], count, child))
        
    while len(successors):
        successors.sort()
        best_node=successors[0][2]
        if best_node.Manhattan_Distance(n)[1] > f_limit:
            return None, best_node.Manhattan_Distance(n)[1]
        
        alternative=successors[1][0]
        result, best_node.cost = RBFS_impl(best_node, n, min(f_limit,alternative))
        
        successors[0] = (best_node.cost, successors[0][1], best_node)
        
        if result!=None:
            break

    return result, len(successors)

def UniformCostSearch(given_state , n):
    root = State(given_state, None, None, 0, 0)
    if root.test():
        return root.solution()
    frontier = PriorityQueue()
    counter = 0
    frontier.put((0, counter, root))
    explored = []
    
    while not(frontier.empty()):
        current_node = frontier.get()
        current_node = current_node[2]
        explored.append(current_node.state)
        
        if current_node.test():
            return current_node.solution(), len(explored)
          
        children = current_node.expand(n)
        for child in children:
            direction = child.direction
            
            if direction == 'Left' or direction == 'Right':
                priority = 1
            elif direction == 'Up' or direction == 'Down':
                priority = 2
                
            if child.state not in explored:
                counter += 1
                frontier.put((child.cost, counter, child))
    return
  
def Greedy(given_state , n):
    frontier = PriorityQueue()
    explored = []
    counter = 0
    root = State(given_state, None, None, 0, 0)
    evaluation = root.Manhattan_Distance(n)
    frontier.put((evaluation[0], counter, root)) # based on greedy evaluation

    while not frontier.empty():
        current_node = frontier.get()
        current_node = current_node[2]
        explored.append(current_node.state)
        
        if current_node.test():
            return current_node.solution(), len(explored)

        children = current_node.expand(n)
        for child in children:
            if child.state not in explored:
                counter += 1
                evaluation = child.Manhattan_Distance(n)
                frontier.put((evaluation[0], counter, child)) #based on greedy evaluation
    return


def AStar_search(given_state , n):
    frontier = PriorityQueue()
    explored = []
    counter = 0
    root = State(given_state, None, None, 0, 0)
    evaluation = root.Manhattan_Distance(n)
    frontier.put((evaluation[1], counter, root)) #based on A* evaluation

    while not frontier.empty():
        current_node = frontier.get()
        current_node = current_node[2]
        explored.append(current_node.state)
        
        if current_node.test():
            return current_node.solution(), len(explored)

        children = current_node.expand(n)
        for child in children:
            if child.state not in explored:
                counter += 1
                evaluation = child.Manhattan_Distance(n)
                frontier.put((evaluation[1], counter, child)) #based on A* evaluation
    return
