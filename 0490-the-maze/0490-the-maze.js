/**
 * @param {number[][]} maze
 * @param {number[]} start
 * @param {number[]} destination
 * @return {boolean}
 */
var hasPath = function(maze, start, destination) {
    const q = [];
    const m = maze.length;
    const n = maze[0].length;
    const dirs = [[0, 1], [0, -1], [1, 0], [-1, 0]];
    q.push(start);

    // while(q.length > 0) {
    //     const pos = q.shift();
    //     const x = pos[0]; const y = pos[1];
    //     maze[x][y] == 2;
    //     if(destination[0] == x && destination[1] == y) return true;
    //     for(let i = 0; i < 4; ++i) {
    //         const r = dirs[i][0]; const c = dirs[i][1];
    //         let nx = r + x; 
    //         let ny = c + y;
           
    //         while (nx >= 0 && nx < m && ny >= 0 && ny < n && maze[nx][ny] !== 1) {

    //             nx += r; ny += c;
    //         }
    //         nx -= r; ny -= c;
    //         if(maze[nx][ny] == 0) q.push([nx, ny]);
    //     }
    // }
    while (q.length > 0) {
                    const pos = q.shift();
        const x = pos[0]; const y = pos[1];
                maze[x][y] = 2;

    // maze[x][y] = 2;
    // if (x == destination[0] && y === destination[1]) {
    //     return true;
    // }
        if(destination[0] === x && destination[1] === y) return true;
    for (let i = 0; i < 4; ++i) {
        const r = dirs[i][0];
        const c = dirs[i][1];
        let nx = x + r;
        let ny = y + c;
        while (nx >= 0 && nx < m && ny >= 0 && ny < n && maze[nx][ny] !== 1) {
            nx += r;
            ny += c;
        }
        nx -= r;
        ny -= c;
        if (maze[nx][ny] === 0) {
            q.push([nx, ny]);
        }
    }
}
    
    return false;
}