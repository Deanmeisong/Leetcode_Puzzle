class TicTacToe:
    def __init__(self, n):
        self.rs = [0] * n
        self.cs = [0] * n
        self.n = n
        self.diag = 0
        self.antid = 0

    def move(self, row, col, player):
        add = 1 if player == 1 else -1
        self.rs[row] += add
        self.cs[col] += add
        if row == col:
            self.diag += add
        if row + col == len(self.cs) - 1:
            self.antid += add
        if abs(self.rs[row]) == self.n or abs(self.cs[col]) == self.n or abs(self.diag) == self.n or abs(self.antid) == self.n:
            return player
        return 0
