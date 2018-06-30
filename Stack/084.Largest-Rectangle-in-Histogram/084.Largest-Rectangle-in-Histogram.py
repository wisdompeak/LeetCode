class Solution:
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        heights = [0]+heights+[0]
        stack=[]
        ret = 0
        for i in range(len(heights)):
            if len(stack)==0 or heights[i]>=heights[stack[-1]]:
                stack.append(i)
            elif heights[i]<heights[stack[-1]]:                
                while heights[stack[-1]]>heights[i]:
                    H = heights[stack[-1]]
                    stack.pop()
                    ret = max(ret, H*(i-stack[-1]-1))
                stack.append(i)            
        return ret
