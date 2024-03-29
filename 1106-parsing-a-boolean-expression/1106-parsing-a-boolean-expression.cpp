class Solution {
public:
    bool parseBoolExpr(string expression) {
        int s = 0;
        return helper(expression, s);
    }
        
    bool helper(string e, int& s) {
        char ch = e[s++];
        if(ch == 't') return true;
        if(ch == 'f') return false;
        
        if(ch == '!') {
            bool ans = !helper(e, ++s);
            ++s;
            return ans;
        }
        
        bool is_and = (ch == '&');
        bool ans = is_and;
        ++s;
        while(true) {
            if (is_and) ans &= helper(e, s);
            else ans |= helper(e, s);
            if (e[s++] == ')') break;
        }

        return ans;

    }
};