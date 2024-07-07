### 3209.Number-of-Subarrays-With-AND-Value-of-K

#### 解法1
关于bitwise AND subarray的一个套路：对于所有以nums[i]结尾的subarray，无论它最长有多少元素，这些subarray的bitwise AND的数值种类最多只有31种。

我们用一个map来存入所有以nums[i-1]结尾的subarray的bitwise AND，就可以更新得到所有以nums[i]结尾的subarray的bitwise AND，只需要将map里的元素都与nums[i]进行AND即可。操作的时间是常数o(31)。

由此我们可以得到任何以nums[i]结尾的subarray，查看里面有多少的数值是k即可。

类似的题目有1521和3171

#### 解法2
我们可以构造一种线段树，可以高效得到任意区间的bitwise AND。

然后对于任意以nums[i]为开始的subarray，我们用线段树的query方法，可以用二分搜索，求得第一个bitwise AND是k的位置a，和最后一个bitwise AND是k的位置b。那么就有b-a+1个subarray满足条件。
