class TicTacToe {
public:
    vector<int> rs;
    vector<int> cs;
    int n;
    int diag = 0;
    int antid = 0;
    TicTacToe(int n) {
        rs = vector<int>(n, 0);
        cs = vector<int>(n, 0);
        this->n = n;
    }
    
    int move(int row, int col, int player) {
        int add = player == 1 ? 1 : -1;
        rs[row] += add;
        cs[col] += add;
        if(row == col) diag += add;
        if(row + col == cs.size() - 1) antid += add;
        
        if(abs(rs[row]) == n or abs(cs[col]) == n or abs(diag) == n or abs(antid) == n) return player;
        
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */