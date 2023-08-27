class Solution(object):
    def asteroidCollision(self, A):
        """
        :type asteroids: List[int]
        :rtype: List[int]
        """
        st = []
        for a in A:
            flag = 1
            while st and (st[-1] > 0 and a < 0):
                if abs(a) > abs(st[-1]):
                    st.pop()
                    continue
                if abs(a) == abs(st[-1]):
                    st.pop()
                flag = 0
                break
            if flag:
                st.append(a)
        n = len(st)
        ans = [0] * n
        
        for i in range(n, 0, -1):
            ans[i - 1] = (st[-1])
            st.pop()
        return ans