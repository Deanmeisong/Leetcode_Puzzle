/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number}
 */
var countComponents = function(n, edges) {
    let roots = new Array(n);
    for(let i = 0; i < n; ++i) roots[i] = i;
    
    function find(x) {
        while(roots[x] != x) {
            roots[x] = roots[roots[x]];
            x = roots[x];
        }
        return x;
    }
    
    for(const e of edges) {
        let r1 = find(e[0]); let r2 = find(e[1]);
        if(r1 != r2) {
            roots[r1] = r2;
            --n;
        }
    }
    
    return n;
};