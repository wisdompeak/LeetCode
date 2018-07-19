# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def eraseOverlapIntervals(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: int
        """
        intervals = sorted(intervals,key=lambda x:x.end)
        count,j = 0,0
        while j<len(intervals):
            right = intervals[j].end
            j+=1
            while j<len(intervals) and intervals[j].start<right:
                j+=1
                count+=1
        return count
