class Solution(object):
    def minBuildTime(self, blocks, split):
        """
        :type blocks: List[int]
        :type split: int
        :rtype: int
        """
        heapq.heapify(blocks)
        while len(blocks) > 1:
            a, b = heapq.heappop(blocks), heapq.heappop(blocks)
            heapq.heappush(blocks, b + split)
        
        return heapq.heappop(blocks)