class TicTacToe {
    constructor(n) {
        this.rs = new Array(n).fill(0);
        this.cs = new Array(n).fill(0);
        this.n = n;
        this.diag = 0;
        this.antid = 0;
    }
    move(row, col, player) {
        let add = player === 1 ? 1 : -1;
        this.rs[row] += add;
        this.cs[col] += add;
        if (row === col) this.diag += add;
        if (row + col === this.cs.length - 1) this.antid += add;
        if (Math.abs(this.rs[row]) === this.n || Math.abs(this.cs[col]) === this.n || Math.abs(this.diag) === this.n || Math.abs(this.antid) === this.n) return player;
        return 0;
    }
}
