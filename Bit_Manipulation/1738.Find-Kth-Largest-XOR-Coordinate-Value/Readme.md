### 1738.Find-Kth-Largest-XOR-Coordinate-Value

和二维矩阵前缀和的思路类似，我们可以用o(1)的时间求出每个网格位置的值：```a[i][j] = a[i-1][j]^a[i][j-1]^a[i-1][j-1]^matrix[i][j]```.

求一个数组中的第k大value，两种做法。第一种用优先队列，按照从小到大排序，当队列里面超过k个元素时，那么队首元素就可以舍弃，因为它至少是第k+1大的元素。

第二种方法类似于```215.Kth-Largest-Element-in-an-Array```。每次猜测一个值x，然后遍历全局矩阵，统计有多少个元素大于等于x，如果count小于k，那么x肯定不可能是答案，我们将猜测的上界下调至x-1；否则，我们就将猜测的下界调整至x。
