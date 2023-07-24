/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
    const romans = ['M', 'D', 'C', 'L', 'X', 'V', 'I'];
    const ints = [1000, 500, 100, 50, 10, 5, 1];
    const m = {};
    for(let i = 0; i < romans.length; ++i) m[romans[i]] = ints[i];
    let ans = 0;
    for(let i = 0; i < s.length; ++i) {
        if(i < s.length - 1) {
            if(m[s[i]] >= m[s[i + 1]]) ans += m[s[i]];
            else ans -= m[s[i]];
        } else {
            ans += m[s[i]];
        }
    }
    return ans;

};