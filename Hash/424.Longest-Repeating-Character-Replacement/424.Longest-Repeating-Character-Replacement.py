class Solution:
    def characterReplacement(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        counts=collections.defaultdict(int)
        lo, result, maxn = 0,0,0
        for hi in range(len(s)):
            counts[s[hi]]+=1
            maxn = max(maxn, counts[s[hi]])
            if hi-lo+1-maxn>k:                
                counts[s[lo]]-=1
                lo+=1
            else:
                result = max(result,hi-lo+1)
        return result
        
