### 2763.Sum-of-Imbalance-Numbers-of-All-Subarrays

#### 解法1：
因为数据规模不大，可以用n^2的复杂度，那么我们可以暴力模拟每个subarray。当我们固定i为左边界的时候，逐个向右移动j作为右边界，考察此时[i:j]的subarray里有多少个符合条件的index。

假设在[i:j-1]的旧subarray里已经有count个符合条件的index，当我们需要考察nums[j]加入后的新subarray时，计数会有什么变化呢？我们发现，新subarray基本上可以继承旧subarray的count，但是我们需要考虑nums[j]带来的变化。

1. 通常情况下，如果旧subarray里面的元素分布是稀疏的，那么一个新元素nums[j]的引入大概率会贡献一个合法的index（旧subarray为空除外），即`count+=1`。除非旧subarray里面已经有了`nums[j]`这个元素，那么显然，相同数值的元素不能贡献多于一个的合法index，我们会忽略count的变化跳出剩余的判断。
2. 如果发现旧subarray里面已经有了`nums[j]+1`这个元素，那么nums[j]会因为它的缘故无法被认为是合法的index，故取消刚才的计数`count-=1`.
3. 如果发现旧subarray里面已经有了`nums[j]-1`这个元素，那么nums[j]反而会侵蚀掉一个之前认为是合法的index，故扣减计数`count-=1`.

综上，此时的count就是[i:j]对应的新subarray的合法index的计数。

#### 解法2：
我们发现，任意的subarray，排序过后里面的每一个index，必然唯一对应着排序之前的某一个index。所以我们想计数排序后合法index的个数，其实直接对排序前的数组进行考察，即思考原始的nums[i]可以是哪些subarray里面的合法index。

要是nums[i]在排序后处在一个合法的index，我们必然要求这个subarray不能包括任何数值为`nums[i]+1`的元素，并且在它后面不能有数值为`nums[i]`的元素。（为了方便理解这一点，你可以认为我们制定如下规则：如果同一个subarray里面有多个相同数值的元素，那么这些元素在排序后不改变原始的顺序）。所以我们从i往前推，找到第一个prevInvalid的位置。同时从i往后推，找到第一个afterInvalid的位置，这样就有`(i-prevInvalid)*(afterInvalid-i)`个必然包含nums[i]的subarray，使得nums[i]在排序后不会跟着数值相同、或者相同数值+1的元素。我们记做`a*b`.

但是以上的计数包括了一种不合法的情况，即nums[i]可能排在了排序后的subarray的最后。所以我们要将这种情况排除。所以我们从i往前推，找到第一个prevLargerThanOne的位置（即·nums[j]>nums[i]+1·）。同时从i往后推，找到第一个afterLargerThanOne的位置。这样就有`(i-prevLargerThanOne)*(afterLargerThanOne-i)`个必然包含nums[i]的subarray，使得nums[i]在排序后是最后一个（因为没有其他合法元素可以排在它后面）。我们记做`c*d`.

所以`a*b-c*d`就是nums[i]可以贡献的subarray的个数，使得它在这些subarray里面贡献的是一个合法的index.

特别注意，之前计算的prevLargerThanOne不能往前超越prevInvalid；同理afterLargerThanOne不能往后超越afterInvalid，这是因为`c*d`的计数前提依然是valid（即不能有与nums[i]相同数值或者相同数值+1的元素存在）。

#### 解法3：
上述的解法2是`o(N^2)`的复杂度。运用预处理可以进一步优化到o(N)。

我们用Hash表（记录val->pos）从前往后扫一遍，就可以知道任何nums[i]的prevInvalid的位置。

我们再利用单调栈的计数从前往后扫一遍，就可以知道任何nums[i]的prevLargerThanOne的位置，具体做法和求prevGreaterElement几乎一样。
