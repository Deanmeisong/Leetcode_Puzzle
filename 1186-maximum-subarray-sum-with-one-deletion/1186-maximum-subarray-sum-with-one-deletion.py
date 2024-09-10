class Solution:
    def maximumSum(self, arr: List[int]) -> int:
        n = len(arr)
        ends = [0] * n
        starts = [0] * n
        
        # Calculate the maximum subarray sum ending at each index
        s = 0
        for i in range(n):
            s = max(s, 0) + arr[i]
            ends[i] = s
        
        # Calculate the maximum subarray sum starting at each index
        s = 0
        for i in range(n - 1, -1, -1):
            s = max(s, 0) + arr[i]
            starts[i] = s
        
        # Initialize the answer with the maximum sum of a subarray without any deletions
        ans = max(ends)
        
        # Consider the maximum sum we can get by deleting one element
        for i in range(1, n - 1):
            ans = max(ans, ends[i - 1] + starts[i + 1])
        
        return ans