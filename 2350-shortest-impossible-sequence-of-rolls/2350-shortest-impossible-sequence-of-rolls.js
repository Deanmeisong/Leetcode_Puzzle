/**
 * @param {number[]} rolls
 * @param {number} k
 * @return {number}
 */
var shortestSequence = function(rolls, k) {
    const s = new Set();
    let res = 1;
    for (let i of rolls) {
        s.add(i);
        if (s.size === k) {
            s.clear();
            res++;
        }
    }
    return res;
};