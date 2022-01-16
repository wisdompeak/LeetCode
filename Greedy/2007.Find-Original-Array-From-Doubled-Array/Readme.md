### 2007.Find-Original-Array-From-Doubled-Array

很显然，changed里面的最大值，一定是original里面的最大值的两倍。这样，我们就把这两个数确定，并且从changed里面剔除。这样此时changed里面的最大值，就是original里面的第二大的值。我们同样可以把这两个元素从changed里面剔除，直至把所有元素都确定。

如果我们在这个过程中，发现changed里面的最大值x与x/2不同时存在于changed里面，说明无解。

#### 解法1：multiset
上述的思想可以粗暴地用multiset来实现。每个回合，直接从multiset里面删除最大的元素x，然后再删除其中数值为x/2的元素。这样的时间复杂度是NlogN.

#### 解法2：双指针
更高效的解法是双指针。将changed排序之后，我们设置left和right两个指针。对于changed[left]而言，我们一定是单调递增地移动right，试图寻找满足```changed[right]==changed[left]*2```的位置。找到这对之后，将used[left]和used[right]都标记为1，这样在后续的寻找中，无论left和right都不能指向已经用过的位置。

双指针遍历的过程中，我们期望恰好找到n/2对。任何时候，left或right越界了，说明我们无法找到下一个合适的配对，就返回空集。
