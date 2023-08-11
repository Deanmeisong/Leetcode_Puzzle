/**
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var kthGrammar = function(n, k) {
    if(n == 1) return 0;
    if(k > (1 << (n - 2))) return 1 ^ kthGrammar(n - 1, k - (1 << (n - 2)));
    else return kthGrammar(n - 1, k);
};