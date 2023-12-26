class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dict = {}
        for x in strs:
            xSorted = sorted(x)
            key = "".join(xSorted)
            if key in dict:
                dict[key].append(x)
            else:
                
                dict[key] = [x]
                
        return dict.values()