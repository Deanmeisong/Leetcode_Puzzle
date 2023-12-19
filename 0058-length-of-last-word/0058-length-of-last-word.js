/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    function isAlphabet(str) {
        return /^[A-Za-z]+$/.test(str);
    }
    let cnt = 0;
    let n = s.length;
    let i = n - 1;
    while (i >= 0 && !isAlphabet(s[i])) {
        --i;
    }
    while (i >= 0 && isAlphabet(s[i--])) {
        ++cnt;
    }
    return cnt;
};