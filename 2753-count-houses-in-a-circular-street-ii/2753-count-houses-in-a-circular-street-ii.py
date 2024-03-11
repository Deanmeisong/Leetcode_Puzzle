# Definition for a street.
# class Street:
#     def closeDoor(self):
#         pass
#     def isDoorOpen(self):
#         pass
#     def moveRight(self):
#         pass
class Solution(object):
    def houseCount(self, street, k):
        """
        :type street: Street
        :type k: int
        :rtype: int
        """
        while not street.isDoorOpen():
            street.moveRight()
        ans = 0
        for i in range(1, k + 1):
            street.moveRight()
            if street.isDoorOpen():
                ans = i
                street.closeDoor()
        return ans