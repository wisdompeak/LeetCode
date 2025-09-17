class Solution(object):
    def longestPalindrome(self, s):
        length = len(s) * 2
        index_longest = offset_longest = 0
        for index in range(length):
            offset = 0
            for offset in range(1 + index % 2, min(index, length - index), 2):
                if s[(index - offset) // 2] != s[(index + offset) // 2]:
                    offset -= 2
                    break

            if offset > offset_longest:
                index_longest = index
                offset_longest = offset
        return s[(index_longest - offset_longest) // 2: (index_longest + offset_longest) // 2 + 1]    
