class Solution:
    def isValid(self, s: str) -> bool:
        st = []
        for c in s:
            if c == '(':
                st.append(')')
            elif c == '[':
                st.append(']')
            elif c == '{':
                st.append('}')
            elif len(st) == 0 or st[-1] != c:
                return False
            else:
                st.pop()
        return len(st) == 0