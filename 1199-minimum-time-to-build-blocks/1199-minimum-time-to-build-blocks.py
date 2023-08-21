class Solution:
    def minBuildTime(self, blocks: List[int], split: int) -> int:
        heapq.heapify(blocks)
        while len(blocks) > 1:
            a, b = heapq.heappop(blocks), heapq.heappop(blocks)
            heapq.heappush(blocks, b + split)
        
        return heapq.heappop(blocks)