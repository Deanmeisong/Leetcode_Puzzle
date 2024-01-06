/**
 * @param {number[]} arr1
 * @param {number[]} arr2
 * @return {number}
 */
var getXORSum = function(arr1, arr2) {
    let ora = 0;
    let orb = 0;
    for(let a of arr1) {
        ora ^= a;
    }
    for(let b of arr2) {
        orb ^= b;
    }
    return ora & orb;
};