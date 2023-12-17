class Solution:
    def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
        m, n, cnt = len(matrix), len(matrix[0]), 0
        for i in range(m):
            row = [0] * n
            for j in range(i, m):
                for k in range(n):
                    row[k] += matrix[j][k]
                dic = collections.defaultdict(int)
                dic[0] = 1
                presum = 0
                for k in range(n):
                    presum += row[k]
                    if dic[presum - target]: cnt += dic[presum - target]
                    dic[presum] += 1
        return cnt