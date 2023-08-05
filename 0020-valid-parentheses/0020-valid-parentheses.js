/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    let st = [];
    for(let c of s) {
        if(c === '(') {st.push(')');}
        else if(c === '[') {st.push(']');}
        else if(c === '{') {st.push('}');}
        else if(st.length === 0 || st[st.length-1] !== c) {return false;}
        else {st.pop();}
    }
    return st.length === 0;
};