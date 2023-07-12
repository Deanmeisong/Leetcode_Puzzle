class Solution:
    def validWordAbbreviation(self, word: str, abbr: str) -> bool:
        i, j = 0, 0;
        while i < len(word) and j < len(abbr):
            c = abbr[j];
            if c.isdigit():
                num = int(c)
                if num == 0: 
                    return False;
                while j + 1 < len(abbr) and abbr[j + 1].isdigit():
                    num = num * 10 + int(abbr[j + 1]);
                    j = j + 1;
                i = i + num;
                j = j + 1;
            else:
                if word[i] != abbr[j]:
                    return False;
                i = i + 1;
                j = j + 1;
            
        return i == len(word) and j == len(abbr);