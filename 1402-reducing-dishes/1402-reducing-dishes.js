/**
 * @param {number[]} satisfaction
 * @return {number}
 */
var maxSatisfaction = function(satisfaction) {
    satisfaction.sort((a, b) => a - b);
    console.log(satisfaction)
        let n = satisfaction.length;
        let res = 0, tmp = 0;

        for(let i = n - 1; i >= 0; --i) {
            if(satisfaction[i] + tmp <=  0) break;
            tmp += satisfaction[i];
            res += tmp;
        }
    return res;
};