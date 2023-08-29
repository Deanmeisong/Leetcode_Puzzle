class Solution {
public:
    int distinctEchoSubstrings(string text) {
        unordered_set<string> st;
        for(int len = 1; len <= text.size() / 2; ++len)
            for(int l = 0, r = len, count = 0; l < text.size() - len; ++l, ++r) {
                if(text[l] == text[r]) ++count;
                else count = 0;
                
                if(count == len) {
                    st.insert(text.substr(l - len + 1, len));
                    --count;
                }
            }
        return st.size();
    }
};