class Solution {
public:
    bool parseBoolExpr(string expression) {
        int s = 0;
        return helper(expression, s);
    }
    
  //   bool parse(const string& exp, int& s) {
  //       char ch = exp[s++];    
  //       if (ch == 't') return true;      
  //       if (ch == 'f') return false;
  //       if (ch == '!') {
  //         bool ans = !parse(exp, ++s);
  //         ++s;
  //         return ans;
  //       } 
  //       bool is_and = (ch == '&');
  //       bool ans = is_and;
  //       ++s;
  //       while (true) {
  //         if (is_and) ans &= parse(exp, s);
  //         else ans |= parse(exp, s);
  //         if (exp[s++] == ')') break;
  //       }
  //       return ans;
  // }
    
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