/**
 * @param {number} length
 * @param {number[][]} updates
 * @return {number[]}
 */
var getModifiedArray = function(length, updates) {
    const diff = new Array(length + 1).fill(0);
    for(const x of updates) {
        diff[x[0]] += x[2]
        diff[x[1] + 1] -= x[2]
    }
    
    let val = 0;
    const res = new Array(length);
    
    for(let i = 0; i < length; ++i) {
        val += diff[i];
        res[i] = val;
    }
    
    return res;
};