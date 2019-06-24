### 054.Distant-Barcodes

有一个比较容易理解的贪心算法。

将所有元素按照频次从大到小排列（所以相同的元素都会排在一起）。然后将这些元素先顺次填满reesult所有index为奇数的位置，然后在顺次填满result所有index为偶数的位置。这样就能尽可能地保证相同的元素不会排在一起了。

与本题类似的题目还有：621.Task Scheduler，767.Reorganize String。
