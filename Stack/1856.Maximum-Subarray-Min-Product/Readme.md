### 1856.Maximum-Subarray-Min-Product

此题和```LC 907.Sum-of-Subarray-Minimums```非常相似，场景也更为直观。传统思维是遍历所有subarray，寻找每个subarray的最小值。这需要o(N^2)的复杂度。

逆向思维是，遍历每个元素nums[i]，思考以它为最小值的subarray最大是什么。显然，满足条件的subarray的左右边界之外都应该是恰比nums[i]小的元素，也就是prev smaller element和next greater element. 这两个位置都是可以用经典的单调栈算法以均摊o(1)的时间来完成。确定了subarray的边界后，那么subarray sum显然也是可以用预处理的前缀和以o(1)计算出来。
