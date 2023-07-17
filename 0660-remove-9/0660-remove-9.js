/**
 * @param {number} n
 * @return {number}
 */
var newInteger = function(n) {
    let s = [];
    while (n) {
        s.push(n % 9);
        n = Math.floor(n / 9);
    }
    let ans = 0;
    for (let i = s.length - 1; i >= 0; --i) {
        ans = ans * 10 + s[i];
    }
    return ans;
};