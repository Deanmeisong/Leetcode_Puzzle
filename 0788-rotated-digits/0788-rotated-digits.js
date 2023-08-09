/**
 * @param {number} n
 * @return {number}
 */
var rotatedDigits = function(n) {
    let ans = 0;
    for(let i = 0; i <= n; ++i) {
        if(helper(i)) ++ans;
    }
    return ans;
}

function helper(x) {
    let flag = false;
    while(x > 0) {
        let t = x % 10;
        x = Math.floor(x / 10);
        if(t == 4 || t == 3 || t == 7) return false;
        if(t == 6 || t == 9 || t == 2 || t == 5) flag = true;
    }
    return flag;
}

