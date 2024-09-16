/**
 * @param {string} s
 * @param {string} t
 * @param {number} maxCost
 * @return {number}
 */
var equalSubstring = function(s, t, maxCost) {
    let i = 0;
    let ans = 0;
    const n = s.length;

    for (let j = 0; j < n; ++j) {
      maxCost -= Math.abs(s.charCodeAt(j) - t.charCodeAt(j));
      while (maxCost < 0 && i <= j && i < n) {
        maxCost += Math.abs(s.charCodeAt(i) - t.charCodeAt(i));
        ++i;
      }
      ans = Math.max(ans, j - i + 1);
    }

    return ans;
};