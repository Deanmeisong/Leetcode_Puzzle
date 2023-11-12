/**
 * @param {number} x
 * @return {number}
 */
var mySqrt = function(x) {
    if (x === 1) return 1;
    let l = 1, r = x;
    while (l < r) {
        let m = Math.floor((r - l) / 2) + l;
        if (m > Math.floor(x / m)) r = m;
        else l = m + 1;
    }
    return l - 1;
};