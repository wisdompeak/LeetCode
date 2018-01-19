class Solution:
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        N = len(matrix)
        for i in range(N//2):
            for j in range((N+1)//2):       
                x,y = i,j
                for k in range(3):
                    m,n = N-1-y, x
                    matrix[x][y],matrix[m][n] = matrix[m][n],matrix[x][y]
                    x,y = m,n        
