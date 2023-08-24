/**
 * @param {number} width
 * @param {number} height
 * @param {number} sideLength
 * @param {number} maxOnes
 * @return {number}
 */
var maximumNumberOfOnes = function(width, height, sideLength, maxOnes) {
    const count = [];
    for(let i = 0; i < sideLength; ++i) {
        for(let j = 0; j < sideLength; ++j) {
            let a = 1 + Math.floor((width - i - 1) / sideLength)
            let b = 1 + Math.floor((height - j - 1) / sideLength)
            count.push(a * b);
        }
    }
    count.sort((a, b) => b - a);
    // count.sort((a, b) => a > b);
    let res = 0;
    for(let i = 0; i < maxOnes; ++i) {
        res += count[i];
    }
    return res;
};