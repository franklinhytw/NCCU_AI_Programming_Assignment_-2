if __name__ == '__main__':
    n = 8
    for i in range(n):
        for j in range(n):
            num = 2**i + 2**j
            if(num < 10):
                print(num, end="    | ")
            elif(num < 100):
                print(num, end="   | ")
            elif(num < 1000):
                print(num, end="  | ")
            elif(num < 10000):
                print(num, end=" | ")
            else:
                print(num, end="| ")
        print()  