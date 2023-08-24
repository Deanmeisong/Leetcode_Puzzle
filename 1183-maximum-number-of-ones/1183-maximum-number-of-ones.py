class Solution(object):
    def maximumNumberOfOnes(self, width, height, sideLength, maxOnes):
        """
        :type width: int
        :type height: int
        :type sideLength: int
        :type maxOnes: int
        :rtype: int
        """
        count = []
        for i in range(sideLength):
            for j in range(sideLength):
                count += [((width - i - 1) // sideLength + 1) * ((height - j - 1) // sideLength + 1)]
        count = sorted(count, reverse = True)
        return sum(count[:maxOnes])