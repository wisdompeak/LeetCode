### 1627.Graph-Connectivity-With-Threshold

本题考查的是如何高效地选择两个数进行Union.如果是遍历数字A、遍历数字B，再判断是否有大于threshold的公约数，时间复杂度会非常高。

一个自然的想法是，遍历大于threshold的公约数x，然后查看x的倍数有哪些。所有关于x的倍数必然都是应该Union的。这类似于埃拉托斯特尼筛法。
