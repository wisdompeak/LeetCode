### 3690.Split-and-Merge-Array-Transformation

本题的数据量不大，数组元素数目很少，可以暴力（配合去重）。因为是求最少变换次数，显然选用BFS。

每次从队列里弹出一个数组，遍历所有的subarray作为sub，剩下的拼接为rem。然后在rem的任意位置插入sub，组成新的数组。
