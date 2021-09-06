import math, statistics, collections, copy

class ConnectFour:
    def __init__(self, row=6, column=7):
        assert(row>=4 and column>=4)
        self.r = row
        self.c = column
        self.turn = 1
        self.board = [[0 for i in range(self.c)] for i in range(self.r)]

    def display(self):
        print('Current board configuration')
        for i in range(0, self.c):
            print(i, end='')
        print()
        for i in range(0, self.c):
            print('-', end='')
        print()
        for i in range(0, self.r):
            for j in range(0, self.c):
                if self.board[i][j] == 0:
                    print('*', end='')
                else:
                    print(self.board[i][j], end='')
            print('')

    def result(self):
        for i in range(0, self.r):
            for j in range(0, self.c-3):
                if self.board[i][j] != 0 and \
                    self.board[i][j] == self.board[i][j+1] and \
                    self.board[i][j+1] == self.board[i][j+2] and \
                    self.board[i][j+2] == self.board[i][j+3]:
                        return self.board[i][j]

        for j in range(0, self.c):
            for i in range(0, self.r-3):
                if self.board[i][j] != 0 and \
                    self.board[i][j] == self.board[i+1][j] and \
                    self.board[i+1][j] == self.board[i+2][j] and \
                    self.board[i+2][j] == self.board[i+3][j]:
                        return self.board[i][j]

        for i in range(0, self.r-3):
            for j in range(0, self.c-3):
                if self.board[i][j] != 0 and \
                    self.board[i][j] == self.board[i+1][j+1] and \
                    self.board[i+1][j+1] == self.board[i+2][j+2] and \
                    self.board[i+2][j+2] == self.board[i+3][j+3]:
                        return self.board[i][j]

        
        for i in range(3, self.r):
            for j in range(0, self.c-3):
                if self.board[i][j] != 0 and \
                    self.board[i][j] == self.board[i-1][j+1] and \
                    self.board[i-1][j+1] == self.board[i-2][j+2] and \
                    self.board[i-2][j+2] == self.board[i-3][j+3]:
                        return self.board[i][j]

        return 0
    
    def move(self, col):
        assert(col>=0 and col<self.c)
        move_made = False
        for i in range(self.r-1, -1, -1):
            if self.board[i][col] == 0:
                move_made = True
                self.board[i][col] = self.turn
                self.turn = 1 if self.turn == 2 else 2
                break
        return move_made

def play(first_turn):
    cf = ConnectFour()
    cf.turn = first_turn
    while cf.result() == 0:
        cf.display()
        if cf.turn == 1:
            move_made = False
            while not move_made:
                print('Enter column number to drop you disc into: ', end='')
                col = int(input())
                valid_move = cf.move(col)
                move_made = valid_move
                if not valid_move:
                    print('Invalid move as desired column is filled already! Enter again')
        else:
            possible_col = list()
            winning_col = list()
            for i in range(0, cf.c):
                cf_copy = copy.deepcopy(cf)
                valid_move = cf_copy.move(i)
                if valid_move:
                    if cf_copy.result() == 2:
                        winning_col.append(i)
                    else:
                        possible = True
                        for j in range(0, cf.c):
                            cf_copy1 = copy.deepcopy(cf_copy)
                            valid_move = cf_copy1.move(j)
                            if valid_move and cf_copy1.result() == 1:
                                possible = False
                        if possible: possible_col.append(i)
            move_col = -1
            if len(winning_col) != 0:
                move_col = winning_col[0]
            elif len(possible_col) != 0:
                move_col = possible_col[0]
            else:
                move_col = 0
            cf.move(move_col)
            print(f'Agent inserts disc to column {move_col}')
    cf.display()
    return cf.result()

if __name__ == '__main__':
    print('Do you want to play first?(y|n): ', end='')
    response = input()
    turn = 1 if response.lower() == 'y' else 0
    res = play(turn)
    if res == 1:
        print('Human wins🥳')
    else:
        print('Agent wins🤖')

