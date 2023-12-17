class Solution {
    int s = 0;
    char[] exp;
    public boolean parseBoolExpr(String expression) {
        exp = expression.toCharArray();
        return parse() == 1;
    }
    
    int parse() {
        char ch = exp[s++];
        if(ch == 't') return 1;
        if(ch == 'f') return 0;
        if(ch == '!') {
            ++s;
            int ans = parse();
            ++s;
            return 1 - ans;
        }
        boolean isAnd = (ch == '&');
        int ans = isAnd ? 1 : 0;
        ++s;
        while(true) {
            if(isAnd) ans &= parse();
            else ans |= parse();
            if(exp[s++] == ')') break;
        }
        return ans;
    }
}