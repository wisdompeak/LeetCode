### 1438.Longest-Continuous-Subarray-With-Absolute-Diff-Less-Than-or-Equal-to-Limit

#### 解法1：Heap
本题如果用multiset会非常好做。固定左端点i，不断试探右端点j能前进到哪里。[i,j]内的元素都放入一个multiset，自动就知道了最大值和最小值。如果满足```mx-mn<=limit```，则这段区间长度就合法。否则我们就移动一次左端点i，同时要更新这个set把nums[i]从中移出去。

#### 解法2：monotone deque
multiset是o(NlogN)的解法，如果使用单调队列，可以优化到o(N)。

我们不用multset来维护最大值和最小值，而是用一个deque来维护当前区间[i,j]的最大值，用另一个deque来维护当前区间[i,j]的最小值。其中用deque来维护一个滑动窗口的最大值，就是```239.Sliding-Window-Maximum```的做法。

基本思想是：当将nums[j]加入队列时，如果发现它比队尾的元素还大，那么说明此时队尾元素可以抛弃，这是因为在未来相当一段时间内区间都会包含有j，所以最大值肯定轮不到是队尾的那个元素。这就提示我们维护的这个deque应该是单调递减的（因为新元素会把所有小的队尾元素都弹出）。每次我们要找当前区间的最大值，就只要看deque的队首元素就行。

同理，我们维护一个单调递增的deque来获取当前区间的最小值，其中最小值也是deque的队首元素。

注意，当j前进到区间[i,j]无法满足```mx-mn<=limit```时，j的前进就停止，我们要移动i。因此需要将nums[i]从这两个deque中移出。移出的操作就是看队首元素（的index）是否就是i，是的话把这个队首元素弹出就行。同时记得更新mx和mn。
