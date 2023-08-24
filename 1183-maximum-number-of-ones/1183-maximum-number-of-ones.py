class Solution:
    def maximumNumberOfOnes(self, width: int, height: int, sideLength: int, maxOnes: int) -> int:
        count = []
        for i in range(sideLength):
            for j in range(sideLength):
                count += [((width - i - 1) // sideLength + 1) * ((height - j - 1) // sideLength + 1)]
        count = sorted(count, reverse = True)
        return sum(count[:maxOnes])