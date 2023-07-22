class Solution:
    def getModifiedArray(self, length: int, updates: List[List[int]]) -> List[int]:
        diff = [0] * (length + 1);
        
        for u in updates:
            diff[u[0]] += u[2]
            diff[u[1] + 1] -= u[2]
            
        res = [0] * length
        val = 0
        
        for i in range(length):
            val += diff[i];
            res[i] = val
        return res;