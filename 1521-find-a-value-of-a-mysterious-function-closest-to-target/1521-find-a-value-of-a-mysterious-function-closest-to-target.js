/**
 * @param {number[]} arr
 * @param {number} target
 * @return {number}
 */
var closestToTarget = function(arr, target) {
    let s = new Set();
    let res = Number.MAX_VALUE; 
    for (let i = 0; i < arr.length; ++i) {
        let s1 = new Set();
        for (let x of s) {
            s1.add(x & arr[i]);
        }
        s1.add(arr[i]);
        for (let x of s1) {
            res = Math.min(res, Math.abs(x - target));
        }
        s = s1;
    }
    return res;
};