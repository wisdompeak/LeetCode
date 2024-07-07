### 3171.Find-Subarray-With-Bitwise-AND-Closest-to-K

#### 解法1
此题和1521几乎一样。

关于bitwise AND subarray的一个套路：对于所有以nums[i]结尾的subarray，无论它最长有多少元素，这些subarray的bitwise OR的数值种类最多只有31种。

我们用一个set来存入所有以nums[i-1]结尾的subarray的bitwise OR，就可以更新得到所有以nums[i]结尾的subarray的bitwise OR，只需要将set里的元素都与nums[i]进行OR即可。操作的时间是常数o(31)。

由此我们可以得到任何以nums[i]结尾的subarray，查看里面哪些数值最接近k。

#### 解法2
暴力解法的时间复杂度是o(N^2)，即枚举所有的subarray。我们发现一旦确定了subarray的首元素，在移动尾指针的时候，bitwsie AND的值是单调递减的。所以我们很容易想到用二分的方法来确定答案最接近k的右端点。这就需要我们提前知道任何两点之间的区间bitwise AND的值。这个需求显然与求任意区间内的range sum一样，用线段树可以解决。

所以本题是先写好查询区间和“bitwise AND”的线段树模板。然后暴力枚举subarray的首元素i，再大于等于i处用二分寻找右端点位置j，使得区间和最接近k。
