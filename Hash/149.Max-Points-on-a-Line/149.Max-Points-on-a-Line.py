# Definition for a point.
# class Point:
#     def __init__(self, a=0, b=0):
#         self.x = a
#         self.y = b

class Solution:
    def maxPoints(self, points):
        """
        :type points: List[Point]
        :rtype: int
        """ 
        
        def inline(a,b,c):
            return (b.y-a.y)*(c.x-a.x)==(c.y-a.y)*(b.x-a.x)
                        
        if (len(points)<=2):
            return len(points)
        
        result = 0;
        for i in range(len(points)):                        
            D = collections.defaultdict(int);
            countSame = 0;            
            for j in range(len(points)):                
                if (j==i): 
                    continue;                         
                if points[j].x==points[i].x and points[j].y==points[i].y: 
                    countSame+=1;
                    continue;
                flag = 0;
                for key in D:                   
                    if inline(points[i],points[key],points[j])==1:
                        flag = 1;
                        D[key]+=1
                        break;
                if (flag==0):
                    D[j]=1
            result = max(result, max(list(D.values())+[0])+countSame+1)
            
        return result
