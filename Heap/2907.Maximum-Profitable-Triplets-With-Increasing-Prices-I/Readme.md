### 2907.Maximum-Profitable-Triplets-With-Increasing-Prices-I

#### 解法1：线段树
此题可以用线段树无脑解决。先从左往右遍历一遍，逐个将物品放入线段树，leaf表示价格，value表示profit。对于第i件物品，在所有价格小于prices[i]的物品中找出profit最大值，记做left[i]. 再从右往左遍历一遍，逐个将物品放入另一棵线段树，leaf表示价格，value表示profit。对于第i件物品，在所有价格大于prices[i]的物品中找出profit最大值，记做right[i]. 最后，找到全局最大的`left[i]+profits[i]+right[i]`.

注意，尽管prices不超过1e6，此题仍然需要先离散化减少开辟叶子节点的需求，否则会TLE。

#### 解法2：单调的有序容器
和上面类似的思想，不过在从左往右遍历的过程中，我们维护一个按key递增有序的Map，key是price，value是profit。同时我们额外维护这个Map使得里面的元素在value的意义上也是递增的。这样对于第i件物品，我们用`upper_bound + prev`找到最后一件恰好小于prices[i]的物品，它的profit就是我们想要的left[i]，因为Map里面其他价格更小的物品的profit是更小的。然后我们将新的`{prices[i], profits[i]}`加入容器时，有一个特别的操作，在它之后任何价格更高、但利润更低的元素都可以从容器里面删除，以此保证插入新元素之后该容器依然是按照key和value都是递增。

类似地，我们再从右往左遍历一遍，同时我们维护这个Map使得里面的元素按照key递增的同时，在value的意义上是递减的。这样对于第i件物品，我们用`upper_bound + prev`找到第一件恰好大于prices[i]的物品，它的profit就是我们想要的right[i]，因为Map里面其他价格更大的物品的profit是更小的。然后我们将新的`{prices[i], profits[i]}`加入容器后，有一个特别的操作，在它之前任何价格低、同时利润也更低的元素都可以从容器里面删除，以此保证插入新元素之后该容器依然是按照value都是递减的。注意，这个操作可能需要reverse_iterator.
