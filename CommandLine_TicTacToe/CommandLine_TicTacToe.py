def display(board = [0, 0, 0, 0, 0, 0, 0, 0, 0]):
    t = ['-', 'X', 'O']
    print(
'''
{} {} {}
{} {} {}
{} {} {}'''.format(t[board[0]], t[board[1]], t[board[2]],\
                   t[board[3]], t[board[4]], t[board[5]],\
                   t[board[6]], t[board[7]], t[board[8]]))
    return

#main program
print(
'''
Welcome to Tic Tac Toe!
Enter the number of the place you want to play!
1 2 3
4 5 6
7 8 9''')

#0 = empty, 1 = X, 2 = O
Board = [0, 0, 0, 0, 0, 0, 0, 0, 0]

#False = X, True = O
player = False

#main loop
while(True):
    display(Board)

    takeInput = True
    while(takeInput):
        takeInput = False

        try:
            Input = int(input("Player " + ("O" if player else "X") + ": ")) - 1
        except:
            print("Please enter a number between 1 and 9!")
            takeInput = True
            continue

        #validate input
        if(Input < 0 or Input >= 9):
            print("Please enter a number between 1 and 9!")
            takeInput = True
        elif(Board[Input]):
            print("That space is taken! Choose another space1")
            takeInput = True
        else:
            Board[Input] = 2 if player else 1

    #check for winning board state
    win = False
    for i in range(0, 3):
        currentPlayer = 2 if player else 1
        win = win or ((\
            currentPlayer == Board[i * 3 + 0] and\
            currentPlayer == Board[i * 3 + 1] and\
            currentPlayer == Board[i * 3 + 2]\
        ) or (\
            currentPlayer == Board[i + 0] and\
            currentPlayer == Board[i + 3] and\
            currentPlayer == Board[i + 6]))
        
    win = win or ((\
        currentPlayer == Board[0] and\
        currentPlayer == Board[4] and\
        currentPlayer == Board[8]\
    ) or (\
        currentPlayer == Board[2] and\
        currentPlayer == Board[4] and\
        currentPlayer == Board[6]))

    #display winning text
    if win:
        display(Board)
        input("Player " + ("O" if player else "X") + " wins! Press Enter to escape!")
        quit()
    #display draw text
    elif sum(Board) == 13:
        input("Draw! Press enter to escape!")
        quit()

    #swap player before looping
    player = not player
