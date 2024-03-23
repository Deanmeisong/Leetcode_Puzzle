class Solution {
public:
    int evalVal(char op, pair<int,int>& a, pair<int,int>& b) {
        if(op == '#') return b.first;
        else if(op == '&') return a.first & b.first;
        else return a.first | b.first;
    }
    
    int evenFlip(char op, pair<int,int>& a, pair<int,int>& b) {
        if(op == '#') return b.second;
        else if(op == '&') 
        {
            if(a.first + b.first == 2) return min(a.second, b.second);
            else if(a.first + b.first == 1) return 1;
            else return min(a.second, b.second) + 1;
        }
        else //&
        {
            if(a.first + b.first == 2) return min(a.second, b.second)+1;
            else if(a.first + b.first == 1) return 1;
            else return min(a.second, b.second);
        }
    }
    
    int minOperationsToFlip(string expression) {
        stack<pair<int,int>> s1; stack<char> s2; pair<int,int> cur = {-1,-1}; char op = '#';
        
        for(auto ch : expression) {
            if(ch == '&' || ch == '|') op = ch;
            else if(ch == '0' || ch == '1')
            {
                pair<int,int> nxt = {ch-'0', 1};
                int val = evalVal(op, cur, nxt);
                int flip = evenFlip(op, cur, nxt);
                cur = {val, flip};
            }
            else if(ch == '(')
            {
                s1.push(cur);
                s2.push(op);
                cur = {-1, -1};
                op = '#';
            }
            else {
                auto last = s1.top(); s1.pop();
                char op = s2.top(); s2.pop();
                int val = evalVal(op, last, cur);
                int flip = evenFlip(op, last, cur);
                cur = {val, flip};
            }
        }
        return cur.second;
    }
};