class Solution:
    def findMinArrowShots(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        points = sorted(points, key=lambda x:x[1])
        j = 0
        count = 0
        while (j<len(points)) :
            right = points[j][1]
            while (j<len(points) and points[j][0]<=right):
                j+=1
            count+=1
        return count
    
