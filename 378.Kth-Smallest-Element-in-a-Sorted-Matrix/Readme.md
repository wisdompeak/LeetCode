### 378. Kth Smallest Element in a Sorted Matrix  
矩阵的规律是：如果matrix[i][j]不是最小的，则matrix[i+1][j]和matrix[i][j+1]就都不用考虑。或者matrix[i][j]是最小的，则matrix[i+1][j]和matrix[i][j+1]就能进如考虑范围。  

所以类似BFS的算法，设计一个小顶堆的Priority_queue，每次出列最小值之后，将最小值邻接的matrix[i+1][j]和matrix[i][j+1]加入这个队列会自动排序。当出列k个数之后就是答案。
