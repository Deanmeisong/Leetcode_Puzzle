# Definition for an infinite stream.
# class InfiniteStream:
#     def next(self) -> int:
#         pass
class Solution:
    def findPattern(self, stream: Optional['InfiniteStream'], pattern: List[int]) -> int:
        num, target, count, n = 0, 0, 0, len(pattern)
        mask = (1<<(n-1)) - 1
        
        for b in pattern:
            target = (target << 1) + b
        
        while num != target or count < n:
            num = ((num&mask)<<1) + stream.next();
            count += 1
        print(count)
        return count - n