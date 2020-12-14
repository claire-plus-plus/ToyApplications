def display(board = [0, 0, 0, 0, 0, 0, 0, 0, 0]):
    t = ['-', 'X', 'O']
    print(
'''

{} {} {}
{} {} {}
{} {} {}'''.format(t[board[0]], t[board[1]], t[board[2]], t[board[3]], t[board[4]], t[board[5]], t[board[6]], t[board[7]], t[board[8]]))
    return

#main program
print(
'''
Welcome to Tic Tac Toe!
Enter the number of the place you want to play!
1 2 3
4 5 6
7 8 9''')

Board = [0, 0, 0, 0, 0, 0, 0, 0, 0]

player = False

while(True):
    display(Board)

    takeInput = True
    while(takeInput):
        takeInput = False

        Input = int(input("Player " + ("O" if player else "X") + ": ")) - 1

        if(Input < 0 or Input >= 9):
            print("Please enter a number between 1 and 9!")
            takeInput = True
        elif(Board[Input]):
            print("That space is taken! Choose another space1")
            takeInput = True
        else:
            Board[Input] = 2 if player else 1

    player = not player
            
