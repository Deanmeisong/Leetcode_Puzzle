/**
 * @param {string} text
 * @return {number}
 */
var longestDecomposition = function(s) {
    let res = 0; let n = s.length; let l = ""; let r = "";
    for(let i = 0; i < n; ++i) {
        l += s[i]; r = s[n - i - 1] + r;
        if(l === r) {
            res += 1;
            l = ""; r = "";
        }
    }
    return res;
};