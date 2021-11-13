### 2064.Minimized-Maximum-of-Products-Distributed-to-Any-Store

我们不想让每个store存放的物品的太多，那么只好多征用store的数目。但是总的store数目是有限的，这就可能导致冲突。想要解决这个冲突，只能允许让每个store存更多的东西。至此，我们不难想到二分搜值就是一个显然易见的算法。

我们尝试每个store存放物品个数的上限是limit，那么对于每一种物品，我们能算出至少需要多少store来存放。遍历所有的物品种类，就可以得出总共需要的store数目n'，然后与实际的store数目n比较。根据如果n'<=n，说明上限可以往下降（还可以占用更多的store）；反之说明上限必须提升（减少需要占用的store）。
