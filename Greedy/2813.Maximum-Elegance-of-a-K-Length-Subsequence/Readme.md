### 2813.Maximum-Elegance-of-a-K-Length-Subsequence

一个显然的想法是，能否遍历种类的数目：在固定种类数目的情况下，贪心地选择对应profit最高的k个item。但是即使说我们只考虑t个category，但是这样的t-distinct的category组合也非常多，我们无法穷举。

我们继续考虑。如果将所有元素按照profit降序排列，粗暴地取前k个元素，并记此时有t种不同的category，那么我们至少可以claim，当强制选择t个category时，此时的收益一定是最高的。因为我们选取的项目本身就是profit的top K.

然后我们想，强制选择小于t个category的话，该如何规划呢？本题的突破口就在这里。我们知道，相比于上述`choose profit top K`的决策，其他任何决策都不会在`total_profit`更优；并且如果打算选择的category个数还更小的话，`distinct_categories^2`也不会占优势。故总的elegance肯定不及上面的方案。所以我们可以终止这个方向的探索。

然后我们想，强制选择多余t个category的话，该如何规划呢？既然top K个item已经包含了t个category，我们必然会贪心地按照profit的降序考察后续的项目，直至找到一个属于新种类的item，这样就有了t+1个category.注意，此时我们为了保持item总数为k，必然要吐出一个item：这个item必然是profit尽量小，同时它对应的category必须还存在其他的元素（否则将其吐出之后总的category数目就又不够t+1了）。所以我们的做法是将之前的top k item都放入一个小顶堆的PQ，需要弹出时查看当前profit最小的item是否是“单身”，如果是的话就忽略，如果否的话就可以将其“吐出”而将属于新category的item加入。这样我们就得到了t+1个category时的profit top k.

依次类推，我们可以得到t+2个category时的profit top k，以及t+3个category时的profit top k等等。最终在所有category数目对应的最大elegance里挑选最大值。

但是注意，在贪心的过程中，如果我们无法找到一个可以吐出的item时，意味着我们无法构造“t+1个category时的profit top k”，因为这时已经发生了`t+1>k`。
