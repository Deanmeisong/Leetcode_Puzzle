class Solution(object):
    def splitMessage(self, message, limit):
        """
        :type message: str
        :type limit: int
        :rtype: List[str]
        """
        
        cur = k = i = 0
        while 2 * len(str(k)) + 3 < limit and cur + len(message) + (len(str(k)) + 3) * k > limit * k:
            k += 1
            cur += len(str(k))
        res = []
        
        if 2 * len(str(k)) + 3 < limit:
            for j in range(1, k + 1):
                l = limit - (len(str(k)) + len(str(j)) + 3)
                res.append('%s<%s/%s>'%(message[i : i + l], j, k))
                i += l
        return res