/**
 * @param {string[]} sentence
 * @param {number} rows
 * @param {number} cols
 * @return {number}
 */
var wordsTyping = function(sentence, rows, cols) {
    
    const n = sentence.length;
    const cache = new Array(n);
    
    for(let i = 0; i < n; ++i) {
        let index = i;
        let len = 0;
        let wordNum = 0;
        while((len + sentence[index % n].length) <= cols) {
            len += sentence[index % n].length + 1;
            wordNum++;
            index++;
        }
        cache[i] = wordNum;
    }
    
    
    let words = 0; let index = 0;
    for(let i = 0; i < rows; ++i) {
        words += cache[index];
        index = (cache[index] + index) % n;
    }
    
    return Math.floor(words / n);
};