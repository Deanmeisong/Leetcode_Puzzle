class Solution:
    def longestObstacleCourseAtEachPosition(self, obstacles: List[int]) -> List[int]:
        arr, ret = [], []
        for x in obstacles:
            if not arr or arr[-1] <= x: 
                arr.append(x)
                ret.append(len(arr))
            else:
                idx = bisect.bisect(arr, x)
                arr[idx] = x
                ret.append(idx + 1)
        return ret