class Solution:
    def wordsTyping(self, sentence: List[str], rows: int, cols: int) -> int:
        n = len(sentence)
        cache = [0] * n
        
        for i in range(n):
            index, wordNum, length = i, 0, 0
            while length + len(sentence[index % n]) <= cols:
                length += len(sentence[index % n]) + 1
                index += 1
                wordNum += 1
            cache[i] = wordNum
            
        words, index = 0, 0
        for i in range(rows):
            words += cache[index]
            index = (index + cache[index]) % n
        
        return words // n
        